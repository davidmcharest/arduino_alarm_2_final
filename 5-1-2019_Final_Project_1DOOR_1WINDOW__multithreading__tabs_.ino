
//Not Verified!!!!
//How it Works:
//alarm() function is run initially and checks to see if alarmActivated = true and AWAYalarmActivated (they start as false), then loops
//to the mainMenu() function. The mainMenu() function checks if activateAlarm or AWAYactivateAlarm = true. If either is true,  the countdown will display and
//
//
//

#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
#include <Keypad.h>        // includes the Keypad Library

//Assigning pin numbers to receivers
int LaserDetectorW = 10;
int LaserDetectorP = 12;

//Assigning pin number to piezo buzzer
int Buzzer = 46;


int screenOffMsg = 0; // Used in mainMenu and enterPassword functions. If value is 0, display Welcome menu text and input options
String password = "1234"; // Used in enterPassword function as the current password to disable alarm or change password
String tempPassword; // Used in enterPassword function to store keys to compare to String password
boolean activated = false; // Used in enterPassword function to determine if keys should be pressed
boolean isActivated; // from borrowed code to check to see if alarm is activated. Currently not in use

boolean activateAlarm = false; // Used in mainMenu function to check to see if alarm is activated and provide a countdown
boolean AWAYactivateAlarm = false; // Used in mainMenu function to check to see if alarm is activated and provide a countdown

boolean alarmActivated = false; // Used in alarm and enterPassword functions to only run alarm function if this is equal to true
boolean AWAYalarmActivated = false; // Used in alarm and enterPassword functions to only run alarm function if this is equal to true

boolean enteredPassword; // State of the entered password to stop the alarm
boolean passChangeMode = false; // Used in enterPassword function
boolean passChanged = false; // Used in enterPassword function
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keypressed;

//define the symbols on the buttons of the keypads
char keyMap[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {18, 19, 20, 21}; //Row pinouts of the keypad
byte colPins[COLS] = {14, 15, 16, 17}; //Column pinouts of the keypad
Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
void setup() {
  lcd.begin(20, 4); //defines dimensions of lcd (20 columns by 4 rows)
  Serial.begin (9600);

  //Defines lasers and buzzer as outputs and receivers as inputs
  pinMode(LaserDetectorW, INPUT);
  pinMode(LaserDetectorP, INPUT);
  pinMode(Buzzer, OUTPUT);
}
//########################################################################
//###################### FUNCTION DEFINITIONS START ######################
//########################################################################
void alarm();
void enterPassword();
void AWAYenterPassword();
void ARMEDenterPassword();
void mainMenu();
//########################################################################
//###################### FUNCTION DEFINITIONS END ########################
//########################################################################
void loop() { //start of the loop

  //sets receiver values
  boolean W = digitalRead(LaserDetectorW);
  boolean P = digitalRead(LaserDetectorP);

  Serial.println(W); // Open the Serial Monitor to see the values
  Serial.println(P); // Open the Serial Monitor to see the values

  alarm();    //calls the alarm function
  mainMenu(); //calls the mainMenu function
} //end of the loop
