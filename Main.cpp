//
// Main.cpp
// WordGuess
//
// Created by Wahid Tanner on 11/28/15
//

#include <iostream>
#include <string>

using namespace std; 

void playGame ();
string scrambleWord (string word);

int main()
{
    cout << "Would you like to play WordGuess? y/n: ";
    
    char input;
    
    while (true)
    {
        cin >> input;
        
        if (input == 'y')
        {
            playGame();
            break;
        }
        else if (input == 'n')
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Please enter y or n: ";
        }
    }
    return 0;
}

// void playGame ()
//     {
//         cout << "Guess this word: " << "tree" << endl;
//         string input;
//         cin >> input;
//         if (input == "tree")
//         {
//             cout << "You won!" << endl;
//         }
//         else
//         {
//             cout << "Sorry, the word was: " << "tree" << endl;
//         }
        
//     }

void playGame ()
{
    string wordToGuess = "tree";
    string wordAfterScramble = scrambleWord(wordToGuess);
    cout << "Guess this word: " << wordAfterScramble << endl;
    string input;
    cin >> input;
    if (input == wordToGuess)
    {
        cout << "You won!" << endl;
    }
    else
    {
        cout << "Sorry, the word was: " << wordToGuess << endl;
    }
}

string scrambleWord (string word)
{
    return word;
}