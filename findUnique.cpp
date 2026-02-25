#include<iostream>
using namespace std;
#include <vector>

int findUnique(vector<int> & arr){
    int n = arr.size();
    int result = 0;
    for(int i = 0; i < n; i++){
        result ^= arr[i];
    }
    return result;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 1, 2, 3, 4};
    int uniqueElement = findUnique(arr);
    cout << "The unique element in the array is: " << uniqueElement << endl;
    return 0;
}