// Q11 - Multiple catch handlers and catch(...)
#include <iostream>
#include <string>
using namespace std;
 
void runTest(int mode) {
    try {
        cout << "Mode " << mode << ": ";
        switch (mode) {
            case 1: throw 42;
            case 2: throw 'X';
            case 3: throw 3.14;
            case 4: throw string("text error");
        }
    }
    catch (int e)    { cout << "catch(int) -> " << e << '\n'; }
    catch (char e)   { cout << "catch(char) -> " << e << '\n'; }
    catch (double e) { cout << "catch(double) -> " << e << '\n'; }
    catch (...)      { cout << "catch(...) -> unexpected type (std::string)\n"; }
}
 
int main() {
    for (int m = 1; m <= 4; ++m) runTest(m);
    return 0;
}
