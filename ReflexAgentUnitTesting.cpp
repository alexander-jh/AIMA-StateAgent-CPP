/*
 *  ReflexAgentUnitTesting.cpp
 *      Author: Alexander Hoke
 *      Date:   09/16/20
 */

#define CATCH_CONFIG_MAIN

#include <unistd.h>
#include "ReflexAgent.hpp"
#include "Testing/catch.hpp"

std::string GetDir();
int *StateTestResults(char *file);
int SimpleAgentResults(char *file);
char *GetCharArray(const std::string& location);

/* ---------- State Agent Test Cases ---------- */

TEST_CASE("Case: hw1-data2.txt", "7 Locations 2 Samples") {
    std::string location = GetDir() + "/Testing/hw1-data2.txt";
    char *file = GetCharArray(location);
    int *results = StateTestResults(file);
    /* Moves made */
    REQUIRE(*results == 7);
    /* Samples collected */
    REQUIRE(*(results + 1) == 6);
    /* Print results */
    printf("%s\n", "Case: hw1-data1.txt");
    printf("Spaces Expected: 7 Samples Expected: 2\n");
    printf("Spaces Seen: %d Samples Collected: %d\n\n", *(results), *(results + 1));
    /* Release mallocs */
    free(file);
    free(results);
}

TEST_CASE("Case: TwoBoulders.txt", "") {
    std::string location = GetDir() + "/Testing/TwoBoulders.txt";
    char *file = GetCharArray(location);
    int *results = StateTestResults(file);
    /* Moves made */
    REQUIRE(*results == 11);
    /* Samples collected */
    REQUIRE(*(results + 1) == 8);
    /* Print results */
    printf("%s\n", "Case: TwoBoulders.txt");
    printf("Spaces Expected: 11 Samples Expected: 4\n");
    printf("Spaces Seen: %d Samples Collected: %d\n\n", *(results), *(results + 1));
    /* Release mallocs */
    free(file);
    free(results);
}

TEST_CASE("Case: SampleDuplicate.txt", "") {
    std::string location = GetDir() + "/Testing/SampleDuplicate.txt";
    char *file = GetCharArray(location);
    int *results = StateTestResults(file);
    /* Moves made */
    REQUIRE(*results == 11);
    /* Samples collected */
    REQUIRE(*(results + 1) == 7);
    /* Print results */
    printf("%s\n", "Case: SampleDuplicate.txt");
    printf("Spaces Expected: 11 Samples Expected: 4\n");
    printf("Spaces Seen: %d Samples Collected: %d\n\n", *(results), *(results + 1));
    /* Release mallocs */
    free(file);
    free(results);
}

TEST_CASE("Case: AdjacentBoulders.txt", "") {
    std::string location = GetDir() + "/Testing/AdjacentBoulders.txt";
    char *file = GetCharArray(location);
    int *results = StateTestResults(file);
    /* Moves made */
    REQUIRE(*results == 5);
    /* Samples collected */
    REQUIRE(*(results + 1) == 4);
    /* Print results */
    printf("%s\n", "Case: AdjacentBoulders.txt");
    printf("Spaces Expected: 5 Samples Expected: 2\n");
    printf("Spaces Seen: %d Samples Collected: %d\n\n", *(results), *(results + 1));
    /* Release mallocs */
    free(file);
    free(results);
}

TEST_CASE("Case: ClearEnd.txt", "") {
    std::string location = GetDir() + "/Testing/ClearEnd.txt";
    char *file = GetCharArray(location);
    int *results = StateTestResults(file);
    /* Moves made */
    REQUIRE(*results == 12);
    /* Samples collected */
    REQUIRE(*(results + 1) == 11);
    /* Print results */
    printf("%s\n", "Case: ClearEnd.txt");
    printf("Spaces Expected: 12 Samples Expected: 4\n");
    printf("Spaces Seen: %d Samples Collected: %d\n\n", *(results), *(results + 1));
    /* Release mallocs */
    free(file);
    free(results);
}

TEST_CASE("Case: OneColumn.txt", "") {
    std::string location = GetDir() + "/Testing/OneColumn.txt";
    char *file = GetCharArray(location);
    int *results = StateTestResults(file);
    /* Moves made */
    REQUIRE(*results == 2);
    /* Samples collected */
    REQUIRE(*(results + 1) == 2);
    /* Print results */
    printf("%s\n", "Case: OneColumn.txt");
    printf("Spaces Expected: 2 Samples Expected: 2\n");
    printf("Spaces Seen: %d Samples Collected: %d\n\n", *(results), *(results + 1));
    /* Release mallocs */
    free(file);
    free(results);
}

TEST_CASE("Case: NowhereToGo.txt", "") {
    std::string location = GetDir() + "/Testing/NowhereToGo.txt";
    char *file = GetCharArray(location);
    int *results = StateTestResults(file);
    /* Moves made */
    REQUIRE(*results == 1);
    /* Samples collected */
    REQUIRE(*(results + 1) == 1);
    /* Print results */
    printf("%s\n", "Case: NowhereToGo.txt");
    printf("Spaces Expected: 1 Samples Expected: 1\n");
    printf("Spaces Seen: %d Samples Collected: %d\n\n", *(results), *(results + 1));
    /* Release mallocs */
    free(file);
    free(results);
}

/* ---------- Simple Agent Test Cases ---------- */

TEST_CASE("Case: hw1-data1.txt", "") {
    std::string location = GetDir() + "/Testing/hw1-data1.txt";
    char *file = GetCharArray(location);
    int seen = SimpleAgentResults(file);
    int expected = 4;
    /* Samples collected */
    REQUIRE(seen == expected);
    /* Print results */
    printf("Case: hw1-data1.txt\n");
    printf("Spaces Seen: %d Samples Collected: %d\n\n", seen, expected);
    /* Release mallocs */
    free(file);
}

TEST_CASE("Case: OneEntry.txt", "") {
    std::string location = GetDir() + "/Testing/OneEntry.txt";
    char *file = GetCharArray(location);
    int seen = SimpleAgentResults(file);
    int expected = 0;
    /* Samples collected */
    REQUIRE(seen == expected);
    /* Print results */
    printf("Case: OneEntry.txt\n");
    printf("Spaces Seen: %d Samples Collected: %d\n\n", seen, expected);
    /* Release mallocs */
    free(file);
}

TEST_CASE("Case: EntireRange.txt", "") {
    std::string location = GetDir() + "/Testing/EntireRange.txt";
    char *file = GetCharArray(location);
    int seen = SimpleAgentResults(file);
    int expected = 6;
    /* Samples collected */
    REQUIRE(seen == expected);
    /* Print results */
    printf("Case: EntireRange.txt\n");
    printf("Spaces Seen: %d Samples Collected: %d\n\n", seen, expected);
    /* Release mallocs */
    free(file);
}



/*
 * Returns the current working directory of the executable.
 */
std::string GetDir() {
    long size;
    char *buf;
    char *ptr;
    size = pathconf(".", _PC_PATH_MAX);
    if ((buf = (char *)malloc((size_t)size)) != nullptr) ptr = getcwd(buf, (size_t)size);
    return std::string(ptr);

}

/*
 * Conversts std::string to char*
 */
char* GetCharArray(const std::string& location) {
    char *file = (char *) malloc((location.size() + 1)*sizeof(char));
    strcpy(file, location.c_str());
    return file;
}

/*
 * Classes only avaliable through pre-processor directive:
 *      -D UNIT_TEST
 */
int *StateTestResults(char *file) {
    int *testState;
    testState = (int *) malloc(2 * sizeof(int));
    StateRover agent = StateRover();
    MovingRoverSensors percept = MovingRoverSensors(file);
    while(agent.ReflexAgentWithState(&percept));
    *testState = agent.getMoveCount();
    *(testState + 1) = agent.getSamplesCollected();
    return testState;
}

/*
 * Test case of Simple Agent
 */
int SimpleAgentResults(char *file) {
    SimpleAgent agent = SimpleAgent(file);
    int samples = 0;
    int percept;
    while((percept = agent.NextPercept()) > -1) {
        if(SimpleAgent::SimpleReflexAgent(percept) == 'G') samples++;
    }
    return samples;
}