// EEPROMallocation - Arduino library for automatic allocation of unique EEPROM addresses for any variable type. http://github.com/per1234/EEPROMallocation
#include "EEPROMallocation.h"


EEPROMallocationClass::EEPROMallocationClass() {
  endAddress = E2END;  //default endAddress value
}


boolean EEPROMallocationClass::setRange(const unsigned int startAddressInput, const unsigned int endAddressInput) {
  if (startAddressInput > endAddressInput || endAddressInput > E2END) {  //sanity check
    return false;
  }
  startAddress = startAddressInput;
  if (freeAddress < startAddress) {  //handle changing the range after addresses have already been allocated
    freeAddress = startAddress;
    freeBitAddress = 0;  //in case there was a bit address allocated previous to changing the range
  }
  endAddress = endAddressInput;
  return true;
}


int EEPROMallocationClass::getAddress(const byte sizeInput) {
  if (sizeInput == 0) {  //get free address for a bit
    if (freeBit > 0) {  //there is a partially filled bit address
      return freeBitAddress;
    }
    else if (freeAddress <= endAddress) {  //use a new address
      freeBitAddress = freeAddress;
      return freeAddress++;
    }
  }
  else if (freeAddress + sizeInput - 1 <= endAddress) {
    unsigned int currentFreeAddress = freeAddress;
    freeAddress += sizeInput;
    return currentFreeAddress;
  }
  return failValue;
}


byte EEPROMallocationClass::getBit() {
  byte currentFreeBit = freeBit;
  freeBit++;
  if (freeBit >= 8) {  //now the bit address is full
    freeBit = 0;
  }
  return currentFreeBit;
}


EEPROMallocationClass EEPROMallocation;

