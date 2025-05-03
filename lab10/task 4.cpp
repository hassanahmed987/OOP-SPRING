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
       string type,id, name, year, extraData, certification;
       getline(ss,type,',');
       getline(ss,id,',');
       getline(ss,name,',');
       getline(ss,year,',');
       getline(ss,extraData,',');
       getline(ss,certification,',');
      
        
        size_t pos=extraData.find(':');
        if(pos!=string::npos){
        	string value=extraData.substr(pos+1);
        	
        		if(type=="AutonomousCar"){
			float softwareversion=stof(value);
			 cout << "Software Version (float): " << softwareversion
                     << " for Vehicle ID: " << id << endl;
		}
		else if(type=="ElectricVehicle"){
			float batterycapacity=stof(value);
			 cout << "batterycapacity: " << batterycapacity
                     << " for Vehicle ID: " << id << endl;
		}

		}
		else {
            cout << "Warning: Colon ':' not found in ExtraData for Vehicle ID: " << id << endl;
        }
	
    }

    in.close();
    return 0;
}
