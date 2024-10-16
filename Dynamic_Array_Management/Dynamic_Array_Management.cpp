#include <iostream>
#include <ctime>
#include <random>

int *arrayCreate(int arraySize, int maxRand) { // Creates the array
    try {
        int* myVector = new int[arraySize];
        std::cout << "Array: ";
        for (int i = 0; i < arraySize; i++) {
            myVector[i] = rand() % maxRand;
            std::cout << "\t" << myVector[i] << "[" << i + 1 << "] ";
            // std::cout << "Adress of " << i << " is " << &myVector[i] << " and is " << myVector[i] << std::endl;
        }
        std::cout << std::endl;
        return myVector;
    }
    catch (const std::exception&) {
        std::cout << "Something went wrong by " << &arrayCreate << std::endl;
    }
}

int* arraySort(int* Array, int arraySize) { // Sorts the array
    try {
        int* sortingArray = Array;
        int tmp;
        for (int i = 0; i < arraySize; i++) {
            for (int j = 0; j < arraySize; j++) {
                if (sortingArray[i] < sortingArray[j]) {
                    tmp = sortingArray[i];
                    sortingArray[i] = sortingArray[j];
                    sortingArray[j] = tmp;
                }
            }
        }
        std::cout << "Sorted array: ";
        for (int i = 0; i < arraySize; i++)
            std::cout << "\t" << sortingArray[i] << "[" << i + 1 << "] ";
        return sortingArray;
    }
    catch (const std::exception&) {
        std::cout << "Something went wrong by " << &arraySort << std::endl;
    }
}

int* arrayPopOut(int* Array, int arraySize) { // Deletes the defined element 
    int elementToPopOut;
    std::cout << "\nEnter which element you want to pop out => "; std::cin >> elementToPopOut;
    try {
        int* workingArray = new int[arraySize - 1];
        std::cout << "Popped out: ";
        for (int i = 0; i < arraySize; i++) {
            if (i != elementToPopOut - 1)
                workingArray[i] = Array[i];
            else
                continue;
            std::cout << "\t" << workingArray[i] << "[" << i+1 << "] ";
        }
        return workingArray;
    }
    catch (const std::exception&) { 
        std::cout << "Something went wrong by " << &arrayPopOut << std::endl;
    }
}

int* arrayPushBack(int* Array, int arraySize) { // Adds new element to the vector
    int elementToPushBack;
    std::cout << "\nEnter the number you want to add at the end => "; std::cin >> elementToPushBack;
    try {
        std::cout << "Modified array: ";
        int* workingArray = new int[arraySize + 1];
        for (int i = 0; i < arraySize; i++) {
            workingArray[i] = Array[i];
            std::cout << "\t" << workingArray[i] << "[" << i + 1 << "] ";
        }
        workingArray[arraySize + 1] = elementToPushBack;
        std::cout << "\t" << workingArray[arraySize + 1] << "[" << arraySize +1 << "] ";
        return workingArray;
    }
    catch (const std::exception&) {
        std::cout << "Something went wrong by" << &arrayPushBack << std::endl;
    }
}

int* arraySortDelete(int* Array, int arraySize) { // Deletes duplicates
    try {
        int tmp;
        short int j = 0;
        int* workingArray = Array;
        std::cout << "\nSuper sorted array: ";
        for (int i = 0; i < arraySize-1; i++) {
            if (workingArray[i] == workingArray[i + 1] && i+1 < arraySize) {
                workingArray[i + 1] = NULL;
                j++;
            }
        }
        int* resultArray = new int[arraySize - j];
        short int n = 0;
        for (int i = 0; i < arraySize - j; i++) {
            if (workingArray[n] != NULL)
            {
                resultArray[i] = workingArray[n];
                n++;
            }
            else
                n++;
            std::cout << "\t" << workingArray[i] << "[" << i + 1 << "] ";
        }
        return workingArray;
    }
    catch (const std::exception&)
    {
        std::cout << "Something went wrong by " << &arraySortDelete << std::endl;
    }
}

int main()
{   
    srand(time(NULL));
    int vectorSize;
    std::cout << "Enter the size of an array => "; std::cin >> vectorSize;
    int* superArray = arrayCreate(vectorSize, 100); // 100 - max number for random generation
    superArray = arraySort(superArray, vectorSize);
    //arrayPopOut(superArray, vectorSize);
    //arrayPushBack(superArray, vectorSize);
    arraySortDelete(superArray, vectorSize);
}
