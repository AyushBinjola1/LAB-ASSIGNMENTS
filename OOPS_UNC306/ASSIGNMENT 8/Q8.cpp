#include <iostream>
using namespace std;
 
class Notification {
public:
    virtual void deliver() {
        cout << "Notification::deliver() - standard delivery" << endl;
    }
    virtual ~Notification() = default;
};
 
// Does NOT override deliver(): inherits the base implementation unchanged
class StandardNotice : public Notification {};
 
class EmergencyNotice : public Notification {
public:
    void deliver() override {
        cout << "EmergencyNotice::deliver() - ALERT sent to all!" << endl;
    }
};
 
class ReminderNotice : public Notification {
public:
    void deliver() override { cout << "ReminderNotice::deliver() - reminder sent" << endl; }
};
 
void send(Notification& n) {          // reference parameter: still dynamic dispatch
    n.deliver();
}
 
int main() {
    StandardNotice std1;
    EmergencyNotice emg;
    ReminderNotice rem;
 
    Notification* list[] = { &std1, &emg, &rem };
 
    cout << "Using Notification* pointers:" << endl;
    for (Notification* n : list) {
        n->deliver();
    }
 
    cout << "\nUsing Notification& references:" << endl;
    send(std1);
    send(emg);
    send(rem);
    return 0;
}
