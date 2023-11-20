#include "engine.h"

void init() {

}

void destroy() {

}

void tick() {

}

void render() {

}

void engine_create() {
    window_create(init, destroy, tick, render);
}