//main.cpp

//Program guesses Wordle answers
//Average guesses per game: ~3.62 in 43 games

#include "defs.h"

#include <iostream>

using namespace std;

int WinMain() {
    string file = "TextFiles/test";
    GiveWordValues(file);
    SortWords(file);
    RemoveNums(file);


    //InputOutput("TextFiles/nytValues.txt");

    return 0;
}