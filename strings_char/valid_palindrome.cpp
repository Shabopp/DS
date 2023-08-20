#include<iostream>
using namespace std;
// to check valid character 
int valid(char ch)
{

    if((ch>='a' && ch<='z')|| (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
    {
        return 1;
    }
    return 0;

}
//to covert the code to lower case
char lowercase(char ch)
{
    if(ch>='a' && ch<='z' ||ch>='0' && ch<='9' )

    {
        return ch;

    }
    else
    {
        char temp=ch-'A'+'a';
        return temp;
    
    }
}
//check whether the given string is palindrome or not
bool checkpalindrome(string a)
{
    int s=0;
    int e=a.size()-1;
    while(s<=e){
    if(a[s]!=a[e])
    {
        return 0;

    }
    else{
        s++;
        e--;

    }
  
}
  return 1;
}
//to store the elemnt which are valid and convert in lower case
bool new_st(string s)
{
    string temp="";
    // valid element stored in temp string
    for (int i=0;i<s.size();i++)
    {
        if(valid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }
    //converting each and every element in lowercase
    for(int i=0;i<temp.size();i++)
    {
        temp[i]=lowercase(temp[i]);
    }
    // check palindrome
    return checkpalindrome(temp);

}
int main()
{
    string s;
    cout<<"enter to check palindrome "<<endl;
    cin>>s;
   bool isPalindrome = new_st(s);
    if (isPalindrome)
        cout << "It's a palindrome." << endl;
    else
        cout << "It's not a palindrome." << endl;
    return 0;
}