//Program assigns values to words based on NYT letter commonality

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int ALPHABETSIZE = 26;

int main()
{
    ifstream readFile;                          //Open file in read mode
    ofstream writeFile;                         //Open file in write mode
    string word, filename = "generalWordle.txt", 
        filename2 = "generalWordleValueList.txt";
    int wordValue = 0;                          //Represents value of imported word

    readFile.open(filename.c_str());            //Opening the read file
    writeFile.open(filename2.c_str());          //Opening the write file
    while (readFile >> word)                    //Read one word from the file at a time
    {
        switch (word[0])                        //Check first letter and increment
        {
            case 'a': wordValue += 141; break;
            case 'b': wordValue += 173; break;
            case 'c': wordValue += 198; break;
            case 'd': wordValue += 111; break;
            case 'e': wordValue += 72; break;
            case 'f': wordValue += 136; break;
            case 'g': wordValue += 115; break;
            case 'h': wordValue += 69; break;
            case 'i': wordValue += 34; break;
            case 'j': wordValue += 20; break;
            case 'k': wordValue += 20; break;
            case 'l': wordValue += 88; break;
            case 'm': wordValue += 107; break;
            case 'n': wordValue += 37; break;
            case 'o': wordValue += 41; break;
            case 'p': wordValue += 142; break;
            case 'q': wordValue += 23; break;
            case 'r': wordValue += 105; break;
            case 's': wordValue += 366; break;
            case 't': wordValue += 149; break;
            case 'u': wordValue += 33; break;
            case 'v': wordValue += 43; break;
            case 'w': wordValue += 83; break;
            case 'x': wordValue += 0; break;
            case 'y': wordValue += 6; break;
            case 'z': wordValue += 3; break;
            default: printf("Error in switch 1.\n");
        }
        
        switch (word[1])
        {
            case 'a': wordValue += 304; break;
            case 'b': wordValue += 16; break;
            case 'c': wordValue += 40; break;
            case 'd': wordValue += 20; break;
            case 'e': wordValue += 242; break;
            case 'f': wordValue += 8; break;
            case 'g': wordValue += 12; break;
            case 'h': wordValue += 144; break;
            case 'i': wordValue += 202; break;
            case 'j': wordValue += 2; break;
            case 'k': wordValue += 10; break;
            case 'l': wordValue += 201; break;
            case 'm': wordValue += 38; break;
            case 'n': wordValue += 87; break;
            case 'o': wordValue += 279; break;
            case 'p': wordValue += 61; break;
            case 'q': wordValue += 5; break;
            case 'r': wordValue += 267; break;
            case 's': wordValue += 16; break;
            case 't': wordValue += 77; break;
            case 'u': wordValue += 186; break;
            case 'v': wordValue += 15; break;
            case 'w': wordValue += 44; break;
            case 'x': wordValue += 14; break;
            case 'y': wordValue += 23; break;
            case 'z': wordValue += 2; break;
            default: printf("Error in switch 2.\n");
        }

        switch (word[2])
        {
            case 'a': wordValue += 307; break;
            case 'b': wordValue += 57; break;
            case 'c': wordValue += 56; break;
            case 'd': wordValue += 75; break;
            case 'e': wordValue += 177; break;
            case 'f': wordValue += 25; break;
            case 'g': wordValue += 67; break;
            case 'h': wordValue += 9; break;
            case 'i': wordValue += 266; break;
            case 'j': wordValue += 3; break;
            case 'k': wordValue += 12; break;
            case 'l': wordValue += 112; break;
            case 'm': wordValue += 61; break;
            case 'n': wordValue += 139; break;
            case 'o': wordValue += 244; break;
            case 'p': wordValue += 58; break;
            case 'q': wordValue += 1; break;
            case 'r': wordValue += 163; break;
            case 's': wordValue += 80; break;
            case 't': wordValue += 111; break;
            case 'u': wordValue += 165; break;
            case 'v': wordValue += 49; break;
            case 'w': wordValue += 26; break;
            case 'x': wordValue += 12; break;
            case 'y': wordValue += 29; break;
            case 'z': wordValue += 11; break;
            default: printf("Error in switch 3.\n");
        }

        switch (word[3])
        {
            case 'a': wordValue += 163; break;
            case 'b': wordValue += 24; break;
            case 'c': wordValue += 152; break;
            case 'd': wordValue += 69; break;
            case 'e': wordValue += 318; break;
            case 'f': wordValue += 35; break;
            case 'g': wordValue += 76; break;
            case 'h': wordValue += 28; break;
            case 'i': wordValue += 158; break;
            case 'j': wordValue += 2; break;
            case 'k': wordValue += 55; break;
            case 'l': wordValue += 162; break;
            case 'm': wordValue += 68; break;
            case 'n': wordValue += 182; break;
            case 'o': wordValue += 132; break;
            case 'p': wordValue += 50; break;
            case 'q': wordValue += 0; break;
            case 'r': wordValue += 152; break;
            case 's': wordValue += 171; break;
            case 't': wordValue += 139; break;
            case 'u': wordValue += 82; break;
            case 'v': wordValue += 46; break;
            case 'w': wordValue += 25; break;
            case 'x': wordValue += 3; break;
            case 'y': wordValue += 3; break;
            case 'z': wordValue += 20; break;
            default: printf("Error in switch 4.\n");
        }

        switch (word[4])
        {
            case 'a': wordValue += 64; break;
            case 'b': wordValue += 11; break;
            case 'c': wordValue += 31; break;
            case 'd': wordValue += 118; break;
            case 'e': wordValue += 424; break;
            case 'f': wordValue += 26; break;
            case 'g': wordValue += 41; break;
            case 'h': wordValue += 139; break;
            case 'i': wordValue += 11; break;
            case 'j': wordValue += 0; break;
            case 'k': wordValue += 113; break;
            case 'l': wordValue += 156; break;
            case 'm': wordValue += 42; break;
            case 'n': wordValue += 130; break;
            case 'o': wordValue += 58; break;
            case 'p': wordValue += 56; break;
            case 'q': wordValue += 0; break;
            case 'r': wordValue += 212; break;
            case 's': wordValue += 36; break;
            case 't': wordValue += 253; break;
            case 'u': wordValue += 1; break;
            case 'v': wordValue += 0; break;
            case 'w': wordValue += 17; break;
            case 'x': wordValue += 8; break;
            case 'y': wordValue += 364; break;
            case 'z': wordValue += 4; break;
            default: printf("Error in switch 5.\n");
        }

        writeFile << wordValue << " " << word << endl;
        wordValue = 0;
    }

    readFile.close();
    writeFile.close();

    return 0;
}