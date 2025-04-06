#include <iostream>
#include<string>
using namespace std;
class car{
	string model;
	double price;
	public:
		car(string mo,double pri):model(mo),price(pri){
		}
		friend class managerinventory;
		friend void compareprice(car& c1,car& c2);
};
 void compareprice(car& c1,car& c2){
	if(c1.price>c2.price){
		cout<<"car "<<c1.model<<" is more expensive"<<endl;
	}
	else if(c2.price>c1.price) {
		cout<<"car "<<c2.model<< " is more expensive"<<endl;
	}
	else{
	cout<<"car "<<c2.model<< " is equally expensive to car "<<c1.model <<endl;
}
}
class managerinventory{
	public:
		void modify(double pri,car& c1){
			c1.price=pri;
		}
		void displaydetails(car& c1){
			cout<<"price: "<<c1.price<<endl;
			cout<<"model: "<<c1.model<<endl;
		}
};
int main(){
	managerinventory m;
	car c1("bmw",28000);
	car c2("audi",30000);
	m.displaydetails(c1);
	m.modify(40000,c1);
	m.displaydetails(c1);
	m.modify(50000,c2);
	m.modify(50000,c1);
	
	compareprice(c1,c2);
	
}
