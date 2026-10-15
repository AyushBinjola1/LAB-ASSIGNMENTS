#include <iostream>
#include <string>
using namespace std;
 
class Employee {
private:
    string name;
    float salary;
public:
    Employee(string n, float s) : name(n), salary(s) {}
    void setSalary(float s) { salary = s; }
    string getName() const { return name; }
    float getSalary() const { return salary; }
    void display() const {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};
 
void updateSalary(Employee *emp, float newSalary) {
    if (emp != nullptr)
        emp->setSalary(newSalary);
}
 
int main() {
    // Object on the stack
    Employee e1("Ayush", 45000.0f);
    Employee *ptr = &e1;               // pointer stores address of e1
 
    cout << "--- Stack object via pointer ---" << endl;
    cout << "Before update: ";
    ptr->display();                    // -> operator
    cout << "Same call using (*ptr): ";
    (*ptr).display();                  // equivalent form
 
    updateSalary(ptr, 52000.5f);
    cout << "After update:  ";
    ptr->display();
 
    // Object on the heap
    Employee *dyn = new Employee("Riya", 60000.0f);
    cout << "\n--- Dynamic object via pointer ---" << endl;
    cout << "Before update: ";
    dyn->display();
    updateSalary(dyn, 65000.0f);
    cout << "After update:  ";
    dyn->display();
 
    delete dyn;        // release heap memory
    dyn = nullptr;     // avoid dangling pointer
    cout << "\nDynamic object deleted, pointer reset to nullptr." << endl;
    return 0;
}
