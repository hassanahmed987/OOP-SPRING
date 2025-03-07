#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;

    Product() {}  

    Product(int prodId, string prodName, int prodQuantity) {
        id = prodId;
        name = prodName;
        quantity = prodQuantity;
    }

    void displayProduct() {
        cout << "ID: " << id << " | Name: " << name << " | Quantity: " << quantity << endl;
    }
};

class Warehouse {
private:
    Product* products; 
    int productCount;
    int capacity;

public:
    Warehouse(int maxProducts) {
        capacity = maxProducts;
        productCount = 0;
        products = new Product[capacity]; 
    }

    ~Warehouse() {
        delete[] products; 
    }

    void addProduct(int id, string name, int quantity) {
        if (productCount < capacity) {
            products[productCount] = Product(id, name, quantity);
            productCount++;
        } else {
            cout << "Warehouse inventory is full!" << endl;
        }
    }

    void sortProductsByName() {
        for (int i = 0; i < productCount - 1; i++) {
            for (int j = 0; j < productCount - i - 1; j++) {
                if (products[j].name > products[j + 1].name) {
                    swap(products[j], products[j + 1]);
                }
            }
        }
    }

    void searchProductById(int searchId) {
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == searchId) {
                cout << "Product Found: ";
                products[i].displayProduct();
                return;
            }
        }
        cout << "Product with ID " << searchId << " not found!" << endl;
    }

    void displayInventory() {
        cout << "Warehouse Inventory: " << endl;
        for (int i = 0; i < productCount; i++) {
            products[i].displayProduct();
        }
    }
};

int main() {
    Warehouse myWarehouse(5);

    myWarehouse.addProduct(101, "Table", 15);
    myWarehouse.addProduct(102, "Laptop", 5);
    myWarehouse.addProduct(103, "Apple", 50);
    myWarehouse.addProduct(104, "Chair", 20);

    cout << "\nBefore Sorting:" << endl;
    myWarehouse.displayInventory();

    myWarehouse.sortProductsByName();

    cout << "\nAfter Sorting by Name:" << endl;
    myWarehouse.displayInventory();

    cout << "\nSearching for Product with ID 102:" << endl;
    myWarehouse.searchProductById(102);

    return 0;
}
