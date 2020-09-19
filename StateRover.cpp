/*
 *  StateRover.cpp
 *      Author: Alexander Hoke
 *      Date:   09/15/20
 */

#include "ReflexAgent.hpp"

int main(int argc, char **args) {
    /* Verify file argument exists and is valid. */
    if(args[1] == nullptr) {
        std::cout << "ERROR: No valid file.\n";
    } else {
        /* Declare new rover object and percept instance */
        MovingRoverSensors percept = MovingRoverSensors(args[1]);
        StateRover stateRover = StateRover();
        /* Execute program until ReflexAgentWithState returns false */
        while (stateRover.ReflexAgentWithState(&percept));
    }
    return 0;
}