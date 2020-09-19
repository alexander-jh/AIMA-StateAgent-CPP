#
# Makefile
#	Author: Alexander Hoke
#	Date:	09/16/20
#

CC		= g++
LIBS	= ReflexAgent.hpp ReflexAgent.cpp RoverSensors.hh RoverSensors.cc
REFLEX	= ReflexRover
STATE	= StateRover
CATCH	= Testing/catch.hpp
TEST   	= ReflexAgentUnitTesting

all: Reflex State

Reflex:
	$(CC) -o $(REFLEX) $(REFLEX).cpp $(LIBS)

State:
	$(CC) -o $(STATE) $(STATE).cpp $(LIBS)

UnitTest:
	$(CC) -D UNIT_TEST -o $(TEST) $(TEST).cpp $(LIBS) $(CATCH)
	./$(TEST)
	rm -rf $(TEST)

clean:
	rm -rf $(REFLEX) $(STATE)