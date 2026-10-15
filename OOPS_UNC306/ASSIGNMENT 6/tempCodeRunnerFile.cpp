#include <iostream>
#include <iomanip>
using namespace std;
 
class Base {
public:
    virtual ~Base() = default;             // makes Base polymorphic
    virtual void who() const { cout << "Base" << endl; }
};
class DerivedA : public Base {
public:
    void who() const override { cout << "DerivedA" << endl; }
    void onlyA() const { cout << "  -> DerivedA-specific function called" << endl; }
};
class DerivedB : public Base {
public:
    void who() const override { cout << "DerivedB" << endl; }
};
 
int main() {
    // 1. static_cast : compile-time numeric conversion
    double d = 7.89;
    int i = static_cast<int>(d);
    cout << "[static_cast] double " << d << " -> int " << i << endl;
 
    // 2. static_cast : upcast DerivedA* -> Base* (always safe)
    DerivedA a;
    Base *bp = static_cast<Base*>(&a);
    cout << "[static_cast upcast] Base* actually points to: ";
    bp->who();
 
    // 3. dynamic_cast : runtime-checked downcast (succeeds)
    DerivedA *pa = dynamic_cast<DerivedA*>(bp);
    if (pa != nullptr) {
        cout << "[dynamic_cast] Base* -> DerivedA* : SUCCESS" << endl;
        pa->onlyA();
    } else
        cout << "[dynamic_cast] Base* -> DerivedA* : FAILED" << endl;
 
    // 4. dynamic_cast : same Base* to DerivedB* (fails -> nullptr)
    DerivedB *pb = dynamic_cast<DerivedB*>(bp);
    if (pb == nullptr)
        cout << "[dynamic_cast] Base* -> DerivedB* : FAILED, returned nullptr" << endl;
    else
        cout << "[dynamic_cast] Base* -> DerivedB* : SUCCESS" << endl;
 
    // 5. const_cast : originally non-const int, accessed via const pointer
    int value = 50;
    const int *cp = &value;
    int *mp = const_cast<int*>(cp);
    *mp = 75;
    cout << "[const_cast] value changed from 50 to " << value
         << " (object was originally non-const)" << endl;
 
    // 6. reinterpret_cast : view int bytes through char*
    int num = 0x12345678;
    char *cptr = reinterpret_cast<char*>(&num);
    cout << "[reinterpret_cast] bytes of int 0x12345678 in memory: ";
    for (size_t k = 0; k < sizeof(int); ++k)
        cout << hex << setw(2) << setfill('0')
             << (static_cast<int>(cptr[k]) & 0xFF) << " ";
    cout << dec << endl;
    cout << "  (byte order shown depends on machine endianness)" << endl;
    return 0;
}
