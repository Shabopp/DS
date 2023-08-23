#include<iostream>
using namespace std;

void reverse(string& str, int i, int j ) {

    cout << "call recieved for " << str << endl;

    //base case
    if(i>j)
        return ;

    swap(str[i], str[j]);
    i++;
    j--;

    //Recursive call
    reverse(str,i,j);

}

int main() {

    string name = "abcde";
    cout << endl;
    reverse(name, 0 , name.length()-1 );
    cout << endl;
    cout << name << endl;

    return 0;
}
/*
dry run

You define the reverse function to reverse a string.

In the main function, you create a string name with the value "abcde".

You call the reverse function with name, i = 0, and j = name.length() - 1.

Inside the reverse function:

You print the current value of str, which is "abcde".

You check the base case if (i > j), which is false because i is initially 0 and j is initially 4. So, the function continues.

You swap str[i] and str[j], which results in "edcba".

You increment i to 1 and decrement j to 3.

You make a recursive call to reverse with the updated values of i and j.

In the recursive call:

You print the current value of str, which is "edcba".

You check the base case if (i > j), which is false because i is 1 and j is 3. So, the function continues.

You swap str[i] and str[j], which results in "edcba" (no change).

You increment i to 2 and decrement j to 2.

You make another recursive call to reverse with the updated values of i and j.

In the second recursive call:

You print the current value of str, which is "edcba".

You check the base case if (i > j), which is true because i is now 2 and j is 2. Therefore, the function returns without further modification.

Control returns to the first recursive call, where i is 2 and j is 2. Since the base case is satisfied, this call also returns.

Control returns to the initial call in the main function.

Finally, you print the value of name, which is "edcba".

So, the code successfully reverses the string "abcde" to "edcba" using recursion.
*/