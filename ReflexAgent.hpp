/*
 *  ReflexAgent.hpp
 *      Author: Alexander Hoke
 *      Date:   09/15/20
 */

#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <iomanip>

#include "RoverSensors.hh"

/*
 * Class for simple reflex agent.
 *
 * private member functions and class variable:
 *  percept: Object to current rover percept-sequence.
 *  InterpretPercept: Returns a condition given current soil status.
 *  RuleMatch: Returns condition-action based on assigned rules.
 *
 * public class variable and member function:
 *  SimpleAgent: Class constructor.
 *  SimpleReflexAgent: Mandated function. Supplied with current percept, returns
 *      appropriate action (GRAB(G), NOOP(N)).
 *  NextPercept: Returns next percept in the sequence.
 */
class SimpleAgent {

private:
    RoverSampleSensor *perceptSeq;
    static int InterpretPercept(int percept);
    static char RuleMatch(int condition);

public:
    SimpleAgent(char *file);
    ~SimpleAgent();
    static char SimpleReflexAgent(int percept);
    int NextPercept();
};

/*
 * Action: Enumeration class of possible actions in the program.
 *
 * -- Variables --
 * Type: Enumerations of the possible actions.
 *
 * -- Functions --
 * GetAction(Type): Returns the first character of an action enumeration. Used
 *                  for hashing command-action on look-up table.
 * PrintAction(Type): Returns the string of the enumerated action type for
 *                    I/O reporting purposes.
 */
class Action {
public:
    enum Type {
        NONE,
        GONORTH,
        GOEAST,
        GOSOUTH,
        LOOKNORTH,
        LOOKEAST,
        LOOKSOUTH,
        GRAB,
    };
    /* Public class function */
    static char GetActionChar(Type lastAction);
    static std::string PrintAction(Type lastAction);
};

/*
 * State: typedef struct of the current agent's state and recent percepts.
 *
 * -- Member variables --
 * pos_x: x-coordinate of agent's current location.
 * pos_y: y-coordinate of agent's current location.
 * soilId: Current soil type at agent's current location.
 * direction: Cardinal direction the agent is facing.
 * searched: True is the current soilId has been collected, false otherwise.
 * vision: Percept reporting of last look action.
 * lastAction: Previous action performed by the agent.
 */
typedef struct State {
public:
    int             pos_x;
    int             pos_y;
    int             soilId;
    std::string     direction;
    bool            searched;
    std::string     vision;
    Action::Type    lastAction;
} State;

/*
 * StateRover: Carries out all functions of the reflex agent with state. The agent
 *             acts with a list of priorities. If the current soil has not been
 *             collected, then the agent first will grab the soil. The agent will
 *             act until a combination of two boulders or NULL percepts are input.
 *             The agent's action depend on it's y-location and direction. It will
 *             attempt to snake around going North, East, South, East, North, East
 *             until termination conditions are met. If obstruction is encountered
 *             it will attempt to move to the next logical step.
 *
 * -- Public Variables --
 * current: Struct of the agent's current state.
 *
 * -- Public Functions --
 * Constructor: Builds object of the agent. with initial values:
 *      pos_x = 1, pos_y = 1, soilId = at position <1,1>, direction = EAST,
 *      searched = false, vision = NULL, lastAction = NULL
 * Destructor: Default destructor for the StateRover object.
 * ReflexAgentWithState: Carries out core functionality of class move by move. Returns
 *                       true so long as lastAction was not NONE. Input *percept is a
 *                       pointer to the current percept tuple <Vision, Sample>
 *
 * -- Private Variables --
 * moveCount: Current number of moves made by the agent.
 * samplesCollected: Count of samples kept by rover.
 * soilCollected: A hash set of all the uniquely observed soil samples collected by the
 *                agent.
 * rules: Hash map of all possible states the agent can encounter in the given
 *        environment. Links state to potential action.
 * consecutiveBoulders: Current count of boulders or NULL percepts received in current
 *                      columns. Reset by eastward movement.
 *
 * -- Private Functions --
 * UpdateState: Updates the current state of the robot following the previous turn's
 *              action. Invokes a switch statement built around the enumerated
 *              Action class. Further descriptions on each case. Accepts two pointers,
 *              one to the current state of the agent and one to the current percept
 *              tuple's instantiation.
 * BuildRules: Inserts all possible condition-action rules into the hash table. Hash
 *             keys for all action except Grab and Terminate are a permutation of
 *             the first characters of lastAction, current vision, direction, and
 *             the digit corresponding to the y-coordinate. Hash table was used
 *             due to near constant look-up time.
 * RuleMatch: Creates the hash key to look up corresponding action.
 * RuleAction: Queries rules, returning corresponding Action::Type.
 * HaveSearched: Queries soilCollected, returning if the current soilId has been
 *               collected.
 * PrintTermination: Prints the number of samples collected and moves taken by
 *                   the agent along its journey.
 * PrintState: Prints the current state of the agent at the end of each cycle
 *             of ReflexAgentWithState().
 * CheckVision: Returns the current vision percept, while verifying that a
 *              nullptr to the next percept is not present.
 */
class StateRover {
public:
#ifdef UNIT_TEST
    std::unordered_set<std::string> locationSeen;
    int getMoveCount();
    int getSamplesCollected();
#endif
    State current;
    /* Public class functions */
    StateRover();
    ~StateRover();
    bool ReflexAgentWithState(MovingRoverSensors *percept);

private:
    std::unordered_set<int> soilCollected;
    std::unordered_map<std::string, Action::Type> rules;
    int consecutiveBoulders;
    int moveCount;
    int samplesCollected;
    /* Private class member functions */
    void UpdateState(State *state, MovingRoverSensors *percept);
    static void BuildRules(std::unordered_map<std::string, Action::Type> *table);
    std::string RuleMatch(State *state) const;
    Action::Type RuleAction(const std::string *rule);
    bool HaveSearched(int soilId);
    static void printTermination(int totalMoves, int samplesCollected);
    static void printState(State *state);
    static std::string CheckVision(MovingRoverSensors *percept, int x_pos, int y_pos);
};