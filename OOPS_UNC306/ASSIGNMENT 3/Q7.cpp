#include <iostream>
#include <cmath>
using namespace std;
 
inline double square(double x) {
    return x * x;
}
 
inline double distance(double x1, double y1, double x2, double y2) {
    return sqrt(square(x2 - x1) + square(y2 - y1));
}
 
inline double speed(double dist, double time) {
    return dist / time;
}
 
int main() {
    double x1, y1, x2, y2, time;
 
    cout << "Enter x1 y1 x2 y2: ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter travel time (hours): ";
    cin >> time;
 
    if (time <= 0) {
        cout << "Invalid travel time!\n";
        return 1;
    }
 
    double dist = distance(x1, y1, x2, y2);   // square() is called twice inside distance()
    double avgSpeed = speed(dist, time);
 
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Distance: " << dist << " units\n";
    cout << "Average Speed: " << avgSpeed << " units/hour\n";
 
    return 0;
}
