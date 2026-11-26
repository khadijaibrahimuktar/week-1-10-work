#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "     MULTIPLICATION TABLE (1 to 10)" << endl;
    cout << "========================================" << endl;
    cout << endl;

    cout << setw(5) << "";
    for (int column = 1; column <= 10; column++) {
        cout << setw(5) << column;
    }
    cout << endl;
    cout << string(55, '-') << endl;

    for (int row = 1; row <= 10; row++) {
        cout << setw(5) << row;
        for (int column = 1; column <= 10; column++) {
            cout << setw(5) << row * column;
        }
        cout << endl;
    }

    cout << "========================================" << endl;

    return 0;
}
