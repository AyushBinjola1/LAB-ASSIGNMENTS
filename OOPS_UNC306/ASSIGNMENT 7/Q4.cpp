#include <iostream>
#include <string>
using namespace std;
 
class Employee {
protected:
    string name;
};
 
class Developer : public Employee {
private:
    string programmingLanguage;
public:
    void setDetails(string n, string language) {
        name = n;
        programmingLanguage = language;
    }
    void display() const {
        cout << "Role     : Developer" << endl;
        cout << "Name     : " << name << endl;
        cout << "Language : " << programmingLanguage << endl;
    }
};
 
class Designer : public Employee {
private:
    string designTool;
public:
    void setDetails(string n, string tool) {
        name = n;
        designTool = tool;
    }
    void display() const {
        cout << "Role     : Designer" << endl;
        cout << "Name     : " << name << endl;
        cout << "Tool     : " << designTool << endl;
    }
};
 
int main() {
    Developer d;
    Designer g;
    d.setDetails("Ayush", "C++");
    g.setDetails("Akash", "Figma");
 
    d.display();
    cout << endl;
    g.display();
    return 0;
}
