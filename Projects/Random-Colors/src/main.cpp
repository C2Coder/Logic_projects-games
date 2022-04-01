#include "Logic.hpp"
#include <iostream>

void logicMain() {
    while (true) {
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                display.setColor(x, y, Rgb(random(0, 256), random(0, 256), random(0, 256)));
                
            }
            display.show(35);
            delay(10);
        }
    }
}