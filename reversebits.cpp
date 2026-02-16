#include <iostream>
#include <vector>
using namespace std;

void toBinary(int n) {
    if (n == 0) {
        cout << "0";
        return;
    }

    vector<int> bits;

    while (n > 0) {
        bits.push_back(n & 1); // extract last bit
        n >>= 1;               // divide by 2
    }

    // print in reverse order
    for (int i = bits.size() - 1; i >= 0; i--) {
        cout << bits[i];
    }
}

int main() {
    int n;
    cin >> n;
    toBinary(n);
}
