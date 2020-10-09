Project:	Lab 1
Author:		Alexander Hoke
Date:		09/19/2020

------------------------------ INCLUDED ------------------------------
Makefile					-	Build file for the project.
ReflexRover.cpp				-	Source code for the simple agent.
StateAgent.cpp				-	Source code for the state-base agent.
RoverSensors.cc     		-	Source code for the instructor supplied 
								input parser.
RoverSensors.hh				-	Header file for the instructor supplied 
								input parser.
ReflexAgent.cpp				-	Source code implementation off all classes
								included for both the ReflexRover and the
								StateRover.
ReflexAgent.hpp				-	Header file for ReflexAgent class and 
								struct definitions.
ReflexAgentUnitTesting.cpp	-	Source code for test cases.
Testing/catch.hpp			-	Header based unit testing framework.
								More detail avaliable in the UNIT
								TESTING portion of the readme.
Testing 					-	Directory to all test case text files.


---------------------------- INSTRUCTIONS ----------------------------
Run the following for both StateRover and ReflexRover executables:
	make
	./StateRover <<file-name>>.txt
	./ReflexRover <<file-name>>.txt

To remove the executable files:
	make clean

To individually compile either file:
	make State
	make Reflex

All instances of the primary executable are copiled using C++ 11:
	g++ -std=c++11


---------------------------- UNIT TESTING -----------------------------
Unit testing was done using a header based unit-test framework Catch2
which can be found:
	https://github.com/catchorg/Catch2

Testing for the ReflexAgent was straight forward, verifying that it 
could run with a minimal number of entries, and that it could
successfully locate the maximum number over its entire range.

Since the StateRover uses the SimpleRover's class which was tested, the
primary concerns for the StateRover were:

	(1) Does it visit all spaces open?
	(2) Does it terminate an appropriate time?
	(3) Does it collect all the samples?

Included in this zip file are all custom test cases made to verify
the agent's behavior. All names are self explanatory. The primary
concern was testing boundary cases.

Both ReflexAgent.cpp and ReflexAgent.hpp rely on the preprocessor
directive 'UNIT_TEST' to enable necessary functionality. The g++
compiler instruction is:
	g++ -std=c++11 -D UNIT_TEST

However, all test case make instruction is:
	make UnitTest