#include <iostream>
using namespace std;
int binearySearch(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
};


// using recursion
int binearySearchRecursive(int arr[], int low, int high, int target){
    if(low > high){
        return -1;
    }
    int mid = low + (high - low)/2;
    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] < target){
        return binearySearchRecursive(arr, mid + 1, high, target);
    }
    else{
        return binearySearchRecursive(arr, low, mid - 1, target);
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 1;
    int result = binearySearch(arr, n , target);
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    }
    else{
        cout << "Element not found in the array." << endl;
    }
}