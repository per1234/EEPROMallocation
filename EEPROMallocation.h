// EEPROMallocation - Arduino library for automatic allocation of unique EEPROM addresses for any variable type. http://github.com/per1234/EEPROMallocation
#ifndef EEPROMallocation_h
#define EEPROMallocation_h

#include <Arduino.h>

class EEPROMallocationClass {
  public:
    EEPROMallocationClass();
#ifdef E2END
    boolean setRange(const unsigned int startAddressInput, const unsigned int endAddressInput = E2END);
#else
    boolean setRange(const unsigned int startAddressInput, const unsigned int endAddressInput);
#endif
    int getAddress(const byte sizeInput = 1);
    byte getBit();
  private:
    static const int8_t failValue = -1;
    unsigned int startAddress;
    unsigned int endAddress;
    unsigned int freeAddress;
    unsigned int freeBitAddress;
    byte freeBit;
};

extern EEPROMallocationClass EEPROMallocation;  //declare the class so it doesn't have to be done in the sketch
#endif

