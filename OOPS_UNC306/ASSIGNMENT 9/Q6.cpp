// Q6 - Binary I/O of fixed-layout records
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
 
struct SensorRecord {
    int id;
    char label[16];
    double reading;
};
 
void saveRecords(const char* name, const SensorRecord* records, int count) {
    ofstream out(name, ios::binary | ios::trunc);
    if (!out) { cerr << "Cannot create " << name << '\n'; return; }
    out.write(reinterpret_cast<const char*>(records), sizeof(SensorRecord) * count);
    if (!out) { cerr << "Write failed\n"; return; }
    cout << "Saved " << count << " records (" << sizeof(SensorRecord) << " bytes each)\n";
}
 
void loadRecords(const char* name) {
    ifstream in(name, ios::binary);
    if (!in) { cerr << "Cannot open " << name << '\n'; return; }
    SensorRecord r;
    cout << left << setw(6) << "ID" << setw(18) << "Label" << "Reading\n";
    while (in.read(reinterpret_cast<char*>(&r), sizeof(r)))
        cout << left << setw(6) << r.id << setw(18) << r.label
             << fixed << setprecision(2) << r.reading << '\n';
    if (in.bad()) cerr << "Read error\n";
}
 
int main() {
    SensorRecord data[3] = {};                 // zero-initialise (also zeroes padding)
    data[0].id = 101; strncpy(data[0].label, "Temperature", 15); data[0].reading = 36.75;
    data[1].id = 102; strncpy(data[1].label, "Humidity",    15); data[1].reading = 58.20;
    data[2].id = 103; strncpy(data[2].label, "Pressure",    15); data[2].reading = 1012.5;
 
    saveRecords("readings.bin", data, 3);
    loadRecords("readings.bin");
    cout << "\nsizeof(SensorRecord) = " << sizeof(SensorRecord)
         << " (4 + 16 + 4 padding + 8)\n";
    return 0;
}
