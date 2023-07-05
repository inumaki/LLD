#include<bits/stdc++.h>
using namespace std;

class Pizza
{
	public:
virtual int cost()=0;
};
class VegDelight: public Pizza
{
	public:
		int cost()
		{
			return 150;
		}
};
class margherita: public Pizza
{
	public:
		int cost()
		{
			return 100;}
};
class Topping:public Pizza {
};
class Mushroom : public Topping{
	
	Pizza *obj;
	public:
		Mushroom(Pizza *obj)
		{
			this->obj = obj;
		}
		int cost(){
		 return this->obj->cost()+10;
		 }
			
	
};

class Cheese : public Topping {	
	
	Pizza *obj;
	public:
		Cheese(Pizza *obj)
		{
			this->obj = obj;
		}
		int cost(){
			 return this->obj->cost()+20;
		 }
	
};
int main()
{

Cheese obj( &(VegDelight veg));
Mushroom mobj(&obj);
cout<<mobj.cost();

}
