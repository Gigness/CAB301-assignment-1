#ifndef EXPERIMENT_H
#define EXPERIMENT_H
#include <algorithm>
#include <vector>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Experiment
{
    public:
        Experiment(int size);
        virtual ~Experiment();
        void outputSize();
        void outputInputData();
        void insertionSort();
        void outputExpData();
        void run();
        void writeResults(string fileName);
        static void writeHeader(string fileName);
        bool isSorted();
        void testRandomVector();


    protected:

    private:
        int size;
        vector<int> inputData;
        unsigned int basicOps = 0;
        double time = 0;

};

#endif // EXPERIMENT_H
