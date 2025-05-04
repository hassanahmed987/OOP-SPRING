#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("sensor_log.txt");

    if (!out) {
        cout << "Error opening file for writing.\n";
        return 1;
    }

    out << "Sensor1: 23.5C\n";
    streampos pos1 = out.tellp();
    cout << "After writing first line, position is: " << pos1 << endl;

    out << "Sensor2: 24.1C\n";
    streampos pos2 = out.tellp();
    cout << "After writing second line, position is: " << pos2 << endl;

    out << "Sensor3: 22.8C\n";
    streampos pos3 = out.tellp();
    cout << "After writing third line, position is: " << pos3 << endl;

    out.close();
    return 0;
}
