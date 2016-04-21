#include "experiment.h"

/**
* Experiment class used to create a permutation of a vector and sort it using
* insertion sort. Basic operations counter and exeuction time in seconds
* are recorded and appended to a csv.
* @param size size of vector to be created.
*/
Experiment::Experiment(int size) : size(size)
{
    for(int i = 0; i < size; i++) {
        inputData.push_back(i);
    }
    random_shuffle(inputData.begin(), inputData.end());
    if(is_sorted(inputData.begin(), inputData.end())) {
        cout << "WARNING: instantiated vector is already sorted... becareful" << endl;
    }
    cout << "vector of size: " << size << " created and randomized" << endl;
}

Experiment::~Experiment()
{
    cout << "Experiment deleted" << endl;
}

/**
* Called on an experiment object to sort the vector
* and store the experimental results (operations, time)
* as instance variables.
*/
void Experiment::run() {
    clock_t begin = clock();
    insertionSort();
    clock_t end = clock();
    time = (double)(end - begin) / CLOCKS_PER_SEC;
    if(!is_sorted(inputData.begin(), inputData.end())) {
        cout << "WARNING - insertionSort() completed, but array is not sorted..." << endl;
    }
}

/**
* Insertion sort algorithm
* Implemented according to Levitin, A. (2012) Page 135.
* Counts basic operations performed.
*/
void Experiment::insertionSort() {
    // basic operation counter
    int counter = 0;

    for(unsigned int i = 1; i < inputData.size(); i++) {
        int key = inputData[i];
        int j = i - 1;
        while(j >= 0 && key < inputData[j]) {
            counter ++;
            inputData[j + 1] = inputData[j];
            j--;
        }
        inputData[j + 1] = key;
    }
    basicOps = counter;
}

/**
* label the columns of the CSV. To be called
* before any data is collected.
*/
void Experiment::writeHeader(string fileName) {
    ofstream dataFile;
    dataFile.open(fileName);
    if(dataFile.fail()) {
        cout << "FILE couldn't be opened" << endl;
        exit(1);
    }
    dataFile << "n,operations,time" << endl;
    dataFile.close();
}

/**
* Appends results of an experiment case to a CSV.
* Only called after the Experiment.run().
*/
void Experiment::writeResults(std::string fileName) {
    ofstream dataFile;
    dataFile.open(fileName, ios::app);
    if(dataFile.fail()) {
        cout << "FILE couldn't be opened" << endl;
        exit(1);
    }

    dataFile << size << "," << basicOps << "," << time << endl;
    dataFile.close();
}

/**
* Method used to inspect the permutations created
* using the random_shuffle algorithm.
* Vector of size 30 is created and shuffled 20 times.
* Results appended to test file for inspection
*/
void Experiment::testRandomVector() {
    ofstream testFile;
    testFile.open("data/random_vector_test.txt");
    if(testFile.fail()) {
        cout << "FILE couldn't be opened" << endl;
        exit(1);
    }

    vector<int> test;
    int size = 30;
    int trials = 20;

    // set up the vector
    for(int i = 0; i < size; i++) {
        test.push_back(i);
    }

    // write initial vector state to file
    for(unsigned int i = 0; i < test.size(); i++) {
        testFile << test[i] << " ";
    }
    testFile << endl;

    // shuffle the vector and write it to a test file
    for(int i = 0; i < trials; i++) {
        random_shuffle(test.begin(), test.end());

        for(unsigned int i = 0; i < test.size(); i++) {
            testFile << test[i] << " ";
        }
        testFile << endl;
    }
}

/**
* Debugging methods.
*/
void Experiment::outputSize() {
    cout << "size: " << size << endl;
}

void Experiment::outputInputData() {
    cout << "inputData: " << endl;
    for(unsigned int i = 0; i < inputData.size(); i++) {
        cout << inputData[i] << endl;
    }
    cout << "---------------------" << endl;

}void Experiment::outputExpData() {
    cout << "Input Size: " << size << endl
    << "Basic Operations performed: " << basicOps << endl
    << "Time taken: " << time << endl;
}
