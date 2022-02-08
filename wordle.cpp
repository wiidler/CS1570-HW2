// Programmer: Will Weidler
// Date: 2/7/22
// File: wordle.cpp
// Assignment: HW2
// Purpose: This file contains a popular clone of the game "Wordle".

#include <string>
#include <iostream>
using namespace std;
int main(){
	cout << "Welcome to Wordle For Friends!" << endl << "≤^.^≥"<< endl << endl;

	cout << "Player 1, please enter your name: ";

	string playerOneName;
	cin >> playerOneName;

	cout << endl << "Welcome, " << playerOneName << "!" << endl;

	cout << endl << "Now, Player 2, please enter your name: ";

	string playerTwoName;
	cin >> playerTwoName;

	cout << endl << "Welcome, " << playerTwoName << "!" << endl;








    string str = "LAUGH"; 
		// note: the first character in a string is
		// 	located at index position 0 (not 1) 
		for(int index=0; index<str.length(); index++){
			cout << str.at(index) << ":" << endl; 
        }
    return 0;
}