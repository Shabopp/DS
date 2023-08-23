#include <iostream>
using namespace std;
int fib(int n){
    if(n == 0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int ans = fib(n-1) + fib(n-2) ;
    return ans;
}
int main(){

    int n;
    cin>>n;
   cout << fib(n);


    return 0;
}
/*
Initial Call: fib(5)

n is initially 5.
It checks the base cases:
n is not equal to 0, so it doesn't return 0.
n is not equal to 1, so it doesn't return 1.
It calculates the result as fib(4) + fib(3).
Recursive Call 1: fib(4)

n is now 4.
It checks the base cases:
n is not equal to 0, so it doesn't return 0.
n is not equal to 1, so it doesn't return 1.
It calculates the result as fib(3) + fib(2).
Recursive Call 2: fib(3)

n is now 3.
It checks the base cases:
n is not equal to 0, so it doesn't return 0.
n is not equal to 1, so it doesn't return 1.
It calculates the result as fib(2) + fib(1).
Recursive Call 3: fib(2)

n is now 2.
It checks the base cases:
n is not equal to 0, so it doesn't return 0.
n is not equal to 1, so it doesn't return 1.
It calculates the result as fib(1) + fib(0).
Recursive Call 4: fib(1)

n is now 1.
It hits the base case: n is equal to 1, so it returns 1.
Now, as we unwind the recursive calls:

Recursive Call 3 (fib(2)) returns fib(1) + fib(0) = 1 + 0 = 1.
Recursive Call 2 (fib(3)) returns fib(2) + fib(1) = 1 + 1 = 2.
Recursive Call 1 (fib(4)) returns fib(3) + fib(2) = 2 + 1 = 3.
Finally, the Initial Call (fib(5)) returns fib(4) + fib(3) = 3 + 2 = 5.

So, when you input the number 5, the program calculates and outputs the 5th Fibonacci number, which is 5.
*/