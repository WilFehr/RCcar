
//led toggle macro
#define toggle(x) digitalWrite(x, !digitalRead(x));

//pin defines
#define button 21
#define led 8

//debounce code
unsigned long int last_debounce_time = 0;
unsigned long int debounce_delay = 50;//increase if flickers


void setup() {
  //pin config
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  while(!digitalRead(button));//wait for button to be pressed
  delay(50);
  while(digitalRead(button));
  delay(50);
  toggle(led);
}
