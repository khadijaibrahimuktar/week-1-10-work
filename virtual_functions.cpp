#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal makes a generic sound." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

int main() {
    cout << "--- With Virtual Keyword ---" << endl;

    Dog myDog;
    Animal *myPet = &myDog;
    myPet->speak();

    return 0;
}
