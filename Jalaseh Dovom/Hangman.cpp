/*
--------------------------------------------------
Name    : Hangman
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 06/Mar/2021
--------------------------------------------------
*/
#ifdef __unix__
#define OS "unix"
#else
#define OS "windows"
#endif
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void clear(void);
void drawHangman(int wrongGuesses);
bool writeWord(string word, vector<char> correctLetters, vector<char> wrongLetters);
bool isLetterInVector(vector<char> letters, char letter);
bool drawBoard(vector<char> &wrongLetters, vector<char> &correctLetters, string word);
string getLower(string s);
void getInput(vector<char> &wrongLetters, vector<char> &correctLetters, string word, bool &lost);
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        string word = string(argv[1]);
        vector<char> wrongLetters;
        vector<char> correctLetters;
        bool complete = false;
        while (!complete)
        {
            complete = drawBoard(wrongLetters, correctLetters, word);
        }
        return 0;
    }
    else
    {
        cout << "Usage: " << argv[0] << " Word";
        return 1;
    }
}
void drawHangman(int wrongGuesses)
{
    switch (wrongGuesses)
    {
    case 0:
        cout << " +--------+" << endl
             << " |        |" << endl
             << " |        |" << endl
             << "          |" << endl
             << "          |" << endl
             << "          |" << endl
             << "          |" << endl
             << "          |" << endl
             << "-----------" << endl
             << "-----------" << endl;
        break;
    case 1:
        cout << " +--------+" << endl
             << " |        |" << endl
             << " |        |" << endl
             << " O        |" << endl
             << "          |" << endl
             << "          |" << endl
             << "          |" << endl
             << "          |" << endl
             << "-----------" << endl
             << "-----------" << endl;
        break;
    case 2:
        cout << " +--------+" << endl
             << " |        |" << endl
             << " |        |" << endl
             << " O        |" << endl
             << " |        |" << endl
             << "          |" << endl
             << "          |" << endl
             << "          |" << endl
             << "-----------" << endl
             << "-----------" << endl;
        break;
    case 3:
        cout << " +--------+" << endl
             << " |        |" << endl
             << " |        |" << endl
             << " O        |" << endl
             << "/|        |" << endl
             << "          |" << endl
             << "          |" << endl
             << "          |" << endl
             << "-----------" << endl
             << "-----------" << endl;
        break;
    case 4:
        cout << " +--------+" << endl
             << " |        |" << endl
             << " |        |" << endl
             << " O        |" << endl
             << "/|\\       |" << endl
             << "          |" << endl
             << "          |" << endl
             << "          |" << endl
             << "-----------" << endl
             << "-----------" << endl;
        break;
    case 5:
        cout << " +--------+" << endl
             << " |        |" << endl
             << " |        |" << endl
             << " O        |" << endl
             << "/|\\       |" << endl
             << "/         |" << endl
             << "          |" << endl
             << "          |" << endl
             << "-----------" << endl
             << "-----------" << endl;
        break;
    case 6:
        cout << " +--------+" << endl
             << " |        |" << endl
             << " |        |" << endl
             << " O        |" << endl
             << "/|\\       |" << endl
             << "/ \\       |" << endl
             << "          |" << endl
             << "          |" << endl
             << "-----------" << endl
             << "-----------" << endl;
        break;
    case -1:
        cout << "You Won!" << endl;
    default:
        break;
    }
}
bool writeWord(string word, vector<char> correctLetters, vector<char> wrongLetters)
{
    bool found = false;
    bool complete = true;
    for (int i = 0; i < word.length(); i++)
    {
        if (find(correctLetters.begin(), correctLetters.end(), tolower(word[i])) != correctLetters.end())
        {
            cout << word[i];
            found = true;
        }
        if (!found)
        {
            cout << "-";
            complete = false;
        }
        found = false;
    }
    if (wrongLetters.size() > 0)
    {
        cout << endl
             << "Wrong guessed letters:";
        for (int i = 0; i < wrongLetters.size() - 1; i++)
        {
            cout << wrongLetters[i] << ", ";
        }
        cout << wrongLetters[wrongLetters.size() - 1];
    }
    cout << endl;
    return complete;
}
bool isLetterInVector(vector<char> letters, char letter)
{
    if (find(letters.begin(), letters.end(), tolower(letter)) != letters.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool drawBoard(vector<char> &wrongLetters, vector<char> &correctLetters, string word)
{
    bool complete = false;
    bool lost = false;
    getInput(wrongLetters, correctLetters, word, lost);
    clear();
    drawHangman(wrongLetters.size());
    complete = writeWord(word, correctLetters, wrongLetters);
    if ((wrongLetters.size() >= 6 and !complete) || lost)
    {
        cout << "You lost." << endl
             << "The secret word was " << word << endl;
        complete = true;
    }
    else if (complete)
    {
        cout << "You won." << endl
             << "The secret word was " << word << endl;
    }
    return complete;
}
string getLower(string s)
{
    string lowerString = s;
    for (int i = 0; i < lowerString.length(); i++)
    {
        lowerString[i] = tolower(lowerString[i]);
    }
    return lowerString;
}
void getInput(vector<char> &wrongLetters, vector<char> &correctLetters, string word, bool &lost)
{
    bool correct = false;
    while (!correct)
    {
        char choice;
        cout << "Do you want to input the whole word?(Y/N)" << endl;
        cin >> choice;
        if (tolower(choice) == 'y')
        {
            cout << "Please enter your guess:" << endl;
            string inputWord;
            cin >> inputWord;
            if (getLower(inputWord) == getLower(word))
            {
                for (int i = 0; i < word.length(); i++)
                {
                    correctLetters.push_back(tolower(word[i]));
                }
            }
            else
            {
                for (int i = 0; i < inputWord.length(); i++)
                {
                    wrongLetters.push_back(tolower(inputWord[i]));
                }
                lost = true;
            }
            correct = true;
        }
        else
        {
            char inputChar;
            cout << "Please enter your guess:" << endl;
            cin >> inputChar;
            inputChar = tolower(inputChar);
            if (!isLetterInVector(correctLetters, inputChar) && !isLetterInVector(wrongLetters, inputChar))
            {
                if (getLower(word).find(inputChar) != string::npos)
                {
                    correctLetters.push_back(inputChar);
                }
                else
                {
                    wrongLetters.push_back(inputChar);
                }
                correct = true;
            }
            else
            {
                cout << "You have entered this letter before." << endl
                     << "Please try again." << endl;
            }
        }
    }
}
void clear(void)
{
    if (OS == "unix")
    {
        system("clear");
    }
    else
    {
        system("cls");
    }
}