#include <iostream>
#include <vector>

void moveZerosToEnd(std::vector<int>& arr) {
    int nonZeroIndex = 0;
    
    // Move all non-zero elements to the front
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            arr[nonZeroIndex++] = arr[i];
        }
    }
    
    // Fill remaining positions with zeros
    while (nonZeroIndex < arr.size()) {
        arr[nonZeroIndex++] = 0;
    }
}

int main() {
    std::vector<int> arr = {1, 0, 2, 0, 3, 0, 4};
    
    moveZerosToEnd(arr);
    
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}