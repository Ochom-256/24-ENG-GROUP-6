// Code sketch for Solar Charging cabinets for Motocycle Batteries

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include <Wire.h>
#include <Adafruit_INA219.h>
Adafruit_INA219 ina219;

#include <OneWire.h>
#include <DallasTemperature.h>
#define tempPin 9 // Data wire is connected to digital pin 11 on the Arduino Nano
OneWire DS18B20(tempPin); // Setup a oneWire instance to communicate with any OneWire device
DallasTemperature tempSensor(&DS18B20); // Pass oneWire reference to DallasTemperature library

String battery_temp;
int buzzer = 7;
int fan = 8;

void setup() {
     Serial.begin(9600);
     pinMode(buzzer, OUTPUT);
     pinMode(fan, OUTPUT);
     
     tempSensorSetUp();
     ina219_currentSensorSetUp();
     
     lcd.init(); // initiate the LCD
     lcd.backlight(); // Turn On the LED backlight on the LCD display
     lcd.setCursor(3,0);
     lcd.print("Motocycle"); 
     
     lcd.setCursor(0,1);
     lcd.print("Battery Monitor");
     
     delay(4000);
     lcd.clear();
}

void loop() {
      float c, f;
      getTemperatureReadings(&c, &f); // pass by reference to
      if (c > 28.8){
         digitalWrite(fan, HIGH);
      }
      else{
         digitalWrite(fan, LOW);
      }    
      battery_temp = (String)c + "*C";
      Serial.print("\nTemperature: ");
      
      Serial.print(battery_temp);
      Serial.print(" | ");  
      
      Serial.print(f);
      Serial.println("F");
      
      get_ina219_measurementValues();
}

void ina219_currentSensorSetUp(){  
      /*
      Initialize the INA219.
      By default the initialization will use the largest range (32V, 2A).  However
      you can call a setCalibration function to change this range (see comments).
      */
      if (! ina219.begin()) {
        Serial.println("Failed to find INA219 chip");
        while (1) { delay(10); }
      }
      /*
      To use a slightly lower 32V, 1A range (higher precision on amps):
      ina219.setCalibration_32V_1A();
       Or to use a lower 16V, 400mA range (higher precision on volts and amps):
      ina219.setCalibration_16V_400mA();
      */
      Serial.println("Measuring voltage and current with INA219...");
}

void get_ina219_measurementValues(){
    
      float shuntvoltage, busvoltage, current_mA, loadvoltage, power_mW;
    
      shuntvoltage = ina219.getShuntVoltage_mV();
      busvoltage = ina219.getBusVoltage_V();
      current_mA = ina219.getCurrent_mA();
      power_mW = ina219.getPower_mW();
      loadvoltage = busvoltage + (shuntvoltage / 1000);
      
      // check if battery is almost full
      if (loadvoltage > 3.80 and current_mA < 5.00){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("Battery Full");

          digitalWrite(buzzer, HIGH);
          delay(1000);
          digitalWrite(buzzer, LOW);
          delay(1000);
      }
      String busVoltage = "\n\nBus Voltage:  " + (String)busvoltage + " V";
      Serial.print(busVoltage);
      
      String shuntVoltage = "\nShunt Voltage:  " + (String)shuntvoltage + " mV";
      Serial.print(shuntVoltage);
      
      String lcd_V, loadVoltage = "\nLoad Voltage:  " + (String)loadvoltage + " V";  
      Serial.print(loadVoltage);

      lcd_V = (String)loadvoltage + "V,"; 
      lcd.setCursor(1,0);
      lcd.print(lcd_V);
   
      String lcd_I, Current = "\nCurrent:  " + (String)current_mA + " mA";
      Serial.print(Current);
      lcd_I = (String)current_mA + "mA";
      lcd.setCursor(9,0);
      lcd.print(lcd_I);

      String lcd_P, Power = "\nPower:  " + (String)power_mW + " mW";    
      Serial.print(Power);
      lcd_P = (String)power_mW + "mW,";  
      lcd.setCursor(0,1);
      lcd.print(lcd_P);

      lcd.setCursor(9,1);
      lcd.print(battery_temp);
      
      delay(4000);
      lcd.clear(); // clears screen to prevent display over writes 
}

void tempSensorSetUp(){
      tempSensor.begin(); // initiate the temperature sensor
}

void getTemperatureReadings(float *celsius, float *fahrenheit){
      tempSensor.requestTemperatures(); // Send the command to get temperatures
      *celsius = tempSensor.getTempCByIndex(0); // store temperature in Celsius
      *fahrenheit = (tempSensor.getTempCByIndex(0) * 9.0) / 5.0 + 32.0; // convert Celsius to fahrenheit and store
}
