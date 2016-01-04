EEPROMallocation
==========

[Arduino](http://arduino.cc/) library that makes it easy to automatically allocate unique EEPROM addresses for any variable type.

The concept for this library comes from the [EEPROMEx](https://github.com/thijse/Arduino-EEPROMEx) library. The Arduino EEPROM v2.0 library now provides most of the functions of EEPROMEx except for address allocation.


<a id="installation"></a>
#### Installation
- Download the most recent version of EEPROMallocation here: https://github.com/per1234/EEPROMallocation/archive/master.zip
- Using Arduino IDE 1.0.x:
  - Sketch > Import Library... > Add Library... > select the downloaded file > Open
- Using Arduino IDE 1.5+:
  - Sketch > Include Library > Add ZIP Library... > select the downloaded file > Open


<a id="usage"></a>
#### Usage
See **File > Examples > EEPROMallocation > EEPROMallocationExample** for demonstration of library usage.

`EEPROMallocation.setRange(startAddress[, endAddress])` - Set the range of EEPROM addresses that can be allocated.
- Parameter: **startAddress** - The first address of the EEPROM range available for allocation. The initial value is 0.
  - Type: unsigned int
- Parameter(optional): **endAddress** - The last address of the EEPROM range available for allocation. The default value is the last EEPROM address(AVR only). The initial value is the last EEPROM address for AVR or 511 otherwise.
  - Type: unsigned int
- Returns: `true` = success, `false` = invalid range
  - Type: boolean

`EEPROMallocation.getAddress([size])` - Get an available EEPROM address. EEPROMallocation will return the same address values every time the program is ran as long as the calls to getAddress() are always in the same order.
- Parameter(optional): **size** - The number of bytes required. If size is 0 then this function will return an address with available bits. The default value is 1 byte.
  - Type: byte
- Returns: The allocated address or `-1` for no address available.
  - Type: int

`EEPROMallocation.getBit()` - Get the next available bit of the EEPROM address returned by EEPROMallocation.getAddress(0).
- Returns: The allocated bit number.
  - Type: byte

