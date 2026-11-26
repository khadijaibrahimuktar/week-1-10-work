#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string studentName;
    string course;

    int score1, score2, score3, score4;
    int totalScore;

    double average;
    double percentage;

    const int MAX_SCORE = 100;

    cout << "========================================" << endl;
    cout << "   STUDENT SCORE CALCULATOR" << endl;
    cout << "========================================" << endl;
    cout << endl;

    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter course (BBIT/BCS): ";
    getline(cin, course);

    cout << "Enter score for Test 1: ";
    cin >> score1;

    cout << "Enter score for Test 2: ";
    cin >> score2;

    cout << "Enter score for Test 3: ";
    cin >> score3;

    cout << "Enter score for Test 4: ";
    cin >> score4;

    if (score1 < 0 || score1 > 100 ||
        score2 < 0 || score2 > 100 ||
        score3 < 0 || score3 > 100 ||
        score4 < 0 || score4 > 100) {
        cout << "Error: Scores must be between 0 and 100." << endl;
        return 1;
    }

    totalScore = score1 + score2 + score3 + score4;
    average = totalScore / 4.0;
    percentage = (totalScore / 400.0) * 100;

    cout << endl;
    cout << "========================================" << endl;
    cout << "   REPORT CARD" << endl;
    cout << "========================================" << endl;
    cout << endl;

    cout << "Student:     " << studentName << endl;
    cout << "Course:      " << course << endl;
    cout << endl;
    cout << "Test 1:      " << score1 << "/" << MAX_SCORE << endl;
    cout << "Test 2:      " << score2 << "/" << MAX_SCORE << endl;
    cout << "Test 3:      " << score3 << "/" << MAX_SCORE << endl;
    cout << "Test 4:      " << score4 << "/" << MAX_SCORE << endl;
    cout << endl;
    cout << "Total:       " << totalScore << "/400" << endl;
    cout << "Average:     " << fixed << setprecision(2) << average << endl;
    cout << "Percentage:  " << fixed << setprecision(2) << percentage << "%" << endl;
    cout << endl;

    if (percentage >= 50) {
        cout << "Result:      PASS" << endl;
    } else {
        cout << "Result:      FAIL" << endl;
    }

    int highestScore = score1;
    if (score2 > highestScore) highestScore = score2;
    if (score3 > highestScore) highestScore = score3;
    if (score4 > highestScore) highestScore = score4;
    cout << "Highest:     " << highestScore << "/" << MAX_SCORE << endl;

    char grade;
    if (percentage >= 90) grade = 'A';
    else if (percentage >= 80) grade = 'B';
    else if (percentage >= 70) grade = 'C';
    else if (percentage >= 60) grade = 'D';
    else grade = 'F';
    cout << "Grade:       " << grade << endl;

    cout << "========================================" << endl;

    return 0;
}
