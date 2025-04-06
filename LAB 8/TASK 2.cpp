#include <iostream>
#include<string>
#include<math.h>
using namespace std;
class account{
	int accountnumber;
	float balance;
	public:
		account(int number,float bal):accountnumber(number),balance(bal){
		}
friend void transferfunds(float num,account& a1,account& a2);
friend class manager;		
};
void transferfunds(float num,account& a1,account& a2){
	if(a1.balance>num){
		a1.balance-=num;
		a2.balance+=num;
	}
	else{
		cout<<"insuffiecnt funds"<<endl;
	}
}
class manager{
	public:
	void displaydetails(account& a){
			cout<<"account number: "<<a.accountnumber<<"\nbalance: "<<a.balance<<endl;
		}
	void addbalance(float num,account& a){
		a.balance+=num;
	}
	void withdraw(float num,account& a){
		a.balance-=num;
	}
};
int main(){
	manager m;
	account a1(1,10000);
	account a2(2,10000);
	m.addbalance(100,a1);
	m.withdraw(100,a1);
	transferfunds(500,a1,a2);
	m.displaydetails(a1);
	m.displaydetails(a2);

}
