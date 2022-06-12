#include <Keypad.h>
#include <Servo.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

Servo servo;

String Digit_Number;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  servo.attach(10);
}
  
void loop(){
  char key = keypad.getKey();// Read the key
  
  // Print if key pressed
  if (key){
    Digit_Number = Digit_Number + key;
    String item = String(Digit_Number);
    int len = item.length();
    if(len == 4){
      if(Digit_Number == "4531"){ 
        Serial.println("Correct"+ Digit_Number);
        servo.write(90);
        delay(2000);
        servo.write(0);
        Digit_Number = "";
        digitalWrite(13, HIGH);
      }
      else{
        Serial.println("Sorry! Try Again"+ Digit_Number);
        Digit_Number = ""; 
        digitalWrite(13, HIGH);
      }
    }else{
      digitalWrite(13, LOW);
    }
  }
}
