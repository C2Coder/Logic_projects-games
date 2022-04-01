#include "Logic.hpp"
#include <iostream>

    int pointY = 0;
    int pointX = 0;

    int foodX = random(0, 10);
    int foodY = random(0, 10);
    int foodCount = 0;

    int barvaR = random(0, 256);
    int barvaG = random(0, 256);
    int barvaB = random(0, 256);

    int headBarvaR = barvaR - 50;
    int headBarvaG = barvaG - 50;
    int headBarvaB = barvaB - 50;


    int lastPosX1 = 0;
    int lastPosX2 = 0;
    int lastPosX3 = 0;
    int lastPosX4 = 0;
    int lastPosX5 = 0;
    int lastPosX6 = 0;
    int lastPosX7 = 0;
    int lastPosX8 = 0;
    int lastPosX9 = 0;
    int lastPosY1 = 0;
    int lastPosY2 = 0;
    int lastPosY3 = 0;
    int lastPosY4 = 0;
    int lastPosY5 = 0;
    int lastPosY6 = 0;
    int lastPosY7 = 0;
    int lastPosY8 = 0;
    int lastPosY9 = 0;
    int foodtest = 0;

void lastPosChange () {
    lastPosX9 = lastPosX8;
    lastPosX8 = lastPosX7;
    lastPosX7 = lastPosX6;
    lastPosX6 = lastPosX5;
    lastPosX5 = lastPosX4;
    lastPosX4 = lastPosX3;
    lastPosX3 = lastPosX2;
    lastPosX2 = lastPosX1;
    lastPosX1 = pointX;

    lastPosY9 = lastPosY8;
    lastPosY8 = lastPosY7;
    lastPosY7 = lastPosY6;
    lastPosY6 = lastPosY5;
    lastPosY5 = lastPosY4;
    lastPosY4 = lastPosY3;
    lastPosY3 = lastPosY2;
    lastPosY2 = lastPosY1;
    lastPosY1 = pointY;

}


void logicMain() {

    foodCount = 0;
    
    buttons.onPress([] {
        lastPosChange();
        pointY -= 1;
        if (pointY < 0) {
            pointY = 9;
        }
    }, Up);

    buttons.onPress([] {
        lastPosChange();
        pointY += 1;
        if (pointY > 9) {
            pointY = 0;
        }
    }, Down);

    buttons.onPress([] {
        lastPosChange();
        pointX -= 1;
        if (pointX < 0) {
            pointX = 9;
        }
    }, Left);

    buttons.onPress([] {
        lastPosChange();
        pointX += 1;
        if (pointX > 9) {
            pointX = 0;
        }
    }, Right);

    buttons.onPress([] {
        barvaR = random(0, 256);
        barvaG = random(0, 256);
        barvaB = random(0, 256);
    }, RightDown);



    while (true) {

        if(pointX == foodX && pointY == foodY){

            foodCount += 1;
            foodX = random(0, 10);
            foodY = random(0, 10);
            
            ;           
        };

        

        display.clear();
        display.setColor(pointX, pointY, Rgb(headBarvaR, headBarvaG, headBarvaB));
        display.setColor(foodX, foodY, Rgb(255, 0, 0));

        if (foodCount > 0) {
        display.setColor(lastPosX1, lastPosY1, Rgb(barvaR, barvaG, barvaB));
        };

        if (foodCount > 1) {
        display.setColor(lastPosX2, lastPosY2, Rgb(barvaR, barvaG, barvaB));
        };

        if (foodCount > 2) {
        display.setColor(lastPosX3, lastPosY3, Rgb(barvaR, barvaG, barvaB));
        };

        if (foodCount > 3) {
        display.setColor(lastPosX4, lastPosY4, Rgb(barvaR, barvaG, barvaB));
        };

        if (foodCount > 4) {
        display.setColor(lastPosX5, lastPosY5, Rgb(barvaR, barvaG, barvaB));
        };

        if (foodCount > 5) {
        display.setColor(lastPosX6, lastPosY6, Rgb(barvaR, barvaG, barvaB));
        };

        if (foodCount > 6) {
        display.setColor(lastPosX7, lastPosY7, Rgb(barvaR, barvaG, barvaB));
        };

        if (foodCount > 7) {
        display.setColor(lastPosX8, lastPosY8, Rgb(barvaR, barvaG, barvaB));
        };

    
        if (foodCount > 8) {
        display.setColor(lastPosX9, lastPosY9, Rgb(barvaR, barvaG, barvaB));
        };

        headBarvaR = barvaR - 50;
        headBarvaG = barvaG - 50;
        headBarvaB = barvaB - 50;

        display.show(100);

        delay(30);
    }
}