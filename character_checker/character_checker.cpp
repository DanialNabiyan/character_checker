// Character_Checker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool checkfile_exist(const std::string& filename) {
    ifstream file(filename);
    return file.good();
}
void splitfile() {
    string mainfilename = "";
    string alphabetfile = "";
    string numberfile = "";
    string specialcharfile = "";
    int alphabet_count = 0;
    int number_count = 0;
    int char_count = 0;

    //get user file
    cout << "Please enter your file: ";
    cin >> mainfilename;
    // get alphabet file
    cout << "Please enter alphabet file: ";
    cin >> alphabetfile;
    //get number file
    cout << "Please enter number file: ";
    cin >> numberfile;
    //get special char file
    cout << "Please enter char file: ";
    cin >> specialcharfile;


    if (!checkfile_exist(mainfilename)) {

        // mamad inja ye alert bezar bego file does not exist 
    }
    else
    {
        ifstream file(mainfilename);
        char ch;

        while (file.get(ch)) {

            //std::cout << ch << std::endl;
            if (isalpha(ch))
            {
                ofstream alpha(alphabetfile, ios::app);
                alpha << ch;
                alphabet_count++;
            }
            else if (isdigit(ch))
            {
                ofstream num(numberfile, ios::app);
                num << ch;
                number_count++;
            }
            else
            {
                if (ch != '\n') {
                    std::cout << ch << std::endl;

                    ofstream charfile(specialcharfile, ios::app);
                    charfile << ch;
                    char_count++;
                }
            }
        }
        cout << "alphabet char count :" << alphabet_count << std::endl;
        cout << "number char count :" << number_count << std::endl;
        cout << "special char count :" << char_count << std::endl;
    }

}
int main()
{
    splitfile();

}