#include<iostream>
#include <stdexcept>
#include <string>

using namespace std;



class databaseexception: public exception{
	public :
		string message;
		databaseexception(string me):message(me){
		}
		string what(){
			return message;
		}
};

class connectionfailedexception:public databaseexception{
	public:
	connectionfailedexception(string me):databaseexception(me){
	}
};

class querytimeoutexception:public databaseexception{
	public:
	querytimeoutexception(string me):databaseexception(me){
	}
	
};
template<typename t>
class databaseconnecter{
	public:
		t database;
		databaseconnecter(t database):database(database){
		}
		void connect(){
			if(database=="invalid_db"){
				throw connectionfailedexception("A database Error Occured");
			}
			else if(database=="slow_db"){
            throw querytimeoutexception("A database Error Occured");
        }
        else{
            cout<<"Database Connected"<<endl;
		}
	}
};
 int main(){
 	try{
 		databaseconnecter<string>db1("invalid_db");
 		cout<<"Attempting to invalid database"<<endl;
 		db1.connect();
	 }
	 catch(connectionfailedexception &e){
	 	cout<<"Caught Connection Failed Exception: "<<e.what()<<endl;
	 }
	   try{
            databaseconnecter<string>db2("slow_db");
            cout<<"Attempting to slow database"<<endl;
            db2.connect();
        }catch(querytimeoutexception &e){
            cout<<"Caught a general database Exception : "<<e.what()<<endl;
        }
        return 0;
 }


