#include <iostream>
#include <string>
using namespace std;

class AlarmSystem {
public:
    string securityLevel;

    AlarmSystem(string level) {
        securityLevel = level;
    }

    void displayAlarmDetails() {
        cout << "Alarm System Security Level: " << securityLevel << endl;
    }
};

class SmartHome {
private:
    AlarmSystem* alarm; 

public:
    string homeName;

    SmartHome(string name, string securityLevel) {
        homeName = name;
        alarm = new AlarmSystem(securityLevel);
    }

    ~SmartHome() {
        delete alarm; 
    }

    void displayHomeDetails() {
        cout << "Smart Home: " << homeName << endl;
        alarm->displayAlarmDetails();
    }
};

int main() {
    SmartHome myHome("modren mansion", "High");
    myHome.displayHomeDetails();

    return 0;
}
