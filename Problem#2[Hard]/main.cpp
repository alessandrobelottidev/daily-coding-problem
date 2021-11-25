/*
Good morning! Here's your coding interview problem for today.
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/
#include <iostream>

int *bruteforce(const int arr[], int n) {
    int* temp = new int[n];

    for (int i = 0; i < n; ++i) {
        int product = 1;
        for (int j = 0; j < n; ++j)
            if (j!=i) product *= arr[j];
        temp[i] = product;
    }

    return temp;
}

int *simpleAnswer(int arr[], int n) {
    int product = 1;
    std::for_each(arr, arr+n, [&product](int e) { product*=e; });

    for (int i = 0; i < n; ++i)
        arr[i] = product / arr[i];

    return arr;
}

int *NComplexityWithoutDivision(const int arr[], int n) {
    if (n == 0) return new int[n] {};
    if (n == 1) return new int[n] {0};
    if (n == 2) return new int[n] {arr[1], arr[0]};

    int* LTR = new int[n];
    int* RTL = new int[n];
    int* prod = new int[n];

    LTR[0] = 1;
    RTL[n-1] = 1;

    for (int i = 1; i < n; ++i)
        LTR[i] = arr[i-1] * LTR[i-1];

    for (int j = n-2; j >= 0; --j)
        RTL[j] = arr[j+1] * RTL[j+1];

    for (int i = 0; i < n; ++i)
        prod[i] = LTR[i] * RTL[i];

    return prod;
}

void printArray(const int arr[], int n) {

    std::cout << "[" << n << "] { ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "}" << std::endl;
}

int main() {
    int n = 5;
    int arr[] = {1,2,3,4,5};
    std::cout << "Initial: "; printArray(arr, n);

    int* ans = bruteforce(arr, n);
    std::cout << "Bruteforce: "; printArray(ans, n);

    ans = NComplexityWithoutDivision(arr, n);
    std::cout << "N Complexity without using division: "; printArray(ans, n);

    ans = simpleAnswer(arr, n);
    std::cout << "Simple answer: "; printArray(ans, n);

    return 0;
}
