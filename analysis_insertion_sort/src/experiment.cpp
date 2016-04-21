#include "experiment.h"

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

void Experiment::run() {
    clock_t begin = clock();
    insertionSort();
    clock_t end = clock();
    time = (double)(end - begin) / CLOCKS_PER_SEC;
    if(!is_sorted(inputData.begin(), inputData.end())) {
        cout << "WARNING - insertionSort() completed, but array is not sorted..." << endl;
    }
}

void Experiment::outputExpData() {
    cout << "Input Size: " << size << endl
    << "Basic Operations performed: " << basicOps << endl
    << "Time taken: " << time << endl;
}

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

void Experiment::outputSize() {
    cout << "size: " << size << endl;
}

bool Experiment::isSorted() {
    for(unsigned int i = 0; i < inputData.size() - 1; i++) {
        if(inputData[i] > inputData[i+1]) {
            return false;
        }
    }
    return true;
}

void Experiment::outputInputData() {
    cout << "inputData: " << endl;
    for(unsigned int i = 0; i < inputData.size(); i++) {
        cout << inputData[i] << endl;
    }
    cout << "---------------------" << endl;
}

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
