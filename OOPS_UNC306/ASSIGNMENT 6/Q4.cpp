#include <iostream>
using namespace std;
 
class Rectangle {
private:
    float width, height;
public:
    void setDimensions(float width, float height) {
        this->width  = width;     // member = parameter
        this->height = height;
    }
    float getWidth() const  { return this->width; }
    float getHeight() const { return this->height; }
    void printDimensions() const {
        cout << "Object address: " << this
             << " | Width: " << this->width
             << ", Height: " << this->height << endl;
    }
};
 
int main() {
    Rectangle r1, r2;
    r1.setDimensions(5.0f, 3.0f);
    r2.setDimensions(10.5f, 7.25f);
 
    cout << "Rectangle r1 (&r1 = " << &r1 << ")" << endl;
    r1.printDimensions();
    cout << "Getters: " << r1.getWidth() << " x " << r1.getHeight() << endl;
 
    cout << "\nRectangle r2 (&r2 = " << &r2 << ")" << endl;
    r2.printDimensions();
    cout << "Getters: " << r2.getWidth() << " x " << r2.getHeight() << endl;
    return 0;
}
