#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValidParenthesis(string s) {
    stack<char> a;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            a.push(ch);
        } else {
            if (!a.empty()) {
                char top = a.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    a.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    return a.empty();
}

int main() {
    string input1 = "([]{()})";
    string input2 = "([)]";

    cout << "Input 1 is " << (isValidParenthesis(input1) ? "valid" : "invalid") << endl;
    cout << "Input 2 is " << (isValidParenthesis(input2) ? "valid" : "invalid") << endl;

    return 0;
}
