#include<bits/stdc++.h>
using namespace std;

class ConfigurationManager {
	
	private:
	static ConfigurationManager instance;
	string currentTheme;

	public:
	ConfigurationManager() {
	this->currentTheme = "light";	
	}	
	
	ConfigurationManager(ConfigurationManager &obj) = delete; // to ensure that shallow copy is not created.
	
	static ConfigurationManager& Get() {
		return instance;
	}
	
	void getTheme() {
		cout<<this->currentTheme<<endl;
	}
	void updateTheme() {
		if(this->currentTheme == "dark")
			this->currentTheme = 'light';
		else
			this->currentTheme = "dark";
	}		
};

ConfigurationManager ConfigurationManager::instance; // not need to deal with null ,since references can't be null

int main() {
	
	ConfigurationManager &obj = ConfigurationManager::Get();
	obj.getTheme();
	obj.updateTheme();
	ConfigurationManager &obj1 = ConfigurationManager::Get();
	obj1.getTheme();

}