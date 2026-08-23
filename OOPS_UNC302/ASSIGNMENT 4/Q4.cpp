#include <iostream>
using namespace std;

class Time {
private:
    int hour, minute, second;

public:
    void getTime() {
        cout << "Enter hour minute second: ";
        cin >> hour >> minute >> second;
    }

    void printTime() {
        cout << hour << "h " << minute << "m " << second << "s" << endl;
    }

    void normalize() {
        minute += second / 60;
        second %= 60;
        hour += minute / 60;
        minute %= 60;
    }

    Time addTime(Time x, Time y) {
        Time result;
        result.hour   = x.hour   + y.hour;
        result.minute = x.minute + y.minute;
        result.second = x.second + y.second;
        result.normalize();      // normalize after every addition
        return result;
    }
};

int main() {
    Time t1, t2, t3;

    cout << "Enter t1:\n"; t1.getTime();
    cout << "Enter t2:\n"; t2.getTime();
    cout << "Enter t3:\n"; t3.getTime();

    cout << "\nt1: "; t1.printTime();
    cout << "t2: ";   t2.printTime();
    cout << "t3: ";   t3.printTime();

    Time sum12 = t1.addTime(t1, t2);        // intermediate sum of t1 and t2
    cout << "\nIntermediate sum (t1+t2): "; sum12.printTime();

    Time total = t1.addTime(sum12, t3);     // repeated object return: outer call uses inner call's result
    cout << "Final Total (t1+t2+t3): "; total.printTime();

    /*
      Carry-intensive test case: 2:59:50 + 1:45:35 + 0:30:50
      Step 1 (t1+t2): hour=3, minute=104, second=85
                       normalize -> second=25, minute=105 -> minute=45, hour=4
                       Intermediate sum = 4h 45m 25s
      Step 2 (sum12+t3): hour=4, minute=75, second=75
                       normalize -> second=15, minute=76 -> minute=16, hour=5
                       Final Total = 5h 16m 15s
    */

    return 0;
}
