#include <iostream>
#include <vector>

using namespace std;

void solve(const string& digit, string output, int index, vector<string>& ans, const string mapping[]) {
    // Base case
    if (index >= digit.length()) {
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(digit, output, index + 1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombinations(const string& digits) {
    vector<string> ans;
    if (digits.length() == 0)
        return ans;
    string output;
    int index = 0;
    const string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, ans, mapping);
    return ans;
}

int main() {
    string input;
    cout << "Enter a string of digits: ";
    cin >> input;

    vector<string> result = letterCombinations(input);

    cout << "Letter combinations: ";
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
