/*
--------------------------------------------------
Name    : Number Guesser
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 25/Feb/2021
--------------------------------------------------
*/
/*
Create a program called number guesser.
There will be a secret number that is set at the start of the program without
any user input. The secret number should be picked from a certain range. The
range of the number should be output to the player. The player should be
prompted to enter his guess. The prompt should show how many guesses the player
has left. The player will then enter his guess. If the guess is too high then
the game will output that the guess was too high. If the guess was too low then
the game will output that it was too low. The player only has a certain number
of guesses. The number of guesses should be based on the range of the secret
number. Any wrong guess will decrement the number of guesses left. The game ends
by saying what the secret number was regardless of if the player guessed the
right number. When the game is over, the player should be prompted if he would
like to play again. If yes then the secret number should change. Any input
errors by the player should have proper handling.
 */
#include <cmath>
#include <ctime>
#include <iostream>
#define HIGH 100
using namespace std;
int generateRandomNumber(int);
int getNumberFromUser(int, int);
bool checkGuess(int, int);
int main() {
  int numberOfGuesses = ceil(1.5 * log2(HIGH));
  int number = generateRandomNumber(HIGH);
  int userGuess;
  bool numberFound = false;
  do {
    userGuess = getNumberFromUser(numberOfGuesses, HIGH);
    if (userGuess != 0) {
      numberFound = checkGuess(userGuess, number);
      numberOfGuesses--;
    }
  } while (numberOfGuesses > 0 && !numberFound);
  if (numberFound) {
    cout << "Congratulations, you have found the number." << endl;
  } else {
    cout << "You lost." << endl;
  }
}
int generateRandomNumber(int rangeHigh) {
  srand(time(NULL));
  return rand() % rangeHigh + 1;
}
int getNumberFromUser(int numberOfGuesses, int rangeHigh) {
  cout << "You have " << numberOfGuesses << " guesses left." << endl
       << "Please pick a number between 1 and " << rangeHigh << "." << endl;
  int userGuess;
  cin >> userGuess;
  if (userGuess <= rangeHigh && userGuess >= 1) {
    return userGuess;
  } else {
    cout << "Invalid input." << endl << "Please enter another number." << endl;
    return 0;
  }
}
bool checkGuess(int userGuess, int number) {
  if (userGuess < number) {
    cout << "Your guess is to low." << endl;
    return false;
  } else if (userGuess > number) {
    cout << "Your guess is to high." << endl;
    return false;
  } else {
    return true;
  }
}