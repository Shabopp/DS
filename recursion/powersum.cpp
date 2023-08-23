#include<iostream> 
using namespace std;

int power(int n) {

    //base case 
    if(n == 0)
        return 1;

    //recursive relation
    return 2 * power(n-1);    
}

int main() {

    int n;
    cin >> n;

    int ans = power(n);

    cout << ans << endl;

    return 0;
}
/*
dry run

Initial Call: power(4)

n is initially 4.
It checks the base case: n is not equal to 0, so it proceeds to the recursive relation.
It calculates the result as 2 * power(4 - 1).
Recursive Call 1: power(3)

n is now 3.
It checks the base case: n is not equal to 0, so it proceeds to the recursive relation.
It calculates the result as 2 * power(3 - 1).
Recursive Call 2: power(2)

n is now 2.
It checks the base case: n is not equal to 0, so it proceeds to the recursive relation.
It calculates the result as 2 * power(2 - 1).
Recursive Call 3: power(1)

n is now 1.
It checks the base case: n is not equal to 0, so it proceeds to the recursive relation.
It calculates the result as 2 * power(1 - 1).
Recursive Call 4: power(0)

n is now 0.
It hits the base case: n is equal to 0, so it returns 1.
Now, as we unwind the recursive calls:

Recursive Call 4 (power(0)) returns 1.
Recursive Call 3 (power(1)) returns 2 * 1 = 2.
Recursive Call 2 (power(2)) returns 2 * 2 = 4.
Recursive Call 1 (power(3)) returns 2 * 4 = 8.
Initial Call (power(4)) returns 2 * 8 = 16.
So, when you input the number 4, the program calculates and outputs 2^4, which is 16.
*/