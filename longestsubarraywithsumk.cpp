#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int k) {
    unordered_map<int, int> sumMap;
    int maxLen = 0;
    int currentSum = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];
        
        if (currentSum == k) {
            maxLen = i + 1;
        }
        
        if (sumMap.find(currentSum - k) != sumMap.end()) {
            maxLen = max(maxLen, i - sumMap[currentSum - k]);
        }
        
        if (sumMap.find(currentSum) == sumMap.end()) {
            sumMap[currentSum] = i;
        }
    }
    
    return maxLen;
}

int main() {
    vector<int> arr = {15, 2, 4, 8, 9, -5, 10, 1};
    int k = 15;
    
    cout << "Longest subarray length: " << longestSubarrayWithSumK(arr, k) << endl;
    
    return 0;
}