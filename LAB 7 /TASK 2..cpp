#include <iostream>
using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double p, int stock = 0)
        : productID(id), productName(name), price(p), stockQuantity(stock) {}

    void applyDiscount(double discount) {
        price -= price * (discount / 100);
    }

    void displayProductInfo() {
        cout << "Product ID: " << productID << "\nName: " << productName << "\nPrice: " << price << "\nStock: " << stockQuantity << "\n";
    }

    double calculateTotalPrice(int quantity) {
        return price * quantity;
    }

    friend ostream& operator<<(ostream& os, Product& p) {
        p.displayProductInfo();
        return os;
    }

    Product operator+(Product& other) {
        return Product(0, "Bulk Purchase", this->price + other.price);
    }
};

class Electronics : public Product {
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double p, int stock, int warranty, string br)
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(br) {}

    void displayProductInfo() {
        Product::displayProductInfo();
        cout << "Brand: " << brand << "\nWarranty: " << warrantyPeriod << " years\n";
    }
};

class Clothing : public Product {
    string size, color, fabricMaterial;

public:
    Clothing(int id, string name, double p, int stock, string s, string c, string fabric)
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(fabric) {}

    void applyDiscount(double discount) {
        if (discount > 50) discount = 50;
        price -= price * (discount / 100);
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double p, int stock, string exp, int cal)
        : Product(id, name, p, stock), expirationDate(exp), calories(cal) {}

    double calculateTotalPrice(int quantity) {
        double total = Product::calculateTotalPrice(quantity);
        if (quantity > 10) total *= 0.9;
        return total;
    }
};

class Book : public Product {
    string author, genre;

public:
    Book(int id, string name, double p, int stock, string a, string g)
        : Product(id, name, p, stock), author(a), genre(g) {}

    void displayProductInfo()  {
        Product::displayProductInfo();
        cout << "Author: " << author << "\nGenre: " << genre << "\n";
    }
};

int main() {
    Electronics laptop(101, "Laptop", 1200.0, 10, 2, "Dell");
    Clothing tshirt(201, "T-Shirt", 20.0, 50, "M", "Red", "Cotton");
    FoodItem apple(301, "Apple", 2.0, 100, "2025-06-01", 50);
    Book novel(401, "oliver twist", 40.0, 30, "charles dickens", "realistic");
    
    cout << laptop << endl;
    cout << tshirt << endl;
    cout << apple << endl;
    cout << novel << endl;
    
    tshirt.applyDiscount(60); // Testing max discount cap
    cout << "Discounted T-Shirt Price: " << tshirt << endl;
    
    cout << "Total Price for 15 Apples: " << apple.calculateTotalPrice(15) << "\n";
    
    Product bulkPurchase = laptop + tshirt;
    cout << bulkPurchase << endl;
    
    return 0;
}
