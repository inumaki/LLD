#include<bits/stdc++.h>
using namespace std;
class Vehicle { //abstract
	
	public:
		virtual int getSeats() =0; //virtual function
		 //virtual  
//		virtual int getAirBags() = 0;

};
class Car : public Vehicle
{
	public:
		int getSeats() {
			return 5;
		}
		int getAirBags() {
			return 2;
		}
		
};
class NullVehicle : public Vehicle //either return nothing or default values
{
	public:
		int getSeats() {
			return 0;
		}
		int getAirBags() {
			return 0;
		}
		
};
//factory pattern

class VehicleFactory {
	public:
	Vehicle* getObject(string str) {
		
		if(str=="car")
			return new Car();
		else
			return new NullVehicle();
	}	
};
//client site
int main()
{
Vehicle *obj = new Vehicle(); //parent 
obj = new Car();

cout<<obj->getSeats();	
	
//VehicleFactory *obj = new VehicleFactory();
//auto objV = obj->getObject("car");
//cout<<objV->getSeats();
}

// How are you going to handle null values



