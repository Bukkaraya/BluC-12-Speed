int receive_data;
char received_str[20];
char empty_str[20] = "";
char conversion_buffer[5];
int  count= 0;
int x_flag = 0;
int y_flag = 0;
int x_print_flag = 0;
int y_print_flag = 0;

void setup() {
  // put your setup code here, to run once:
  //pinMode(receive_data, OUTPUT);
  Serial.begin(38400);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    receive_data = Serial.read();
    receive_data = receive_data - 48;
    if (receive_data == -2){ //if '.'
      count = 0;
      x_flag = 1;
    }
    else if (receive_data == -15){ //if '!'
      count = 0;
      y_flag = 1;
    }
    else {
      if (x_flag == 1){
        received_str[0] = "\0";
        x_flag = 0;
        x_print_flag = 1;
        y_print_flag = 0;
        count = 0;
      }
      if (y_flag == 1){
        received_str[0] = "\0";
        y_flag = 0;
        y_print_flag = 1;
        x_print_flag = 0;
        count = 0;
      }
      if (receive_data > -1){
        itoa(receive_data, conversion_buffer, 10);
        strcat(received_str, conversion_buffer);
        count++;  
      }
      if (count == 3){
        if (x_print_flag == 1){
          Serial.print("x: ");
        }
        if (y_print_flag == 1){
          Serial.print("y: ");
        }
        Serial.println(received_str);
      }
      delay(250);
    } 
  }
}

