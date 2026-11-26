#include <iostream>

using namespace std;

int main() {
    int n;
    int sum = 0;

    cout << "Enter a positive number (N): ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number." << endl;
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    cout << "The sum of numbers from 1 to " << n << " is: " << sum << endl;

    return 0;
}
