// Initializing pins, numbers on board
const int pin_forward = 7;
const int pin_reverse = 8;
const int pin_left    = 5;
const int pin_right   = 6;

// Initializing bit masks
const int forward_mask = 8; // 1000
const int reverse_mask = 4; // 0100
const int left_mask    = 2; // 0010
const int right_mask   = 1; // 0001

int protocol_num; // number of current state
int forward_value = 0;
int reverse_value = 0;
int left_value = 0;
int right_value = 0; // values that will be read from Serial after applying mask
boolean commandComplete = false;

void setup() {
  pinMode(pin_forward, OUTPUT);
  pinMode(pin_reverse, OUTPUT);
  pinMode(pin_left,    OUTPUT);
  pinMode(pin_right,   OUTPUT);

  digitalWrite(pin_forward, HIGH);
  digitalWrite(pin_reverse, HIGH);
  digitalWrite(pin_left,    HIGH);
  digitalWrite(pin_right,   HIGH);

  Serial.begin(9600);
}

void loop(){
  if(commandComplete){
    Serial.println();
    Serial.println("Current move:");
    Serial.println(protocol_num);
    
    forward_value = protocol_num & forward_mask;
    reverse_value = protocol_num & reverse_mask;
    left_value    = protocol_num & left_mask;
    right_value   = protocol_num & right_mask;
    
    Serial.print(forward_value);
    Serial.print(reverse_value);
    Serial.print(left_value);
    Serial.print(right_value);

    digitalWrite(pin_forward, forward_value?LOW:HIGH);
    digitalWrite(pin_reverse, reverse_value?LOW:HIGH);
    digitalWrite(pin_left,    left_value?LOW:HIGH);
    digitalWrite(pin_right,   right_value?LOW:HIGH);

    commandComplete = false;
  }
}

void serialEvent() {
  if(Serial.available() > 0){
    protocol_num = Serial.parseInt();
  }
  while(Serial.available() > 0){
    Serial.read(); // clean up whatever left in Serial
  }
  commandComplete = true;
}

