#include <iostream>
using namespace std;

class ticket{
	protected:
	int ticketid;
	string passangername;
	float price;
	string date;
	string destination;
	public:
		ticket(int id,string name,float pri,string dat,string des)
		:ticketid(id),passangername(name),price(pri),date(dat),destination(des){}
	void reserve(){
	 cout << "Ticket reserved for " << passangername << " on " << date << " to " << destination << "\n";
	}
	void cancel(){
		cout << "Ticket " << ticketid << " canceled.\n";
	}
	void displayticketinfo(){
		cout<< "ticket ID: "<<ticketid<<"\npassanger name: "<<passangername<<"\nprice: "<<price<<"\ndate: "<<date<<"\ndestination: "<<destination<<endl;     
	}
};
class flightticket :public ticket{
	string 	airlinename;
	int flightnumber;
	string seatclass;
	public:
		flightticket(string air,int num,string cla,int id,string name,float pri,string dat,string des)
		:airlinename(air),flightnumber(num),seatclass(cla),ticket(id,name,pri,dat,des){}
		void displayticketinfo(){
			ticket:: displayticketinfo();
			cout<<"airline name: "<<airlinename<<"\nfight number: "<<flightnumber<<"\nseat class: "<<seatclass<<endl;
		}
		
};
class trainticket : public ticket{
	int trainnumber;
	string coachtype;
	string departuretime;
	public:
		trainticket(int tr,string coach,string de,int id,string name,float pri,string dat,string des)
		:trainnumber(tr),coachtype(coach),departuretime(de),ticket(id,name,pri,dat,des){
			}
		void reserve(){
		cout << "Train Ticket Reserved: Auto-assigning seat for " << passangername << "\n";
		}
		
};
class busticket : public ticket{
	string buscompany;
	int seatnumber;
	public:
		busticket(string bus,int sea,int id,string name,float pri,string dat,string des)
		:buscompany(bus),seatnumber(sea),ticket(id,name,pri,dat,des){}
		void cancel(){
			cout << "Bus Ticket " << ticketid << " canceled. Eligible for last-minute refund.\n";
		}
	
};
class concertticket :public ticket{
	string artistname;
	string venue;
	string seattype;
	public:
		concertticket(string ar,string ve,string pe,int id,string name,float pri,string dat,string des)
		:artistname(ar),venue(ve),seattype(pe),ticket(id,name,pri,dat,des){}
	void displayticketinfo(){
		ticket :: displayticketinfo();
		cout<<"artist name: "<<artistname<<"\nvenue: "<<venue<<"\nseattype: "<<seattype<<endl;
	}
};
int  main(){
	flightticket flight("jinnah airways",29345,"first class",12093,"Hassan",10000.0,"19-08-25","dubai");
	trainticket train(7856, "Sleeper", "10:30 AM", 22045, "Ali", 5000.0, "20-08-25", "Karachi");
    busticket bus("Green Line", 12, 33067, "Ahmed", 1500.0, "21-08-25", "Lahore");
    concertticket concert("Atif Aslam", "National Stadium", "VIP", 44078, "Sara", 3000.0, "22-08-25", "Islamabad");

    flight.displayticketinfo();
    cout << "\n";
    train.displayticketinfo();
    cout << "\n";
    bus.displayticketinfo();
    cout << "\n";
    concert.displayticketinfo();
}

