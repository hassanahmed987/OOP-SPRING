#include<iostream>
using namespace std;
class menuitem{
	protected:
		string dishname;
		double price;
	public:
		menuitem(string na,double pri):dishname(na),price(pri){
		}
		virtual void showdetails()=0;
		virtual void prepare()=0;
};
class appetizer: public menuitem{
	public:
		appetizer(string na,double pri):menuitem(na,pri){
		}
		void showdetails(){
			cout<<"appetizer dishname: "<<dishname<<"\nwith price: "<<price<<endl;
		}
		void prepare(){
			cout<<"appetizer "<<dishname<<" is to prepared"<<endl;
		}
};
class maincourse: public menuitem{
	public:
		maincourse(string na,double pri):menuitem(na,pri){
		}
		void showdetails(){
			cout<<"main dishname: "<<dishname<<"\nwith price: "<<price<<endl;
		}
		void prepare(){
			cout<<"main "<<dishname<<" is to prepared"<<endl;
		}
		
};
int main(){
appetizer ap("wings",1299.5);
maincourse ma("biryani",1545.8);

menuitem* d1=&ap;
menuitem* d2=&ma;
d1->showdetails();
d1->prepare();
d2->showdetails();
d2->prepare();

}
