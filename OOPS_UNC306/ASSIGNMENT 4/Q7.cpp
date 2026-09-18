#include <iostream>
using namespace std;

class EndSemester;   // forward declaration needed for the friend prototype

class InternalAssessment {
private:
    double internalScore;

public:
    void setScore(double s) {
        if (s < 0 || s > 100) {
            cout << "Invalid internal score! Set to 0.\n";
            internalScore = 0;
        } else {
            internalScore = s;
        }
    }
    friend double calculateFinal(InternalAssessment, EndSemester);
};

class EndSemester {
private:
    double endSemScore;

public:
    void setScore(double s) {
        if (s < 0 || s > 100) {
            cout << "Invalid end-semester score! Set to 0.\n";
            endSemScore = 0;
        } else {
            endSemScore = s;
        }
    }
    friend double calculateFinal(InternalAssessment, EndSemester);
};

// common friend function - has access to both classes' private data
double calculateFinal(InternalAssessment ia, EndSemester es) {
    double finalScore = 0.40 * ia.internalScore + 0.60 * es.endSemScore;

    cout << "Internal: " << ia.internalScore << ", End-Sem: " << es.endSemScore
         << ", Final: " << finalScore << " -> ";

    if (finalScore >= 50 && ia.internalScore >= 40 && es.endSemScore >= 40)
        cout << "PASS\n";
    else
        cout << "FAIL\n";

    return finalScore;
}

int main() {
    InternalAssessment ia1, ia2, ia3;
    EndSemester es1, es2, es3;

    cout << "-- Case 1: Normal pass --\n";
    ia1.setScore(80); es1.setScore(70);
    calculateFinal(ia1, es1);

    cout << "\n-- Case 2: Overall score failure --\n";
    ia2.setScore(45); es2.setScore(45);
    calculateFinal(ia2, es2);

    cout << "\n-- Case 3: Fails due to individual component below 40 --\n";
    ia3.setScore(75); es3.setScore(35);
    calculateFinal(ia3, es3);

    return 0;
}
