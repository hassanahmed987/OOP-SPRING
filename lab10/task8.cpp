#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("config.txt");
    outFile << "AAAAABBBBBCCCCC"; 
    outFile.close();

    fstream file("config.txt", ios::in | ios::out);
	if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    
    file.seekp(5, ios::beg);

    file << "XXXXX";

    file.close(); 

    ifstream inFile("config.txt");
    string contents;
    getline(inFile, contents);
    cout << "Updated file contents: " << contents << endl;
    inFile.close();

    return 0;
}
