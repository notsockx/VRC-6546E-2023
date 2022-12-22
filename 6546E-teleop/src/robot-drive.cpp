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

// variables
int vTgt;
int rTgt;
bool IntakeOn = false;

// responsible for grabbing user input
void GetUserInput(void) {
  vTgt = Controller1.Axis2.position();
  rTgt = Controller1.Axis4.position();

  // todo: rate profile calculations
  // see https://www.desmos.com/calculator/r5pkxlxhtb
}

// updates controller screen
void UpdateControllerUI(void) {
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("TR: ");
  Controller1.Screen.setCursor(2, 1);
  Controller1.Screen.print("TL: ");
  Controller1.Screen.setCursor(1, 5);
  Controller1.Screen.print(DriveRight.temperature(celsius));
  Controller1.Screen.setCursor(2, 5);
  Controller1.Screen.print(DriveLeft.temperature(celsius));
}

// responsible for updating drivebase movement
void DriveControl(void) {
 while(1) {
   UpdateControllerUI();
   DriveRight.spin(fwd, Controller1.Axis2.position(), pct);
   DriveLeft.spin(fwd, Controller1.Axis3.position(), pct);
 
   task::sleep(10);
 }
}

void IntakeControl(void) {
  if(IntakeOn) { Intake.spin(fwd,100,pct); }
  else { Intake.stop(); }
  IntakeOn = !IntakeOn;
}

