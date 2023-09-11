#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else {
            // ch is either ')' or a lowercase letter
            if (ch == ')') {
                bool isRedundant = true;

                while (st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}

int main() {
    string expression1 = "((a+b))";
    string expression2 = "(a+(b+c))";
    string expression3 = "(a+b)";

    cout << "Expression 1 is " << (findRedundantBrackets(expression1) ? "redundant" : "not redundant") << endl;
    cout << "Expression 2 is " << (findRedundantBrackets(expression2) ? "redundant" : "not redundant") << endl;
    cout << "Expression 3 is " << (findRedundantBrackets(expression3) ? "redundant" : "not redundant") << endl;

    return 0;
}
