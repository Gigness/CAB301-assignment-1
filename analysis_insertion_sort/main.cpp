#include <iostream>
#include "experiment.h"
#include "experimentrunner.h"
#include <array>

#include <fstream>

using namespace std;

int main()
{
    // Test the method used to create permutations of a vector
    Experiment test(1000);
    test.testRandomVector();

    // collect data from 5000 to 75000 by 2500, performed 10 times each
    ExperimentRunner experimentRunner(5000, 75000, 2500, 10, "data/data_5000_75000_10.csv");
    experimentRunner.start();

    // collect data from 100000 to 150000 by 50000, performed 10 times each
    ExperimentRunner experimentRunner1(100000, 150000, 50000, 10, "data/data_100000_150000_10.csv");
    experimentRunner1.start();

    return 0;
}
