// #include <Adafruit_NeoPixel.h>
// #ifdef __AVR__
//   #include <avr/power.h>
// #endif 

#include <FastLED.h>
 
#define LED_PIN     54
#define NUM_LEDS    12
#define BRIGHTNESS  250
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
 
#define UPDATES_PER_SECOND 100

//define the digital pin that the LED strip is connected to
// #define PIN 14
#define SENSORPIN1 7
#define SENSORPIN2 2
#define SENSORPIN3 3
#define SENSORPIN4 4
#define SENSORPIN5 5
#define SENSORPIN6 6

// Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, PIN, NEO_GRB + NEO_KHZ800);

int incomingByte;      // a variable to read incoming serial data into
int val[12];            // array 6 sensors total

// variables will change:
int sensorState1 = 0, lastState1 = 0;         // variable for reading the pushbutton status
int sensorState2 = 0, lastState2 = 0;         // variable for reading the pushbutton status
int sensorState3 = 0, lastState3 = 0;         // variable for reading the pushbutton status
int sensorState4 = 0, lastState4 = 0;         // variable for reading the pushbutton status
int sensorState5 = 0, lastState5 = 0;         // variable for reading the pushbutton status
int sensorState6 = 0, lastState6 = 0;         // variable for reading the pushbutton status

void setup() {
  // // put your setup code here, to run once:
  // strip.begin(); //we always need to do this
  // strip.show(); // Initialize all pixels to 'off'

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

  pinMode(SENSORPIN1, INPUT);     
  digitalWrite(SENSORPIN1, HIGH); // turn on the pullup
  pinMode(SENSORPIN2, INPUT);     
  digitalWrite(SENSORPIN2, HIGH); // turn on the pullup
  pinMode(SENSORPIN3, INPUT);     
  digitalWrite(SENSORPIN3, HIGH); // turn on the pullup
  pinMode(SENSORPIN4, INPUT);     
  digitalWrite(SENSORPIN4, HIGH); // turn on the pullup
  pinMode(SENSORPIN5, INPUT);     
  digitalWrite(SENSORPIN5, HIGH); // turn on the pullup
  pinMode(SENSORPIN6, INPUT);     
  digitalWrite(SENSORPIN6, HIGH); // turn on the pullup

  Serial.begin(9600);      // initialize serial communication
  //pinMode(ledPin, OUTPUT); //initialize theLED pin as an output
}

void loop() {
  // read analog inputs one by one and send them to max
  // strip.setPixelColor(0, 200, 200, 200);
  // strip.setPixelColor(1, 200, 200, 200);
  // strip.setPixelColor(2, 200, 200, 200);
  // strip.show();

  leds[0] = CRGB(100, 0, 0);
  leds[1] = CRGB(0, 0, 200);
  leds[2] = CRGB(0, 200, 10);
  leds[3] = CRGB(0, 0, 200);
  leds[4] = CRGB(0, 200, 0);
  leds[5] = CRGB(200, 0, 0);
  leds[6] = CRGB(0, 200, 0);
  leds[7] = CRGB(0, 0, 200);
  leds[8] = CRGB(0, 200, 0);
  leds[9] = CRGB(200, 0, 0);
  leds[10] = CRGB(0, 0, 200);
  leds[11] = CRGB(200, 0, 0);
  FastLED.show();

  // read the state of the pushbutton value:
  sensorState1 = digitalRead(SENSORPIN1);
  sensorState2 = digitalRead(SENSORPIN2);
  sensorState3 = digitalRead(SENSORPIN3);
  sensorState4 = digitalRead(SENSORPIN4);
  sensorState5 = digitalRead(SENSORPIN5);
  sensorState6 = digitalRead(SENSORPIN6);
  
  // for(int i = 0; i < 3; i++)
  // {
  //   val[i] = analogRead(i);
  //   Serial.print(val[i]);
  //   Serial.print(" ");
  // }
  // Serial.println();
  // delay(10);
  
  if (sensorState1 && !lastState1) {
    Serial.println(0);
  } 
  else if(!sensorState1 && lastState1) {
    Serial.println(1);
  }
  if (sensorState2 && !lastState2) {
    Serial.println(2);
  } 
  else if(!sensorState2 && lastState2) {
    Serial.println(3);
  }
  if (sensorState3 && !lastState3) {
    Serial.println(4);
  } 
  else if(!sensorState3 && lastState3) {
    Serial.println(5);
  }
  if (sensorState4 && !lastState4) {
    Serial.println(6);
  } 
  else if(!sensorState4 && lastState4) {
    Serial.println(7);
  }
  if(sensorState5 && !lastState5) {
    Serial.println(8);
  } 
  else if(!sensorState5 && lastState5) {
    Serial.println(9);
  }
  if (sensorState6 && !lastState6) {
    Serial.println(10);
  } 
  else if(!sensorState6 && lastState6) {
    Serial.println(11);
  }
  lastState1 = sensorState1;
  lastState2 = sensorState2;
  lastState3 = sensorState3;
  lastState4 = sensorState4;
  lastState5 = sensorState5;
  lastState6 = sensorState6;


  //see if there's incoming serial data
  if(Serial.available() > 0)
  {
    //read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    //cup 1 on
    if(incomingByte == 'H')
    {
      leds[0] = CRGB(0, 0, 200);
      leds[1] = CRGB(0, 0, 200);
      FastLED.show();
    }
    //if it's an L (ASCII 76) turn off the LED: cup 1 off
    if(incomingByte == 'L')
    {
      leds[0] = CRGB(0, 0, 0);
      leds[1] = CRGB(0, 0, 0);
      FastLED.show();
    }
    //cup 2 on
    if(incomingByte == 'F')
    {
      leds[2] = CRGB(0, 0, 200);
      leds[3] = CRGB(0, 0, 200);
      FastLED.show();
    }
    //cup 2 off
    if(incomingByte == 'N')
    {
      leds[2] = CRGB(0, 0, 0);
      leds[3] = CRGB(0, 0, 0);
      FastLED.show();
    }
    //cup 3 on
    if(incomingByte == 'A')
    {
      leds[4] = CRGB(0, 0, 200);
      leds[5] = CRGB(0, 0, 200);
      FastLED.show();
    }
    //cup 3 off
    if(incomingByte == 'Z')
    {
      leds[4] = CRGB(0, 0, 0);
      leds[5] = CRGB(0, 0, 0);
      FastLED.show();
    }
    //cup 4 on
    if(incomingByte == 'B')
    {
      leds[6] = CRGB(0, 0, 200);
      leds[7] = CRGB(0, 0, 200);
      FastLED.show();
    }
    //cup 4 off
    if(incomingByte == 'Y')
    {
      leds[6] = CRGB(0, 0, 0);
      leds[7] = CRGB(0, 0, 0);
      FastLED.show();
    }
    //cup 5 on
    if(incomingByte == 'C')
    {
      leds[8] = CRGB(0, 0, 200);
      leds[9] = CRGB(0, 0, 200);
      FastLED.show();
    }
    //cup 5 off
    if(incomingByte == 'X')
    {
      leds[8] = CRGB(0, 0, 0);
      leds[9] = CRGB(0, 0, 0);
      FastLED.show();
    }
    //cup 6 on
    if(incomingByte == 'D')
    {
      leds[10] = CRGB(0, 0, 200);
      leds[11] = CRGB(0, 0, 200);
      FastLED.show();
    }
    //cup 6 off
    if(incomingByte == 'W')
    {
      leds[10] = CRGB(0, 0, 0);
      leds[11] = CRGB(0, 0, 0);
      FastLED.show();
    }
  }
  
}
