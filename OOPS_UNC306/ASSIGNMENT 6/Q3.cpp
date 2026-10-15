#include <iostream>
#include <string>
using namespace std;
 
class Employee {
private:
    string name;
    float salary;
public:
    Employee(string n, float s) : name(n), salary(s) {}
    void setName(const string &n) { name = n; }
    void setSalary(float s) { salary = s; }
    void display() const {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};
 
void checkPointer(Employee *emp) {
    if (emp == nullptr) {
        cout << "Pointer is NULL - cannot access employee." << endl;
        return;
    }
    cout << "Pointer is valid. Original data: ";
    emp->display();
    emp->setName("Ayush Binjola");
    emp->setSalary(55000.0f);
    cout << "Updated data:                    ";
    emp->display();
}
 
int main() {
    Employee *ptr = nullptr;
    cout << "Call 1 (nullptr):" << endl;
    checkPointer(ptr);
 
    Employee e("Ayush", 40000.0f);
    ptr = &e;
    cout << "\nCall 2 (valid object):" << endl;
    checkPointer(ptr);
    return 0;
}
