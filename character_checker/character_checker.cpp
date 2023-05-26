#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <filesystem>

using namespace std;

// A function that checks if a file exists
bool checkfile_exist(const std::string& filename) {
	ifstream file(filename);
	return file.good();
}

string readInput(const std::string& message) {
	string input;
	while (true) {
		cout << message;
		getline(cin, input);
		if (input.empty()) {
			cerr << "Error: Input must not be empty." << std::endl;
		}
		else {
			break;
		}
	}
	return input;
}

// A function that generates a file filled with random characters
void RandomGenerator() {
	// Get the name and path of the file from the user
	string filepath = "";
	filepath = readInput("Enter random character file path: ");

	// Add .txt extension to the filename
	if (filepath.substr(filepath.find_last_of(".") + 1) != "txt") {
		filepath += ".txt";
	}

	// Create a new file with the given file path
	ofstream outfile(filepath);
	if (!outfile.is_open()) {
		cerr << "Failed to create file!" << endl;
	}
	else {
		cout << "File created successfully.\n";

		// Define the characters to be used in generating the random data
		string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()+~`|}{[]\\:;?><,./-=";
		int char_index = 0;
		int file_size = 100; // The size of the generated file (in bytes)

		// Generate random data
		srand(time(0));
		for (int i = 0; i < file_size; i++) {
			char_index = rand() % chars.length(); // Get a random index into the chars string
			outfile << chars[char_index]; // Write the selected character to the file
		}

		outfile.close();
	}
}

// A function that reads a file and splits its contents into files containing alphabetic, numeric, and special characters

void splitfile() {
	string mainfilepath = "";
	string alphabetfilepath = "";
	string numberfilepath = "";
	string specialcharfilepath = "";
	int alphabet_count = 0;
	int number_count = 0;
	int char_count = 0;


	// Get the file paths from the user
	cout << "Please enter your main file path: ";
	mainfilepath = readInput("");
	cout << "Please enter alphabet file path: ";
	//alphabetfilepath = readInput("");
	getline(cin, alphabetfilepath);
	if (alphabetfilepath.empty())
	{
		alphabetfilepath = "alphabet.txt";
	}
	cout << "Please enter number file path: ";
	//numberfilepath = readInput("");
	getline(cin, numberfilepath);
	if (numberfilepath.empty())
	{
		numberfilepath = "number.txt";
	}
	cout << "Please enter special character file path: ";
	//specialcharfilepath = readInput("");
	getline(cin, specialcharfilepath);
	if (specialcharfilepath.empty())
	{
		specialcharfilepath = "special.txt";
	}
	ofstream alpha(alphabetfilepath);
	ofstream num(numberfilepath);
	ofstream charfile(specialcharfilepath);
	alpha.close();
	num.close();
	charfile.close();
	

	// Check if the main file exists
	if (!checkfile_exist(mainfilepath)) {
		cerr << "File not found!" << endl;
		return;
	}

	ifstream file(mainfilepath);
	string line;

	// Iterate over each line in the file
	while (getline(file, line)) {
		for (char ch : line) {
			// Determine the type of character (alphabetic, numeric, or special)
			if (isalpha(ch))
			{
				// If the character is alphabetic, write it to the alphabet file and increment the alphabet count
				ofstream alpha(alphabetfilepath, ios::app | ios::ate);
				alpha << ch;
				alphabet_count++;
			}
			else if (isdigit(ch))
			{
				// If the character is numeric, write it to the number file and increment the number count
				ofstream num(numberfilepath, ios::app | ios::ate);
				num << ch;
				number_count++;
			}
			else
			{
				// If the character is a special character, write it to the special character file and increment the special character count
				if (!isspace(ch)) {
					ofstream charfile(specialcharfilepath, ios::app | ios::ate);
					charfile << ch;
					char_count++;
				}
			}
		}
		// Write a newline character at the end of each line
		ofstream alpha(alphabetfilepath, ios::app | ios::ate);
		alpha << endl;
		ofstream num(numberfilepath, ios::app | ios::ate);
		num << endl;
		ofstream charfile(specialcharfilepath, ios::app | ios::ate);
		charfile << endl;
	}

	// Print the counts of each type of character
	cout << "Alphabetic character count: " << alphabet_count << endl;
	cout << "Numeric character count: " << number_count << endl;
	cout << "Special character count: " << char_count << endl;
}


// The main function that calls the other functions and displays a menu to select which task to perform
int main() {
	int choice = 0;
	string input = "";

	while (true) {
		cout << "Please choose one of the following options:" << endl;
		cout << "1. Generate a file filled with random characters." << endl;
		cout << "2. Split a file into files containing alphabetic, numeric and special characters." << endl;
		cout << "3. Exit" << endl;
		cout << "Please enter option: ";

		input = readInput("");

		if (input == "/menu") {
			continue;
		}

		choice = stoi(input);

		switch (choice) {
		case 1:
			RandomGenerator();
			break;
		case 2:
			splitfile();
			break;
		case 3:
			cout << "Goodbye!" << endl;
			return 0;
		default:
			cerr << "Invalid choice!" << endl;
			break;
		}

		cout << endl; // Add a line break between each iteration of the loop
	}

	return 0;
}

