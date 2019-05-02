// One Function: alarm()
// alarm() - Checks if alarm is activated and loops through the different sensors until one is tripped
//
void alarm() {

  boolean W = digitalRead(LaserDetectorW);
  boolean P = digitalRead(LaserDetectorP);

  if (alarmActivated == true) { //default state is: alarmActivated = false
    if (W == 1 && P == 1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Press the * key");
      lcd.setCursor(0, 1);
      lcd.print("To Turn off Alarm");
      lcd.setCursor(0, 2);
      //text to print
      lcd.print("Window     - Armed");
      lcd.setCursor(0, 3);
      lcd.print("Front Door - Armed");
      //digitalWrite(Buzzer, LOW);
      delay(2000);
      if (
        myKeypad.getKey()== '*') {
        ARMEDenterPassword();
    }}
    else
    {
      if (W == 0 && P == 0)
      {

        lcd.setCursor(0, 2);
        //text to print
        lcd.print("Window     - ALERT!");
        lcd.setCursor(0, 3);
        lcd.print("Front Door - ALERT!");
        digitalWrite(Buzzer, HIGH);
        enterPassword(); //calls the enterPassword function
      }
      else
      {
        if (W == 1 && P == 0)
        {
          lcd.setCursor(0, 2);
          //text to print
          lcd.print("Window     - Armed");
          lcd.setCursor(0, 3);
          lcd.print("Front Door - ALERT!");
          digitalWrite(Buzzer, HIGH);
          enterPassword(); //calls the enterPassword function
        }
        else
        {
          if (W == 0 && P == 1)
          {
            lcd.setCursor(0, 2);
            //text to print
            lcd.print("Window     - ALERT!");
            lcd.setCursor(0, 3);
            lcd.print("Front Door - Armed");
            digitalWrite(Buzzer, HIGH);
            enterPassword(); //calls the enterPassword function
          }
          else
          {
            lcd.setCursor(0, 2);
            //text to print
            lcd.print(" Error ");
            lcd.setCursor(0, 3);
            lcd.print("With Loops");
            digitalWrite(Buzzer, HIGH);
            enterPassword(); //calls the enterPassword function
          }
        }
      }
    }
  }
  if (AWAYalarmActivated == true) { //default state is: AWAYalarmActivated = false
    if (W == 1 && P == 1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Press the * key");
      lcd.setCursor(0, 1);
      lcd.print("To Turn off Alarm");
      lcd.setCursor(0, 2);
      //text to print
      lcd.print("Window     - Armed");
      lcd.setCursor(0, 3);
      lcd.print("Front Door - Armed");
      //digitalWrite(Buzzer, LOW);
      delay(2000);
      if (
        myKeypad.getKey()== '*') {
        ARMEDenterPassword();
    }}
    else
    {
      if (W == 0 && P == 0)
      {

        lcd.setCursor(0, 2);
        //text to print
        lcd.print("Window     - ALERT!");
        lcd.setCursor(0, 3);
        lcd.print("Front Door - ALERT!");

        delay(1000);
        //lcd.clear();
        AWAYenterPassword(); //calls the AWAYenterPassword function
      }
      else
      {
        if (W == 1 && P == 0)
        {
          lcd.setCursor(0, 2);
          //text to print
          lcd.print("Window     - Armed");
          lcd.setCursor(0, 3);
          lcd.print("Front Door - ALERT!");
          digitalWrite(Buzzer, HIGH);
          delay(2000);
          //lcd.clear();
          AWAYenterPassword(); //calls the AWAYenterPassword function
        }
        else
        {
          if (W == 0 && P == 1)
          {
            lcd.setCursor(0, 2);
            //text to print
            lcd.print("Window     - ALERT!");
            lcd.setCursor(0, 3);
            lcd.print("Front Door - Armed");
            digitalWrite(Buzzer, HIGH);
            delay(2000);
            //lcd.clear();
            AWAYenterPassword(); //calls the AWAYenterPassword function
          }
          else
          {
            lcd.setCursor(0, 2);
            //text to print
            lcd.print(" Error ");
            lcd.setCursor(0, 3);
            lcd.print("With Loops");
            digitalWrite(Buzzer, HIGH);
            delay(2000);
            //lcd.clear();
            AWAYenterPassword(); //calls the AWAYenterPassword function
          }
        }
      }
    }
  }
}
