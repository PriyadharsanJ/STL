#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a string is a palindrome
int isPalindrome(string str)
{
    int n = str.length();

    for (int i=0; i<n/2; i++)
    {
        if (str[i] != str[n-i-1])
        {
            return 0;
        }
    }
    return 1;
}

// This Function iterates through all substrings to find the longest substring
string LongestPalindrome(string input)
{
    string LongestPalindrome;

    for (int i = 0; i < input.length(); i++)
    {
        for (int j = i + 1; j <= input.length(); j++)
        {
            string sub = input.substr(i, j - i);
            LongestPalindrome = isPalindrome(sub) && sub.length() > LongestPalindrome.length() ? sub : LongestPalindrome;
        }
    }
    return LongestPalindrome;
}

int main()
{
    string str;
    cout << "Enter a string : ";
    getline(cin, str);
    string result = LongestPalindrome(str);
    if (result.length() > 1)
    {
        cout << result << endl;
    }
    else
    {
        cout << "There are no palindromes in the string!";
    }
    return 0;
}

