#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = n-1; i >= 1; i--){
        int didSwap = 0;
        for(int j = 0; j <= i-1; j++){
          if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            didSwap = 1;
          }
        }
        if(didSwap == 0){
            break;
        }
        cout<<"runs"<<endl;
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
};
