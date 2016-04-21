#ifndef EXPERIMENTRUNNER_H
#define EXPERIMENTRUNNER_H

#include <string>
#include "experiment.h"


class ExperimentRunner
{
    public:
        ExperimentRunner(int smallestInputSize, int largestInputSize, int increments, int trialsPerDataSet, string fileName);
        virtual ~ExperimentRunner();
        void start();

    protected:

    private:
        int minVectorSize;
        int maxVectorSize;
        int increments;
        int trials;
        string resultsFile;
};

#endif // EXPERIMENTRUNNER_H
