#include <bits/stdc++.h>
#include <iostream>
using namespace std;

char check(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    } else {
        return ch - 'A' + 'a';
    }
}

bool valid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        return true;
    } else {
        return false;
    }
}

bool checkPalindrome(string s) {
    int st = 0;
    int e = s.length() - 1;
    while (st <= e) {
        if (valid(s[st])) {
            if (valid(s[e])) {
                if (check(s[st]) != check(s[e])) {
                    return false;
                } else {
                    st++;
                    e--;
                }
            } else {
                e--;
            }
        } else {
            st++;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    if (checkPalindrome(input)) {
        cout << "The input string is a palindrome." << endl;
    } else {
        cout << "The input string is not a palindrome." << endl;
    }
    return 0;
}
