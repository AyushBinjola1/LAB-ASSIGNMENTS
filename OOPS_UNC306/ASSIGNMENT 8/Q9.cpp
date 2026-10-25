#include <iostream>
using namespace std;
 
// ---------- Concrete base with a virtual destructor ----------
class Session {
public:
    Session() { cout << "Session constructed" << endl; }
    virtual ~Session() { cout << "Session destroyed (base)" << endl; }
};
 
class SecureSession : public Session {
public:
    SecureSession() { cout << "SecureSession constructed" << endl; }
    ~SecureSession() override { cout << "SecureSession destroyed (derived)" << endl; }
};
 
// ---------- Abstract base with a pure virtual destructor ----------
class Job {
public:
    virtual void execute() { cout << "Job::execute() default" << endl; }
    virtual ~Job() = 0;                 // pure virtual destructor
};
 
Job::~Job() { cout << "Job destroyed (base)" << endl; }   // body is mandatory
 
class ScheduledJob : public Job {
public:
    void execute() override { cout << "ScheduledJob::execute()" << endl; }
    ~ScheduledJob() override { cout << "ScheduledJob destroyed (derived)" << endl; }
};
 
int main() {
    cout << "--- Virtual destructor ---" << endl;
    Session* s = new SecureSession;
    delete s;                           // derived destructor, then base destructor
 
    cout << "\n--- Pure virtual destructor ---" << endl;
    Job* j = new ScheduledJob;
    j->execute();
    delete j;                           // ~ScheduledJob(), then ~Job()
 
    //X Job job;                        // Job is abstract
    //X Job* bad = new Job;             // Job is abstract
    return 0;
}
