#include <iostream>
#include <string>

class ConfigurationManager {
private:
    static ConfigurationManager* instance;
    std::string currentTheme;

    ConfigurationManager() {
        this->currentTheme = "light";
    }

public:
    ConfigurationManager(const ConfigurationManager&) = delete; // To prevent shallow copy

    static ConfigurationManager* Get() {
        if (!instance) {
            instance = new ConfigurationManager();
        }
        return instance;
    }

    void getTheme() {
        std::cout << this->currentTheme << std::endl;
    }

    void updateTheme() {
        if (this->currentTheme == "dark")
            this->currentTheme = "light";
        else
            this->currentTheme = "dark";
    }
};

// Initialize the static member instance to nullptr
ConfigurationManager* ConfigurationManager::instance = nullptr;

int main() {
    ConfigurationManager* obj = ConfigurationManager::Get();
    obj->getTheme();
    obj->updateTheme();
    ConfigurationManager* obj1 = ConfigurationManager::Get();
    obj1->getTheme();

    // Clean up memory (optional, as it will be released when the program ends)
    delete obj;

    return 0;
}
