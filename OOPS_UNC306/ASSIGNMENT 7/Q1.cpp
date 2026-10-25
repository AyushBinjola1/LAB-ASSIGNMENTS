#include <iostream>
#include <string>
using namespace std;
 
class Person {
protected:
    string name;
    int age;
};
 
class Student : public Person {
private:
    int rollNo;
public:
    void setDetails(string n, int a, int r) {
        name = n;      // protected member of Person, accessible here
        age = a;       // protected member of Person, accessible here
        rollNo = r;
    }
    void display() const {
        cout << "Name    : " << name << endl;
        cout << "Age     : " << age << endl;
        cout << "Roll No : " << rollNo << endl;
    }
};
 
int main() {
    Student s;
    s.setDetails("Ayush", 19, 1025150433);
    cout << "--- Student Information ---" << endl;
    s.display();
    // s.name = "X";   // ERROR: 'name' is protected
    // s.rollNo = 5;   // ERROR: 'rollNo' is private
    return 0;
}
