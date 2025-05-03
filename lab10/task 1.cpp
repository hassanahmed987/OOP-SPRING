#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream in("vehicles.txt");

    if (!in) {
        cout << "ERROR: Could not open vehicles.txt file" << endl;
        return 1;
    }

    string line;
    while (getline(in, line)) {
        if (line.empty() || line.substr(0, 2) == "//")
            continue; 
        cout << line << endl;
    }

    in.close();
    return 0;
}
