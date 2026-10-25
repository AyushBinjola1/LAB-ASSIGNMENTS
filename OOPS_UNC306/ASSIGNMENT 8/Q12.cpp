#include <iostream>
using namespace std;
 
class Device {
public:
    virtual void performTask() = 0;              // pure virtual at the root
    virtual ~Device() = default;
};
 
class RobotDevice : public Device {
public:
    void calibrate() { cout << "RobotDevice::calibrate() - sensors calibrated" << endl; }
    // performTask() is NOT implemented here: it stays pure virtual
};
 
class AutonomousRobot : public RobotDevice {
public:
    void performTask() override {
        cout << "AutonomousRobot::performTask() - navigating" << endl;
    }
};
 
// A final class that omits the override can never be instantiated
class InspectionRobot final : public RobotDevice {};
 
int main() {
    //X Device d;                     // Device is abstract
    //X RobotDevice r;                // RobotDevice is still abstract
    //X InspectionRobot ir;           // performTask() never implemented, class is final
 
    AutonomousRobot robot;
    robot.calibrate();                // inherited from RobotDevice
    robot.performTask();              // overridden in AutonomousRobot
 
    Device* dp = &robot;
    RobotDevice* rp = &robot;
    cout << "\nThrough Device*:" << endl;
    dp->performTask();
    cout << "Through RobotDevice*:" << endl;
    rp->performTask();
    return 0;
}
