#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[50];

    cout << "Enter your name: ";
    cin.getline(name, sizeof(name));

    cout << "Name: " << name << endl;
    cout << "Length: " << strlen(name) << endl;

    if (name[0] != '\0') {
        cout << "First character: " << name[0] << endl;
    } else {
        cout << "First character: (none)" << endl;
    }

    char copy[sizeof(name)];
    strcpy(copy, name);
    cout << "Copy: " << copy << endl;

    return 0;
}
