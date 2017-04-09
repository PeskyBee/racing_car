#ifndef __HELPERS_H_
#define __HELPERS_H_

namespace rc {
enum MovementStates {
    IDLE = 0,
    FORWARD = 1 << 3,
    REVERSE = 1 << 2,
    LEFT = 1 << 1,
    RIGHT = 1 << 0
};

/** updates movement state according to the newly given mask **/
unsigned int updateState(unsigned int state, unsigned int mask) {
    return state ^ mask;
}

}

#endif
