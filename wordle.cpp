// Programmer: Will Weidler
// Date: 2/7/22
// File: wordle.cpp
// Assignment: HW2
// Purpose: This file contains a popular clone of the game "Wordle".

#include <string>
#include <iostream>
#include <algorithm>
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

	while (true){
		cout << endl << playerOneName << ", please rate the friendship level you have with " << playerTwoName << "." << endl;
		cout << "(enter an integer value in [0, 100]): ";

		int friendshipValue;

		cin >> friendshipValue;
		cout << endl;

		if (friendshipValue == (int)friendshipValue and friendshipValue >= 0 and friendshipValue <= 100){ // figure out how to check if friendshipValue is an integer
			cout << "Hooray, that's an admirable friendship between you two!" << endl << endl;
			break;
		}
		else {
			cout << "Can't you read, " << playerOneName << "? The friendship level you input is invalid!" << endl;
		}
	}

	cout << "Let the game begin!" << endl << endl;

	cout << "Wait... " << playerOneName << ", I need the key word from you (yes, you may whisper into my ears... and remember, it has to be a valid five-letter word, all UPPERCASE!): ";

	string keyWord;
	
	while (keyWord.length() < 5 or keyWord.length() > 5 or any_of(keyWord.begin(), keyWord.end(), ::isdigit)){
		cin >> keyWord;
		cout << endl;
		if (keyWord.length() < 5 or keyWord.length() > 5){
			cout << "Seriously, " << playerOneName << "? Your input word is " << keyWord.length() << " letters long! Don't make me quit on you right now..." << endl << endl;
			cout << "Please enter the key word again (remember, it has to be a valid five-letter word, all UPPERCASE!): ";
		}
		else if (any_of(keyWord.begin(), keyWord.end(), ::isdigit)){
			cout << "Don't make me arrest you, " << playerOneName << "! Your input word is contaminated with non-alphabet characters..." << endl << endl;
			cout << "Please enter the key word again (remember, it has to be a valid five-letter word, all UPPERCASE!): ";
		}
		else{
			cout << "Got it, " << playerOneName << "! The key word is now securely processed and saved." << endl << endl;
		}

	}

	cout << "Get ready, " << playerTwoName << "! It's now time to Wordle with " << playerOneName << "!" << endl << "You will have a total of 6 attemts to guess the word correctly." << endl << endl;

	int attempts = 1;
	while (attempts <= 6){ // This is the 6 attempts of the game
		cout << "This is your attempt #" << attempts << ", " << playerTwoName << ", please enter a valid five-letter word (all UPPERCASE): ";
		string guessWord;
		while (guessWord.length() < 5 or guessWord.length() > 5 or any_of(guessWord.begin(), guessWord.end(), ::isdigit)){
			cin >> guessWord;
			cout << endl;
			if (guessWord.length() < 5 or guessWord.length() > 5){
				cout << "Seriously, " << playerTwoName << "? Your input word is " << guessWord.length() << " letters long! Don't make me quit on you right now..." << endl << endl;
				cout << "Please enter the key word again (remember, it has to be a valid five-letter word, all UPPERCASE!): ";
			}
			else if (any_of(guessWord.begin(), guessWord.end(), ::isdigit)){
				cout << "Don't make me arrest you, " << playerTwoName << "! Your input word is contaminated with non-alphabet characters..." << endl << endl;
				cout << "Please enter the key word again (remember, it has to be a valid five-letter word, all UPPERCASE!): ";
			}
			else{
				cout << "You entered \"" << guessWord << "\". Nice try, keep going!" << endl;
				// add the game's input of the guess and output of the word with its placements here
				// also don't forget the friendship level stuff
				// also will need to while loop the whole game until final user value == "N"
				// this is going somewhere
				attempts += 1;
			}
		}
	}

    string str = "LAUGH"; 
		// note: the first character in a string is
		// 	located at index position 0 (not 1) 
		for(int index=0; index<str.length(); index++){
			cout << str.at(index) << ":" << endl; 
        }
    return 0;
}