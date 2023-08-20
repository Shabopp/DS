#include <iostream>
using namespace std;

void reverse_words(string &str) {
    int start = 0;

    for (int i = 0; i <= str.length(); i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            int end = i - 1;

            while (start < end) {
                swap(str[start], str[end]);
                start++;
                end--;
            }
            start = i + 1;
        }
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Use getline to get the entire line of input

    reverse_words(input);
    cout << "Reversed string: " << input << endl;

    return 0;
}

/*dry run
"Hello world, how are you?"
The program prompts the user to enter a string. We enter the string "Hello world, how are you?".

Inside the main function, the getline(cin, input) function is used to read the entire line of input, including spaces. So, input now holds the value "Hello world, how are you?".

The program then calls the reverse_words function and passes the input string to it.

Inside the reverse_words function:

start is initialized to 0.
The loop iterates through each character in the string using the index i.
When i is at index 5, the character ' ' is encountered. This indicates the end of the word "Hello".
The loop inside this condition swaps the characters of the word "Hello", resulting in "olleH".
start is updated to i + 1, which becomes 6.
The process continues for each word in the string:

The word "world," is reversed to "dlrow,".
The word "how" remains the same when reversed.
The word "are" remains the same when reversed.
The word "you?" is reversed to "?uoy".
After reversing all the words, the loop exits.

Finally, the reversed string "olleH ,dlrow how era ?uoy" is printed as the output.

*/




