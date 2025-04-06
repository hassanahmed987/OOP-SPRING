#include <iostream>
#include<string>
#include<math.h>
using namespace std;
class vector2D{
	private:
		float x;
		float y;
	public:
		vector2D(float xx,float yy):x(xx),y(yy){
		}
		vector2D operator+(vector2D& v1){
		return vector2D(x+v1.x,y+v1.y);
		}
		vector2D operator-(vector2D& v1){
			return vector2D(x-v1.x,y-v1.y);
		}
	vector2D operator*(vector2D& v1){
			return vector2D(x*v1.x,y*v1.y);
		}
		friend ostream& operator<<(ostream& out,vector2D v1);
		 friend void dotproduct(vector2D& v1,vector2D& v2);
		
};
   ostream& operator<<(ostream& out,vector2D v1){
			out<<"vector = ("<<v1.x<<","<<v1.y<<")"<<endl;
			return out;
		}
    void dotproduct(vector2D& v1, vector2D& v2){
    float dotproduct =(v1.x*v2.x)+(v1.y*v2.y);
    cout<<"dotproduct: "<<dotproduct<<endl;
	}
	int main(){
		vector2D v1(5,10);
		vector2D v2(8,12);
	vector2D sumresult=	v1+v2;
	vector2D minusresult= v1-v2;
	vector2D multiplyresult= v1*v2;
	cout<<sumresult;
	cout<<minusresult;
	cout<<multiplyresult;
		dotproduct(v1,v2);
	}
