//
// Main.cpp
// WordGuess
//
// Created by Wahid Tanner on 11/28/15
//

#include <iostream>
#include <string>
#include <vector>
#include <random>

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
    vector<string> wordCollection;
    wordCollection.push_back("tree");
    wordCollection.push_back("cat");
    wordCollection.push_back("cow");
    
    
    mt19937 rng; //random number generator
    rng.seed(random_device()());
     // distribution in range [0, the number of items in the collection minus 1]
    uniform_int_distribution<mt19937::result_type> distribution(0, wordCollection.size() - 1);
    string wordToGuess = wordCollection[distribution (rng)];
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
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<mt19937::result_type> distribution(0, word.size() - 1);
    for (int index = 0; index < word.size(); index++)
    {
        int firstIndex = distribution(rng);
        int secondIndex = distribution(rng);
        char temp = word[firstIndex];
        word[firstIndex] = word[secondIndex];
        word[secondIndex] = temp;
    }
    return word;
}