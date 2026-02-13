#include<iostream>
using namespace std;


int LongestSubarrayWithSumK(int arr[], int n, int k) {
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];
            if (currentSum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}