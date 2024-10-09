 
#ifndef USBCONNECTION_H  
#define USBCONNECTION_H  

#include <stack>  
#include <iostream>  

class USBConnection {
private:
    int ID;
    static std::stack<int> ids;  

    USBConnection(int id) : ID(id) {}

public:  
    static USBConnection* CreateUsbConnection() {
        if (ids.empty()) {
            std::cout << "No more USB ports available\n";
            return nullptr;
        } 
        int newId = ids.top();
        ids.pop();
        return new USBConnection(newId);
    }

    ~USBConnection() {
        ids.push(ID);
    }

    int get_id() const {
        return ID;
    }

    struct Initializer {
        Initializer() {
            if (ids.empty()) {
                ids = std::stack<int>({ 3, 2, 1 }); 
            }
        }
    };
    static Initializer initializer; 
};
 

#endif