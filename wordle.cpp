// Programmer: Will Weidler
// Date: 2/7/22
// File: wordle.cpp
// Assignment: HW2
// Purpose: This file contains a popular clone of the game "Wordle".

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool isInWord(const char guess, const string goalWord, const int WORDLENGTH) // Function used to find out if each letter in a guess is in a word
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

while (newGame != "N"){ // This is where the game loops if player one chooses to start a new game with a new player two
		cout << endl << "Now, Player 2, please enter your name: ";

		string playerTwoName;
		cin >> playerTwoName;

		cout << endl << "Welcome, " << playerTwoName << "!" << endl;
		int friendshipValue = -1;

		while (((friendshipValue == (int)friendshipValue) and friendshipValue >= 0 and friendshipValue <= 100) == false){ // (fix if a word is entered)
			cout << endl << playerOneName << ", please rate the friendship level you have with " << playerTwoName << "." << endl;
			cout << "(enter an integer value in [0, 100]): ";

		
			cin >> friendshipValue;
			cout << endl;

			if ((friendshipValue == (int)friendshipValue) and friendshipValue >= 0 and friendshipValue <= 100){ // figure out how to check if friendshipValue is an integer
				cout << "Hooray, that's an admirable friendship between you two!" << endl << endl;
			}
			else{
				cout << "Can't you read, " << playerOneName << "? The friendship level you input is invalid!" << endl;
			}
		}
		string playAgain;
		while (playAgain != "N") { // This is where the game loops if player one wants to play again with the same player two
			int roundNumber;

			cout << "Let the game begin!" << endl << endl;

			cout << "Wait... " << playerOneName << ", I need the key word from you (yes, you may whisper into my ears... and remember, it has to be a valid five-letter word, all UPPERCASE!): ";

			string keyWord;

			while (keyWord.length() != 5 or any_of(keyWord.begin(), keyWord.end(), ::isdigit)){ // If the keyword is not 5 characters long or if there are characters other than letters in the word, this loops until it meets the criteria.
				cin >> keyWord;
				cout << endl;
				if (keyWord.length() < 5 or keyWord.length() > 5){
					cout << "Seriously, " << playerOneName << "? Your input word is " << keyWord.length() << " letters long! Don't make me quit on you right now..." << endl << endl;
					cout << "Please enter the key word again (remember, it has to be a valid five-letter word, all UPPERCASE!): ";
				}
				else if (any_of(keyWord.begin(), keyWord.end(), ::isalpha) ==  false){
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
			while (attempts <= 6 and (attempts <= 6 and victory != 1)){ // This is the 6 attempts of the game
				cout << "This is your attempt #" << attempts << ", " << playerTwoName << ", please enter a valid five-letter word (all UPPERCASE): ";
				string guessWord;
				while (guessWord.length() != 5 or any_of(guessWord.begin(), guessWord.end(), ::isdigit)){ // If the keyword is not 5 characters long or if there are characters other than letters in the word, this loops until it meets the criteria.
					cin >> guessWord;
					cout << endl;
					if (guessWord.length() != 5){
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
					else{ // Outputs guess and hints if word meets all above criteria, ends game after 6 rounds and gives special failure message
						if (attempts == 6){
							cout << "You entered \"" << guessWord << "\". Sorry, you lose! The word was \"" << keyWord << "\"." << endl;
							attempts += 1;
						}
						else{
							cout << "You entered \"" << guessWord << "\". Nice try, keep going!" << endl;
							for(int index=0; index < (int) guessWord.length(); index++)
							{
								cout << guessWord.at(index) << ":";
								if (guessWord.at(index) == keyWord.at(index)){
									cout << " ^o^" << endl;
								} 
								else if (isInWord(guessWord.at(index), keyWord, keyWord.length())){
									cout << " ^('-')^" << endl;
								}
								else if (isInWord(guessWord.at(index), keyWord, keyWord.length()) == false){ 
									cout << " @.@" << endl;
								}
							}
							cout << endl;
							attempts += 1; // Progresses the round
						}
					}
				}
			}
			roundNumber += 1; // Increases 
			int friendshipValueOld;
			cout << "Round " << roundNumber << " Summary" << endl;
			cout << "     Player 1 : " << playerOneName << endl;
			cout << "     Player 2 : " << playerTwoName << endl;
			if (victory == 1){
				if ((friendshipValue + attempts) > 100){
					friendshipValueOld = friendshipValue;
					friendshipValue = 100;
				
				}
				else{
					friendshipValueOld = friendshipValue;
					friendshipValue += attempts;
				}
				cout << "     Friendship Level: " << (friendshipValueOld) << " -> " << (friendshipValue) << endl << endl;
			}
			else if (victory == 0){
				cout << "     Friendship Level: " << (friendshipValue) << endl << endl;
			}
			

			cout << playerOneName << ", do you want to play another round with " << playerTwoName << " (Y/N)? ";
			cin >> playAgain;
			if (playAgain == "N"){
				cout << "OK, " << playerOneName << ". Your final friendship level with " << playerTwoName << " is " << friendshipValue << " after " << roundNumber << " round(s) of Wordle." << endl;
				cout << "Remember, a real friend is one who always Wordles with you when the rest of the world won't!" << endl << endl;

				cout << "Okay " << playerOneName << ", do you want to start a new game with a different player then (Y/N)? ";
				cin >> newGame;
				
				if (newGame == "N"){
					cout << "OK, good bye, " << playerOneName << "! See you soon, Wordle Wordle!" << endl; // Closes game
				}
				else if ( newGame == "Y"){ // Restarts game with new player
					cout << "Awesome! Let get this started!" << endl << endl;
					attempts = 1; // Resets attempts
					roundNumber = 1; // Resets round number
				}
			}
			else{
				cout << "Awesome! Let get this started!" << endl << endl; // Restarts game with same players
					attempts = 1; // Resets attempts

			}
		}
	}
	return 0;
}