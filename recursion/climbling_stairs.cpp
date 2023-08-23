#include <iostream>

// Function to count the distinct ways to climb stairs
int countDistinctWayToClimbStair(long long nStairs)
{
    // Base cases
    if (nStairs < 0)
        return 0;
    
    if (nStairs == 0)
        return 1;
    
    // Recursive case
    int ans = countDistinctWayToClimbStair(nStairs - 1) +
              countDistinctWayToClimbStair(nStairs - 2);
    
    return ans;
}

int main()
{
    long long nStairs;
    
    // Input the number of stairs
    std::cout << "Enter the number of stairs: ";
    std::cin >> nStairs;
    
    // Calculate and display the result
    int ways = countDistinctWayToClimbStair(nStairs);
    std::cout << "Number of distinct ways to climb " << nStairs << " stairs: " << ways << std::endl;
    
    return 0;
}

/*
dry run
countDistinctWayToClimbStair(4)
Here's how the function works step by step:

countDistinctWayToClimbStair(4) is called.

Inside the function:

First, it checks the base cases:
nStairs (which is 4 in this case) is not less than 0, so the first base case doesn't apply.
nStairs is not equal to 0, so the second base case doesn't apply either.
Now, it calculates the result recursively:

countDistinctWayToClimbStair(4 - 1) becomes countDistinctWayToClimbStair(3).
countDistinctWayToClimbStair(4 - 2) becomes countDistinctWayToClimbStair(2).
Continuing with the recursive calls:

countDistinctWayToClimbStair(3) is called.

Inside countDistinctWayToClimbStair(3):
It again checks the base cases:
nStairs (which is 3) is not less than 0, so the first base case doesn't apply.
nStairs is not equal to 0, so the second base case doesn't apply.
It calculates the result recursively:
countDistinctWayToClimbStair(3 - 1) becomes countDistinctWayToClimbStair(2).
countDistinctWayToClimbStair(3 - 2) becomes countDistinctWayToClimbStair(1).
countDistinctWayToClimbStair(2) is also called.

Inside countDistinctWayToClimbStair(2):
Base cases are checked:
nStairs (which is 2) is not less than 0.
nStairs is not equal to 0.
It calculates the result recursively:
countDistinctWayToClimbStair(2 - 1) becomes countDistinctWayToClimbStair(1).
countDistinctWayToClimbStair(2 - 2) becomes countDistinctWayToClimbStair(0).
The recursion continues with countDistinctWayToClimbStair(1) and countDistinctWayToClimbStair(0) in a similar manner.

Eventually, you reach the base cases:

countDistinctWayToClimbStair(0) returns 1 because it's a base case.
countDistinctWayToClimbStair(1) also returns 1.
countDistinctWayToClimbStair(2) returns 2 because it's calculated as countDistinctWayToClimbStair(1) + countDistinctWayToClimbStair(0).
Now, you can compute the higher-level recursive calls:

countDistinctWayToClimbStair(3) is calculated as countDistinctWayToClimbStair(2) + countDistinctWayToClimbStair(1), which is 2 + 1 = 3.
Finally, countDistinctWayToClimbStair(4) is calculated as countDistinctWayToClimbStair(3) + countDistinctWayToClimbStair(2), which is 3 + 2 = 5.
So, there are 5 distinct ways to climb 4 stairs using the given function.
*/