#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
    
    // Method 1: Using set to remove duplicates
    std::set<int> uniqueElements(arr.begin(), arr.end());
    
    // Convert back to vector if needed
    std::vector<int> result(uniqueElements.begin(), uniqueElements.end());
    
    // Print result
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}