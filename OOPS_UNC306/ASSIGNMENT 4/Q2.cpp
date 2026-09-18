#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    void setDimensions(double l, double w);
    void displayDimensions();
    double calculateArea(const Rectangle& rect);
};

// ---- Member functions defined outside the class using :: ----
void Rectangle::setDimensions(double l, double w) {
    length = l;
    width = w;
}

void Rectangle::displayDimensions() {
    cout << "Length: " << length << ", Width: " << width << endl;
}

double Rectangle::calculateArea(const Rectangle& rect) {
    return rect.length * rect.width;
}

int main() {
    Rectangle rect;

    rect.setDimensions(12.5, 6.0);
    rect.displayDimensions();

    double area = rect.calculateArea(rect);
    cout << "Area: " << area << endl;

    return 0;
}
