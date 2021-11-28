/*
Good morning! Here's your coding interview problem for today.
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/
#include <iostream>
#include <stdlib.h>

// This can help us if we want to solve the problem ever so slightly faster
/*int rearrangeArr(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] >= 0) {
            if (i != j) std::swap(arr[i], arr[j]);
            j++;
        }
    return j;
}*/


int firstMissingPositive(int arr[], int n) {
	if (n <= 0) return 1;
	if (n == 1) return ( arr[0] != 1 ) ? 1 : 2;
    
	for(int i = 0; i < n; ++i)
		if(arr[i] <= 0) arr[i] = n+1;

    for(int i = 0; i < n; ++i) {
		int temp = std::abs(arr[i]);
		if(temp > 0 && temp < n+1)
			arr[temp-1] = -std::abs(arr[temp-1]);
	}

	for(int i = 0; i < n; ++i)
		if(arr[i]>0)
			return i+1;

	return n+1;
}

void printArray(int arr[], int n) {
    std::cout << "{ ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << " }" << std::endl;
}

int main()
{
    // Example tests
    int n = 5;
    int arr[] = {3, 4, -1, 1, 0};
    std::cout << "Inital state: "; printArray(arr, n);
    std::cout << "Solution: " << firstMissingPositive(arr, n) << std::endl;

    return 0;
}

