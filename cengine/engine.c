#include "engine.h"

void init() {

}

void destroy() {

}

void tick() {

}

void render() {

}

int engine_create() {
    return window_create(init, destroy, tick, render);
}