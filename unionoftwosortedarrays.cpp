#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> unionOfArrays(vector<int>& arr1, vector<int>& arr2) {
    set<int> unionSet(arr1.begin(), arr1.end());
    unionSet.insert(arr2.begin(), arr2.end());
    
    return vector<int>(unionSet.begin(), unionSet.end());
}

int main() {
    vector<int> arr1 = {1, 2, 4, 5, 6};
    vector<int> arr2 = {2, 3, 5, 7};
    
    vector<int> result = unionOfArrays(arr1, arr2);
    
    cout << "Union of two arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}