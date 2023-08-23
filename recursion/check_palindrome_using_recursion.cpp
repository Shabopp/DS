#include<iostream>
using namespace std;

char lowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkpalindrome(string name, int s, int e)
{
    if (s >= e)
    {
        return true;
    }

    if (lowercase(name[s]) != lowercase(name[e]))
    {
        return false;
    }
    else
    {
        return checkpalindrome(name, s + 1, e - 1); // Return the result of the recursive call.
    }
}

int main()
{
    string name = "malayalam";
    int len = name.length();
    cout << "Name is palindrome or not: " << (checkpalindrome(name, 0, len - 1) ? "Yes" : "No") << endl;
    return 0;
}
/*

Let's dry run your code with the input string "malayalam" to see how it checks if it's a palindrome (ignoring case):

The input string is "malayalam".

In the main function, you call checkpalindrome(name, 0, len - 1) with name = "malayalam" and len = 9.

In the checkpalindrome function:

s = 0, e = 8 (the indices of the first and last characters).

You compare lowercase(name[0]) (which is 'm') with lowercase(name[8]) (which is 'm'), and they are equal.

You make a recursive call to checkpalindrome(name, 1, 7).

In the new call:

s = 1, e = 7.

You compare lowercase(name[1]) (which is 'a') with lowercase(name[7]) (which is 'a'), and they are equal.

You make another recursive call to checkpalindrome(name, 2, 6).

In the new call:

s = 2, e = 6.

You compare lowercase(name[2]) (which is 'l') with lowercase(name[6]) (which is 'l'), and they are equal.

You make another recursive call to checkpalindrome(name, 3, 5).

In the new call:

s = 3, e = 5.

You compare lowercase(name[3]) (which is 'a') with lowercase(name[5]) (which is 'a'), and they are equal.

At this point, s is equal to e, which means you've checked all the characters, so the function returns true.

Control returns to the previous call with s = 3 and e = 5. Since the innermost call returned true, the current call also returns true.

Control returns to the call with s = 2 and e = 6. Since the inner call also returned true, this call returns true as well.

Control returns to the call with s = 1 and e = 7. Again, since the inner call returned true, this call returns true.

Finally, control returns to the initial call in the main function with s = 0 and e = 8. Since all the inner calls returned true, the whole expression (checkpalindrome(name, 0, len - 1) ? "Yes" : "No") evaluates to "Yes".

So, the code correctly determines that "malayalam" is a palindrome (ignoring case) and outputs "Yes".
*/




