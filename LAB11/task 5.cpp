#include <iostream>
#include <exception>

using namespace std;

class NegativeStockException : public exception { };

class OverCapacityException : public exception { };

template<typename T>
class InventoryItem {
public:
    InventoryItem(T sto, T ma)
      : stock(sto), max(ma)
    {
        if (stock < T(0))
            throw NegativeStockException();
        if (stock > max)
            throw OverCapacityException();
    }

private:
    T stock;
    T max;
};

int main() {
    cout << "Attempting to set stock to -5..." << endl;
    try {
        InventoryItem<int> itemNeg(-5, 100);
    }
    catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException" << endl;
        cout << "-" << endl;
        cout << "what(): " << e.what() << endl;
    }

    cout << "Attempting to set stock to 120 (max 100)..." << endl;
    try {
        InventoryItem<int> itemOver(120, 100);
    }
    catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException" << endl;
        cout << "-" << endl;
        cout << "what(): " << e.what() << endl;
    }

    return 0;
}
