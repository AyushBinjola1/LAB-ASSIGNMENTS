#include <iostream>
using namespace std;
 
// ================= Diamond WITH virtual base =================
namespace VirtualDiamond {
class Root {
    int id;
public:
    explicit Root(int i) : id(i) { cout << "  Root(" << id << ") constructed" << endl; }
    virtual ~Root() { cout << "  ~Root(" << id << ") destroyed" << endl; }
};
class Left : virtual public Root {
public:
    Left() : Root(1) { cout << "  Left constructed" << endl; }
    ~Left() override { cout << "  ~Left destroyed" << endl; }
};
class Right : virtual public Root {
public:
    Right() : Root(2) { cout << "  Right constructed" << endl; }
    ~Right() override { cout << "  ~Right destroyed" << endl; }
};
class Final : public Left, public Right {
public:
    Final() : Root(100), Left(), Right() { cout << "  Final constructed" << endl; }
    ~Final() override { cout << "  ~Final destroyed" << endl; }
};
//X class Bad : public Left, public Right { public: Bad() {} }; // Root has no default ctor
}
 
// ================= Diamond WITHOUT virtual base =================
namespace PlainDiamond {
class Root {
    int id;
public:
    explicit Root(int i) : id(i) { cout << "  Root(" << id << ") constructed" << endl; }
    virtual ~Root() { cout << "  ~Root(" << id << ") destroyed" << endl; }
};
class Left : public Root {
public:
    Left() : Root(1) { cout << "  Left constructed" << endl; }
    ~Left() override { cout << "  ~Left destroyed" << endl; }
};
class Right : public Root {
public:
    Right() : Root(2) { cout << "  Right constructed" << endl; }
    ~Right() override { cout << "  ~Right destroyed" << endl; }
};
class Final : public Left, public Right {
public:
    Final() { cout << "  Final constructed" << endl; }
    ~Final() override { cout << "  ~Final destroyed" << endl; }
};
//X class Bad : public Left, public Right { public: Bad() : Root(100) {} }; // indirect base
}
 
int main() {
    cout << "Virtual diamond - construction:" << endl;
    {
        VirtualDiamond::Final f;
        cout << "Virtual diamond - destruction:" << endl;
    }
 
    cout << "\nNon-virtual diamond - construction:" << endl;
    {
        PlainDiamond::Final f;
        cout << "Non-virtual diamond - destruction:" << endl;
    }
    return 0;
}
