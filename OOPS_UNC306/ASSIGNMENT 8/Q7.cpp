#include <iostream>
using namespace std;
 
class Vault;                                   // forward declaration
 
//X virtual void globalAudit();                // virtual only allowed for member functions
 
class Auditor {
public:
    virtual void inspect(const Vault& v);      // virtual member function
    static void notice() {                     // ordinary static member function
        cout << "Auditor::notice() - static member function" << endl;
    }
    virtual ~Auditor() = default;              // destructors may be virtual
    //X virtual static void helper();          // a member cannot be virtual and static
    //X virtual Auditor(int);                  // constructors cannot be virtual
};
 
class Vault {
    int accessCode = 7482;
    friend void Auditor::inspect(const Vault&);   // only this member is a friend
};
 
void Auditor::inspect(const Vault& v) {
    cout << "Auditor::inspect() reads accessCode = " << v.accessCode << endl;
}
 
class SeniorAuditor : public Auditor {
public:
    void inspect(const Vault& v) override {
        cout << "SeniorAuditor::inspect() - extended inspection" << endl;
        //X cout << v.accessCode;                  // friendship is not inherited
        Auditor::inspect(v);                       // delegate to the friend function
    }
};
 
int main() {
    Vault vault;
    Auditor a;
    SeniorAuditor s;
 
    Auditor* list[] = { &a, &s };
    for (Auditor* p : list) {
        p->inspect(vault);                         // dispatched by dynamic type
        cout << endl;
    }
    Auditor::notice();
    return 0;
}
