#include <iostream>
using namespace std;
 
class Device {
public:
    virtual void identify() { cout << "  Device: generic device" << endl; }
    virtual ~Device() = default;
};
 
class Camera : public Device {
    int megapixels = 12;
public:
    void identify() override { cout << "  Camera: " << megapixels << " MP sensor" << endl; }
    void capture() { cout << "  Camera: capturing an image" << endl; }
};
 
class Lidar : public Device {
    double rangeMeters = 100.0;
public:
    void identify() override { cout << "  Lidar: range " << rangeMeters << " m" << endl; }
    void scan() { cout << "  Lidar: scanning the surroundings" << endl; }
};
 
int main() {
    Device dev;
    Camera cam;
    Lidar lid;
 
    // 1. Valid upcasting (derived -> base, public inheritance)
    Device* p1 = &cam;
    Device* p2 = &lid;
    Device& ref = cam;
    cout << "Upcasting:" << endl;
    p1->identify();
    p2->identify();
    ref.identify();
 
    //X Camera* bad = &dev;    // invalid: Device is not necessarily a Camera
    //X p1->capture();         // Device has no member capture()
 
    // 2. Safe downcasting with dynamic_cast
    cout << "\ndynamic_cast results:" << endl;
    Device* p3 = &dev;
    cout << "  p1 (Camera object) -> Camera*: "
         << (dynamic_cast<Camera*>(p1) ? "valid" : "nullptr") << endl;
    cout << "  p2 (Lidar object)  -> Camera*: "
         << (dynamic_cast<Camera*>(p2) ? "valid" : "nullptr") << endl;
    cout << "  p3 (Device object) -> Camera*: "
         << (dynamic_cast<Camera*>(p3) ? "valid" : "nullptr") << endl;
 
    // 3. Array of Device* (each element is a pointer, so traversal is safe)
    Device* all[] = { &dev, &cam, &lid };
    cout << "\nTraversing Device* array:" << endl;
    for (Device* p : all) {
        p->identify();
        if (Camera* c = dynamic_cast<Camera*>(p)) {
            c->capture();
        } else if (Lidar* l = dynamic_cast<Lidar*>(p)) {
            l->scan();
        } else {
            cout << "  (plain Device: no extra operation)" << endl;
        }
    }
 
    // 4. Why pointer arithmetic on Device* is unsafe (NOT executed)
    cout << "\nsizeof(Device) = " << sizeof(Device)
         << ", sizeof(Camera) = " << sizeof(Camera)
         << ", sizeof(Lidar) = " << sizeof(Lidar) << endl;
    // Camera cams[3];
    // Device* p = cams;   // legal upcast of the first element only
    // ++p;                // UNSAFE: moves by sizeof(Device), but elements are
    //                     // sizeof(Camera) apart -> p no longer points to a Camera
    return 0;
}
