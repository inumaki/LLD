#include<bits/stdc++.h>
using namespace std;

class Observer;
class Observable;

class ObservableInterface
{
public:
virtual void add(Observer obj)=0;
virtual void notify()=0;
virtual void setData()=0;
virtual string getData()=0;

};
class ObserverInterface
{
public:
	virtual void update()=0;
};
class Observer:public ObserverInterface
{
	Observable *obj;
public:
	Observer(Observable *obj)
	{
	this->obj = obj;
	}
	
	void update()
	{
	cout<<"Inside observer , temp is  = "<<this->obj->getData()<<endl;
cout<<"DS"<<endl;	
	}
};
class Observable : public ObservableInterface
{
vector<Observer>list;
int temp = 27;

public:
void add(Observer obj)
{
	list.push_back(obj);
}
void notify()
{
for(auto it:list)
it.update();
}
void setData()
{
	this->temp= 5;
	this->notify();
}
string getData()
{
	return this->temp+" C";
}
};


int main()
{
Observable obj;
Observer obj1( &obj);
Observer obj2(&obj);


obj.add(obj1);



obj.setData();
obj.setData();

}
