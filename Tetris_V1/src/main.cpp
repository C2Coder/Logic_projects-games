#include <Logic.hpp>
#include <iostream>

char testFrame[12][12];

char frame[12][12];

int diffX = 4;
int diffY = 0;

int pieceRotation = 1;

char Tpiece[4][5][5] {
    { { 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 } },
    { { 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 1, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0 } },
    { { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 1, 1, 1, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0 } },
    { { 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 1, 1, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0 } }
};

void displayFrame() {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (frame[x + 1][y + 1] == 1) {
                display.setColor(x, y, Rgb(0, 125, 125));
            } else {
                display.setColor(x, y, Rgb(0, 0, 0));
            }
        }
    }
    display.show(50);
}

void printPiece() {

    if (pieceRotation >= 5) {
        pieceRotation = 1;
    }
    if (pieceRotation <= 0) {
        pieceRotation = 4;
    }

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (Tpiece[pieceRotation - 1][y][x] == 1) {
                testFrame[4 - x + diffX][diffY + y + 2] = 1;
                //display.setColor(4 - x, y, Rgb(0, 125, 0));
            } else {
                testFrame[4 - x + diffX][diffY + y + 2] = 0;
                //display.setColor(4 - x, y, Rgb(0, 0, 0));
            }
        }
    }
    //display.show(100);
    //display.clear();
}

void test() {
    bool fail = false;
    for (int i = 0; i < 12; i++) {
        if (testFrame[0][i] == 1) {
            fail = true;
        }
        if (testFrame[11][i] == 1) {
            fail = true;
        }
        if (testFrame[i][0] == 1) {
            fail = true;
        }
        if (testFrame[i][11] == 1) {
            fail = true;
        }
    }

    if (fail != true) {

        for (int x = 0; x < 12; x++) {
            for (int y = 0; y < 12; y++) {
                frame[x][y] = testFrame[x][y];
            }
        }
    }
}

void loop() {

    printPiece();
    test();
    displayFrame();

    /*for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            int h = hues[x][y];
            display.setColor(x, y, Hsv(h, 255, 255));
        }
    }*/
}

void logicMain() {

    buttons.onPress([]() {
        pieceRotation--;
    },
        RightDown);
    buttons.onPress([]() {
        pieceRotation++;
    },
        LeftDown);

    buttons.onPress([]() {
        diffX++;
    },
        Right);
    buttons.onPress([]() {
        diffX--;
    },
        Left);

    while (true) {
        loop();
    }
}