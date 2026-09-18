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

    void addTime(Time x, Time y) {
        int totalSeconds = x.second + y.second;
        int totalMinutes = x.minute + y.minute + totalSeconds / 60;
        int totalHours   = x.hour   + y.hour   + totalMinutes / 60;

        second = totalSeconds % 60;
        minute = totalMinutes % 60;
        hour   = totalHours;
    }
};

int main() {
    Time t1, t2, sum;

    cout << "Enter first time:\n";
    t1.getTime();
    cout << "Enter second time:\n";
    t2.getTime();

    sum.addTime(t1, t2);   // t1 and t2 passed as arguments

    cout << "\nTime 1: "; t1.printTime();
    cout << "Time 2: ";   t2.printTime();
    cout << "Sum: ";      sum.printTime();

    return 0;
}
