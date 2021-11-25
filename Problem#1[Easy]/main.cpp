/*
Good morning! Here's your coding interview problem for today.
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

// 1: O(n^2)
bool bruteforce(std::vector<int> list, int k) {
    for (int i = 0; i < list.size(); ++i)
        for (int j = 0; j < list.size() - 1; ++j)
            if (list.at(i) + list.at(j) == k) return true;

    return false;
}

// 2: O(n*log(n))
bool binaraySearch(std::vector<int> list, int k) {
    std::sort(list.begin(), list.end());

    for (int item : list)
        if (std::binary_search(list.begin(), list.end(), k-item)) return true;

    return false;
}

// 3: O(n) ???
bool stackOverFlowStrangeSimpleSolution(std::vector<int> list, int k) {
    std::sort(list.begin(), list.end());

    int j = list.size()-1;
    for (int i = 0; i < list.size(); ++i) {
        if (i==j) break;

        int sum = list.at(i) + list.at(j);

        (sum > k) ? j-- : i++;
        if (sum == k) return true;
    }

    return false;
}

// 4: O(n) best sol
bool hashMap(std::vector<int> list, int k) {
    std::unordered_map<int, bool> map;

    for (int item : list)
        if (map[item]) return true; else map.insert({k-item, true});

    return false;
}

int main() {
    std::vector<int> list = {10, 15, 3, 7};

    std::cout << "Bruteforce: " << bruteforce(list, 17) << std::endl;
    std::cout << "Binary Search: " << binaraySearch(list, 17) << std::endl;
    std::cout << "StackOverFlow: " << stackOverFlowStrangeSimpleSolution(list, 17) << std::endl;
    std::cout << "HashMap: " << hashMap(list, 17) << std::endl;

    return 0;
}
