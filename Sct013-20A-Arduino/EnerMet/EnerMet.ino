/*!
 * @file readACCurrent.
 * @n This example reads Analog AC Current Sensor.

 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (https://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @get from https://www.dfrobot.com

 Created 2016-3-10
 By berinie Chen <bernie.chen@dfrobot.com>

 Revised 2019-8-6
 By Henry Zhao<henry.zhao@dfrobot.com>
*/

const int ACPin = A2;         //set arduino signal read pin
#define ACTectionRange 20;    //set Non-invasive AC Current Sensor tection range (5A,10A,20A)

// VREF: Analog reference
// For Arduino UNO, Leonardo and mega2560, etc. change VREF to 5
// For Arduino Zero, Due, MKR Family, ESP32, etc. 3V3 controllers, change VREF to 3.3
#define VREF 5

float readACCurrentValue()
{
  float ACCurrtntValue = 0;
  float peakVoltage = 0;  
  float voltageVirtualValue = 0;  //Vrms
  // for (int i = 0; i < 5; i++)
  // {
    peakVoltage = analogRead(ACPin);   //read peak voltage
  //   delay(1);
  // }
  peakVoltage = peakVoltage ;   
  voltageVirtualValue = peakVoltage * 0.707;    //change the peak voltage to the Virtual Value of voltage
  /*The circuit is amplified by 2 times, so it is divided by 2.*/
  voltageVirtualValue = (voltageVirtualValue / 1024 * VREF ) / 2;  

  ACCurrtntValue = voltageVirtualValue * ACTectionRange;

  return ACCurrtntValue;
}

void setup() 
{
  Serial.begin(115200);
  
  
}

void loop() 
{
  float ACCurrentValue = readACCurrentValue(); //read AC Current Value
  Serial.print(ACCurrentValue);
  Serial.println(" A");

  float Power = 220*ACCurrentValue;
  Serial.print(Power);
  Serial.println(" W");

  
}
