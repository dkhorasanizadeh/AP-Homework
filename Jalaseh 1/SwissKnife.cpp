/*
--------------------------------------------------
Name    : Swiss Knife
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 22/Feb/2021
--------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> changeInputToString(int argc, char **argv);
void checkPalindrome(string text);
void helpMenu(void);
void findSubstring(string motherString, string substring);
void reversString(string text);
void stringConcatenate(vector<string> words);
void sortStrings(vector<string> words);
int main(int argc, char **argv)
{
    vector<string> arguments = changeInputToString(argc, argv);
    if (argc == 1 || arguments[0] == "--help" || arguments[0] == "-h")
    {
        helpMenu();
    }
    else if (arguments[0] == "--palindrome" || arguments[0] == "-p")
    {
        for (int i = 1; i < arguments.size(); i++)
        {
            checkPalindrome(arguments[i]);
        }
    }
    else if (arguments[0] == "--find" || arguments[0] == "-f")
    {
        findSubstring(arguments[1], arguments[2]);
    }
    else if (arguments[0] == "--reverse" || arguments[0] == "-r")
    {
        for (int i = 1; i < arguments.size(); i++)
        {
            reversString(arguments[i]);
        }
    }
    else if (arguments[0] == "--concatenate" || arguments[0] == "-c")
    {
        stringConcatenate(vector<string>(arguments.begin() + 1, arguments.end()));
    }
    else if (arguments[0] == "--sort" || arguments[0] == "-s")
    {
        sortStrings(vector<string>(arguments.begin() + 1, arguments.end()));
    }
    return 0;
}
vector<string> changeInputToString(int argc, char **argv)
{
    vector<string> arguments;
    for (int i = 1; i < argc; i++)
    {
        arguments.push_back(string(argv[i]));
    }
    return arguments;
}
void checkPalindrome(string text)
{
    int leftChar = 0;
    int rightChar = text.length() - 1;
    while (rightChar > 1)
    {
        if (text[leftChar++] != text[rightChar--])
        {
            cout << "\"" << text << "\" is not palindrome." << endl;
            return;
        }
    }
    cout << "\"" << text << "\" is palindrome." << endl;
}
void helpMenu(void)
{
    cout << "-h, --help        prints all commands in terminal." << endl
         << "-p, --palindrome    checks if input string is palindrome." << endl
         << "-c, --concatenate    concatenates all the input strings." << endl
         << "-s, --sort        sorts all of the input strings in alphabetic order." << endl
         << "-f, --find        find a substring in a string." << endl
         << "-r, --reverse        reverse all the input strings.";
}
void findSubstring(string motherString, string substring)
{
    if (motherString.find(substring) != string::npos)
    {
        cout << "\"" << substring << "\" was found in \"" << motherString << "\"" << endl;
    }
    else
    {
        cout << "\"" << substring << "\" was not found in \"" << motherString << "\"" << endl;
    }
}
void reversString(string text)
{
    reverse(text.begin(), text.end());
    cout << "\"" << text << "\"" << endl;
}
void stringConcatenate(vector<string> words)
{
    string finalString;
    for (int i = 0; i < words.size(); i++)
    {
        finalString.append(words[i]);
    }
    cout << finalString << endl;
}
void sortStrings(vector<string> words)
{
    sort(words.begin(), words.end());
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
}
