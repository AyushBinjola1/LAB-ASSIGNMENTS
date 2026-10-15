#include <iostream>
using namespace std;
 
class Data {
private:
    void *ptr;
public:
    Data(void *p) : ptr(p) {}
    void printValue(char type) const {
        if (ptr == nullptr) {
            cout << "Pointer is null." << endl;
            return;
        }
        switch (type) {
            case 'i':
                cout << "int value   : " << *static_cast<int*>(ptr) << endl;
                break;
            case 'f':
                cout << "float value : " << *static_cast<float*>(ptr) << endl;
                break;
            default:
                cout << "Unsupported type indicator '" << type
                     << "' - pointer not dereferenced." << endl;
        }
    }
};
 
int main() {
    int   num = 42;
    float pi  = 3.14159f;
 
    Data d1(&num);   // int*   -> void* (implicit)
    Data d2(&pi);    // float* -> void* (implicit)
 
    d1.printValue('i');
    d2.printValue('f');
 
    cout << "\nInvalid indicator test:" << endl;
    d1.printValue('x');
    d2.printValue('d');
 
    cout << "\nNull pointer test:" << endl;
    Data d3(nullptr);
    d3.printValue('i');
    return 0;
}
