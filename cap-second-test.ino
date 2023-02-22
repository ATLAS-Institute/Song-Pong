#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif 

//define the digital pin that the LED strip is connected to
#define PIN 17
#define SENSORPIN 4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, PIN, NEO_GRB + NEO_KHZ800);

int incomingByte;      // a variable to read incoming serial data into
int val[3];            // array 6 sensors total

// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status

void setup() {
  // put your setup code here, to run once:
  strip.begin(); //we always need to do this
  strip.show(); // Initialize all pixels to 'off'

  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup

  Serial.begin(9600);      // initialize serial communication
  //pinMode(ledPin, OUTPUT); //initialize theLED pin as an output
}

void loop() {
  // read analog inputs one by one and send them to max
  strip.setPixelColor(0, 200, 200, 200);
  strip.setPixelColor(1, 200, 200, 200);
  strip.setPixelColor(2, 200, 200, 200);
  strip.show();

  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
  
  // for(int i = 0; i < 3; i++)
  // {
  //   val[i] = analogRead(i);
  //   Serial.print(val[i]);
  //   Serial.print(" ");
  // }
  // Serial.println();
  // delay(10);
  
  if (sensorState && !lastState) {
    Serial.println(0);
  } 
  if (!sensorState && lastState) {
    Serial.println(1);
  }
  lastState = sensorState;
  //see if there's incoming serial data
  if(Serial.available() > 0)
  {
    //read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    //cup 1 on
    if(incomingByte == 'H')
    {
      strip.setPixelColor(3, 200, 0, 0);
      strip.show();
    }
    //if it's an L (ASCII 76) turn off the LED: cup 1 off
    if(incomingByte == 'L')
    {
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
    }
    //cup 2 on
    if(incomingByte == 'H')
    {
      strip.setPixelColor(4, 0, 200, 0);
      strip.show();
    }
    //cup 2 off
    if(incomingByte == 'L')
    {
      strip.setPixelColor(4, 0, 0, 0);
      strip.show();
    }
    //cup 3 on
    if(incomingByte == 'H')
    {
      strip.setPixelColor(5, 0, 0, 200);
      strip.show();
    }
    //cup 3 off
    if(incomingByte == 'L')
    {
      strip.setPixelColor(5, 0, 0, 0);
      strip.show();
    }
  }
  
}
