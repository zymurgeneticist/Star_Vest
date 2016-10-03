
int bright0 = 0; // LED1 brightness
int bright1 = 0; // LED2 brightness
int bright2 = 100; // LED3 brightness
int fade0 = 2; // LED1 fade amount
int fade1 = 3; // LED2 fade amount
int fade2 = 5; // LED3 fade amount
int dcm2 = 1; // duty cycle multiplier
int state2 = LOW; // state of D2 HIGH or LOW
unsigned long previousMillis = 0; // last cycle time LED state changed
unsigned long currentMillis = 0; // current cycle time
unsigned long currentMicros = 0; // current duty cycle time
unsigned long previousMicros = 0; // last duty cycle time

// the setup routine runs once when you press reset:
void setup()  { 
  
  
  // declare pins to be an outputs:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT); // Since D2 does not support analogWrite we need to PWM via software
} 

// the loop routine runs over and over again forever:
void loop()  { 

  // set the duty cycle for D2
  currentMicros = micros(); // set currentMicros to the current time
    if (currentMicros - previousMicros >= dcm2*50) {
    // save the last time you changed the duty cycle state
    previousMicros = currentMicros;

    // change state of duty cycle
    if (state2 == LOW) {
      state2 = HIGH;
    } else {
      state2 = LOW;
    }
    }
  
  // set the brightness of the analog-connected LEDs:
  analogWrite(0, bright0);
  analogWrite(1, bright1);  
  digitalWrite(2, state2);

  currentMillis = millis(); // set currentMillis to the current time
  
 
// if statement standing in for delay checking to see if it's time to run if statements
if (currentMillis >= previousMillis + 15) {

   // change the brightness for next time through the loop:
  bright0 = bright0 + fade0;
  bright1 = bright1 + fade1;
  bright2 = bright2 + fade2;
  dcm2 = (bright2*100)/255; // duty cycle multiplier will convert brightness to a ratio


  // reverse the direction of the fading at the ends of the fade: 
  if (bright0 <= 50 || bright0 >= 250) {
    if(bright0 <= 50)fade0 = random(2,5); // Change the fade amount
    if(bright0 >= 250)fade0 = -fade0; // Change the direction of the fade
  }   
  if (bright1 <= 50 || bright1 >= 250) {
    if(bright1 <= 50)fade1 = random(2,5); // Change the fade amount
    if(bright1 >= 250)fade1 = -fade1;  // Change the direction of the fade
  }
  if (bright2 <= 50 || bright2 >= 250) {
    if(bright2 <= 50)fade2 = random(2,5); // Change the fade amount
    if(bright2 >= 250)fade2 = -fade2;  // Change the direction of the fade
  }  

  previousMillis = currentMillis;
}

}
