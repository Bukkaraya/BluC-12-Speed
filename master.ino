/*
 * CONNECT TO OUTGOING PORT HC-05 'DEV-B' TO VIEW DATA ON SERIAL MONITOR
 * USE THIS SKETCH ONLY FOR VIEWING SENSOR DATA ON SERIAL MONITOR.....NOT FOR FILE WRITING
 */
const int x_pin = A3;
const int y_pin = A2;
int x_value, y_value;

void setup()
{
  Serial.begin(38400);
  //accelerometer input
  pinMode(x_pin,INPUT);
  pinMode(y_pin,INPUT);
}

void loop()
{
  x_value = analogRead(x_pin); //analog reading accelerometer values
  y_value = analogRead(y_pin);
  sendPacket(x_value, y_value);
  delay(2000);//delay of 2 seconds
}


void sendPacket(int x, int y) {
     // Start Delimiter is .
     Serial.write(".");
     // Send x
     Serial.print("x");
     Serial.print(x);
     Serial.print(",");
     // Send y
     Serial.print("y");
     Serial.print(y);
     Serial.print(",");
     // End Delimiter is !
     Serial.write("!"); 
}
