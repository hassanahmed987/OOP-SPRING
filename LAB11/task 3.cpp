#include<iostream>
#include <stdexcept>
using namespace std;


class TemperatureException:public exception{


};

template<typename T>
class Temperature{
private:
 T celcius;
 public:
 Temperature(T celcius):celcius(celcius){}

 void convert(){
    if(celcius< (-273.15)){
        throw TemperatureException();
    }
    T farhen=(celcius*1.8)+32;
    cout<<"Farheniet Value is "<<farhen<<endl;
 }
};

int main(){
    try{
        cout<<"Attempting to Conver 12"<<endl;
        Temperature<int> T1(12);
        T1.convert();
        cout<<"Attempting to Conver -280"<<endl;
        Temperature<double> T2(-280);
        T2.convert();
    }catch(TemperatureException &e){
        cout<<"Caught Exception: "<<e.what()<<endl;
    }
    return 0;
}
