#include<iostream>
using namespace std;

int sum(int arr[], int size)
{
    // Base case: if the size is 0, return 0 as the sum
    if (size == 0)
    {
        return 0;
    }
    
    // Recursive case:
    // The sum of the first element (arr[0]) and the sum of the rest of the elements (arr+1)
    int remainingPart = arr[0] + sum(arr + 1, size - 1);
    
    return remainingPart;
}

int main()
{
    int arr[5] = {1, 2, 0, 4, 5};
    
    int totalSum = sum(arr, 5); // Call the sum function with the array and its size
    
    cout << "The sum of elements in the array is: " << totalSum << endl;

    return 0;
}
int sum(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    
    int remainingPart = arr[0] + sum(arr + 1, size - 1);
    
    return remainingPart;
}

int main()
{
    int arr[5] = {1, 2, 0, 4, 5};
    
    int totalSum = sum(arr, 5);
    
    cout << "The sum of elements in the array is: " << totalSum << endl;

    return 0;
}

/*
Initial Call: sum(arr, 5)

size is 5, which is not equal to 0, so it proceeds to the recursive call.
It calculates remainingPart as arr[0] + sum(arr + 1, size - 1):
arr[0] is 1.
It makes a recursive call sum(arr + 1, 4).
Recursive Call 1: sum(arr + 1, 4)

size is 4, which is not equal to 0, so it proceeds to the recursive call.
It calculates remainingPart as arr[0] + sum(arr + 1, size - 1):
arr[0] (in this call) is 2.
It makes a recursive call sum(arr + 1, 3).
Recursive Call 2: sum(arr + 1, 3)

size is 3, which is not equal to 0, so it proceeds to the recursive call.
It calculates remainingPart as arr[0] + sum(arr + 1, size - 1):
arr[0] (in this call) is 0.
It makes a recursive call sum(arr + 1, 2).
Recursive Call 3: sum(arr + 1, 2)

size is 2, which is not equal to 0, so it proceeds to the recursive call.
It calculates remainingPart as arr[0] + sum(arr + 1, size - 1):
arr[0] (in this call) is 4.
It makes a recursive call sum(arr + 1, 1).
Recursive Call 4: sum(arr + 1, 1)

size is 1, which is not equal to 0, so it proceeds to the recursive call.
It calculates remainingPart as arr[0] + sum(arr + 1, size - 1):
arr[0] (in this call) is 5.
It makes a recursive call sum(arr + 1, 0).
Recursive Call 5: sum(arr + 1, 0)

size is 0, which matches the base case, so it returns 0.
Now, let's calculate the sums as we unwind the recursive calls:

Recursive Call 5 returns 0.
Recursive Call 4 returns 5 + 0 = 5.
Recursive Call 3 returns 4 + 5 = 9.
Recursive Call 2 returns 0 + 9 = 9.
Recursive Call 1 returns 2 + 9 = 11.
Finally, the initial call returns 1 + 11 = 12, which is the sum of all the elements in the array.

So, the sum of elements in the array {1, 2, 0, 4, 5} is indeed 12, as calculated by the code.
/*