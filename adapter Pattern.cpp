#include<bits/stdc++.h>
using namespace std;
//adapter pattern
class Server{ //adaptee json to xml
	public:
		string getXml() {
			return "aryan"; //xml
		}
};
//interface
class JsonInterface {
	public:
		virtual string convertToJson() =0; //pure virtual function
		
};
//concrete class
class JsonAdapter : public JsonInterface { //has-a relation with Weight class
	public:
		Server obj;
		string convertToJson() {
			return "name : "+obj.getXml(); //json format
		}
};


int main() { //client
	JsonAdapter *obj = new JsonAdapter();
	cout<<obj->convertToJson();
}