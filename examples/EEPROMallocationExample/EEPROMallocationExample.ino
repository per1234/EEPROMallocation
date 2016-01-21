// Demonstrates usage of the EEPROMallocation library
#include <EEPROMallocation.h>
#include <EEPROM.h>

int address1;
int address2;
byte address2bit;

void setup() {
  Serial.begin(9600);

  // set the range and check if it was successful
  if (EEPROMallocation.setRange(20) == false) {
    Serial.println(F("Invalid EEPROM address range"));
    while (true);
  }

  // write an int
  const byte x = 42;
  address1 = EEPROMallocation.getAddress(sizeof(x));

  if (address1 == -1) {  //check if there was an available address
    Serial.println(F("No EEPROM address available for allocation"));
  }
  else {
    Serial.print(F("Writing value: "));
    Serial.print(x);
    Serial.print(F(" to EEPROM address: "));
    Serial.println(address1);
    EEPROM.write(address1, x);

    Serial.print(F("Read value from EEPROM: "));
    Serial.println(EEPROM.read(address1));
  }

  // write a boolean value to a bit
  address2 = EEPROMallocation.getAddress(0);
  if (address2 == -1) {  //check if there was an available address
    Serial.println(F("No EEPROM address available for allocation"));
  }
  else {
    const boolean y = true;
    address2bit = EEPROMallocation.getBit();
    byte value = EEPROM.read(address2);  //read the byte at address2

    Serial.print(F("Writing value: "));
    Serial.print(y ? F("true") : F("false"));
    Serial.print(F(" to EEPROM address: "));
    Serial.print(address2);
    Serial.print(F(", bit: "));
    Serial.println(address2bit);

    bitWrite(value, address2bit, y);  //write the bit to the byte
    EEPROM.write(address2, value);  //write the byte to EEPROM

    Serial.print(F("Read value from EEPROM: "));
    Serial.println(bitRead(EEPROM.read(address2), address2bit) ? "true" : "false");
  }
}

void loop() {
}

