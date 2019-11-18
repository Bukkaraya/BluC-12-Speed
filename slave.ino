enum directions {
  STRAIGHT,
  REVERSE,
  RIGHT,
  LEFT,
  STILL
};

int received_data;
String conversion_buffer;
int value;

int x_change;
int y_change;

int BASE_X_ACCEL = 348;
int BASE_Y_ACCEL = 348;

int x_value = BASE_X_ACCEL;
int y_value = BASE_Y_ACCEL;

int TURN_THRESHOLD = 25;
int LINEAR_THRESHOLD = 15;

directions currentMovementDirection;

int carSpeed = 200;



void setup() {
  Serial.begin(38400);
}



// Design Choice: Turning has a higher priority
// than going in a linear motion. As a result it,
// has a higher threshold.


// Have to figure out proper timing.

void loop() {

  resetValues();

  if(! (Serial.available() > 0)) {
    return;
  }
  
  
  received_data = Serial.read();
  if(received_data == '.') {
    readPacket();
  }


  x_change = BASE_X_ACCEL - x_value;
  y_change = BASE_Y_ACCEL - y_value;

  currentMovementDirection = STILL;
  
  if (abs(y_change) > TURN_THRESHOLD) {
    if(y_change < 0) {
      currentMovementDirection = RIGHT;
    } else {
      currentMovementDirection = LEFT; 
    }
  } else {
    if (abs(x_change) > LINEAR_THRESHOLD) {
      if (x_change < 0) {
        currentMovementDirection = REVERSE;
      } else {
        currentMovementDirection = STRAIGHT;
      }
    }
  }

  // TODO: Figure out a way to set the car speed
  moveCar(currentMovementDirection, carSpeed);
  
  
  
}


void moveCar(directions carDirection, int carSpeed) {
  // Set the car speed here

  switch(carDirection) {
    case STRAIGHT:
      Serial.println("Move car forward");
      break;
    case REVERSE:
      Serial.println("Move car reverse");
      break;
    case RIGHT:
      Serial.println("Move car right");
      break;
    case LEFT:
      Serial.println("Move car left");
      break;
    case STILL:
    default:
      Serial.println("NOP");
      break;
  }

  // Do this for 200ms and then stop
    // car motion
    // Stop car motion here
  delay(50);
    
}


void resetValues() {
  x_value = BASE_X_ACCEL;
  y_value = BASE_Y_ACCEL;
}

void readPacket() {
  Serial.println("Receiving Data...");
  value = Serial.read();
  while(value != '!') {
    if(value == 'x') {
      conversion_buffer = Serial.readStringUntil(',');
      x_value = conversion_buffer.toInt();
    }

    if(value == 'y') {
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
