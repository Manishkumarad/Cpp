#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(vector<int>& nums) {
    int n = nums.size();
    long long expectedSum = (long long)n * (n + 1) / 2;
    long long actualSum = 0;
    
    for (int num : nums) {
        actualSum += num;
    }
    
    return expectedSum - actualSum;
}

int main() {
    vector<int> nums = {1, 2, 4, 5, 6};  // Missing: 3
    cout << "Missing number: " << findMissingNumber(nums) << endl;
    
    return 0;
}