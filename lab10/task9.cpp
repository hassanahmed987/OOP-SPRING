#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("large_log.txt");
    out << "This is the first part of the log.\n";
    out << "This is the second part of the log.\n";
    out << "And the third part.\n";
    out.close();

    ifstream in("large_log.txt");

    if (!in) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char buffer1[11] = {0}; 
    in.read(buffer1, 10);
    cout << "First 10 characters: " << buffer1 << endl;
    cout << "Position after first read: " << in.tellg() << endl;

    char buffer2[11] = {0};
    in.read(buffer2, 10);
    cout << "Next 10 characters: " << buffer2 << endl;
    cout << "Position after second read: " << in.tellg() << endl;

    in.close();
    return 0;
}
