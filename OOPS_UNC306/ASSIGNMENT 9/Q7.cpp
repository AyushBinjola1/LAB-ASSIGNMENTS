// Q7 - File-state checking and text-file statistics
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;
 
struct FileStats { int lines; long long characters; };
 
FileStats analyzeText(const string& fileName) {
    ifstream in(fileName);
    if (!in.is_open())
        throw runtime_error("cannot open file '" + fileName + "'");
 
    FileStats s{0, 0};
    string line;
    while (getline(in, line)) {
        ++s.lines;
        s.characters += static_cast<long long>(line.size());
        if (!in.eof()) ++s.characters;          // count the '\n' that getline consumed
    }
    // loop ended: eof is normal, bad() is a genuine I/O error
    if (in.bad())
        throw runtime_error("I/O error while reading '" + fileName + "'");
    return s;
}
 
static void test(const string& name) {
    try {
        FileStats s = analyzeText(name);
        cout << name << ": lines = " << s.lines << ", characters = " << s.characters << '\n';
    } catch (const exception& e) {
        cout << name << ": ERROR - " << e.what() << '\n';
    }
}
 
int main() {
    { ofstream f("multi.txt"); f << "Hello\nC++ streams\nThird line here\n"; }
    { ofstream f("empty7.txt"); }
    test("multi.txt");
    test("empty7.txt");
    test("does_not_exist.txt");
    return 0;
}
