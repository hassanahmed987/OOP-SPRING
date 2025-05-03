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
      
        
        if(type=="AutonomousCar"){
        	size_t pos=extraData.find(':');
        	if(pos!=string::npos){
        		string versionstr=extraData.substr(pos+1);
        		float version=stof(versionstr);
        	cout<<"software version is :"<<version<<endl;
			}
			else{
				cout<<": not found"<<endl;
			}
        
		}
        else if(type=="ElectricVehicle"){
        	size_t pos=extraData.find(':');
        	if(pos!=string::npos){
        		string batterystr=extraData.substr(pos+1);
        		float battery=stof(batterystr);
        		cout<<"battery is : "<<battery<<endl;
			}else{
				cout<<"not found"<<endl;
			}
		}
		else if(type=="HybridTruck"){
			size_t cargocolon=extraData.find(':');
			size_t pos=extraData.find('|');
			size_t batterycolon=extraData.rfind(':');
			if(cargocolon!=string::npos&&pos!=string::npos&&batterycolon!=string::npos){
				string cargostr=extraData.substr(cargocolon+1,pos-cargocolon-1);
				string Batterystr=extraData.substr(batterycolon+1);
				int cargo=stoi(cargostr);
				int Battery=stoi(Batterystr);
			    cout<<"cargo is : "<<cargo<<endl;
				cout<<"battery is : "<<Battery<<endl;
			}else{
				cout<<"not found"<<endl;
			}
		}
        
		else {
            cout << "Warning: Colon ':' not found in ExtraData for Vehicle ID: " << id << endl;
        }
	
    }

    in.close();
    return 0;
}
