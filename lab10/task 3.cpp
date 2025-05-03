#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
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
       istringstream ss(line);
       string type,id, name, yearstr, extraData, certification;
       getline(ss,type,',');
       getline(ss,id,',');
       getline(ss,name,',');
       getline(ss,yearstr,',');
       getline(ss,extraData,',');
       getline(ss,certification,',');
       
       int year = stoi(yearstr);
       
        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "ExtraData: " << extraData << endl;
        cout << "Certification: " << certification << endl;

    }

    in.close();
    return 0;
}
