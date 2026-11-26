#include <iostream>
using namespace std;

void fixLeak() {
    int *ptr = new int(42);

    cout << "Inside fixed function. Value: " << *ptr << endl;
    cout << "Memory allocated at address: " << static_cast<void *>(ptr) << endl;

    delete ptr;
    ptr = nullptr;

    cout << "Memory has been successfully freed." << endl;
}

int main() {
    cout << "--- Testing the Fix ---" << endl;
    fixLeak();

    return 0;
}
