int received_data;
String conversion_buffer;
int value;
int x_value;
int y_value;

void setup() {
  // put your setup code here, to run once:
  //pinMode(receive_data, OUTPUT);
  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    received_data = Serial.read();
    if(received_data == '.') {
      Serial.print("Receiving Data...");
      value = Serial.read();
      while(value != '!') {
        if(value == 'x') {
          Serial.println("Value if for X");
          conversion_buffer = Serial.readStringUntil(',');
          x_value = conversion_buffer.toInt();
        }

        if(value == 'y') {
          Serial.println("Reading Y Value:");
          conversion_buffer = Serial.readStringUntil(',');
          y_value = conversion_buffer.toInt();
        }

        value = Serial.read();
      }

      Serial.print("X Value:");
      Serial.println(x_value);
      Serial.print("Y Value:");
      Serial.println(y_value);
    }
  }
}

void readPacket() {
  return;
}
