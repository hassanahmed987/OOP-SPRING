#include<iostream>
using namespace std;
class shipment{
protected:
	string trackingnumber;
	double weight;
	public:
		shipment(string num,double kg):trackingnumber(num),weight(kg){
		}
		void virtual estimatedeliverlytime()=0;
		void virtual showdetails()=0;
};
class airfreight :public shipment{
public:
	airfreight(string num,double kg):shipment(num,kg){
	}
	void estimatedeliverlytime(){
		cout<<"estimating air deliverly time"<<endl;
	}
	void showdetails(){
		cout<<"air tracking number : "<<trackingnumber<<"\nweight: "<<weight<<endl;
	}
		
};
class groundshipment :public shipment{
public:
	groundshipment(string num,double kg):shipment(num,kg){
	}
	void estimatedeliverlytime(){
		cout<<"estimating ground deliverly time"<<endl;
	}
	void showdetails(){
		cout<<"ground tracking number : "<<trackingnumber<<"\nweight: "<<weight<<endl;
	}
};
int main(){
groundshipment ground("1234",59.4);
airfreight air("4321",122);
shipment* s1=&ground;
shipment* s2=&air;
s1->estimatedeliverlytime();
s1->showdetails();
s2->estimatedeliverlytime();
s2->showdetails();

}
