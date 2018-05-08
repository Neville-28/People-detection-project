#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
const int trigPin2 = 11;
const int echoPin2 =12;
long duration;
long duration2;
int distance;
int distance2;
void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration/29/2;
lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
if(distance < 10){
lcd.println("Warning! Closing "); // Prints string "Distance" on the LCD
}
else if(distance >= 10 && distance <=18){
lcd.println("Coming!!!!      ");
}
else{
lcd.println("                 ");
}
delay(100);
lcd.setCursor(0,1);
lcd.print("                ");
delay(500);
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distance2= duration2/29/2;
lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed
if(distance2 < 10){
lcd.println("Warning! Leaving "); // Prints string "Distance" on the LCD
}
delay(100);
lcd.setCursor(0,0);
lcd.print("                ");
delay(500);

}
