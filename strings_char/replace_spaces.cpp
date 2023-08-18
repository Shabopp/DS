#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
 string replace_spaces(string &s)
 {
    string temp="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]== ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');

        }
        else{
            temp.push_back(s[i]);
        }
    }
    return temp;

 }

int main()
{
    string s = "my name is khan";  // Added a missing semicolon
    string replaced = replace_spaces(s);  // Store the result of replace_spaces
    cout << "Original string: " << s << endl;
    cout << "String with spaces replaced: " << replaced << endl;
    return 0;
}
