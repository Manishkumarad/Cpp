#include<iostream>
using namespace std;

// void selectionSort(int arr[], int n){
//     for(int i = 0; i < n-1; i++){
//         int min = i;
//         for(int j = i+ 1; j < n;  j++){
//             if(arr[j] < arr[min]){
//                 min = j;
//             } 
//         }
//             int temp = arr[i];
//             arr[i] = arr[min]; 
//             arr[min] = temp;
//     }
// }

 
// void bubbleSort(int arr[], int n){
//     for(int i = n-1; i >= 1; i--){
//         int didSwap = 0;
//         for(int j = 0; j <= i-1; j++){
//           if(arr[j] > arr[j+1]){
//             int temp = arr[j];
//             arr[j] = arr[j+1];
//             arr[j+1] = temp;
//             didSwap = 1;
//            }
//         }
//         if(didSwap == 0){
//             break;
//         }
//         cout<<"runs"<<endl;
//     }
// }

// void insertionSort(int arr[], int n){
//     for(int i = 0; i < n-1; i++){
//         int j = i;
//         while(j > 0 && arr[j-1] > arr[j]){
//             int temp = arr[j];
//             arr[j] = arr[j-1];
//             arr[j-1] = temp;
//             j--;
//        }
//     }
// }

int main(){
    int arr[] = {20, 12, 34, 51, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    cout << "Sorted array: \n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}