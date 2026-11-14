// Q4 - Merge two files into a third
#include <iostream>
#include <fstream>
using namespace std;
 
bool mergeFiles(const char* first, const char* second, const char* destination) {
    ifstream a(first, ios::binary), b(second, ios::binary);
    if (!a.is_open()) { cerr << "Error: cannot open " << first << '\n'; return false; }
    if (!b.is_open()) { cerr << "Error: cannot open " << second << '\n'; return false; }
    ofstream out(destination, ios::out | ios::trunc | ios::binary);
    if (!out.is_open()) { cerr << "Error: cannot create " << destination << '\n'; return false; }
 
    char ch;
    while (a.get(ch)) out.put(ch);
    while (b.get(ch)) out.put(ch);
 
    out.flush();
    return !out.fail() && !a.bad() && !b.bad();   // success only if I/O is fine
}
 
static void show(const char* name) {
    ifstream in(name, ios::binary);
    char ch;
    cout << "[" << name << "]\n";
    while (in.get(ch)) cout.put(ch);
    cout << "<EOF>\n";
}
 
int main() {
    { ofstream f("first.txt");  f << "Hello World\nThis is the first file"; }  // no trailing newline
    { ofstream f("second.txt"); f << "\nSecond file line 1\nLine 2 is longer than the others\n"; }
    { ofstream f("empty.txt"); }
 
    cout << "Test 1: normal files\n";
    if (mergeFiles("first.txt", "second.txt", "merged.txt")) { cout << "Merge OK\n"; show("merged.txt"); }
 
    cout << "\nTest 2: first file does not end with a newline\n";
    { ofstream f("second2.txt"); f << "Appended text\n"; }
    if (mergeFiles("first.txt", "second2.txt", "merged2.txt")) show("merged2.txt");
 
    cout << "\nTest 3: empty first file\n";
    if (mergeFiles("empty.txt", "second2.txt", "merged3.txt")) show("merged3.txt");
 
    cout << "\nTest 4: missing source file\n";
    if (!mergeFiles("nofile.txt", "second.txt", "merged4.txt")) cout << "Merge FAILED (reported correctly)\n";
    return 0;
}
