// Q5 - Random access: seekg, seekp, tellg, tellp
#include <iostream>
#include <fstream>
using namespace std;
 
void createSampleFile(const char* name) {
    ofstream out(name, ios::binary | ios::trunc);
    out << "ABCDEFGH";                       // exactly 8 bytes
}
 
void inspectAndUpdate(const char* name) {
    fstream f(name, ios::in | ios::out | ios::binary);
    if (!f) { cerr << "Cannot open " << name << '\n'; return; }
 
    f.seekg(0, ios::end);
    cout << "File size (tellg at end): " << f.tellg() << " bytes\n";
 
    f.seekg(4, ios::beg);                    // get pointer -> offset 4
    char c;
    f.get(c);
    cout << "Character at offset 4 : " << c << '\n';
    cout << "tellg after read      : " << f.tellg() << '\n';
 
    f.clear();
    f.seekp(4, ios::beg);                    // put pointer -> offset 4
    cout << "tellp before write    : " << f.tellp() << '\n';
    f.put('Z');
    f.flush();
    cout << "tellp after write     : " << f.tellp() << '\n';
 
    f.seekg(0, ios::beg);                    // reset read position
    cout << "Updated contents      : ";
    while (f.get(c)) cout << c;
    cout << '\n';
 
    f.clear();
    f.seekg(0, ios::end);
    cout << "File size after update: " << f.tellg() << " bytes (unchanged)\n";
}
 
int main() {
    createSampleFile("sample.txt");
    inspectAndUpdate("sample.txt");
    return 0;
}
