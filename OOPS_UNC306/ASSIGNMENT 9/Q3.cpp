// Q3 - Text files: create, append, read, truncate
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
void createNotices(const string& fileName) {
    ofstream out(fileName, ios::out | ios::trunc);
    if (!out.is_open()) { cerr << "Error: cannot create " << fileName << '\n'; return; }
    out << "Notice 1: Lab test on Monday\n";
    out << "Notice 2: Submit assignment by Friday\n";
}
 
void appendNotice(const string& fileName, const string& text) {
    ofstream out(fileName, ios::app);              // keeps old content
    if (!out) { cerr << "Error: cannot open " << fileName << " for append\n"; return; }
    out << text << '\n';
}
 
void displayNotices(const string& fileName) {
    ifstream in(fileName);
    if (!in.is_open()) { cerr << "Error: cannot open " << fileName << " for reading\n"; return; }
    string line;
    int n = 1;
    while (getline(in, line)) cout << n++ << ". " << line << '\n';
    if (n == 1) cout << "(file is empty)\n";
}
 
int main() {
    const string f = "notices.txt";
    createNotices(f);
    appendNotice(f, "Notice 3: Holiday on Saturday");
    cout << "--- notices.txt after create + append ---\n";
    displayNotices(f);
 
    // Truncation demo on a separate test run
    cout << "\n--- Truncation demo ---\n";
    {
        ofstream t(f, ios::out | ios::trunc);       // opening wipes old data
        t << "Notice A: Only this remains\n";
    }
    displayNotices(f);
 
    // Failure detection demo
    cout << "\n--- Failure demo ---\n";
    displayNotices("missing_notices.txt");
    return 0;
}
