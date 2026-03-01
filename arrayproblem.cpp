#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
===== ARRAY PROBLEMS WITH DSA PATTERNS =====
1. Two Sum - Hash Map Pattern
2. Find Maximum in Array - Linear Scan
3. Reverse Array - Two Pointer
4. Remove Duplicates - Two Pointer
5. Rotate Array - Array Manipulation
6. Prefix Sum Pattern
7. Sliding Window - Max Subarray
8. Binary Search in Sorted Array
*/

// ===== PROBLEM 1: TWO SUM =====
// DSA Pattern: Hash Map
// Intuition: Use hash map to store complements
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

// ===== PROBLEM 2: FIND MAXIMUM ELEMENT =====
// DSA Pattern: Linear Scan
// Intuition: Iterate and compare each element
int findMax(vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal;
}

// ===== PROBLEM 3: REVERSE ARRAY =====
// DSA Pattern: Two Pointer
// Intuition: Swap elements from start and end, move pointers inward
void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// ===== PROBLEM 4: REMOVE DUPLICATES =====
// DSA Pattern: Two Pointer
// Intuition: Use pointer to track unique position
int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return 0;
    int i = 0;
    for (int j = 1; j < arr.size(); j++) {
        if (arr[j] != arr[i]) {
            arr[++i] = arr[j];
        }
    }
    return i + 1;
}

// ===== PROBLEM 5: ROTATE ARRAY =====
// DSA Pattern: Array Rotation
// Intuition: Reverse entire + reverse parts
void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

// ===== PROBLEM 6: PREFIX SUM =====
// DSA Pattern: Prefix Sum
// Intuition: Pre-compute cumulative sums for fast range queries
vector<int> prefixSum(vector<int>& arr) {
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    return prefix;
}

// ===== PROBLEM 7: MAXIMUM SUBARRAY (Kadane's Algorithm) =====
// DSA Pattern: Sliding Window + Dynamic Programming
// Intuition: Track max ending here and global max
int maxSubarray(vector<int>& arr) {
    int maxCurrent = arr[0], maxGlobal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        maxCurrent = max(arr[i], maxCurrent + arr[i]);
        maxGlobal = max(maxGlobal, maxCurrent);
    }
    return maxGlobal;
}

// ===== PROBLEM 8: BINARY SEARCH =====
// DSA Pattern: Binary Search
// Intuition: Divide and conquer on sorted array
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// ===== PROBLEM 9: MERGE SORTED ARRAYS =====
// DSA Pattern: Two Pointer Merge
// Intuition: Compare elements from both arrays
vector<int> mergeSorted(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i++]);
        } else {
            result.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size()) result.push_back(arr1[i++]);
    while (j < arr2.size()) result.push_back(arr2[j++]);
    return result;
}

// ===== PROBLEM 10: CONTAINS DUPLICATE =====
// DSA Pattern: Hash Set
// Intuition: Track seen elements
bool containsDuplicate(vector<int>& arr) {
    unordered_map<int, bool> seen;
    for (int num : arr) {
        if (seen[num]) return true;
        seen[num] = true;
    }
    return false;
}

// ===== MAIN: EXAMPLES =====
int main() {
    cout << "===== ARRAY PROBLEMS DSA PATTERNS =====\n\n";

    // Example 1: Two Sum
    vector<int> nums = {2, 7, 11, 15};
    auto result = twoSum(nums, 9);
    cout << "1. Two Sum [2,7,11,15], target=9: [" << result[0] << "," << result[1] << "]\n";

    // Example 2: Find Max
    vector<int> arr = {3, 5, 1, 8, 2};
    cout << "2. Max Element in [3,5,1,8,2]: " << findMax(arr) << "\n";

    // Example 3: Reverse
    vector<int> arr3 = {1, 2, 3, 4, 5};
    reverseArray(arr3);
    cout << "3. Reverse [1,2,3,4,5]: ";
    for (int x : arr3) cout << x << " ";
    cout << "\n";

    // Example 4: Max Subarray
    vector<int> arr4 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "4. Maximum Subarray: " << maxSubarray(arr4) << "\n";

    // Example 5: Binary Search
    vector<int> sorted_arr = {1, 3, 5, 7, 9};
    cout << "5. Binary Search (target=7): " << binarySearch(sorted_arr, 7) << "\n";

    return 0;
}