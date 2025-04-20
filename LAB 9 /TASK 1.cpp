#include<iostream>
using namespace std;
class patient{
	protected:
		string name;
		string id;
	public:
		patient(string na,string i):name(na),id(i){
		}
		virtual void displaytreatment()=0;
		virtual void calculatecost()=0;
};
class inpatient: public patient{
	public:
		inpatient(string na,string i):patient(na,i){
		}
		void displaytreatment(){
			cout<<"This is inpatient named "<<name<<" with id "<<id<<endl;
		}
		void calculatecost(){
			cout<<"The cost is 20000$"<<endl;
		}
};
class outpatient: public patient{
	public:
		outpatient(string na,string i):patient(na,i){
		}
		void displaytreatment(){
			cout<<"This is outpatient named "<<name<<" with id "<<id<<endl;
		}
		void calculatecost(){
			cout<<"The cost is 45000$"<<endl;
		}
		
};
int main(){
	inpatient ip("hassan","1234");
	outpatient op("faaiz","4321");
	patient* p1=&ip;
	patient* p2=&op;
	p1->displaytreatment();
	p1->calculatecost();
	p2->displaytreatment();
	p2->calculatecost();
	
}
