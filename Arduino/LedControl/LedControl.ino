bool leds[6];

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  off();
}// setup

char command;
// the loop function runs over and over again forever
void loop() {
  command = Serial.read();
  

  switch (command) {
    case '1': turnOn(2, 0); break;
    case '2': turnOn(3, 1); break;
    case '3': turnOn(4, 2); break;
    case '4': turnOn(5, 3); break;
    case '5': turnOn(6, 4); break;
    case '6': turnOn(7, 5); break;
    case '7': off(); break; //turn off  all leds
    case '8': on(); break; //turn on all leds
  }//switch
}// loop

int turnOn(int port, int idx) {
  // turn on led if index is false
  if (leds[idx] == false) {
    digitalWrite(port, HIGH);
    leds[idx] = !leds[idx];
    return 0;
  }

  // turn off led if index is true
  if (leds[idx] == true) {
    digitalWrite(port, LOW);
    leds[idx] = !leds[idx];
    return 0;
  }
}// turn on

void off()  {
    
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

  for(int idx = 0; idx < 6; idx++) 
    leds[idx] = false;
}// off

void on() {
    
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

  for(int idx = 0; idx < 6; idx++) 
    leds[idx] = true;
}// on

