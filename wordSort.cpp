//wordSort.cpp
//Program assigns values to words based on NYT letter commonality

#include "defs.h"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>
#include <functional>
#include <iterator>
#include <set>
#include <string>

using namespace std;


//Given a list of words, find and print their values
void GiveWordValues(const string file) {
    ifstream readFile(file+".txt");          //Open unsorted word file in read mode
    ofstream {file+"Sorted.txt"};
    ofstream writeFile(file+"Sorted.txt");   //Open new file in write mode to store words with values
    string word;
    int wordValue = 0;                       //Represents value of imported word

    while (readFile >> word) {               //Read one word from the file at a time
        wordValue = 0;                       //Reset wordValue for the next word
        for (int i = 0; i < LENGTH; ++i) {
            ASSERT(0 <= word[i]-'a' <= 26);  //Assert that word[i]-'a' is a lowercase letter
            wordValue += VALUES[i][word[i]-'a'];
        }
        writeFile << wordValue << " " << word << endl;  //Prints the word's value followed by the word. Ex. 956 saree
    }

    readFile.close();
    writeFile.close();
}


//Removes the numbers given to words by WordSort()
void RemoveNums(const string file) {
    ifstream readFile(file+"Sorted.txt");
    string word;
    int i = 0;

    vector<string> words;
    while (readFile >> word) {  //Read one word from the file at a time
        if (i % 2)              //The file follows the format num, space, word so every second element should be saved
            words.push_back(word);
        ++i;
    }

    readFile.close();
    ofstream writeFile(file+"Sorted.txt");

    for (string s : words)
        writeFile << s << endl;
    writeFile.close();
}


struct words {
    int num;
    string word;
};

bool compareByNum(const words& a, const words& b) {
    return a.num > b.num;
}

//Sort the list of words given their values
void SortWords(const string file) {
    ifstream readFile(file+"Sorted.txt");
    vector<words> list;
    int a;
    string b;

    while (readFile >> a >> b)  //Push words and associated values from the text file to an array of structs holding the number and word seperately
        list.push_back({a,b});
    readFile.close();

    sort(list.begin(), list.end(), compareByNum);  //Use the pre-defined overloaded < function to sort the list using the values of the words

    ofstream {"temp.txt"};
    ofstream writeFile("temp.txt");//file+"Sorted.txt");  //Push the sorted list back to the text file
    for (const auto& l : list) {
        cout << l.word << endl;
        writeFile << l.word << endl;
    }
    writeFile.close();
}
