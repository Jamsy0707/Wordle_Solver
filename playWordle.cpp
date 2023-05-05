//Program plays Wordle
//Avg: 3.45 in 20 games

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void editList(char, char, int, string);
bool isEmpty(fstream&);

//Driver function
int main()
{
    ifstream readFile;                          //Open file in read mode
    fstream writeFile;                          //Open file in write or read mode
    string word, result,                        //Word holds current word from list, result holds user entered result of guess
        filename = "nytValues.txt",             //List of words to guess
        filename2 = "tempList.txt";             //Holds copy of original list
    
    readFile.open(filename.c_str());            //Open original list 
    writeFile.open(filename2.c_str());          //Open temp work list
    while (readFile >> word)            
        writeFile << word << endl;              //Copy original list to temp list
    readFile.close();

    cout << "\nInput 5 characters without spaces: 'g' for green, 'y' for yellow, 'x' for grey, '?' if the word isn't valid, or 'q' to quit.\n\n";

    writeFile.close();
    writeFile.open(filename2.c_str());          //This is to reset the file to the begining

    while (writeFile >> word)                   //Read one word from the file at a time
    {
        cout << "Guess: " << word << endl << "Input: ";
        cin >> result;

        while (result.size() != 5 && result != "q" && result != "?")    //Loop until user enters exactly 5 characters for results
        {
            cout << "\nInput must be exactly 5 characters.\nInput: ";
            cin >> result;
        }

        if (result == "q")                      //Quit program if user enters 'q'
        {
            break;
        } 
        else if (result == "ggggg")
        {
            cout << "Success!\n";
            break;
        }
        else if (result == "?")
        {
            cout << endl;
            continue;
        }

        cout << endl;

        switch (result[0])
        {
            case 'g': editList(word[0], 'g', 0, filename2); break;
            case 'y': editList(word[0], 'y', 0, filename2); break;
            case 'x': editList(word[0], 'x', 0, filename2); break;
            default: cout << "Input for character 1 is not valid.\n";
        }

        switch (result[1])
        {
            case 'g': editList(word[1], 'g', 1, filename2); break;
            case 'y': editList(word[1], 'y', 1, filename2); break;
            case 'x': editList(word[1], 'x', 1, filename2); break;
            default: cout << "Input for character 2 is not valid.\n";
        }

        switch (result[2])
        {
            case 'g': editList(word[2], 'g', 2, filename2); break;
            case 'y': editList(word[2], 'y', 2, filename2); break;
            case 'x': editList(word[2], 'x', 2, filename2); break;
            default: cout << "Input for character 3 is not valid.\n";
        }

        switch (result[3])
        {
            case 'g': editList(word[3], 'g', 3, filename2); break;
            case 'y': editList(word[3], 'y', 3, filename2); break;
            case 'x': editList(word[3], 'x', 3, filename2); break;
            default: cout << "Input for character 4 is not valid.\n";
        }

        switch (result[4])
        {
            case 'g': editList(word[4], 'g', 4, filename2); break;
            case 'y': editList(word[4], 'y', 4, filename2); break;
            case 'x': editList(word[4], 'x', 4, filename2); break;
            default: cout << "Input for character 5 is not valid.\n";
        }

        writeFile.close();
        writeFile.open(filename2.c_str());      //This is to reset the file to the begining
    }

    if (isEmpty(writeFile))                    //Error case for if the correct answer is not in the word list
        cout << "ERROR - no valid word found.\n";

    writeFile.close();
    cout << endl;

    return 0;
}

//Function edits the list of words based on feedback from the last word
void editList(char letter, char comp, int pos, string file)
{
    string word;
    ifstream readFile;                          //Open file in read mode
    ofstream writeFile;                         //Open file in write mode
    readFile.open(file.c_str());                //Opening the working edit file
    writeFile.open("temp.txt");                 //Opening a new temp file so original list doesn't get messed up

    while(readFile >> word)
    {                                           //If the word has the green letter in the right spot or the yellow letter but not in the previous spot or doesn't contain the gray letter
        if (((comp == 'g') && (word[pos] == letter)) || 
            ((comp == 'y') && ((word[0] == letter) || (word[1] == letter) || (word[2] == letter) || (word[3] == letter) || (word[4] == letter)) && (word[pos] != letter)) ||
            ((comp == 'x') && ((word[0] != letter) && (word[1] != letter) && (word[2] != letter) && (word[3] != letter) && (word[4] != letter)))
           )    
            writeFile << word << endl;          //Write the word to a new temp file
    }

    readFile.clear();                           //Clear eof and fail bits
    readFile.seekg(0, ios::beg);
    readFile.close();                           //Close read and write files
    writeFile.close();
    remove(file.c_str());                       //Remove old read file
    rename("temp.txt",file.c_str());            //Rename temp write file to old read file

    return;
}

bool isEmpty(fstream& pFile)                  //Function returns true if the file is empty
{
    return pFile.peek() == ifstream::traits_type::eof();
}