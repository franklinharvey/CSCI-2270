#include <iostream>

using namespace std;
struct WeatherData{
    double temperature;
    double humidity;
    double windVelocity;
    bool sunny;
    WeatherData(double temp, double humid, double wind){
        temperature=temp;
        humidity=humid;
        windVelocity=wind;
        sunny=true;
    }
    WeatherData(){};
};
int main()
{
    WeatherData d1;
    cout<<d1.humidity<<endl;
    cout<<d1.temperature<<endl;
    cout<<d1.windVelocity<<endl;
    cout<<d1.sunny<<endl;



    WeatherData d2(20,30,50);
    cout<<d2.humidity<<endl;
    cout<<d2.temperature<<endl;
    cout<<d2.windVelocity<<endl;
    cout<<d2.sunny<<endl;

    WeatherData wdArray[10];
    for (int i=0; i<10; i++){
        cout<<"humidity:"<<wdArray[i].humidity<<" temp:"<<wdArray[i].temperature<<" wind:"<<wdArray[i].windVelocity<<endl;
    }

}
