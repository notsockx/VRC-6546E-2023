using namespace vex;

extern brain Brain;
extern controller Controller1;

// drivebase
extern motor DriveRight1;
extern motor DriveRight2;
extern motor DriveRight3;
extern motor DriveLeft1;
extern motor DriveLeft2;
extern motor DriveLeft3;
extern motor_group DriveRight;
extern motor_group DriveLeft;

// intake
extern motor Intake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void );