//Program removes numbers from text file list

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int ALPHABETSIZE = 26;

int main()
{
    ifstream readFile;                          //Open file in read mode
    ofstream writeFile;                         //Open file in write mode
    string word, filename = "nytValues.txt", 
        filename2 = "noNums.txt";
    int wordValue = 0;                          //Represents value of imported word

    readFile.open(filename.c_str());            //Opening the read file
    writeFile.open(filename2.c_str());          //Opening the write file
    while (readFile >> word)                    //Read one word from the file at a time
    {
        if (word[0] >= 'a' && word[0] <= 'z')
            writeFile << word << endl;
    }

    readFile.close();
    writeFile.close();

    return 0;
}