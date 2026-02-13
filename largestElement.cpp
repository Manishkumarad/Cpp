#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {10, 25, 5, 40, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int largest = *max_element(arr, arr + n);
    
    cout << "Largest element: " << largest << endl;
    
    return 0;
}

int findLargest(int arr[], int n) {
    return *max_element(arr, arr + n);
}