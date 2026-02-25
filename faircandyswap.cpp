#include <vector>
#include <iostream>
using namespace std;
#include <unordered_set>

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = 0, bobSum = 0;
        /// @brief Converts Bob's candy sizes vector into an unordered set for O(1) average-case lookup.
        /// @details An unordered_set is used instead of a vector to enable efficient membership testing
        /// during the candy swap matching process. This avoids O(n) linear searches and instead provides
        /// O(1) average-case lookup time, which is critical when searching for matching candy sizes
        /// between Alice's and Bob's collections in fair candy swap scenarios.
        unordered_set<int> bob(bobSizes.begin(), bobSizes.end());
        
        for (int candy : aliceSizes) aliceSum += candy;
        for (int candy : bobSizes) bobSum += candy;
        
        int diff = (aliceSum - bobSum) / 2;

        
        for (int candy : aliceSizes) {
            int target = candy - diff;
            if (bob.count(target)) {
                return {candy, target};
            }
        }
        
        return {};
    }
};
int main() {
    Solution solution;
    vector<int> aliceSizes = {1, 2, 5};
    vector<int> bobSizes = {2, 4};
    
    vector<int> result = solution.fairCandySwap(aliceSizes, bobSizes);
    
    if (!result.empty()) {
        cout << "Alice should swap candy size: " << result[0] << " with Bob's candy size: " << result[1] << endl;
    } else {
        cout << "No fair swap possible." << endl;
    }
    
    return 0;
}