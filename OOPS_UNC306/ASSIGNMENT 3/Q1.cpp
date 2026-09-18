#include <iostream>
#include <cmath>   
using namespace std;
 

int calculateTotal(int marks[], int n);
double calculatePercentage(int total, int n);
char findGrade(double percentage);
bool isPassed(int marks[], int n);
 

int main() {
    const int n = 5;
    int marks[n];
 
    cout << "Enter marks of 5 subjects (0-100 each):\n";
    for (int i = 0; i < n; i++) {
        cout << "Subject " << (i + 1) << ": ";
        cin >> marks[i];
    }
 
    
    int total = calculateTotal(marks, n);
    double percentage = calculatePercentage(total, n);
    char grade = findGrade(percentage);
    bool passed = isPassed(marks, n);
 
    cout << "\n--- Result ---\n";
    cout << "Total: " << total << endl;
    cout << "Percentage: " << round(percentage * 100) / 100 << "%\n";
    cout << "Grade: " << grade << endl;
    cout << "Result: " << (passed ? "PASS" : "FAIL") << endl;
 
    return 0;
}
 
int calculateTotal(int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += marks[i];
    return sum;
}
 
double calculatePercentage(int total, int n) {
    return (double)total / (n * 100) * 100;
}
 
char findGrade(double percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 75) return 'B';
    else if (percentage >= 60) return 'C';
    else if (percentage >= 50) return 'D';
    else if (percentage >= 40) return 'E';
    else return 'F';
}
 
bool isPassed(int marks[], int n) {
    for (int i = 0; i < n; i++)
        if (marks[i] < 40) return false;
    return true;
}
