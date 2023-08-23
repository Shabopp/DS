#include <iostream>
using namespace std;

bool checkequal(int a[26], int b[26]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool checkpermutation(string s1, string s2) {
    int count1[26] = {0};
    
    // Count the frequency of each character in s1
    for (int i = 0; i < s1.length(); i++) {
        int index1 = s1[i] - 'a';
        count1[index1]++;
    }
    
    int count2[26] = {0};
    int i = 0;
    int len1 = s1.length();
    
    // Check the first window of characters in s2
    while (i < len1) {
        char newch = s2[i];
        int index2 = newch - 'a';
        count2[index2]++;
        i++;
    }
    
    if (checkequal(count1, count2))
        return true;

    // Check for the remaining string in s2
    while (i < s2.length()) {
        char newch = s2[i];
        int index_new = newch - 'a';
        count2[index_new]++;

        char ch = s2[i - len1];
        int index_old = ch - 'a';
        count2[index_old]--;
        i++;

        if (checkequal(count1, count2))
            return true;
    }

    return false;
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    if (checkpermutation(s1, s2)) {
        cout << "A permutation of the first string is present in the second string." << endl;
    } else {
        cout << "A permutation of the first string is not present in the second string." << endl;
    }

    return 0;
}
/*
Dry Run with s1 = "ab" and s2 = "eidboaoo":

Initialize s1 = "ab" and s2 = "eidboaoo".
Initialize arrays count1 and count2 with 26 zeros each to represent the character counts.

count1 = [0, 0, 0, 0, ..., 0]
count2 = [0, 0, 0, 0, ..., 0]
Loop through s1 to count the frequency of each character in count1:

For the first character 'a':

index1 = 0 (because 'a' - 'a' = 0)
Increment count1[0] by 1, so count1 = [1, 0, 0, 0, ..., 0]
For the second character 'b':

index1 = 1 (because 'b' - 'a' = 1)
Increment count1[1] by 1, so count1 = [1, 1, 0, 0, ..., 0]
Initialize i = 0 and len1 = 2 (length of s1).

Start looping through s2 from i = 0 to i = 1 (first window):

For the character 'e':
index2 = 4 (because 'e' - 'a' = 4)
Increment count2[4] by 1, so count2 = [0, 0, 0, 0, 1, 0, ..., 0]
Check if count1 and count2 are equal (they are not equal), so continue to the next character.

Increment i to 2.

Continue looping through s2:

For the character 'i':
index2 = 8 (because 'i' - 'a' = 8)
Increment count2[8] by 1, so count2 = [0, 0, 0, 0, 1, 0, ..., 1]
Check if count1 and count2 are equal (they are not equal), so continue to the next character.

Increment i to 3.

Continue looping through s2:

For the character 'd':
index2 = 3 (because 'd' - 'a' = 3)
Increment count2[3] by 1, so count2 = [0, 0, 0, 1, 1, 0, ..., 1]
Check if count1 and count2 are equal (they are not equal), so continue to the next character.

Increment i to 4.

Continue looping through s2:

For the character 'b':
index2 = 1 (because 'b' - 'a' = 1)
Increment count2[1] by 1, so count2 = [0, 1, 0, 1, 1, 0, ..., 1]
Check if count1 and count2 are equal (they are not equal), so continue to the next character.

Increment i to 5.

Continue looping through s2:

For the character 'o':
index2 = 14 (because 'o' - 'a' = 14)
Increment count2[14] by 1, so count2 = [0, 1, 0, 1, 1, 0, ..., 2]
Check if count1 and count2 are equal (they are not equal), so continue to the next character.

Increment i to 6.

Continue looping through s2:

For the character 'a':
index2 = 0 (because 'a' - 'a' = 0)
Increment count2[0] by 1, so count2 = [1, 1, 0, 1, 1, 0, ..., 2]
Check if count1 and count2 are equal (they are not equal), so continue to the next character.

Increment i to 7.

Continue looping through s2:

For the character 'o':
index2 = 14 (because 'o' - 'a' = 14)
Increment count2[14] by 1, so count2 = [1, 1, 0, 1, 1, 0, ..., 3]
Check if count1 and count2 are equal (they are not equal), so continue to the next character.

Increment i to 8.

The first window of characters in s2 has been checked, and it does not contain a permutation of s1.

Start sliding the window:

For the character 'e':
index_new = 4 (because 'e' - 'a' = 4)
Increment count2[4] by 1, so count2 = [1, 1, 0, 1, 2, 0, ..., 3]
index_old = 0 (because the character at i - len1 = 8 - 2 = 6 is 'a')
Decrement count2[0] by 1, so count2 = [0, 1, 0, 1, 2, 0, ..., 3]
Check if count1 and count2 are equal (they are not equal), so continue sliding the window.

Continue sliding the window through s2, but it still does not contain a permutation of s1.

The entire string s2 has been checked, and no permutation of s1 is found.

Return false because no permutation of s1 is present in s2.

Final Output:

A permutation of the first string is not present in the second string.

In this dry run, we've gone through the code step by step to check if a permutation of s1 is present in s2. In this particular case, there was no permutation found.
*/