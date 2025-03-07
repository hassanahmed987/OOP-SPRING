#include <iostream>
using namespace std;

class Device {
public:
    int deviceID;
    bool status;

    Device(int id, bool stat) {
        deviceID = id;
        status = stat;
    }

    void displayDetails() {
        cout << "Device ID: " << deviceID << ", Status: ";
        if (status) {
            cout << "On" << endl;
        } else {
            cout << "Off" << endl;
        }
    }
};

class SmartPhone : public Device {
public:
    float screenSize;

    SmartPhone(int id, bool stat, float size) : Device(id, stat) {
        screenSize = size;
    }

    void displayDetails() {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : public Device {
public:
    bool heartRateMonitor;

    SmartWatch(int id, bool stat, bool hrm) : Device(id, stat) {
        heartRateMonitor = hrm;
    }

    void displayDetails() {
        Device::displayDetails();
        cout << "Heart Rate Monitor: ";
        if (heartRateMonitor) {
            cout << "Enabled" << endl;
        } else {
            cout << "Disabled" << endl;
        }
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
public:
    int stepCounter;

    SmartWearable(int id, bool stat, float size, bool hrm, int steps) 
        : SmartPhone(id, stat, size), SmartWatch(id, stat, hrm) {
        stepCounter = steps;
    }

    void displayDetails() {
        cout << "Smart Wearable Device Details:" << endl;
        SmartPhone::displayDetails();
        cout << "Heart Rate Monitor: ";
        if (heartRateMonitor) {
            cout << "Enabled" << endl;
        } else {
            cout << "Disabled" << endl;
        }
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    SmartWearable wearable(101, true, 5.5, true, 12000);
    wearable.displayDetails();
    return 0;
}

