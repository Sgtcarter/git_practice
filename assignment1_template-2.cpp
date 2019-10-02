/*********
assignment 1 template
*********/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <time.h>

const int LENGTH = 4;
using namespace std;

// Function prototypes

void InitializeCards(int cards[][LENGTH]);
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH], int a1, int b1 , int a2 , int b2);
// you may have more function prototypes
// ======================
// InitializeCards
// Places pairs of numbers in the 2D array and then
// randomly shuffles them.
// ======================
//Notice that when you pass a 2D-array to a function, you MUST specify the number of columns
void InitializeCards(int cards[][LENGTH]) 
{
	//seed rand() - remember to always do this before using rand()
    // also make sure to include the <time.h> library.
	srand(time(NULL)); 
	int x1, y1, x2, y2;
	int i;
	int temp;

	// Place pairs in known locations -   this is how our array looks like after
	cards[0][0] = 1; cards[0][1] = 1;//   1  1  2  2
	cards[0][2] = 2; cards[0][3] = 2;
	cards[1][0] = 3; cards[1][1] = 3;//   3  3  4  4
	cards[1][2] = 4; cards[1][3] = 4;
	cards[2][0] = 5; cards[2][1] = 5;//   5  5  6   6
	cards[2][2] = 6; cards[2][3] = 6;
	cards[3][0] = 7; cards[3][1] = 7;//   7  7  8   8
	cards[3][2] = 8; cards[3][3] = 8;

	// Now that 2D has been initialized with 8 pairs, we want to shuffle the board so
	// that the pairs aren't right next to each other
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
int main()
{
	string name;
	int x1 , y1, x2, y2;
	
	// 1) Welcome the user and ask him to enter his full name.

		// add your code here
	cout << "Welcome to the memory game! Please enter your full name: " << endl;
	cin >> name;
    
	// 2) Create a two 2D array that will hold the number for each card. Pass it to 
	// 	  InitializeCards function. 

		// add your code here
		int arr[4][LENGTH];
	    InitializeCards(arr);
	    

	// 3) Create the 2D array of Booleans that represents whether or not the card is matched. 
	// 	  This should be initialized to all 0 at first. 

		// add your code here
		bool Booleans[LENGTH][LENGTH];
		Booleans[0][0] = 0; Booleans[0][1] = 0;//   1  1  2  2
		Booleans[0][2] = 0; Booleans[0][3] = 0;
		Booleans[1][0] = 0; Booleans[1][1] = 0;//   3  3  4  4
		Booleans[1][2] = 0; Booleans[1][3] = 0;
		Booleans[2][0] = 0; Booleans[2][1] = 0;//   5  5  6   6
		Booleans[2][2] = 0; Booleans[2][3] = 0;
		Booleans[3][0] = 0; Booleans[3][1] = 0;//   7  7  8   8
		Booleans[3][2] = 0; Booleans[3][3] = 0;

	// 4) while the game is not over :
		while (Booleans[0][0] == 0 || Booleans[0][1] == 0 
		|| Booleans[0][2] == 0 || Booleans[0][3] == 0
		|| Booleans[1][0] == 0 || Booleans[1][1] == 0
		|| Booleans[1][2] == 0 || Booleans[1][3] == 0
		|| Booleans[2][0] == 0 || Booleans[2][1] == 0
		|| Booleans[2][2] == 0 || Booleans[2][3] == 0
		|| Booleans[3][0] == 0 || Booleans[3][1] == 0
		|| Booleans[3][2] == 0 || Booleans[3][3] == 0) {
		// Display the current state of the game board. Remember that non-matched pairs should be "facedown"
		// and that matched pairs should be "faceup"
		
			// add your code here
			 cout << "--------------" << endl;
			for(int i = 0; i < 4; i++){
		 	for (int j = 0; j < 4; j++){
			 if (Booleans[i][j] == 1){
			cout << arr[i][j] << setw(5);	 
		 }
		 else
			 cout << "*" << setw(5);
		 	}
		 	cout << endl;
			}
			

		// Prompt the user to enter the coordinates of two cards
		// Note: user can choose to quit

			// add your code here
			do{
			cout << "Please enter two different cards. Enter -1 to quit the program." << endl;
			cout << "Enter the coordinates of your first card here: " << endl;
			cin >> x1; 
			if (x1 == -1 || x2 == -1 || y1 == -1 || y2 == -1)
			    return 0;
			cin >> y1; 
			if (x1 == -1 || x2 == -1 || y1 == -1 || y2 == -1)
			    return 0;

			cout << "Enter the coordinates of your second card here: " << endl;
			cin >> x2;
			if (x1 == -1 || x2 == -1 || y1 == -1 || y2 == -1)
			    return 0;
			cin >> y2;
			if (x1 == -1 || x2 == -1 || y1 == -1 || y2 == -1)
			    return 0;
			}
			while(x1 != x2 && y1 != y2);
			
		// If the values of the two coordinates match :
		//     say that a match has been found and flip the cards over forever

			// add your code here
			if (arr [x1][y1] == arr[x2][y2]){
			cout << "A match has been found!" << endl;
			ShowCards(arr, Booleans, x1, y1, x2, y2);
			}

		// else :
		//     temporarily flip over the cards to show the user the values, then flip them over again.

			// add your code here
			else{
			cout << "No match" << endl;
			ShowCards(arr, Booleans, x1, y1, x2, y2);
			}
		}

	// 5) Save the user’s name and how many turns it took to win the game into an output text file. If he quits
	// before winning save “Don’t give up” message in the file.

		// add your code here
}



// ======================
// ShowCards
// Generates a display on the screen.  If faceup=0,
// an * is output, otherwise the card in that slot is output.
// ======================
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH], int a1, int b1, int a2, int b2) 
{
        bool temp[4][4];
    	temp[0][0] = 0; temp[0][1] = 0;
		temp[0][2] = 0; temp[0][3] = 0;
		temp[1][0] = 0; temp[1][1] = 0;
		temp[1][2] = 0; temp[1][3] = 0;
		temp[2][0] = 0; temp[2][1] = 0;
		temp[2][2] = 0; temp[2][3] = 0;
		temp[3][0] = 0; temp[3][1] = 0;
		temp[3][2] = 0; temp[3][3] = 0;
	// add your code here
	
	if (cards[a1][b1] == cards[a2][b2]){
	faceup[a1][b1] = 1;
	faceup[a2][b2] = 1;
    cout << "--------------" << endl;
	for(int i = 0; i < 4; i++){
	 for (int j = 0; j < 4; j++){
		 if (faceup[i][j] == 1){
			cout << cards[i][j] << setw(5);	 
		 }
		 else
			 cout << "*" << setw(5);
	 }
	 cout << endl;
	 }
	}
    else {
         cout << "--------------" << endl;
       
        temp[a1][b1] = 1;
        temp[a2][b2] = 1;
         
	for(int i = 0; i < 4; i++){
	 for (int j = 0; j < 4; j++){
		 if (faceup[i][j] == 1){
			cout << cards[i][j] << setw(5);	 
		 }
		 else if(temp[i][j] == 1)
		    cout << cards[i][j] << setw(5);
		 else
			 cout << "*" << setw(5);
	 }
	 cout << endl;
	}
	temp[a1][b1] = 0;
    temp[a2][b2] = 0;
}
}
