#include<bits/stdc++.h>
using namespace std;
class Interface
{
	public:
		virtual void next(int log, string message)=0;
};
class AbstractHandler:public Interface 
{
	public:
		
	int DEBUG = 1;
	int INFO = 2;
	int ERROR = 3;
	
	Interface *nextObject;
	
		AbstractHandler(Interface *nextObject)
	 	{
			 this->nextObject = nextObject;
		}
		void next(int log, string message) 
		{	
			if(this->nextObject)
				return this->nextObject->next(log, message);
		}
};
class DebugHandler : public AbstractHandler
{
	public:
		DebugHandler(Interface* nextObject) : AbstractHandler(nextObject)
		{
			
		}
		void next(int log, string message)
		{	
			if(log == this->DEBUG)
				cout<<"Log level is DEBUG and message is = "<<message<<endl;
			else
				AbstractHandler::next(log,message);
		}
};
class InfoHandler : public AbstractHandler
{
	public:
		InfoHandler(Interface* nextObject) : AbstractHandler(nextObject)
		{
			
		}
		void next(int log, string message)
		{		
			if(log == this->INFO)
				cout<<"Log level is INFO and message is = "<<message<<endl;
			else
				AbstractHandler::next(log,message);
		}
};
class ErrorHandler : public AbstractHandler
{
	public:
		ErrorHandler(Interface* nextObject) : AbstractHandler(nextObject)
		{
			
		}
		void next(int log, string message)
		{		
			if(log == this->ERROR)
				cout<<"Log level is ERROR and message is = "<<message<<endl;
			else
				AbstractHandler::next(log,message);
		}
};

int main()
{
	Interface *obj = new InfoHandler(new ErrorHandler(new DebugHandler(NULL)));
	obj->next(4,"Api has been hit successfully");
}