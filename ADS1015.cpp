/**************************************************************************/
/*!
    @file     Adafruit_ADS1015.cpp
    @author   Andrei Patranoiu
    @license  BSD (see license.txt)

    Driver for the ADS1015 ADC Extended from Adafruits driver for
    single ended reads. For use on Raspberry Pi's

    This is a library for the Adafruit MPL115A2 breakout
    ----> https://www.adafruit.com/products/???


*/

#include "ADS1015.h"

ADS1015::ADS1015(int address) {
    this->fd = wiringPiI2CSetup(address);
    std::cout << "Device initialization result: "<< fd << std::endl;
    if(this->fd < 0){
        //error
        exit;
    }
}

ADS1015::~ADS1015(){
    this->fd = 0;
}

int ADS1015::readADC_Single() {
    int x, data, low, high, value;

    x = wiringPiI2CWriteReg16(fd, CONFIG_REG, (DEFAULT_CONFIG));

    if(x < 0) {
        std::cout << "Error writing to ADC" << std::endl;
        return -1;
    }

    //wait for conversion to finish
    sleep(2);

    data = (wiringPiI2CReadReg16(fd, CONVERSION_REG));
    low = (data & 0xFF00) >> 8;
    high = (data & 0x00FF) << 8;
    value = high | low;

    if(value>>15 == 1){
        value = 0;
        /*value = ~value;
        value = (value | 0x0001);
        value = -(value >> 4);*/
    }
    else
        value = value >> 4;

    //std::cout << "What is my data: " << value << std::endl;
    return value;
}