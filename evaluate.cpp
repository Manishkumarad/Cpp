#include <bits/stdc++.h>
using namespace std;

int evaluate(string expr) {
    stack<int> values;
    stack<string> ops;

    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == ' ' || expr[i] == '(' || expr[i] == ',')
            continue;

        // Number
        if (isdigit(expr[i])) {
            int num = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        }
        // Function name
        else if (isalpha(expr[i])) {
            string fn;
            while (i < expr.size() && isalpha(expr[i])) {
                fn += expr[i];
                i++;
            }
            i--;
            ops.push(fn);
        }
        // Closing bracket → evaluate
        else if (expr[i] == ')') {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            string fn = ops.top(); ops.pop();

            if (fn == "add") values.push(a + b);
            else if (fn == "sub") values.push(a - b);
            else if (fn == "mul") values.push(a * b);
            else values.push(a / b); // div
        }
    }

    return values.top();
}
int main() {
    string expr = "add(2, mul(3, 4))";
    cout << "Result: " << evaluate(expr) << endl; // Output: 7
    return 0;
}