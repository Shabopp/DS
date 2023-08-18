#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string removeOccurrences(string s, string part)
{
    while(s.length()!=0 && s.find(part)<s.length())
    {
        s.erase(s.find(part),part.length());
    }
    return s;
}
void printResult(const string &s, const string &part)
{
    cout << "Original string: " << s << endl;
    cout << "Part to remove: " << part << endl;
    
    string result = removeOccurrences(s, part);
    cout << "After removing occurrences: " << result << endl;
}
int main()
{
    string s="daabcbaabcbc";
    string part="abc";
     printResult(s, part);
     return 0;

}