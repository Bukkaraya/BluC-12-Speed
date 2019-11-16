//define the pins
const int xaxis = A3;
const int yaxis = A2;
const int zaxis = A1;

void setup() {
  // put your setup code here, to run once:
  //initialize the serial communication
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //print the sensor values:
  Serial.print(analogRead(xaxis));
  Serial.print("\t");
  Serial.print(analogRead(yaxis));
  Serial.print("\t");
  Serial.print(analogRead(zaxis));
  Serial.println();

  delay(3000);

}
