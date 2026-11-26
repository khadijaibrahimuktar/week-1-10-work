#include <iostream>
#include <iomanip>
using namespace std;

double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }

    return static_cast<double>(sum) / size;
}

void displayHighestScore(int scores[], int size) {
    int highestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (scores[i] > scores[highestIndex]) {
            highestIndex = i;
        }
    }

    cout << "Highest score: " << scores[highestIndex]
         << " at position " << highestIndex + 1 << endl;
}

void displayAboveAverage(int scores[], int size, double average) {
    cout << "\nScores above average (" << fixed << setprecision(2) << average << "):" << endl;
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (scores[i] > average) {
            cout << "  Score " << scores[i] << " at position " << i + 1 << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "  None" << endl;
    }
}

int main() {
    const int SIZE = 10;
    int scores[SIZE];

    cout << "Enter " << SIZE << " student scores:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Score " << i + 1 << ": ";
        if (!(cin >> scores[i])) {
            cout << "Invalid input. Please enter integer scores." << endl;
            return 1;
        }
    }

    double average = calculateAverage(scores, SIZE);

    cout << "\n--- Results ---" << endl;
    cout << "Average score: " << fixed << setprecision(2) << average << endl;
    displayHighestScore(scores, SIZE);
    displayAboveAverage(scores, SIZE, average);

    return 0;
}
