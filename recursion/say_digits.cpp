#include<iostream> 
using namespace std;

void sayDigit(int n, string arr[]) {

    //base case
    if(n == 0)
        return ;

    //processing 
    int digit = n % 10;
     n = n / 10;
    

    //recursive call
    sayDigit(n, arr);

    cout << arr[digit] << " ";

}

int main() {

    string arr[10] = {"zero", "one", "two", "three",
                         "four", "five", "six"
                        , "seven", "eight", "nine"};
    int n;
    cin >> n;

    cout << endl << endl << endl ;
    sayDigit(n, arr);
    cout << endl << endl << endl ;


    return 0;
}
/* 
dry run
Initial Call: sayDigit(725, arr)

n is initially 725.
It calculates digit as 725 % 10, which is 5, and then updates n to 725 / 10, which is 72.
It makes a recursive call: sayDigit(72, arr).
Recursive Call 1: sayDigit(72, arr)

n is now 72.
It calculates digit as 72 % 10, which is 2, and then updates n to 72 / 10, which is 7.
It makes another recursive call: sayDigit(7, arr).
Recursive Call 2: sayDigit(7, arr)

n is now 7.
It calculates digit as 7 % 10, which is 7, and then updates n to 7 / 10, which is 0.
The base case is reached because n is now 0, so it returns.
Now, as we unwind the recursive calls:

Recursive Call 2 (sayDigit(7, arr)) prints "seven ".
Recursive Call 1 (sayDigit(72, arr)) prints "two ".
Initial Call (sayDigit(725, arr)) prints "five ".
So, when you input the number 725, the program will output "five two seven" because it processes the digits in reverse order and looks up their string representation in the arr array.
/*




