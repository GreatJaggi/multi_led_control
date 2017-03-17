char command;
bool leds[6]; // [0, 1, 2, 3, 4, 5]
// bool = either true or false

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  off();
}// setup

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

int ledSwitch(int port, int idx) {
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
  return 0;
}// led switch

void off()  {
  for(int idx = 2; idx < 8; idx++)
    digitalWrite(idx, LOW);

  for(int idx = 0; idx < 6; idx++) 
    leds[idx] = false;
}// off

void on() {
  for(int idx = 2; idx < 8; idx++)
    digitalWrite(idx, HIGH);

  for(int idx = 0; idx < 6; idx++) 
    leds[idx] = true;
}// on
