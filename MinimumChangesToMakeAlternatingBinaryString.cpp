#include <iostream>
#include <string>
using namespace std;

//C++ Code
class Solution {
public:
    int minOperations(string s) {
        int change1 = 0; // pattern starting with 0
        int change2 = 0; // pattern starting with 1
        
        for(int i = 0; i < s.size(); i++){
            
            // expected char if start with 0
            if(s[i] != (i % 2 == 0 ? '0' : '1'))
                change1++;
            
            // expected char if start with 1
            if(s[i] != (i % 2 == 0 ? '1' : '0'))
                change2++;
        }
        
        return min(change1, change2);
    }
};
int main() {
    Solution solution;
    string s = "0100";
    
    int result = solution.minOperations(s);
    cout << "Minimum changes to make alternating: " << result << endl; // Output: 1
    
    return 0;
}
/*
1758. Minimum Changes To Make Alternating Binary String

Problem:
You are given a binary string s.
You need to find the minimum number of changes required to make the string alternating.

An alternating string means:

010101... (starts with 0)
or

101010... (starts with 1)

You can change any character (0 → 1 or 1 → 0).

Key Idea (Pattern)

Greedy + Counting

There are only two valid alternating patterns possible for any binary string:

Start with 0 → 010101...

Start with 1 → 101010...

We calculate:

changes needed for pattern1

changes needed for pattern2

Return minimum of both.

Example
Input
s = "0100"
Pattern 1 → "0101"
index : 0 1 2 3
s     : 0 1 0 0
exp   : 0 1 0 1
                 ↑ mismatch
changes = 1
Pattern 2 → "1010"
index : 0 1 2 3
s     : 0 1 0 0
exp   : 1 0 1 0
        ↑ ↑ ↑
changes = 3
Answer
min(1,3) = 1
Dry Run
s = "1111"

Pattern1: 0101

1 vs 0 → change
1 vs 1 → ok
1 vs 0 → change
1 vs 1 → ok

changes = 2

Pattern2: 1010

1 vs 1 → ok
1 vs 0 → change
1 vs 1 → ok
1 vs 0 → change

changes = 2

Answer = 2


Time Complexity
O(n)
Space Complexity
O(1)
DSA Pattern Used

Greedy

String Traversal / Counting

Because we locally check mismatches and choose the minimum global result.

✅ Interview Tip:
Whenever you see alternating pattern problems, always check both starting possibilities.

010101...
101010...*/