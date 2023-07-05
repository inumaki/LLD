#include<bits/stdc++.h>
using namespace std;
class Drive
{
	public:	
	virtual string getDrive()=0;
};
class OffRoad: public Drive
{
	public:
		string getDrive()
		{
			return "You are driving off road vehicle";
		}
};
class Economy:public Drive
{
	public:
		string getDrive()
		{
			return "You are driving economy vehicle";
		}
};
class Car
{
	Drive *obj;
	public:	
	Car(Drive *obj)
{
	this->obj= obj;
}
	string getDrive()
	{
	return this->obj->getDrive();
	}
	
};
int main()
{
	Car swift(new Economy);
cout<<swift.getDrive();
	cout<<"\n";
	Car hummer(new OffRoad);
	cout<<hummer.getDrive();	
}