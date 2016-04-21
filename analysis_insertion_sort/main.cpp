#include <iostream>
#include "experiment.h"
#include "experimentrunner.h"
#include <array>

#include <fstream>

using namespace std;

int main()
{
    Experiment test(1000);
    test.testRandomVector();
//    ExperimentRunner experimentRunner(5000, 75000, 2500, 10, "data/data_5000_75000_10.csv");
//    experimentRunner.start();
//
//    ExperimentRunner experimentRunner1(100000, 150000, 50000, 10, "data/data_100000_150000_10.csv");
//    experimentRunner1.start();
//
//    return 0;
}
