#include <iostream>
#include <string>
using namespace std;
 
class Person {
protected:
    string name;
};
 
class Student : public Person {
protected:
    int rollNo;
};
 
class Employee : public Person {
protected:
    int employeeID;
};
 
class WorkingStudent : public Student, public Employee {
public:
    void setDetails(string n, int roll, int id) {
        Student::name = n;      // name via the Student path
        Employee::name = n;     // name via the Employee path (second Person copy)
        rollNo = roll;
        employeeID = id;
    }
    void display() const {
        cout << "Name (via Student)  : " << Student::name << endl;
        cout << "Name (via Employee) : " << Employee::name << endl;
        cout << "Roll No             : " << rollNo << endl;
        cout << "Employee ID         : " << employeeID << endl;
    }
};
 
int main() {
    WorkingStudent ws;
    ws.setDetails("Ayush", 1025150433, 5501);
    cout << "--- Working Student Details ---" << endl;
    ws.display();
    // cout << ws.name;   // ERROR: reference to 'name' is ambiguous
    return 0;
}
