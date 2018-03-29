/*!
    @file     Adafruit_ADS1015.cpp
    @author   Andrei Patranoiu
    @license  BSD (see license.txt)

    Driver for the ADS1015 ADC Extended from Adafruits driver for
    single ended reads. For use on Raspberry Pi's

    This is a library for the Adafruit MPL115A2 breakout
    ----> https://www.adafruit.com/products/???


*/

#ifndef CAPSTONE_ADS1015_H
#define CAPSTONE_ADS1015_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <wiringPiI2C.h>
#include <string>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define CONFIG_REG 0x01
#define CONVERSION_REG 0x00

#define DEFAULT_CONFIG 0x83C5//0xC583
#define DEFAULT_CONFIG1 0x83
#define DEFAULT_CONFIG2 0x85

class ADS1015 {
    public:
    ADS1015(int);
    virtual ~ADS1015();

    int readADC_Single();

    private:
    int fd;


};


#endif //CAPSTONE_ADS1015_H
