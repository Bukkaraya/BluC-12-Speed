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
  pinMode(x_pin,INPUT);//accelerometer input
  pinMode(y_pin,INPUT);
}

void loop()
{
  x_value = analogRead(x_pin); //analog reading accelerometer values
  delay(2000);
  y_value = analogRead(y_pin);
  Serial.print(".");
  Serial.println(x_value);
  Serial.print("!");
  Serial.println(y_value);
  delay(2000);//delay of 2 seconds
}
