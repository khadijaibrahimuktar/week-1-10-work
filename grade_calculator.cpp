#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int numStudents;
    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;

    cout << "===== GRADE CALCULATOR =====" << endl;
    cout << "How many students? ";
    cin >> numStudents;

    for (int i = 1; i <= numStudents; i++) {
        string name;
        double score;
        char grade;
        char modifier = ' ';

        cout << "\nStudent " << i << " name: ";
        cin >> name;
        cout << "Enter percentage score (0-100): ";
        cin >> score;

        // Input validation
        if (score < 0 || score > 100) {
            cout << "Invalid score! Must be between 0 and 100." << endl;
            i--;            // ask for this student again
            continue;
        }

        // Base letter grade
        if (score >= 90)      grade = 'A';
        else if (score >= 80) grade = 'B';
        else if (score >= 70) grade = 'C';
        else if (score >= 60) grade = 'D';
        else                  grade = 'F';

        // Plus/minus modifiers
        if (grade != 'F') {
            int lastDigit = (int)score % 10;
            if (grade == 'A') {
                if (score >= 97) modifier = '+';
                else if (score < 93) modifier = '-';
            } else {
                if (lastDigit >= 7) modifier = '+';
                else if (lastDigit <= 2) modifier = '-';
            }
        }

        // Display result
        cout << fixed << setprecision(1);
        cout << name << " - Score: " << score << "%" << endl;
        cout << "Grade: " << grade;
        if (modifier != ' ') cout << modifier;
        cout << endl;

        // Message and count
        switch (grade) {
            case 'A': cout << "Excellent work!" << endl; countA++; break;
            case 'B': cout << "Good job!" << endl; countB++; break;
            case 'C': cout << "Satisfactory." << endl; countC++; break;
            case 'D': cout << "Needs improvement." << endl; countD++; break;
            default:  cout << "Please seek help." << endl; countF++;
        }
    }

    // Summary
    cout << "\n===== SUMMARY =====" << endl;
    cout << "A: " << countA << endl;
    cout << "B: " << countB << endl;
    cout << "C: " << countC << endl;
    cout << "D: " << countD << endl;
    cout << "F: " << countF << endl;

    return 0;
}