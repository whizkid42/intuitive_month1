#include <iostream>
using namespace std;

int main() {
    string robot_name = "Intuitive Da Vinci";
    int joints = 6;
    double max_velocity = 1.0; // in m/s

    // ex1.cpp: Print robot details
    cout << "Robot Name: " << robot_name << endl;
    cout << "Number of Joints: " << joints << endl;
    cout << "Max Velocity (m/s):  " << max_velocity << endl;

    // ex2.cpp: Print sizes of variables
    cout << "Size of robot_name: " << sizeof(robot_name) << " bytes" << endl;
    cout << "Size of joints: " << sizeof(joints) << " bytes" << endl;
    cout << "Size of max_velocity: " << sizeof(max_velocity) << " bytes" << endl;

    //ex3.cpp: constant variable
    const int MAX_JOINTS = 7;
    const double MAX_VELOCITY = 1.5;

    return 0;
}