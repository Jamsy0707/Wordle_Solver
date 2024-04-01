# Wordle_Solver
Algo to play wordle (personal project)

To play: 
  1. Compile main.cpp and io.cpp
  2. Open the NYT Wordle or Wordle game of your choice
  3. The program will tell you the best word to guess and expect you to input the results of that guess
  4. Enter 'g' for green letters, 'y' for yellow letters, and 'x' for grey letters.
     Additionaly, 'q' will halt the program and '?' will guess a new word if the current guess was invalid.

Note: Currently, the program uses a list of words given by the NYT but can utilize any sorted list of words.
      To do so, add the sorted word text file to TextFiles and change the name of the file being passed by InputOutput() in main.cpp.
