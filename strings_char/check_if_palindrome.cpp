#include<iostream>
using namespace std;
char lowercase(char ch)
{
  
    if(ch>='a' && ch<='z')
    {
        return ch;
    }
    else{
     char temp=ch-'A'+'a';
     return temp;
     }
   
}
bool checkpalindrome(char name[],int n)
{
    int s=0;
    int e=n-1;
    while(s<=e){
    if(lowercase(name[s])!=lowercase(name[e]))
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
int getlength(char name[])
{
    int count=0;
    for (int i = 0;name[i]!='\0'; i++)
    {
        count++;
    }
   return count; 
}
int main()
{
    char name[20];
    cout<<"Enter a Name"<<endl;
    cin>>name;
    int len=getlength(name);  
cout<<"name is palindrome or not : "<< checkpalindrome(name,len);
return 0;
}