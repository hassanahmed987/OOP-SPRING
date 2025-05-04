#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("large_log.txt");

    if (!in) {
        cout << "Could not open file!" << endl;
        return 1;
    }

    string line;

    // First line
    getline(in, line);
    cout << "Line 1: " << line << endl;
    cout << "Position after line 1: " << in.tellg() << endl;

    // Second line
    getline(in, line);
    cout << "Line 2: " << line << endl;
    cout << "Position after line 2: " << in.tellg() << endl;

    // Third line
    getline(in, line);
    cout << "Line 3: " << line << endl;
    cout << "Position after line 3: " << in.tellg() << endl;

    in.close();
    return 0;
}
