//io.cpp

#include "defs.h"

#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;


/*
    Name:    CheckInputErrors
    Purpose: Check that the result of the guess, as inputted by the user, is correct and fix it if necessary.
    Vars:    word   - The last word guessed.
             result - The result of the previous guess. Ex. yggxx
    Returns: BREAK if the user inputs 'q' or 'ggggg'.
             CONTINUE if the previous guess was an invalid word.
             The corrected result string otherwise.
*/
string CheckInputErrors(const string word, string result) {
    //Loop until user enters exactly LENGTH characters for results
    while (result.size() != LENGTH && result != "q" && result != "?") {
        cout << "\nInput must be exactly " << LENGTH << " characters. \nInput: ";
        cin >> result;
    }

    if (result == "q")       //Quit program if user enters 'q'
        return "BREAK";
    else if (result == "?")  //If the word is not valid in the game, entering '?' continues to the next word
        return "CONTINUE";
    
    //Check that all input letters are correct
    for (int i = 0; i < LENGTH; ++i) {
        while (result[i] != 'g' && result[i] != 'y' && result[i] != 'x') {
            cout << "\nInput for character " << i+1 << " is not valid. \nInput the character again: ";
            cin >> result[i];
        }
    }

    //Break if the input is all 'g's, indicating the previous guess was correct
    if (result[0] == 'g' && all_of(result.cbegin(), result.cend(), [&](char c){ return result[0] == c; })) {
        cout << "\nSuccess!\n";
        return "BREAK";
    }

    //Check for the case when two letters in result are the same but one is green or yellow while the other is grey. 
    //This will cause the problem of filtering words that are still good guesses. 
    //Ex. If "gooey" gives xgxxx, all words with 'o' will be filtered although we see the second letter is an 'o'.
    for (int i = 0; i < LENGTH; ++i)
        for (int j = 0; j < LENGTH; ++j)
            if (i != j && word[i] == word[j] && result[i] != 'x' && result[j] == 'x')  //Same letter, word[i] is yellow or green, word[j] is grey
                result[j] = 'y'; 


    return result;
}


/*
    Name:    EditList
    Purpose: Edits the list of viable guesses based on user feedback from the last word.
    Vars:    letter - The a-z letter from the last guess.
             comp   - The result of using that letter in that spot. Either g, y, or x.
             pos    - The position of the letter.
*/
void EditList(const char letter, const char comp, const int pos) {
    fstream readFile(TL);               //Opening the working edit file
    ofstream {TEMP};                    //Opening a new temp file so original list doesn't get messed up
    fstream writeFile(TEMP);
    string word;

    while(readFile >> word) {           //If the word has the green letter in the right spot or the yellow letter but not in the previous spot or doesn't contain the gray letter
        if (((comp == 'g') && (word[pos] == letter)) || 
            ((comp == 'y') && ((word[0] == letter) || (word[1] == letter) || (word[2] == letter) || (word[3] == letter) || (word[4] == letter)) && (word[pos] != letter)) ||
            ((comp == 'x') && ((word[0] != letter) && (word[1] != letter) && (word[2] != letter) && (word[3] != letter) && (word[4] != letter)))
           )    
            writeFile << word << endl;  //Write the word to a new temp file
    }
    readFile.clear();                   //Clear eof and fail bits
    readFile.seekg(0, ios::beg);
    readFile.close();                   //Close read and write files
    writeFile.close();

    remove(TL);                         //Remove old read file
    rename(TEMP, TL);                   //Rename temp write file to old read file
}


/*
    Name:    InputOutput
    Purpose: Takes an input for the previous result and outputs a guess. The main function of the program.
*/
void InputOutput(const string file) {
    ifstream readFile(file);
    ofstream {TL};
    fstream writeFile(TL);
    string word, result;

    while (readFile >> word) writeFile << word << endl;  //Copy original list to temp working list
    readFile.close();
    writeFile.close();  //Reset the writeFile to the beginning
    writeFile.open(TL);

    cout << "\nWelcome to " << NAME;
    cout << "\nInput " << LENGTH << " characters without spaces: 'g' for green, 'y' for yellow, 'x' for grey, '?' if the word isn't valid, or 'q' to quit.\n";

    //Guess one word from the file at a time and edit the list file based on the results of that guess
    while (writeFile >> word) {
        cout << "\nGuess: " << word << "\nInput: ";
        cin >> result;

        //Check that the input is valid and break/continue from the while loop if necessary
        result = CheckInputErrors(word, result);
        if (result == "BREAK")    break;
        if (result == "CONTINUE") continue;

        writeFile.close();

        //Loop through the user input and edit the word guess list
        for (int i = 0; i < LENGTH; ++i)
            EditList(word[i], result[i], i);

        writeFile.open(TL);  //Reset the writeFile to the beginning
    }

    if (writeFile.peek() == ifstream::traits_type::eof())  //Error case if the correct answer is not in the word list
        cout << "ERROR - no valid word found.\n";

    writeFile.close();
    cout << endl;
}