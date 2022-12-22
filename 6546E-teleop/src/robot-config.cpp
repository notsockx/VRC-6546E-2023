#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// brain + controller
brain Brain;
controller Controller1 = controller(primary);

// Right drive motors     port    ratio     reversed?
motor DriveRight1 = motor(PORT11, ratio6_1, false);
motor DriveRight2 = motor(PORT12, ratio6_1, false);
motor DriveRight3 = motor(PORT14, ratio6_1, false);

// Left drive motors      port    ratio     reversed?
motor DriveLeft1  = motor(PORT20, ratio6_1, true);
motor DriveLeft2  = motor(PORT19, ratio6_1, true);
motor DriveLeft3  = motor(PORT18, ratio6_1, true);

// Drivebase motor groups
motor_group DriveRight = motor_group(DriveRight1, DriveRight2, DriveRight3);
motor_group DriveLeft = motor_group(DriveLeft1, DriveLeft2, DriveLeft3);

// Intake motors
motor Intake = motor(PORT13, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}