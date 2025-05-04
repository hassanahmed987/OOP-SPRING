#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem {
private:
    int itemID;
    char itemName[20];

public:
    InventoryItem(int id,  char* name) {
        itemID = id;
        strcpy(itemName, name);  
    }

    InventoryItem() : itemID(0) {
        itemName[0] = '\0';  
    }

    void displayItem() const {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
    }


};

int main() {
    InventoryItem item1(1234, "Rice");
        ofstream out("inventory.dat", ios::binary);     
        out.write((char*)&item1,sizeof(item1));
        out.close();

    InventoryItem item2;
    ifstream in("inventory.dat",ios::binary);
    in.read((char*)&item2,sizeof(item2));
    in.close();

    cout << "Loaded item from file:\n";
    item2.displayItem();  

    return 0;
}
