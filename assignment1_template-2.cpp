/*********
Name: Lance Sunzeri
Date: 10/4/19
This is a memory game. Flip all the matching cards over to win.
*********/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>

const int LENGTH = 4;
int rand();
using namespace std;

// Function prototypes
void InitializeCards(int cards[][LENGTH]);
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH], 
int a1, int b1, int a2, int b2);

// ======================
// InitializeCards
// Recieves arr array
// Will not return anything (void)
// Places pairs of numbers in the 2D array and then
// randomly shuffles them.
// ======================

void InitializeCards(int cards[][LENGTH]) {
  srand(time(NULL));
  int x1, y1, x2, y2;
  int i;
  int temp;

  // Place pairs in known locations -   this is how our array looks like after
  cards[0][0] = 1;
  cards[0][1] = 1; //   1  1  2  2
  cards[0][2] = 2;
  cards[0][3] = 2;
  cards[1][0] = 3;
  cards[1][1] = 3; //   3  3  4  4
  cards[1][2] = 4;
  cards[1][3] = 4;
  cards[2][0] = 5;
  cards[2][1] = 5; //   5  5  6   6
  cards[2][2] = 6;
  cards[2][3] = 6;
  cards[3][0] = 7;
  cards[3][1] = 7; //   7  7  8   8
  cards[3][2] = 8;
  cards[3][3] = 8;

  // Now that 2D has been initialized with 8 pairs, we want to 
  // shuffle the board so that the pairs aren't right next to each other
  for (int i = 0; i < 30; i++) {
    //Get set of random coordinates and swap
    //First random coordinate on our 2d "grid"
    y1 = rand() % LENGTH;
    x1 = rand() % LENGTH;
    //Second random coordinate of our 2d "grid"
    y2 = rand() % LENGTH;
    x2 = rand() % LENGTH;

    //Now we swap value at (x1, y1) with value at(x2, y2)
    temp = cards[x1][y1];
    cards[x1][y1] = cards[x2][y2];
    cards[x2][y2] = temp;
    //Note: just like with 1D arrays, modifying an n-dimensional array inside
    // a function will change the array itself
  }
}

// ======================
//     main function
// ======================
int main() {
  string name;
  int x1, y1, x2, y2;
  int turns = 0;
  int num = 0;
  ofstream myfile;

  // This welcomes the user

  cout << "Welcome to the memory game! Please enter your full name: " << endl;
  getline(cin, name);
  cout << "Find all the matching pairs on the board!" << endl;

  // A two 2D array that will hold the number for each card. Passes through 
  // the InitializeCards function. 

  int arr[4][LENGTH];
  InitializeCards(arr);

 
  /* This is the 2D array of Booleans that represents 
  	 whether or not the card is matched.
  */
  bool Booleans[LENGTH][LENGTH];
  Booleans[0][0] = 0;
  Booleans[0][1] = 0;
  Booleans[0][2] = 0;
  Booleans[0][3] = 0;
  Booleans[1][0] = 0;
  Booleans[1][1] = 0;
  Booleans[1][2] = 0;
  Booleans[1][3] = 0;
  Booleans[2][0] = 0;
  Booleans[2][1] = 0;
  Booleans[2][2] = 0;
  Booleans[2][3] = 0;
  Booleans[3][0] = 0;
  Booleans[3][1] = 0;
  Booleans[3][2] = 0;
  Booleans[3][3] = 0;

  // While the game is not over :
  while (Booleans[0][0] == 0 || Booleans[0][1] == 0 ||
    Booleans[0][2] == 0 || Booleans[0][3] == 0 ||
    Booleans[1][0] == 0 || Booleans[1][1] == 0 ||
    Booleans[1][2] == 0 || Booleans[1][3] == 0 ||
    Booleans[2][0] == 0 || Booleans[2][1] == 0 ||
    Booleans[2][2] == 0 || Booleans[2][3] == 0 ||
    Booleans[3][0] == 0 || Booleans[3][1] == 0 ||
    Booleans[3][2] == 0 || Booleans[3][3] == 0) {

  	// Displays the current state of the board:
    cout << endl;
    cout << setw(11) << "0" << setw(5) << "1" << setw(5) << "2" 
         << setw(5) << "3" << endl;
    cout << "     " << "======================" << endl;
    for (int i = 0; i < 4; i++) {
      cout << setw(5) << num++ << "|";
      for (int j = 0; j < 4; j++) {
        if (Booleans[i][j] == 1) {
          cout << setw(5) << arr[i][j] << setw(5);
        } else
          cout << setw(5) << "*" << setw(5);
      }
      cout << endl;
    }
    num = 0;

    // Prompts the user to enter the coordinates of two cards
    // Note: user can choose to quit
    do {
      cout << "Please enter two different cards. "; 
      cout << "Enter -1 to quit the program." << endl;
      cout << "Enter the row and column coordinates of your first card here:"; 
      cout << "(For example: 2 1 )" << endl;
      cin >> x1;
      if (x1 == -1 || x2 == -1 || y1 == -1 || y2 == -1) {
        myfile.open("result.txt");
        myfile << "Don't give up!" << endl;
        myfile.close();
        cout << "Don't give up!" << endl;
        return 0;
      }
      cin >> y1;
      if (x1 == -1 || x2 == -1 || y1 == -1 || y2 == -1) {
        myfile.open("result.txt");
        myfile << "Don't give up!" << endl;
        myfile.close();
        cout << "Don't give up!" << endl;
        return 0;
      }

      cout << "Enter the x and y coordinates of your second card here: " 
      	   << endl;
      cin >> x2;
      if (x1 == -1 || x2 == -1 || y1 == -1 || y2 == -1) {
        myfile.open("result.txt");
        myfile << "Don't give up!" << endl;
        myfile.close();
        cout << "Don't give up!" << endl;
        return 0;
      }
      cin >> y2;
      if (x1 == -1 || x2 == -1 || y1 == -1 || y2 == -1) {
        myfile.open("result.txt");
        myfile << "Don't give up!" << endl;
        myfile.close();
        cout << "Don't give up!" << endl;
        return 0;
      }
      cout << endl;
      if (x1 > 3 || y1 > 3 || x2 > 3 || y2 > 3 
      	  || x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 ){
      	cout << "Invalid inputs, please enter values from 0 - 3" 
      		 << endl << endl;
      }
      else if(x1 == x2 && y1 == y2){
      	cout << "Invalid inputs, do not enter the same cards twice" 
      		 << endl << endl;
      }
      else if(Booleans[x1][y1] == 1 && Booleans[x2][y2] == 1){
      	cout << "Invalid inputs, these pairs are already matched." 
      		 << endl << endl;
      }
    }
    while (x1 == x2 && y1 == y2 || x1 > 3 || y1 > 3 || x2 > 3 || y2 > 3 
      	   || x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0
    	   || Booleans[x1][y1] == 1 && Booleans[x2][y2] == 1);

    // If the values of the two coordinates match :
    // it says that a match has been found and it flips the cards over forever
    if (arr[x1][y1] == arr[x2][y2]) {
      cout << "A match has been found!" << endl;
      ShowCards(arr, Booleans, x1, y1, x2, y2);
    }

    // else :
    // This temporarily flip over the cards to show the user the values, 
    // then flips them over again.
    else {
      cout << "No match" << endl;
      ShowCards(arr, Booleans, x1, y1, x2, y2);
    }
    turns += 1;
  }

  // This displays the user's name and how many turns it took to win.
  myfile.open("result.txt");
  myfile << "Congradulations " << name << " you won! It took you: " << turns 
  		 << " turns to beat the game!" << endl;
  myfile.close();
  cout << "Congradulations " << name << " you won! It took you: " << turns 
  	   << " turns to beat the game!" << endl;
  return 0;
}

// ======================
// ShowCards
// Function does not return anything (void)
// Generates a display on the screen.  If faceup=0,
// an * is output, otherwise the card in that slot is output.
// temp just reveals the cards.
// ======================
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH], 
			   int a1, int b1, int a2, int b2) {
  int num = 0;
  bool temp[4][4];
  temp[0][0] = 0;
  temp[0][1] = 0;
  temp[0][2] = 0;
  temp[0][3] = 0;
  temp[1][0] = 0;
  temp[1][1] = 0;
  temp[1][2] = 0;
  temp[1][3] = 0;
  temp[2][0] = 0;
  temp[2][1] = 0;
  temp[2][2] = 0;
  temp[2][3] = 0;
  temp[3][0] = 0;
  temp[3][1] = 0;
  temp[3][2] = 0;
  temp[3][3] = 0;

  if (cards[a1][b1] == cards[a2][b2]) {
    faceup[a1][b1] = 1;
    faceup[a2][b2] = 1;
    cout << setw(11) << "0" << setw(5) << "1" << setw(5) << "2" 
         << setw(5) << "3" << endl;
    cout << "     " << "======================" << endl;
    for (int i = 0; i < 4; i++) {
      cout << setw(5) << num++ << "|";
      for (int j = 0; j < 4; j++) {
        if (faceup[i][j] == 1) {
          cout << setw(5) << cards[i][j] << setw(5);
        } else
          cout << setw(5) << "*" << setw(5);
      }
      cout << endl;
    }
  } else {
    cout << setw(11) << "0" << setw(5) << "1" << setw(5) << "2" 
         << setw(5) << "3" << endl;
    cout << "     " << "======================" << endl;

    temp[a1][b1] = 1;
    temp[a2][b2] = 1;

    for (int i = 0; i < 4; i++) {
      cout << setw(5) << num++ << "|";
      for (int j = 0; j < 4; j++) {
        if (faceup[i][j] == 1) {
          cout << setw(5) << cards[i][j] << setw(5);
        } else if (temp[i][j] == 1)
          cout << setw(5) << cards[i][j] << setw(5);
        else
          cout << setw(5) << "*" << setw(5);
      }
      cout << endl;
    }
  }
}



/*
Run results:

1. |Invalid Input|

Please enter two different cards. Enter -1 to quit the program.
Enter the x and y coordinates of your first card here:
4 5
Enter the x and y coordinates of your second card here:
6 7

Invalid inputs, please enter values from 0 - 3
---------------------------------------------------------------
2. |Three inputs with valid values|

Please enter two different cards. Enter -1 to quit the program.
Enter the x and y coordinates of your first card here:
0 0
Enter the x and y coordinates of your second card here:
0 1

No match
          0    1    2    3
     ======================
    0|    3    4    *    *
    1|    *    *    *    *
    2|    *    *    *    *
    3|    *    *    *    *

          0    1    2    3
     ======================
    0|    *    *    *    *
    1|    *    *    *    *
    2|    *    *    *    *
    3|    *    *    *    *

Please enter two different cards. Enter -1 to quit the program.
Enter the x and y coordinates of your first card here:
0 1
Enter the x and y coordinates of your second card here:
0 3

A match has been found!
          0    1    2    3
     ======================
    0|    *    4    *    4
    1|    *    *    *    *
    2|    *    *    *    *
    3|    *    *    *    *

          0    1    2    3
     ======================
    0|    *    4    *    4
    1|    *    *    *    *
    2|    *    *    *    *
    3|    *    *    *    *

Please enter two different cards. Enter -1 to quit the program.
Enter the x and y coordinates of your first card here:
1 0
Enter the x and y coordinates of your second card here:
1 1

No match
          0    1    2    3
     ======================
    0|    *    4    *    4
    1|    2    6    *    *
    2|    *    *    *    *
    3|    *    *    *    *

          0    1    2    3
     ======================
    0|    *    4    *    4
    1|    *    *    *    *
    2|    *    *    *    *
    3|    *    *    *    *
----------------------------------------------------
3. |The Quit Input|

Please enter two different cards. Enter -1 to quit the program.
Enter the x and y coordinates of your first card here:
-1
Don't give up!
*/
