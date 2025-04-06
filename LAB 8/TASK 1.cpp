#include <iostream>
#include<string>
#include<math.h>
using namespace std;
class complex{
		int real;
		int ima;
		public:
		
		complex(int re,int imag):real(re),ima(imag){
			}
			
		complex operator+(complex& num2){
			return complex (real+num2.real,ima+num2.ima);
		}
		
		complex operator-(complex& num2){
			return complex (real-num2.real,ima-num2.ima);
		}
		complex operator*(complex& num2){
			return complex (real*num2.real,ima*num2.ima);
		}
		complex operator/(complex& num2){
			return complex (real/num2.real,ima/num2.ima);
		}
		friend ostream& operator<<(ostream& out,complex &RESULT);
		friend void magnitude(complex& num);
	
	
};
	void magnitude(complex& num){
			cout<<"magnitude is: "<<sqrt(num.ima^2+num.real^2)<<endl;
		}
	ostream& operator<<(ostream& out,complex &RESULT){
			out<<RESULT.real<<"i, "<<RESULT.ima<<"j"<<endl;
			return out;
		}

int main(){
	complex c1(10,6),c2(2,3);
	complex plusresult=c1+c2;
	complex minusresult=c1-c2;
	complex multiplyresult=c1*c2;
	complex divideresult=c1/c2;

  cout << "Addition Result: " << plusresult;
    cout << "Subtraction Result: " << minusresult;
    cout << "Multiplication Result: " << multiplyresult;
    cout << "Division Result: " << divideresult;
	magnitude(c1);

}
