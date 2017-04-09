#include <iostream>
#include <cassert>

#include "movement.h"

using namespace std;
using namespace rc;

int main() {
    assert(updateState(IDLE, FORWARD) == FORWARD);
    assert(updateState(FORWARD, IDLE) == FORWARD);
    assert(updateState(FORWARD, REVERSE) == (FORWARD | REVERSE));
    assert(updateState(FORWARD, FORWARD) == IDLE);
    assert(updateState(FORWARD | RIGHT, FORWARD) == RIGHT);
    assert(updateState(FORWARD | RIGHT, FORWARD | RIGHT) == IDLE);
    return 0;
}
