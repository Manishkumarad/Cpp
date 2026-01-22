#include <iostream>
using namespace std;
#include <climits>


int  secondSmallest(int arr[], int n){
    int smallest  = arr[0];
    int ssmallest = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < ssmallest && arr[i] != smallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int largetstElement(int arr[], int n){
    int largest = arr[0];
    int secondLargest = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
        if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    return largest;
}
int main() {
    int arr[] = {3, 5, 7, 2, 8, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ssmallest = secondSmallest(arr, n);
    cout << "The second smallest element is: " << ssmallest << endl;
    int largest = largetstElement(arr, n);
    int secondLargest = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    cout << "The largest element is: " << largest << endl;
    cout << "The second largest element is: " << secondLargest << endl;
    return 0;
}