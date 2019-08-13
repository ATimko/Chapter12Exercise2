#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	cout << "Let's Play Word Jumble!\n"
		<< "\n"
		<< "Enter 'hint' for a hint.\n"
		<< "Enter 'exit' to exit.\n\n";

	// define a vector of possible words
	const int rows = 3;
	const int cols = 10;
	//vector<string> words{ "guitar", "violin", "tapestry" };
	char words[rows][cols]{ "guitar", "violin", "tapestry" };

	// get random word from vector
	srand(time(nullptr));
	int index = rand() % rows;
	char word[cols];
//	strncpy(word, words[index], cols);
	//for (int i = 0; words[index][i] != '\0'; ++i) {

	for (int i = 0; i < cols; ++i) {
		word[i] = words[index][i];
	}
	//string word = words[index];

	// jumble the word
//	char jumbled_word[cols];
//	strncpy(jumbled_word, word, cols);
	char jumbled_word[cols];
	for (int i = 0; i < cols;  ++i) {
		jumbled_word[i] = word[i];
	}
	//auto length = word.size();
	size_t length = strlen(word);
	for (int index1 = 0; index1 < length; ++index1) {
		int index2 = rand() % length;
		char temp = jumbled_word[index1];
		jumbled_word[index1] = jumbled_word[index2];
		jumbled_word[index2] = temp;
	}

	// display the jumbled word in upper case
	cout << "The jumble is...";
	for (char c : jumbled_word) {
		cout << (char)toupper(c);
	}
	cout << "\n\n";

	// loop until the user guesses the jumble or enters 'exit'
	int hint_count = 1;
	string guess = "";
	while (guess != "exit") {
		cout << "Your guess: ";
		cin >> guess;
		cin.ignore(1000, '\n');

		if (guess == word) {
			cout << "Congratulations! You guessed it.\n\n";
			break;
		}
		else if (guess == "hint") {
			cout << "Hint: ";
			for (int i = 0; i < strlen(word); ++i) {
				if (i < hint_count) {
					cout << static_cast<char>(toupper(word[i])) << ' ';
				}
				else {
					cout << '_' << ' ';
				}
			}
			cout << "\n\n";
			++hint_count;
		}
		else if (guess == "exit") {
			cout << "Bye! Let's play again soon.\n\n";
		}
		else {
			cout << "Nope. Try again!\n\n";
		}
	}
	system("pause");
	return 0;
}
