#include<iostream>
using namespace std;
class weathersensor{
	public:
		void virtual readdata()=0;
		void virtual displayreport()=0;
		
};
class thermometer :public weathersensor{
	float temp;
	public:
		void readdata(){
			temp=135.5;
			cout<<"Reading data of the thermometer"<<endl;
		}
		void displayreport(){
			cout<<"temrature is " << temp << "C"<<endl;
		}
		
};
class barometer :public weathersensor{
	float pressure;
		public:
		void readdata(){
			pressure=313;
			cout<<"Reading data of the barometer"<<endl;
		}
		void displayreport(){
			cout<<"pressure is "<<pressure <<  "pascals"<<endl;
		}
};
int main(){
	barometer b;
	thermometer t;
	weathersensor * w1=&b;
	weathersensor * w2=&t;
	w1->readdata();
	w1->displayreport();
	w2->readdata();
	w2->displayreport();
}
