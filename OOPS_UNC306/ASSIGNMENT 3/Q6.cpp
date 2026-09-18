#include <iostream>
using namespace std;
 
#define BONUS(s) ((s) * 0.10)
#define TAX(s)   ((s) * 0.05)
 
double calculateBonus(double salary);
double calculateTax(double salary);
 
int main() {
    double basicSalary;
    cout << "Enter basic salary: ";
    cin >> basicSalary;
 
    // ---- Macro-based ----
    double macroBonus = BONUS(basicSalary);
    double macroTax = TAX(basicSalary);
    double macroNet = basicSalary + macroBonus - macroTax;
 
    // ---- Function-based ----
    double funcBonus = calculateBonus(basicSalary);
    double funcTax = calculateTax(basicSalary);
    double funcNet = basicSalary + funcBonus - funcTax;
 
    cout << "\n--- Macro-based Result ---\n";
    cout << "Bonus: " << macroBonus << ", Tax: " << macroTax
         << ", Net Salary: " << macroNet << endl;
 
    cout << "\n--- Function-based Result ---\n";
    cout << "Bonus: " << funcBonus << ", Tax: " << funcTax
         << ", Net Salary: " << funcNet << endl;
 
    // test macro with an arithmetic expression to show why parentheses matter
    double a = 40000, b = 10000;
    cout << "\nBONUS(a + b) = " << BONUS(a + b)
         << "  (correct only because the macro body/parameters use parentheses)\n";
 
    return 0;
}
 
double calculateBonus(double salary) {
    return salary * 0.10;
}
 
double calculateTax(double salary) {
    return salary * 0.05;
}
