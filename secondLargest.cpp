#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    /**
     * @brief Vector containing a collection of integers.
     * 
     * This vector stores multiple integer values that can be used for various
     * operations such as searching, sorting, or finding specific elements
     * (e.g., the second largest element).
     * 
     * @details
     * The vector contains 7 elements: {10, 5, 20, 8, 15, 25, 3}
     * - Used to demonstrate algorithms for data processing
     * - Can be iterated to find maximum, minimum, or other statistical values
     * - Index-based access allows O(1) lookup time
     * 
     * @note
     * For finding the second largest element:
     * 1. Sort the vector in descending order, OR
     * 2. Traverse the vector twice to find largest and second largest
     * 3. The second largest in this array would be 20 (after 25)
     */
    vector<int> arr = {10, 5, 20, 8, 15, 25, 3};
    
    if (arr.size() < 2) {
        cout << "Array must have at least 2 elements" << endl;
        return 1;
    }
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    cout << "Second largest element: " << arr[1] << endl;
    
    return 0;
}