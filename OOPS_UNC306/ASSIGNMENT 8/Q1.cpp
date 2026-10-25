#include <iostream>
using namespace std;
 
class AccessBase {
private:
    int secret = 10;
protected:
    int level = 20;
public:
    int status = 30;
    void show() const {
        cout << "AccessBase      : secret=" << secret << ", level=" << level
             << ", status=" << status << endl;
    }
};
 
class PublicBranch : public AccessBase {
public:
    void check() const {
        cout << "PublicBranch    : level=" << level << ", status=" << status << endl;
        //X cout << secret;    // private in AccessBase: never directly accessible
    }
};
 
class ProtectedBranch : protected AccessBase {
public:
    void check() const {
        cout << "ProtectedBranch : level=" << level << ", status=" << status << endl;
    }
};
 
class PrivateBranch : private AccessBase {
public:
    void check() const {
        cout << "PrivateBranch   : level=" << level << ", status=" << status << endl;
    }
};
 
class FinalBranch : public ProtectedBranch {
public:
    void verify() const {
        // level and status are protected members of ProtectedBranch: accessible
        cout << "FinalBranch     : level=" << level << ", status=" << status << endl;
    }
};
 
class PrivateFinal : public PrivateBranch {
public:
    void verify() const {
        //X cout << level;     // made private by private inheritance: not visible here
    }
};
 
int main() {
    PublicBranch pub;
    ProtectedBranch pro;
    PrivateBranch pri;
    FinalBranch fin;
 
    pub.check();
    pro.check();
    pri.check();
    fin.verify();
 
    cout << "\nClient of PublicBranch: status = " << pub.status << endl;
    pub.show();
 
    //X cout << pub.level;     // protected member: not accessible in main()
    //X pro.show();            // public became protected (protected inheritance)
    //X cout << pro.status;    // public became protected (protected inheritance)
    //X pri.show();            // public became private (private inheritance)
    //X cout << pri.status;    // public became private (private inheritance)
    //X cout << fin.status;    // still protected inside FinalBranch
    //X AccessBase* bp = &pri; // private base: conversion not allowed in main()
    return 0;
}
