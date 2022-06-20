#include "Console.hpp"

float Console::readNumber(string prompt) {
    float value;
    cout << prompt;

    while (!(cin >> value)) {
        // Explain error
        cout << "ERROR: a number must be entered: ";
        // Clear input stream
        cin.clear();
        // Discard previous input
        cin.ignore(123, '\n');
    }
    cout << "Successfully entered " << value << endl;
    return value;
}

float Console::readNumber() {
    float value;

    while (!(cin >> value)) {
        // Explain error
        cout << "ERROR: a number must be entered: ";
        // Clear input stream
        cin.clear();
        // Discard previous input
        cin.ignore(123, '\n');
    }
    cout << "Successfully entered " << value << endl;
    return value;
}

string Console::readString(string prompt) {
    string value;
    cout << prompt;

    while (!(cin >> value)) {
        // Explain error
        cout << "ERROR a string must be entered: ";
        // Clear input stream
        cin.clear();
        // Discard previous input
        cin.ignore(123, '\n');
    }
    return value;
}