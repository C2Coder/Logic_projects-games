#include "Logic.hpp"
#include <iostream>

const int MAX_TEMPERATURE = 32;

std::array<Rgb, MAX_TEMPERATURE + 1> Paleta1{
    Rgb(0, 0, 0),
    Rgb(10, 7, 10),
    Rgb(31, 7, 7),
    Rgb(47, 15, 7),
    Rgb(71, 15, 7),
    Rgb(87, 23, 7),
    Rgb(103, 31, 7),
    Rgb(119, 31, 7),
    Rgb(143, 39, 7),
    Rgb(159, 47, 7),
    Rgb(175, 63, 7),
    Rgb(191, 71, 7),
    Rgb(199, 71, 7),
    Rgb(223, 79, 7),
    Rgb(223, 87, 7),
    Rgb(223, 87, 7),
    Rgb(215, 95, 7),
    Rgb(215, 95, 7),
    Rgb(215, 103, 15),
    Rgb(207, 111, 15),
    Rgb(207, 119, 15),
    Rgb(207, 120, 15),
    Rgb(207, 120, 23),
    Rgb(199, 120, 23),
    Rgb(199, 125, 23),
    Rgb(199, 125, 31),
    Rgb(191, 130, 31),
    Rgb(191, 130, 31),
    Rgb(191, 130, 39),
    Rgb(191, 135, 47),
    Rgb(183, 135, 47),
    Rgb(183, 140, 47),
    Rgb(183, 140, 55)

};



int firePixels[10][10];

void drawFire()
{
    for (int X = 0; X < 10; X++)
    {
        for (int Y = 0; Y < 10; Y++)
        {
            display.setColor(X, Y, Paleta1[firePixels[X][Y]]);
        }
    }
    display.show(25);
}

void startFire()
{
    for (int X = 0; X < 10; X++)
    {
        firePixels[X][9] = MAX_TEMPERATURE - random(0, 10);

    }
}

void stopFire()
{
    for (int X = 4; X < 6; X++)
    {
        firePixels[X][9] = 0;
    }
}

void doFire()
{
    for (int X = 0; X < 10; X++)
    {
        for (int Y = 1; Y < 10; Y++)
        {
            int puvodniTeplota = firePixels[X][Y];
            int novaTeplota = puvodniTeplota - random(1, 11);

            if (novaTeplota < 1)
            {
                novaTeplota = 0;
            };

            firePixels[X][Y - 1] = novaTeplota;
            
        }
    }
}





void logicMain()
{
    //startFire();

    while (true)
    {
        startFire();

        doFire();
        drawFire();

        delay(100);
    }
}