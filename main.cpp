#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;

    while (true) {
        cout << "db > ";
        if (!getline(cin, input)) {
            break;
        }

        if (input == ".exit") {
            cout << "Exiting database.\n";
            break;
        } else {
            cout << "Unrecognized command '" << input << "'.\n";
        }
    }

    return 0;
}
