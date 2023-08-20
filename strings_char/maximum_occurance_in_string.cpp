#include<iostream>
using namespace std;

char getmax(string s) {
    int num[26] = {}; 
    for(int i = 0; i < s.length(); i++) {   
        int ch = s[i] - 'a';
        num[ch]++;
    }
    
    int max = 0;
    int ans = -1;
    for(int i = 0; i < 26; i++) {   
        if(num[i] > max) {
            max = num[i];
            ans = i;
        }
    }
    
    char result = ans + 'a';
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    char maxChar = getmax(input);
    cout << "The most frequent character is: " << maxChar << endl;
    
    return 0;
}
/*
"hellothere"
The program prompts the user to enter a string. We input "hellothere".

Inside the main function, the cin >> input statement reads the input string.

The program then calls the getmax function and passes the input string "hellothere" to it.

Inside the getmax function:

An array num of size 26 (representing the English alphabet) is initialized to all zeros.
The loop iterates through each character in the input string.
For each character, it calculates the corresponding index in the num array using 'a' as the base. So, 'h' - 'a' gives the index 7.
The count for the character 'h' is incremented in the num array.
The same is done for all characters in the input string.
After counting the occurrences of each character, the program proceeds to find the most frequent character.

It initializes max to 0 and ans to -1.
It loops through each index in the num array.
If the count at index i is greater than max, it updates max to that count and ans to i.
For the input string "hellothere", the character 'h' has the highest count of 2.
After finding the most frequent character 'h', it calculates the character to be returned as the result.

'h' - 'a' gives 7, which is then converted back to a character by adding 'a'. So, the result is 'h'.
The most frequent character 'h' is printed as the output.

So, the program calculates and prints the most frequent character in the input string "hellothere", which is 'h'.
*/