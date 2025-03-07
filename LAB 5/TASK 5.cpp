#include<iostream>
#include<string>
using namespace std;

class doctors{
	string name;
	string specialization;
	int experience;
	public:
		doctors() {}
		doctors(string names,string work,int years):name(names),specialization(work),experience(years){}
	void display(){
		cout<<"name: "<<name<<"specialization: "<<specialization<<"work experience: "<< experience<<endl;
	}
};
class hospital{
	doctors* doctor;
	int doctorcount;
	int maxdoctors;
	public:
	string hospitalname;
		hospital(string name,int capacity):hospitalname(name),maxdoctors(capacity),doctorcount(0){
		doctor= new doctors[maxdoctors];
		}
		void adddoctor(string name, string specialization, int experience){
			if(doctorcount<maxdoctors){
				doctor[doctorcount]=doctors(name, specialization, experience);
				doctorcount++;
			}
			else{
				cout<<"no more space for doctors"<<endl;
			}
		}
		 void displaydetails() {
        cout << "Hospital Name: " << hospitalname << endl;
        for (int i = 0; i < doctorcount; i++) { 
            cout << "Doctor " << i + 1 << " working in the hospital: ";
            doctor[i].display();
        }
    }
};
int main(){
	hospital hos("aga khan",10);
	hos.adddoctor("hassan","cardio",15);
	hos.displaydetails();
	
}
