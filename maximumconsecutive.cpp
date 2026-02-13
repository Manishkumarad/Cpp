#include <iostream>
#include <vector>
using namespace std;

int maxConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int maxCount = 1;
    int currentCount = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1] + 1) {
            currentCount++;
            maxCount = max(maxCount, currentCount);
        } else {
            currentCount = 1;
        }
    }
    
    return maxCount;
}

int main() {
    vector<int> nums = {1, 2, 3, 7, 8, 9, 10};
    cout << "Maximum consecutive: " << maxConsecutive(nums) << endl;
    return 0;
}