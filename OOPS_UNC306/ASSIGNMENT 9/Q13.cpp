// Q13 - User-defined exception class
#include <iostream>
#include <exception>
using namespace std;
 
class InvalidMark : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid mark: must be between 0 and 100";
    }
};
 
void checkMark(int mark) {
    if (mark < 0 || mark > 100) throw InvalidMark();
    cout << "Mark " << mark << " is valid\n";
}
 
int main() {
    int marks[] = {-5, 72, 105};
    for (int m : marks) {
        try {
            checkMark(m);
        } catch (const std::exception& e) {
            cout << "Mark " << m << " rejected: " << e.what() << '\n';
        }
    }
    return 0;
}
