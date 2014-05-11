Spark Core and TMP102 Temperature Sensor
----------------------------------------

----------
[bildr.org][1] sample application for TMP102, the only change done is publish an event with name ***tmpinfo***. Took [@bko][2]'s web page and modified to display ***tmpinfo***

###Connection###
 1. TMP006 Vcc to 3.3V
 2. TMP006 GND to GND 
 3. TMP006 SCL to D1 (with pullup resistor)
 4. TMP006 SDA to D0 (with pullup resistor)

  [1]: http://bildr.org/2011/01/tmp102-arduino/
  [2]: https://community.spark.io/t/tutorial-getting-started-with-spark-publish/3422