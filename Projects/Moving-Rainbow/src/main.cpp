#include "Logic.hpp"
#include <iostream>

int posun = 0;

void logicMain() {
    while (true) {
        posun++;

        for (int y = 0; y < 10; y = y + 1) {
            for (int x = 0; x < 10; x = x + 1) {
                int Hue = 255.0 / 70 * y * x + posun;
                if (Hue > 255) {
                    Hue = Hue - 255;
                }
                display.setColor(x, y, Hsv(Hue, 255, 255));
            }
            display.show(25);
        }
    }
}