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

void RandomGenerator() {
    // Get filename and path from user
    string filename = "";
    string path = "";
    cout << "Enter random character filename: ";
    cin >> filename;
    cout << "Enter random character path: ";
    cin >> path;

    // Concatenate filename and path to create full file path
    string filepath = path + "/" + filename;

    // Create a new file with the given filename and path
    ofstream outfile(filepath);

    if (!outfile) {
        cerr << "Failed to create file!";
    }

    cout << "File created successfully.\n";


    // کاراکترهای پر استفاده در تولید فایل رندوم
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()+~`|}{[]\:;?><,./-=";
    int char_index = 0;
    int file_size = 100; // سایز فایل تولیدی (به بیت)


    // تولید داده‌های رندوم به صورت تصادفی
    srand(time(0));

    for (int i = 0; i < file_size; i++) {
        char_index = rand() % chars.length(); // اندیس کاراکتر رندوم
        outfile << chars[char_index]; // نوشتن کاراکتر رندوم در فایل
    }

    outfile.close();


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

        cerr << "File not found!";
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
void main()
{
    RandomGenerator();
    splitfile();

}