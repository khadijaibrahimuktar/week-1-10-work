#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

int parseScore(const string &scoreText) {
    size_t parsedCharacters = 0;
    int score = stoi(scoreText, &parsedCharacters);
    if (parsedCharacters != scoreText.length()) {
        throw invalid_argument("Score contains non-numeric characters.");
    }
    return score;
}

int main() {
    ifstream file("students.csv");
    if (!file.is_open()) {
        cerr << "Error: Could not find students.csv!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;
    cout << "--- Processing Student Records ---" << endl;

    while (getline(file, line)) {
        lineNumber++;
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string name;
        string scoreStr1;
        string scoreStr2;
        string scoreStr3;
        string extraField;

        if (!getline(ss, name, ',') ||
            !getline(ss, scoreStr1, ',') ||
            !getline(ss, scoreStr2, ',') ||
            !getline(ss, scoreStr3, ',')) {
            cout << "WARNING: Skipping malformed record on line "
                 << lineNumber << " (Expected name and three scores)." << endl;
            continue;
        }

        if (getline(ss, extraField, ',')) {
            cout << "WARNING: Skipping malformed record for " << name
                 << " (Too many fields)." << endl;
            continue;
        }

        try {
            int s1 = parseScore(scoreStr1);
            int s2 = parseScore(scoreStr2);
            int s3 = parseScore(scoreStr3);

            double average = (s1 + s2 + s3) / 3.0;
            cout << name << " -> Average: " << average << endl;
        } catch (const invalid_argument &) {
            cout << "WARNING: Skipping malformed record for " << name
                 << " (Invalid score data)." << endl;
        } catch (const out_of_range &) {
            cout << "WARNING: Skipping malformed record for " << name
                 << " (Score is out of range)." << endl;
        }
    }

    if (file.bad()) {
        cerr << "Error: Failed while reading students.csv." << endl;
        return 1;
    }

    file.close();
    cout << "\n--- Processing Complete ---" << endl;
    return 0;
}
