#include "experimentrunner.h"

/**
* Constructor for experiment runner.
* @param smallestInputSize minimum vector size for experiment
* @param largestInputSize maximum vector size for experiment
* @param increments used to increase the vector size from mimimum to maximum
* @param trails number of times to repeat experiment for a given vector size
* @param resultsFile location of the results csv
*/
ExperimentRunner::ExperimentRunner(int smallestInputSize, int largestInputSize, int increments, int trialsPerDataSet, string file)
: minVectorSize(smallestInputSize), maxVectorSize(largestInputSize), increments(increments), trials(trialsPerDataSet), resultsFile(file)
{
    int totalExperiments = ((largestInputSize - smallestInputSize) / increments) * trials;
    cout << "Experiment runner" << endl
    << "minVectorSize: " << minVectorSize << endl
    << "maxVectorSize: " << maxVectorSize << endl
    << "increments: " << increments << endl
    << "trials: " << trials << endl
    << "total experiments: " << totalExperiments << endl
    << "resultsFile: " << resultsFile << endl;
}

ExperimentRunner::~ExperimentRunner()
{
    cout << "ExperimentRunner completed" << endl;
}

/**
* Wrapper to run all experiments. Writes results to the results file.
*/
void ExperimentRunner::start()
{
    Experiment::writeHeader(resultsFile);
    cout << "ExperimentRunner starting..." << endl;
    for(int i = minVectorSize; i <= maxVectorSize; i += increments) {
        for(int j = 0; j < trials; j++) {
            Experiment e(i);
            e.run();
            e.writeResults(resultsFile);
        }
    }
}
