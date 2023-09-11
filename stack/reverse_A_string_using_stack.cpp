#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string str="shadab";
    stack <char> s;

    for(int i=0;i<str.length();i++)
    {
        char ans=str[i];
        s.push(ans);

    }

    string reversed="";
    while(!s.empty())
    {
        char ch=s.top();
        reversed.push_back(ch);
        s.pop();
    }
    cout<<"reversed string = "<<reversed<<endl;
    return 0;
}