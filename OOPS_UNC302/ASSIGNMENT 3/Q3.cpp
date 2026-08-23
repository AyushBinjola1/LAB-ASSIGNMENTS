#include <iostream>
#include <iomanip>
using namespace std;

double itemCost(double price, int quantity);
double calculateBill(double c1, double c2, double c3);

int main() {

    double price1, price2, price3;
    int qty1, qty2, qty3;

    cout << "Enter price and quantity for item 1: "; cin >> price1 >> qty1;
    cout << "Enter price and quantity for item 2: "; cin >> price2 >> qty2;
    cout << "Enter price and quantity for item 3: "; cin >> price3 >> qty3;

    if (price1 < 0 || price2 < 0 || price3 < 0 || qty1 < 0 || qty2 < 0 || qty3 < 0) {
        cout << "Invalid input: price and quantity cannot be negative.\n";
        return 1;
    }


    double c1 = itemCost(price1, qty1);
    double c2 = itemCost(price2, qty2);
    double c3 = itemCost(price3, qty3);

    double gross = calculateBill(c1, c2, c3);
    double discount = gross > 5000.0 ? 0.10 * gross : 0.0;
    double payable = gross - discount;

    cout << fixed << setprecision(2);
    cout << "Item 1 Cost: Rs. " << c1 << "\n";
    cout << "Item 2 Cost: Rs. " << c2 << "\n";
    cout << "Item 3 Cost: Rs. " << c3 << "\n";
    cout << "Gross Bill: Rs. " << gross << "\n";
    cout << "Discount: Rs. " << discount << "\n";
    cout << "Final Payable Amount: Rs. " << payable << "\n";

}

 

double itemCost(double price, int quantity) { 
    return price * quantity;

}

double calculateBill(double c1, double c2, double c3) { 
    return c1 + c2 + c3;
}