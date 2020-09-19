/*
 *  ReflexAgent.cpp
 *      Author: Alexander Hoke
 *      Date:   09/15/20
 */

#include "ReflexAgent.hpp"

SimpleAgent::SimpleAgent(char *file) {
    // If no pointer to a file exists return command line instance.
    if(file != nullptr) {
        perceptSeq = new RoverSampleSensor(file);
    } else {
        perceptSeq = new RoverSampleSensor();
    }
}

SimpleAgent::~SimpleAgent() = default;

int SimpleAgent::InterpretPercept(int percept) {
    return percept % 5;
}

int SimpleAgent::NextPercept() {
    int percept = -1;
    SamplePercept *nextSample = perceptSeq->getSamplePercept();
    // Returns -1 if EOF is reached
    if(nextSample != nullptr) {
        percept = nextSample->value();
    }
    return percept;
}

char SimpleAgent::RuleMatch(int condition) {
    char action;
    // If condition-action rule==0 return GRAB action, else NOOP.
    (condition == 0) ? (action = 'G') : (action = 'N');
    return action;
}

char SimpleAgent::SimpleReflexAgent(int percept) {
    // Generate current state
    int condition = InterpretPercept(percept);
    // Evaluate state and return action
    return RuleMatch(condition);
}


char Action::GetActionChar(Action::Type lastAction) {
    /* Returns first character of action for hashing */
    switch(lastAction) {
        case Action::GONORTH:
            return 'G';
        case Action::GOEAST:
            return 'G';
        case Action::GOSOUTH:
            return 'G';
        case Action::LOOKNORTH:
            return 'L';
        case Action::LOOKEAST:
            return 'L';
        case Action::LOOKSOUTH:
            return 'L';
        case Action::GRAB:
            return 'G';
        default:
            return 'N';
    }
}

std::string Action::PrintAction(Action::Type lastAction) {
    /* Return string representation of action */
    switch(lastAction) {
        case Action::GONORTH:
            return "GONORTH";
        case Action::GOEAST:
            return "GOEAST";
        case Action::GOSOUTH:
            return "GOSOUTH";
        case Action::LOOKNORTH:
            return "LOOKNORTH";
        case Action::LOOKEAST:
            return "LOOKEAST";
        case Action::LOOKSOUTH:
            return "LOOKSOUTH";
        case Action::GRAB:
            return "GRAB";
        default:
            return "NULL";
    }
}

StateRover::StateRover() {
    moveCount = 0;
    samplesCollected = 0;
    current.pos_x = 1;
    current.pos_y = 1;
    current.direction = "EAST";
    current.searched = false;
    current.lastAction = Action::NONE;
    current.vision = "NULL";
    current.soilId = 0;
    consecutiveBoulders = 0;
    BuildRules(&(this->rules));
#ifdef UNIT_TEST
    this->locationSeen.insert("0101");
#endif
}

bool StateRover::ReflexAgentWithState(MovingRoverSensors *percept) {
    UpdateState(&(this->current), percept);
    std::string rule = RuleMatch(&(this->current));
    this->current.lastAction = RuleAction(rule);
    /* If the Action::Type returned is NONE, then the agent terminates */
    bool atEnd = (this->current.lastAction == Action::Type::NONE);
#ifdef UNIT_TEST
    std::string loc = "0" + std::to_string(this->current.pos_x);
    loc += "0" + std::to_string(this->current.pos_y);
    this->locationSeen.insert(loc);
#else
    if (atEnd) {
        printTermination(this->moveCount, this->samplesCollected);
    } else {
        printState(&this->current);
    }
#endif
    /* Negated to return true to calling program */
    return !atEnd;
}

void StateRover::BuildRules(std::unordered_map<std::string, Action::Type> *table) {
    table->insert(std::pair<std::string, Action::Type>("GRAB", Action::GRAB));
    table->insert(std::pair<std::string, Action::Type>("TERM", Action::NONE));
    table->insert(std::pair<std::string, Action::Type>("LCE1", Action::GOEAST));
    table->insert(std::pair<std::string, Action::Type>("LCE2", Action::GOEAST));
    table->insert(std::pair<std::string, Action::Type>("LCN1", Action::GONORTH));
    table->insert(std::pair<std::string, Action::Type>("LCS2", Action::GOSOUTH));
    table->insert(std::pair<std::string, Action::Type>("GCN2", Action::LOOKEAST));
    table->insert(std::pair<std::string, Action::Type>("GCS1", Action::LOOKEAST));
    table->insert(std::pair<std::string, Action::Type>("LNN1", Action::LOOKEAST));
    table->insert(std::pair<std::string, Action::Type>("LNS2", Action::LOOKEAST));
    table->insert(std::pair<std::string, Action::Type>("GCE1", Action::LOOKNORTH));
    table->insert(std::pair<std::string, Action::Type>("LNE1", Action::LOOKNORTH));
    table->insert(std::pair<std::string, Action::Type>("GNE1", Action::LOOKNORTH));
    table->insert(std::pair<std::string, Action::Type>("GCE2", Action::LOOKSOUTH));
    table->insert(std::pair<std::string, Action::Type>("LNE2", Action::LOOKSOUTH));
}

void StateRover::UpdateState(State *state, MovingRoverSensors *percept) {
    /* Declare reference variables for readability */
    Action::Type lastAction = state->lastAction;
    int *x = &(state->pos_x);
    int *y = &(state->pos_y);
    int soilId;
    switch(lastAction) {
        /* Increment y-coord, update SoilId, increment moveCount. Do
         * not need to adjust direction, because look will always be
         * called prior to movement. */
        case Action::GONORTH:
            (*y)++;
            soilId = percept->getSamplePercept(*x, *y)->value();
            state->soilId = soilId;
            state->searched = HaveSearched(soilId);
            this->moveCount++;
            break;
        /* Analog to GONORTH, except increment x-coord. Resets the
         * boulder/nullptr count. */
        case Action::GOEAST:
            (*x)++;
            soilId = percept->getSamplePercept(*x, *y)->value();
            state->soilId = soilId;
            state->searched = HaveSearched(soilId);
            this->moveCount++;
            this->consecutiveBoulders = 0;
            break;
        /* Decrements y-coord, analog to other movements */
        case Action::GOSOUTH:
            (*y)--;
            soilId = percept->getSamplePercept(*x, *y)->value();
            state->searched = HaveSearched(soilId);
            this->moveCount++;
            break;
        /* Follows same increments and decrements to x,y-coords as the
         * movements. Updates relative direction, vision percept, and
         * if the percept is not clear increments boulder count. */
        case Action::LOOKNORTH:
            state->direction = "NORTH";
            state->vision = CheckVision(percept, *x, (*y)+1);
            if(state->vision == "NULL" || state->vision == "BOULDER") this->consecutiveBoulders++;
            break;
        case Action::LOOKEAST:
            state->direction = "EAST";
            state->vision = CheckVision(percept, (*x)+1, *y);
            if(state->vision == "NULL" || state->vision == "BOULDER") this->consecutiveBoulders++;
            break;
        case Action::LOOKSOUTH:
            state->direction = "SOUTH";
            state->vision = CheckVision(percept, *x, (*y)-1);
            if(state->vision == "NULL" || state->vision == "BOULDER") this->consecutiveBoulders++;
            break;
        /* Gets soilId, hashes soilId, updates searched. */
        case Action::GRAB:
            soilId = percept->getSamplePercept(*x, *y)->value();
            state->soilId = soilId;
            this->soilCollected.insert(soilId);
            state->searched = true;
            if(SimpleAgent::SimpleReflexAgent(soilId) == 'G') this->samplesCollected++;
            break;
        /* No other possible cases */
        default:
            break;
    }
}

/* Implemented so Grab is not improperly called. */
bool StateRover::HaveSearched(int soilId) {
    /* Reference hash set */
    std::unordered_set<int> soil = this->soilCollected;
    /* If the terminating pointer is not returned, then the
     * sample exists in the set. */
    bool soilObserved = !(soil.find(soilId) == soil.end());
    return soilObserved;
}

std::string StateRover::RuleMatch(State *state) const {
    std::string rule;
    if(this->consecutiveBoulders == 2) {
        rule = "TERM";
    } else if (!state->searched) {
        rule = "GRAB";
    } else {
        char temp[4];
        temp[0] = Action::GetActionChar(state->lastAction);
        /* Identical cases to NULL and BOULDER for hash table */
        if(state->vision == "BOULDER" || state->vision == "NULL") {
            temp[1] = 'N';
        } else {
            temp[1] = state->vision[0];
        }
        temp[2] = state->direction[0];
        /* Force conversion of int to ASCII */
        temp[3] = (char) ('0' + state->pos_y);
        /* Force cast of char* to std::string */
        rule = std::string(temp);
    }
    return rule;
}

/* rule passed as reference to avoid copying */
Action::Type StateRover::RuleAction(std::string rule) {
    return this->rules[rule.substr(0,4)];
}

void StateRover::printTermination(int totalMoves, int samplesCollected) {
    std::cout << std::endl << "Total Compounds Collected: " << samplesCollected;
    std::cout << "\t Total Moves: " << totalMoves << std::endl;
}

void StateRover::printState(State *state) {
    std::cout << std::setw(9) << "Position: <" +
                 std::to_string(state->pos_x) + "," + std::to_string(state->pos_y) + "> ";
    std::cout << "Looking: " << std::setw(6) << std::left << state->direction;
    std::cout << "Perceived: " << std::setw(12) << "<" + std::to_string(state->soilId)
    + ","  + state->vision + ">";
    std::cout << "Action: " << Action::PrintAction(state->lastAction);
    std::cout << std::endl;
}

std::string StateRover::CheckVision(MovingRoverSensors *percept, int x_pos, int y_pos) {
    /* Pointer to current vision percept */
    VisionPercept *vp = percept->getVisionPercept(x_pos, y_pos);
    std::string vision;
    /* If pointer not null assign as clear/not clear */
    if (vp != nullptr) {
        (vp->isClear()) ? (vision = "CLEAR") : (vision = "BOULDER");
    } else {
        vision = "NULL";
    }
    return vision;
}

/* Default destructor */
StateRover::~StateRover() = default;

/* Testing functions */
#ifdef UNIT_TEST
    int StateRover::getMoveCount() {
        return this->locationSeen.size();
    }
    int StateRover::getSamplesCollected() {
        return this->samplesCollected;
    }
#endif
