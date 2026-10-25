#include <iostream>
using namespace std;
 
// ---------- Case 1: neither branch is virtual ----------
namespace NoVirtual {
class A {
protected:
    int value = 10;
public:
    void display() const { cout << "    A::value = " << value << endl; }
    const A* self() const { return this; }
};
class B : public A {};
class C : public A {};
class D : public B, public C {
public:
    void test() {
        B::value = 1;                  // A subobject reached through B
        C::value = 2;                  // a different A subobject reached through C
        cout << "    B::value = " << B::value << ", C::value = " << C::value << endl;
        B::display();
        C::display();
        const A* viaB = static_cast<B*>(this)->self();
        const A* viaC = static_cast<C*>(this)->self();
        cout << "    A subobjects in D = " << (viaB != viaC ? 2 : 1) << endl;
        //X display();                 // ambiguous: two A subobjects
        //X cout << value;             // ambiguous: two A subobjects
    }
};
}
 
// ---------- Case 2: only B is virtual ----------
namespace OnlyBVirtual {
class A {
protected:
    int value = 10;
public:
    void display() const { cout << "    A::value = " << value << endl; }
    const A* self() const { return this; }
};
class B : virtual public A {};
class C : public A {};
class D : public B, public C {
public:
    void test() {
        B::value = 1;
        C::value = 2;
        cout << "    B::value = " << B::value << ", C::value = " << C::value << endl;
        B::display();
        C::display();
        const A* viaB = static_cast<B*>(this)->self();
        const A* viaC = static_cast<C*>(this)->self();
        cout << "    A subobjects in D = " << (viaB != viaC ? 2 : 1) << endl;
        //X display();                 // still ambiguous: C brings its own A
        //X cout << value;             // still ambiguous: C brings its own A
    }
};
}
 
// ---------- Case 3: only C is virtual ----------
namespace OnlyCVirtual {
class A {
protected:
    int value = 10;
public:
    void display() const { cout << "    A::value = " << value << endl; }
    const A* self() const { return this; }
};
class B : public A {};
class C : virtual public A {};
class D : public B, public C {
public:
    void test() {
        B::value = 1;
        C::value = 2;
        cout << "    B::value = " << B::value << ", C::value = " << C::value << endl;
        B::display();
        C::display();
        const A* viaB = static_cast<B*>(this)->self();
        const A* viaC = static_cast<C*>(this)->self();
        cout << "    A subobjects in D = " << (viaB != viaC ? 2 : 1) << endl;
        //X display();                 // still ambiguous: B brings its own A
        //X cout << value;             // still ambiguous: B brings its own A
    }
};
}
 
// ---------- Case 4: both branches are virtual ----------
namespace BothVirtual {
class A {
protected:
    int value = 10;
public:
    void display() const { cout << "    A::value = " << value << endl; }
    const A* self() const { return this; }
};
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {
public:
    void test() {
        B::value = 1;
        C::value = 2;                  // same object as B::value
        cout << "    B::value = " << B::value << ", C::value = " << C::value << endl;
        value = 5;                     // unambiguous: only one A
        display();                     // unambiguous: only one A
        const A* viaB = static_cast<B*>(this)->self();
        const A* viaC = static_cast<C*>(this)->self();
        cout << "    A subobjects in D = " << (viaB != viaC ? 2 : 1) << endl;
    }
};
}
 
int main() {
    cout << "Case 1: neither branch virtual" << endl;
    NoVirtual::D d1;
    d1.test();
 
    cout << "\nCase 2: only B virtual" << endl;
    OnlyBVirtual::D d2;
    d2.test();
 
    cout << "\nCase 3: only C virtual" << endl;
    OnlyCVirtual::D d3;
    d3.test();
 
    cout << "\nCase 4: both virtual" << endl;
    BothVirtual::D d4;
    d4.test();
    return 0;
}
