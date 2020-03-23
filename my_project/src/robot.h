#ifndef __MY_ROBOT_AGENT__H
#define __MY_ROBOT_AGENT__H 

#include "enviro.h"

using namespace enviro;

#define NUM_POSITION_BUFFER 100

class MyRobotController : public Process, public AgentInterface {

    public:
    MyRobotController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update();
    void stop() {}

    private:
    /* This function is to convert an angle from degrees to rotation */
    void degreeToRotation(double degree);
    /* This function is to check if the robot is stuck and cannot move */
    bool cannotMove();

    int32_t x_positions[NUM_POSITION_BUFFER];
};

class MyRobot : public Agent {
    public:
    MyRobot(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    MyRobotController c;
};

DECLARE_INTERFACE(MyRobot)

#endif
