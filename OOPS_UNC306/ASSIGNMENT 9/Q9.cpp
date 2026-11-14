// Q9 - Class template with two type parameters
#include <iostream>
#include <typeinfo>
using namespace std;
 
template <typename CodeType, typename PriceType>
class StockEntry {
    CodeType code;
    PriceType price;
public:
    StockEntry(CodeType c, PriceType p) : code(c), price(p) {}
    void display() const {
        cout << "Code: " << code << "  Price: " << price << '\n';
    }
};
 
int main() {
    StockEntry<int, double> e1(1001, 249.50);
    StockEntry<char, int>   e2('A', 75);
    e1.display();
    e2.display();
    cout << "Same type? " << boolalpha
         << (typeid(e1) == typeid(e2)) << '\n';
    return 0;
}
