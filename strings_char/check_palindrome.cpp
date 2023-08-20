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

bool check(string str,int n)
{
    int s=0;
    int e=n-1;
    while(s<e){
    if(tolower(str[s]) != tolower(str[e]))
    {
        return false;
    }
    else{
        s++;
        e--;
    }
    }
    return true;
}
int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    int n=input.length();
    if (check(input,n)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    
    return 0;
}