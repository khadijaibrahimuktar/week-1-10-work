#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream inputFile("numbers.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open numbers.txt for reading!" << endl;
        return 1;
    }

    int num;
    int sum = 0;

    cout << "Reading numbers from file..." << endl;
    while (inputFile >> num) {
        cout << "Read: " << num << endl;
        sum += num;
    }

    if (!inputFile.eof()) {
        cerr << "Error: numbers.txt contains invalid data." << endl;
        return 1;
    }
    inputFile.close();

    cout << "Total Sum: " << sum << endl;

    ofstream outputFile("sum.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Could not create sum.txt for writing!" << endl;
        return 1;
    }

    outputFile << "The total sum is: " << sum << endl;
    outputFile << "Calculated automatically by the C++ program." << endl;
    if (!outputFile) {
        cerr << "Error: Could not write the result to sum.txt." << endl;
        return 1;
    }
    outputFile.close();

    cout << "Result successfully saved to sum.txt!" << endl;
    return 0;
}
