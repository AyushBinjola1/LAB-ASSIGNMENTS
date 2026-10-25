#include <iostream>
#include <string>
using namespace std;
 
class Printer {
public:
    void status() const { cout << "Printer::status()  - printer ready" << endl; }
    void printPage() const { cout << "Printing a page..." << endl; }
};
 
class Scanner {
public:
    void status() const { cout << "Scanner::status()  - scanner ready" << endl; }
    void scanPage() const { cout << "Scanning a page..." << endl; }
};
 
// Inherits two different status() functions
class AllInOne : public Printer, public Scanner {
public:
    void operate() const {
        //X status();         // ambiguous: Printer::status() or Scanner::status()?
        Printer::status();    // resolved with scope qualification
        Scanner::status();
        printPage();
        scanPage();
    }
};
 
// Defines its own status(): hides both inherited versions
class SmartAllInOne : public Printer, public Scanner {
public:
    void status() const {
        cout << "SmartAllInOne::status() - combined device ready" << endl;
    }
};
 
class BasicDisplay {
public:
    void show(int x) const { cout << "BasicDisplay::show(int)    = " << x << endl; }
    void show(double x) const { cout << "BasicDisplay::show(double) = " << x << endl; }
};
 
// show(string) hides BOTH inherited overloads
class AdvancedDisplay : public BasicDisplay {
public:
    void show(const string& s) const {
        cout << "AdvancedDisplay::show(string) = " << s << endl;
    }
};
 
// using-declaration brings the base overload set back
class FullDisplay : public BasicDisplay {
public:
    using BasicDisplay::show;
    void show(const string& s) const {
        cout << "FullDisplay::show(string)     = " << s << endl;
    }
};
 
int main() {
    cout << "--- AllInOne ---" << endl;
    AllInOne a;
    a.operate();
    //X a.status();           // ambiguous call through the object
    a.Printer::status();
    a.Scanner::status();
 
    cout << "\n--- SmartAllInOne ---" << endl;
    SmartAllInOne s;
    s.status();               // derived version
    s.Printer::status();      // base versions still reachable by qualification
    s.Scanner::status();
 
    cout << "\n--- AdvancedDisplay (name hiding) ---" << endl;
    AdvancedDisplay ad;
    ad.show("hello");
    //X ad.show(5);           // base show(int) is hidden by show(string)
    //X ad.show(2.5);         // base show(double) is hidden by show(string)
    ad.BasicDisplay::show(5); // qualification reaches the hidden function
 
    cout << "\n--- FullDisplay (using declaration) ---" << endl;
    FullDisplay fd;
    fd.show(5);
    fd.show(2.5);
    fd.show("hello");
    return 0;
}
