#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    string temp = "";
    int i = 0;
    
    while (i < s.length()) {
        if (temp.empty() || temp.back() != s[i]) {
            temp.push_back(s[i]);
        } else {
            temp.pop_back();
        }
        i++;
    }        
    return temp;
}

int main() {
    string input = "abbaca";
    string result = removeDuplicates(input);
    cout << "Result: " << result << endl;
    return 0;
}


/*
Now let's go through the dry run step by step:

Initialize temp as an empty string, i as 0.
i = 0: Check if temp is empty. It is, so push 'a' into temp.
temp: "a"

i = 1: Check if 'b' is equal to the last character in temp ('a'). They are not equal, so push 'b' into temp.
temp: "ab"
i = 2: Check if 'b' is equal to the last character in temp ('b'). They are equal, so pop the last character from temp.
temp: "a"
i = 3: Check if 'a' is equal to the last character in temp ('a'). They are equal, so pop the last character from temp.
temp: ""
i = 4: Check if temp is empty. It is, so push 'c' into temp.
temp: "c"
i = 5: Check if 'a' is equal to the last character in temp ('c'). They are not equal, so push 'a' into temp.
temp: "ca"
The result after the loop is the final content of temp, which is "ca".

So, the function will return "ca" for the input string "abbaca". */
