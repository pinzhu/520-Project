#include <iostream>
#include "robot.h"
#include <cmath>

using namespace enviro;

/* This function is to convert an angle from degrees to rotation */
void MyRobotController::degreeToRotation(double degree) {
    double radian = 0.0174533*degree;

    teleport(position().x, position().y, radian);
}

/* This function is to check if the robot is stuck and cannot move */
bool MyRobotController::cannotMove() {
    double check = 5;

    for (int i = 1; i < NUM_POSITION_BUFFER; i++) {
        if (abs(x_positions[0]-x_positions[i]) > check) {
           return false; // can move
        }
    }

    // cannot move
    return true;
}

/* Call back function */
void MyRobotController::update() {
    static uint32_t val;
    

    /* Initialize */
    if (val == 0) {
        for (int i = 0; i < NUM_POSITION_BUFFER; i++) {
            x_positions[i] = 0;
        }
    }

    /* Get the Position */
    x_positions[val % NUM_POSITION_BUFFER] = position().x;

    /* No ration and move forward */
    track_velocity(15,0);

    if (sensor_value(0) < 5.5) {
        if (val % 2 != 0) 
            degreeToRotation(0); // don't rotate
        else
            degreeToRotation(90); // rorate 45 degree
        val++;
    }

    /* If robot is stucked, start over from the beginning */
    if ((position().x > 330) || cannotMove() ){
        teleport(-320, -150, 0);
    }
}
