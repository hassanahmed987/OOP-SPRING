#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(string id, string name, string loc = "Unknown") : deviceID(id), deviceName(name), location(loc), status(false) {}
    
     void turnOn() { status = true; }
     void turnOff() { status = false; }
     string getStatus() const { return status ? "On" : "Off"; }
     void displayInfo() const {
        cout << "Device ID: " << deviceID << "\nDevice Name: " << deviceName
             << "\nStatus: " << getStatus() << "\nLocation: " << location << endl;
    }
};

class Light : public Device {
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(string id, string name, string loc, int brightness, string color)
        : Device(id, name, loc), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo(){
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << "\nColor Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
private:
    float temperature;
    string mode;
    float targetTemperature;

public:
    Thermostat(string id, string name, string loc, float temp, string mode, float target)
        : Device(id, name, loc), temperature(temp), mode(mode), targetTemperature(target) {}

    string getStatus(){
       cout<<"current temp : "<<temperature<<endl;
    }
};

class SecurityCamera : public Device {
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(string id, string name, string loc, string res, bool nightVision)
        : Device(id, name, loc), resolution(res), nightVisionEnabled(nightVision), recordingStatus(false) {}

    void turnOn() {
        status = true;
        recordingStatus = true;
        cout << "Security Camera is now recording." << endl;
    }
};

class SmartPlug : public Device {
private:
    float powerConsumption;
    int timerSetting;

public:
    SmartPlug(string id, string name, string loc, float power, int timer)
        : Device(id, name, loc), powerConsumption(power), timerSetting(timer) {}

    void turnOff() {
        cout << "Power consumed before shutdown: " << powerConsumption << " kWh" << endl;
        status = false;
    }
};

int main() {
    Light livingRoomLight("L001", "Living Room Light", "Living Room", 75, "Warm White");
    Thermostat homeThermostat("T001", "Home Thermostat", "Hallway", 22.5, "Cooling", 24.0);
    SecurityCamera frontDoorCamera("C001", "Front Door Camera", "Entrance", "1080p", true);
    SmartPlug kitchenPlug("P001", "Kitchen Plug", "Kitchen", 1.2, 30);

    livingRoomLight.displayInfo();
    cout << endl;

    cout << homeThermostat.getStatus() << endl;
    cout << endl;

    frontDoorCamera.turnOn();
    cout << endl;
    
    kitchenPlug.turnOff();
    cout << endl;

    return 0;
}
