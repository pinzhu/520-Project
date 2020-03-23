#ifndef __BLOCK_AGENT__H
#define __BLOCK_AGENT__H 

#include "enviro.h"

using namespace enviro;

class BlockController : public Process, public AgentInterface {

    public:
    BlockController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update(){
        // This function is to push back when robot tries to move block
        damp_movement();

        // This function is to rotate
        track_velocity(0,2);
    }
    void stop() {}

};

class Block : public Agent {
    public:
    Block(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    BlockController c;
};

DECLARE_INTERFACE(Block)

#endif
