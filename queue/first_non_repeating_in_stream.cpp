#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

string firstnonrepeating(string a)
{
    unordered_map<char, int> count;
    string ans = "";
    queue<char> q;
    for(int i = 0; i < a.length(); i++)
    {
        char ch = a[i];
        count[ch]++;
        q.push(ch);
        while(!q.empty())
        {
            if(count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = firstnonrepeating(input);

    cout << "First non-repeating characters are: " << result << endl;

    return 0;
}
