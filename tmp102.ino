//////////////////////////////////////////////////////////////////
//©2011 bildr
//Released under the MIT License - Please reuse change and share
//Simple code for the TMP102, simply prints temperature via serial
//////////////////////////////////////////////////////////////////

int tmp102Address = 0x48;
char szInfo[128];

void setup(){
  Serial.begin(9600);
  Wire.begin();
}

void loop(){

  float celsius = getTemperature();
  Serial.print("Celsius: ");
  Serial.println(celsius);


  float fahrenheit = (1.8 * celsius) + 32;  
  Serial.print("Fahrenheit: ");
  Serial.println(fahrenheit);
  
  sprintf(szInfo, "Temperature: %2.2f Degree (%2.2f F)", celsius, fahrenheit);
  
  Spark.publish("tmpinfo", szInfo);

  delay(1000); //just here to slow down the output. You can remove this
}

float getTemperature(){
  Wire.requestFrom(tmp102Address,2); 

  byte MSB = Wire.read();
  byte LSB = Wire.read();

  //it's a 12bit int, using two's compliment for negative
  int TemperatureSum = ((MSB << 8) | LSB) >> 4; 

  float celsius = TemperatureSum*0.0625;
  
  return celsius;
}
