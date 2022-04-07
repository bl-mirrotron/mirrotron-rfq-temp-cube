#include "BlinkyBus.h"
#include <OneWire.h>
#define BAUD_RATE  19200
#define commLEDPin    13

#define BLINKYBUSBUFSIZE  11
union BlinkyBusUnion
{
  struct
  {
    int16_t state;
    int16_t i16_temp1;
    int16_t i16_temp2;
    int16_t i16_temp3;
    int16_t i16_temp4;
    int16_t i16_temp5;
    int16_t i16_temp6;
    int16_t i16_temp7;
    int16_t i16_temp8;
    int16_t i16_interval;
    int16_t i16_watchdog;
  };
  int16_t buffer[BLINKYBUSBUFSIZE];
} bb;
BlinkyBus blinkyBus(bb.buffer, BLINKYBUSBUFSIZE, Serial1, commLEDPin);

struct DS18B20
{
  int signalPin;
  int powerPin;
  byte chipType;
  byte address[8];
  OneWire oneWire;
  float temp = 0.0;
};

DS18B20 dS18B20_1;
DS18B20 dS18B20_2;
DS18B20 dS18B20_3;
DS18B20 dS18B20_4;
DS18B20 dS18B20_5;
DS18B20 dS18B20_6;
DS18B20 dS18B20_7;
DS18B20 dS18B20_8;

unsigned long now;
unsigned long lastMeasurement = 0;
int ipoll = 0;

void setup() 
{
  dS18B20_1.signalPin = 6;
  dS18B20_1.powerPin = 5;
  pinMode(dS18B20_1.powerPin, OUTPUT);
  digitalWrite(dS18B20_1.powerPin, HIGH);    
  dS18B20_1.oneWire = OneWire(dS18B20_1.signalPin);
  dS18B20_1.chipType = initDS18B20(dS18B20_1.address, &dS18B20_1.oneWire);

  dS18B20_2.signalPin = 8;
  dS18B20_2.powerPin = 7;
  pinMode(dS18B20_2.powerPin, OUTPUT);
  digitalWrite(dS18B20_2.powerPin, HIGH);    
  dS18B20_2.oneWire = OneWire(dS18B20_2.signalPin);
  dS18B20_2.chipType = initDS18B20(dS18B20_2.address, &dS18B20_2.oneWire);

  dS18B20_3.signalPin = 10;
  dS18B20_3.powerPin = 9;
  pinMode(dS18B20_3.powerPin, OUTPUT);
  digitalWrite(dS18B20_3.powerPin, HIGH);    
  dS18B20_3.oneWire = OneWire(dS18B20_3.signalPin);
  dS18B20_3.chipType = initDS18B20(dS18B20_3.address, &dS18B20_3.oneWire);

  dS18B20_4.signalPin = 12;
  dS18B20_4.powerPin = 11;
  pinMode(dS18B20_4.powerPin, OUTPUT);
  digitalWrite(dS18B20_4.powerPin, HIGH);    
  dS18B20_4.oneWire = OneWire(dS18B20_4.signalPin);
  dS18B20_4.chipType = initDS18B20(dS18B20_4.address, &dS18B20_4.oneWire);

  dS18B20_5.signalPin = 14;
  dS18B20_5.powerPin = 15;
  pinMode(dS18B20_5.powerPin, OUTPUT);
  digitalWrite(dS18B20_5.powerPin, HIGH);    
  dS18B20_5.oneWire = OneWire(dS18B20_5.signalPin);
  dS18B20_5.chipType = initDS18B20(dS18B20_5.address, &dS18B20_5.oneWire);

  dS18B20_6.signalPin = 16;
  dS18B20_6.powerPin = 17;
  pinMode(dS18B20_6.powerPin, OUTPUT);
  digitalWrite(dS18B20_6.powerPin, HIGH);    
  dS18B20_6.oneWire = OneWire(dS18B20_6.signalPin);
  dS18B20_6.chipType = initDS18B20(dS18B20_6.address, &dS18B20_6.oneWire);

  dS18B20_7.signalPin = 18;
  dS18B20_7.powerPin = 19;
  pinMode(dS18B20_7.powerPin, OUTPUT);
  digitalWrite(dS18B20_7.powerPin, HIGH);    
  dS18B20_7.oneWire = OneWire(dS18B20_7.signalPin);
  dS18B20_7.chipType = initDS18B20(dS18B20_7.address, &dS18B20_7.oneWire);

  dS18B20_8.signalPin = 20;
  dS18B20_8.powerPin = 21;
  pinMode(dS18B20_8.powerPin, OUTPUT);
  digitalWrite(dS18B20_8.powerPin, HIGH);    
  dS18B20_8.oneWire = OneWire(dS18B20_8.signalPin);
  dS18B20_8.chipType = initDS18B20(dS18B20_8.address, &dS18B20_8.oneWire);

  Serial1.begin(BAUD_RATE);
  bb.state = 1; //init
  bb.i16_watchdog = 0; //init
  bb.i16_interval = 10000;
  blinkyBus.start();
  lastMeasurement = millis(); 
  
//  Serial.begin(9600);

}

void loop() 
{
  now = millis();
  if ((now - lastMeasurement) > bb.i16_interval)
  {
    lastMeasurement = now;
    dS18B20_1.temp = getDS18B20Temperature(&dS18B20_1.oneWire, dS18B20_1.address, dS18B20_1.chipType);
    dS18B20_2.temp = getDS18B20Temperature(&dS18B20_2.oneWire, dS18B20_2.address, dS18B20_2.chipType);
    dS18B20_3.temp = getDS18B20Temperature(&dS18B20_3.oneWire, dS18B20_3.address, dS18B20_3.chipType);
    dS18B20_4.temp = getDS18B20Temperature(&dS18B20_4.oneWire, dS18B20_4.address, dS18B20_4.chipType);
    dS18B20_5.temp = getDS18B20Temperature(&dS18B20_5.oneWire, dS18B20_5.address, dS18B20_5.chipType);
    dS18B20_6.temp = getDS18B20Temperature(&dS18B20_6.oneWire, dS18B20_6.address, dS18B20_6.chipType);
    dS18B20_7.temp = getDS18B20Temperature(&dS18B20_7.oneWire, dS18B20_7.address, dS18B20_7.chipType);
    dS18B20_8.temp = getDS18B20Temperature(&dS18B20_8.oneWire, dS18B20_8.address, dS18B20_8.chipType);

    bb.i16_temp1  = (int16_t) (dS18B20_1.temp * 10.0);
    bb.i16_temp2  = (int16_t) (dS18B20_2.temp * 10.0);
    bb.i16_temp3  = (int16_t) (dS18B20_3.temp * 10.0);
    bb.i16_temp4  = (int16_t) (dS18B20_4.temp * 10.0);
    bb.i16_temp5  = (int16_t) (dS18B20_5.temp * 10.0);
    bb.i16_temp6  = (int16_t) (dS18B20_6.temp * 10.0);
    bb.i16_temp7  = (int16_t) (dS18B20_7.temp * 10.0);
    bb.i16_temp8  = (int16_t) (dS18B20_8.temp * 10.0);
    bb.i16_watchdog = bb.i16_watchdog + 1;
    if ( bb.i16_watchdog > 32760 ) bb.i16_watchdog = 0;

/*
    Serial.print(bb.i16_temp1);
    Serial.print(" ");
    Serial.print(bb.i16_temp2);
    Serial.print(" ");
    Serial.print(bb.i16_temp3);
    Serial.print(" ");
    Serial.print(bb.i16_temp4);
    Serial.print(" ");
    Serial.print(bb.i16_temp5);
    Serial.print(" ");
    Serial.print(bb.i16_temp6);
    Serial.print(" ");
    Serial.print(bb.i16_temp7);
    Serial.print(" ");
    Serial.print(bb.i16_temp8);
    Serial.print(" ");
    Serial.print(bb.i16_watchdog);
    Serial.print(" ");
    Serial.println(" ");
*/   
  }
  ipoll = blinkyBus.poll();
  if (ipoll == 2)
  {
    if (blinkyBus.getLastWriteAddress() == 9) {} //measurement interval changed
  }
  blinkyBus.poll();
}

byte initDS18B20(byte* addr, OneWire* ow)
{
  byte type_s = 0;
  if ( !ow->search(addr)) 
  {
    ow->reset_search();
    delay(250);
    return 0;
  }
   
  // the first ROM byte indicates which chip
  switch (addr[0]) 
  {
    case 0x10:
      type_s = 1;
      break;
    case 0x28:
      type_s = 0;
      break;
    case 0x22:
      type_s = 0;
      break;
    default:
      return 0;
  } 
  return type_s;
}
float getDS18B20Temperature(OneWire* ow, byte* addr, byte chipType)
{
  byte i;
  byte data[12];
  float celsius;
  ow->reset();
  ow->select(addr);
  ow->write(0x44, 1);        // start conversion, with parasite power on at the end
  
  delay(750);     // maybe 750ms is enough, maybe not
  
  ow->reset();
  ow->select(addr);    
  ow->write(0xBE);         // Read Scratchpad

  for ( i = 0; i < 9; i++) data[i] = ow->read();
  int16_t raw = (data[1] << 8) | data[0];
  if (chipType) 
  {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10)  raw = (raw & 0xFFF0) + 12 - data[6];
  }
  else 
  {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
  }
  celsius = (float)raw / 16.0;
  return celsius;
  
}
