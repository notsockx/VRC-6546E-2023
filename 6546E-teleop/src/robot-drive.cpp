/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       robot-drive.cpp                                           */
/*    Author:       Emilio Orcullo                                            */
/*    Created:      Thu Dec 22 2022                                           */
/*    Description:  Driver control functions                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// DO NOT TOUCH
#include "vex.h"
#include "robot-config.h"

using namespace vex;

// drive variables
bool IntakeOn = false;

// responsible for grabbing user input
void GetUserInput(void) {
  
}

// updates controller screen
void UpdateControllerUI(void) {
  while (1) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print(
      DriveRight1.power() + DriveRight2.power() + DriveRight3.power() +
      DriveLeft1.power() + DriveLeft2.power() + DriveLeft3.power());
    task::sleep(100);
  }
}

// responsible for updating drivebase movement
void DriveControl(void) {
  // drive variables
  int x;
  int y;
  int maxV;
  while (1) {
    // map controller input to coordinate space w/ axis units of milivolts
    x = Controller1.Axis1.value() * 94.4881889764;
    y = Controller1.Axis2.value() * 94.4881889764;
    // 94.4881889764 = 12000/127

    // todo: rate profile calculations
    // see https://www.desmos.com/calculator/r5pkxlxhtb

    // get maximum axis value
    maxV = abs(x * int(abs(x) > abs(y)) + y * int(abs(y) >= abs(x)));

    if (y >= 0) {
      if (x >= 0) {   // quadrant 1
        DriveRight.spin(fwd, y - x, voltageUnits(mV));
        DriveLeft.spin(fwd, maxV, voltageUnits(mV));
      } else {        // quadrant 2
        DriveRight.spin(fwd, maxV, voltageUnits(mV));
        DriveLeft.spin(fwd, y + x, voltageUnits(mV));
      }
    } else {
      if (x >= 0) {   // quadrant 4
        DriveRight.spin(reverse, maxV, voltageUnits(mV));
        DriveLeft.spin(reverse, -y - x, voltageUnits(mV));
      } else {        // quadrant 3
        DriveRight.spin(reverse, -y + x, voltageUnits(mV));
        DriveLeft.spin(reverse, maxV, voltageUnits(mV));
      }
    }
  }
}

// controls intake
void IntakeControl(void) {
  if (IntakeOn) {
    Intake.spin(fwd, 100, pct);
  } else {
    Intake.stop();
  }
  IntakeOn = !IntakeOn;
}
