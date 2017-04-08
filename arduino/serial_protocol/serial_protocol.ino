// Initializing pins, numbers on board
const int pin_forward = 7;
const int pin_reverse = 8;
const int pin_left    = 5;
const int pin_right   = 6;

// Initializing bit masks
const int forward_mask = 1 << 3; // 1000
const int reverse_mask = 1 << 2; // 0100
const int left_mask    = 1 << 1; // 0010
const int right_mask   = 1 << 0; // 0001

int protocol_num = -1;

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
    if((protocol_num = Serial.read()) == -1) return;
  
    digitalWrite(pin_forward, (protocol_num & forward_mask) ? LOW : HIGH);
    digitalWrite(pin_reverse, (protocol_num & reverse_mask) ? LOW : HIGH);
    digitalWrite(pin_left,    (protocol_num & left_mask) ? LOW : HIGH);
    digitalWrite(pin_right,   (protocol_num & right_mask) ? LOW : HIGH);
}

