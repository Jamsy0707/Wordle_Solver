//defs.h

#include <string>

#ifndef DEFS_H
#define DEFS_H

#define DEBUG
#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed",#n); \
printf("On %s ",__DATE__); \
printf("At %s ",__TIME__); \
printf("In File %s ",__FILE__); \
printf("At Line %d\n",__LINE__); \
exit(1); }
#endif

#define NAME  "Wordle Bot"
#define TL    "TextFiles/tempList.txt"   //Holds a list of viable word guesses that will be reduced as the program runs
#define TEMP  "TextFiles/temp.txt"       //A temporary list used for altering the list of viable guesses
#define ALPHABETSIZE 26
#define LENGTH 5                         //The length of a possible guess. This is usually 5 but can be longer or shorter for alternative games.

const short VALUES[5][26] =
{
    {141, 173, 198, 111, 72, 136, 115, 69, 34, 20, 88, 107, 37, 41, 142, 23, 105, 366, 149, 33, 43, 83, 0, 6, 3},
    {304, 16, 40, 20, 242, 8, 12, 144, 202, 2, 10, 201, 38, 87, 279, 61, 5, 267, 16, 77, 186, 15, 44, 14, 23, 2},
    {307, 57, 56, 75, 177, 25, 67, 9, 266, 3, 12, 112, 61, 139, 244, 58, 1, 163, 80, 111, 165, 49, 26, 12, 29, 11},
    {163, 24, 152, 69, 318, 35, 76, 28, 158, 2, 55, 162, 68, 182, 132, 50, 0, 152, 171, 139, 82, 46, 25, 3, 3, 20},
    {64, 11, 31, 118, 424, 26, 41, 139, 11, 0, 113, 156, 42, 130, 58, 56, 0, 212, 36, 253, 1, 0, 17, 8, 364, 4}
};


//io.cpp
extern std::string CheckInputErrors(const std::string word, std::string result);
extern void        EditList(const char letter, const char comp, const int pos);
extern void        InputOutput(const std::string file);

//wordSort.cpp
extern void GiveWordValues(const std::string file);
extern void RemoveNums(const std::string file);
extern void SortWords(const std::string file);


#endif