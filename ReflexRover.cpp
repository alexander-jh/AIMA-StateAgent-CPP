/*
 *  ReflexRover.cpp
 *      Author: Alexander Hoke
 *      Date:   09/15/20
 */

#include "ReflexAgent.hpp"

int main(int argv, char **args) {
    SimpleAgent rover = SimpleAgent(args[1]);
    int percept = rover.NextPercept();
    // Execute program until EOF is hit, if percept == -1 terminate program
    while(percept > -1) {
        printf("Perception: %-5d", percept);
        printf("Action: %c\n", SimpleAgent::SimpleReflexAgent(percept));
        percept = rover.NextPercept();
    }
    return 0;
}