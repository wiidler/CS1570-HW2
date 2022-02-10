// Programmer: Will Weidler
// Date: 2/7/22
// File: wordle.cpp
// Assignment: HW2
// Purpose: This file contains a popular clone of the game "Wordle".

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool isInWord(const char guess, const string goalWord, const int WORDLENGTH)
{
    bool returnVal = false;
    for(int i=0; i<WORDLENGTH; i++)
    {
        if(guess == goalWord[i])
            returnVal = true;
    }
    return returnVal;
}

int main(){
	cout << "Welcome to Wordle For Friends!" << endl << "<=^.^=>"<< endl << endl;

	cout << "Player 1, please enter your name: ";

	string playerOneName;
	cin >> playerOneName;

	cout << endl << "Welcome, " << playerOneName << "!" << endl;

string newGame;

while (newGame != "N"){
		cout << endl << "Now, Player 2, please enter your name: ";

		string playerTwoName;
		cin >> playerTwoName;

		cout << endl << "Welcome, " << playerTwoName << "!" << endl;
		int friendshipValue = -1;

		while ((friendshipValue == (int)friendshipValue and friendshipValue >= 0 and friendshipValue <= 100) == false){ // Figure out a better way to incorporate logic into while loop statement
			cout << endl << playerOneName << ", please rate the friendship level you have with " << playerTwoName << "." << endl;
			cout << "(enter an integer value in [0, 100]): ";

		
			cin >> friendshipValue;
			cout << endl;

			if (friendshipValue == (int)friendshipValue and friendshipValue >= 0 and friendshipValue <= 100){ // figure out how to check if friendshipValue is an integer
				cout << "Hooray, that's an admirable friendship between you two!" << endl << endl;
			}
			else {
				cout << "Can't you read, " << playerOneName << "? The friendship level you input is invalid!" << endl;
			}
		}
		string playAgain;
		while (playAgain != "N") {
			int roundNumber = 1;

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
			int victory = 0;
			while (attempts <= 6 and victory != 1){ // This is the 6 attempts of the game
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
					else if (guessWord == keyWord){
						cout << "You entered \"" << guessWord << "\". Congratulations, \"" << guessWord << "\" it is!" << endl << endl;
						victory = 1;
					}
					else{
						cout << "You entered \"" << guessWord << "\". Nice try, keep going!" << endl;
						for(int index=0; index<guessWord.length(); index++)
						{
							cout << guessWord.at(index) << ":";
							if (guessWord.at(index) == keyWord.at(index)){
								cout << " ^o^" << endl;
							} 
							else if (isInWord(guessWord.at(index), keyWord, keyWord.length())){
								cout << " ^('-')^" << endl;
							}
							else if (isInWord(guessWord.at(index), keyWord, keyWord.length()) == false){ // else if
								cout << " @.@" << endl;
							}
						}
						cout << endl;
						attempts += 1;
					}
				}
			}
			cout << "Round " << roundNumber << " Summary" << endl;
			cout << "     Player 1 : " << playerOneName << endl;
			cout << "     Player 2 : " << playerTwoName << endl;
			cout << "     Friendship Level: " << friendshipValue << " -> " << (friendshipValue + attempts) << endl << endl;
			friendshipValue += attempts;

			cout << playerOneName << ", do you want to play another round with " << playerTwoName << " (Y/N) ? ";
			cin >> playAgain;
			if (playAgain == "N"){
				cout << "OK, " << playerOneName << ". Your final friendship level with " << playerTwoName << " is " << friendshipValue << " after " << roundNumber << " round(s) of Wordle." << endl;
				cout << "Remember, a real friend is one who always Wordles with you when the rest of the world won't!" << endl << endl;

				cout << "Okay " << playerOneName << ", do you want to start a new game with a different player then (Y/N)? ";
				cin >> newGame;
				
				if (newGame == "N"){
					cout << "OK, good bye, " << playerOneName << "! See you soon, Wordle Wordle!" << endl;
				}
				else if ( newGame == "Y"){
					cout << "Awesome! Let get this started!" << endl << endl;
				}
			}
		}
	}
	return 0;
}