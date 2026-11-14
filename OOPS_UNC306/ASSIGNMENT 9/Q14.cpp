// Q14 - Templates + file I/O + exceptions : ResultLog<T>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;
 
template <typename T>
class ResultLog {
public:
    void save(const char* fileName, const T* values, int count,
              T minAllowed, T maxAllowed) {
        if (values == nullptr || count <= 0)
            throw invalid_argument("invalid reading count");
        if (minAllowed > maxAllowed)
            throw invalid_argument("invalid permitted range");
        // validate everything first so no partial file is produced
        for (int i = 0; i < count; ++i)
            if (values[i] < minAllowed || values[i] > maxAllowed)
                throw out_of_range("reading " + to_string(values[i]) +
                                   " is outside the permitted range");
        ofstream out(fileName, ios::out | ios::trunc);
        if (!out.is_open())
            throw runtime_error(string("cannot open file for writing: ") + fileName);
        for (int i = 0; i < count; ++i) out << values[i] << '\n';
        out.flush();
        if (!out)
            throw runtime_error("write failure on " + string(fileName));
        cout << "Saved " << count << " readings to " << fileName << '\n';
    }
 
    void loadAndDisplay(const char* fileName) {
        ifstream in(fileName);
        if (!in.is_open())
            throw runtime_error(string("cannot open file for reading: ") + fileName);
        T v;
        int n = 0;
        cout << "Readings in " << fileName << ":\n";
        while (in >> v) cout << "  " << ++n << ") " << v << '\n';
        if (!in.eof())
            throw runtime_error("malformed data in " + string(fileName));
    }
};
 
int main() {
    int    iv[] = {10, 25, 40, 55};
    double dv[] = {1.5, 2.75, 3.25};
    double bad[] = {1.0, 99.9, 2.0};
 
    ResultLog<int> li;
    ResultLog<double> ld;
    try {
        li.save("ints.txt", iv, 4, 0, 100);
        li.loadAndDisplay("ints.txt");
        ld.save("doubles.txt", dv, 3, 0.0, 10.0);
        ld.loadAndDisplay("doubles.txt");
    } catch (const exception& e) { cout << "Error: " << e.what() << '\n'; }
 
    cout << "\n-- Failure tests --\n";
    try { ld.save("bad.txt", bad, 3, 0.0, 10.0); }
    catch (const exception& e) { cout << "Error: " << e.what() << '\n'; }
    try { li.save("x.txt", iv, 0, 0, 100); }
    catch (const exception& e) { cout << "Error: " << e.what() << '\n'; }
    try { li.loadAndDisplay("no_such_file.txt"); }
    catch (const exception& e) { cout << "Error: " << e.what() << '\n'; }
    try { li.save("/nonexistent_dir/out.txt", iv, 4, 0, 100); }
    catch (const exception& e) { cout << "Error: " << e.what() << '\n'; }
    return 0;
}
