#include <iostream>
#include <string>
using namespace std;
 
class Engineer {
protected:
    string engField;
};
 
class Manager {
protected:
    int teamSize;
};
 
class TechManager : public Engineer, public Manager {
public:
    void setDetails(string field, int size) {
        engField = field;   // from Engineer
        teamSize = size;    // from Manager
    }
    void display() const {
        cout << "Engineering Field : " << engField << endl;
        cout << "Team Size         : " << teamSize << endl;
    }
};
 
int main() {
    TechManager tm;
    tm.setDetails("Electronics & Communication", 12);
    cout << "--- Tech Manager Details ---" << endl;
    tm.display();
    return 0;
}
