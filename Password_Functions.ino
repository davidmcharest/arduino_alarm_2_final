// Three Functions: enterPassword(), AWAYenterPassword(), and ARMEDenterPasword()
// enterPassword()      - activates keypad and waits for input from user. If entered, turn off alarm
// AWAYenterPassword()  - activates keypad and waits for input from user. If entered, turn off alarm. This function needs to display a 30 second countdown in rows 1 and 2 of the lcd while allowing
// ARMEDenterPassword() - activates keypad and waits for input from user. If entered, turn off alarm. Used when alarm system is armed and you want to disarm without tripping it
// 
void enterPassword() { //activates keypad and waits for input from user. If entered, turn off alarm
  int k = 5;
  tempPassword = "";
  activated = true;
  lcd.setCursor(0, 0);
  lcd.print("                    ");
  lcd.setCursor(0, 1);
  lcd.print("                    ");
  lcd.setCursor(0, 0);
  lcd.print(" *** ALARM *** ");
  lcd.setCursor(0, 1);
  lcd.print("Pass>");
  while (activated) {
    keypressed = myKeypad.getKey();
    if (keypressed != NO_KEY) {
      if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
          keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
          keypressed == '8' || keypressed == '9' )  {
        tempPassword += keypressed;
        lcd.setCursor(k, 1);
        lcd.print("*");
        k++;
      }
    }
    if (k > 9 || keypressed == '#') {
      tempPassword = "";
      k = 5;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" *** ALARM *** ");
      lcd.setCursor(0, 1);
      lcd.print("Pass>");
    }
    if (keypressed == '*') {
      if (tempPassword == password ) {
        activated = false;
        alarmActivated = false;
        digitalWrite(Buzzer, LOW);
        screenOffMsg = 0;
      }
      else if (tempPassword != password) {
        lcd.setCursor(0, 1);
        lcd.print("Wrong! Try Again");
        delay(2000); //wrong pw
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" *** ALARM *** ");
        lcd.setCursor(0, 1);
        lcd.print("Pass>");
      }
    }
  }
}
void AWAYenterPassword() { //activates keypad and waits for input from user. If entered, turn off alarm. This function needs to display a 30 second countdown in rows 1 and 2 of the lcd while allowing
  //user the input the password in the keypad to turn off the system before the buzzer goes off
  unsigned long chrono = millis();
  int k = 5;
  tempPassword = "";
  activated = true;
  lcd.setCursor(0, 0);
  lcd.print("                    ");
  lcd.setCursor(0, 1);
  lcd.print("                    ");
  lcd.setCursor(0, 0);
  lcd.print("Alarm in 10 seconds");
  lcd.setCursor(0, 1);
  lcd.print("Pass>");
  while (activated) {
    if (activated == true) {
      lcd.setCursor(0, 0);
      lcd.print("Alarm in 10 seconds");
      if (millis() - chrono >= 10000){
      if (AWAYalarmActivated == true){
      digitalWrite(Buzzer, HIGH);}}
      keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY) {
        if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
            keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
            keypressed == '8' || keypressed == '9' )  {
          tempPassword += keypressed;
          lcd.setCursor(k, 1);
          lcd.print("*");
          k++;
        }
      }
      if (k > 9 || keypressed == '#') {
        tempPassword = "";
        k = 5;
        lcd.setCursor(0, 0);
        lcd.print("                    ");
        lcd.setCursor(0, 1);
        lcd.print("                    ");
        lcd.setCursor(0, 0);
        lcd.print("Alarm in 10 seconds");
        lcd.setCursor(0, 1);
        lcd.print("Pass>");
      }
      if (keypressed == '*') {
        if (tempPassword == password ) {
          activated = false;
          AWAYalarmActivated = false;
          digitalWrite(Buzzer, LOW);
          screenOffMsg = 0;
        }
        else if (tempPassword != password) {
          lcd.setCursor(0, 1);
          lcd.print("Wrong! Try Again");
          delay(1000); //wrong pw
          lcd.setCursor(0, 0);
          lcd.print("                    ");
          lcd.setCursor(0, 1);
          lcd.print("                    ");
          lcd.setCursor(0, 0);
          lcd.print("Alarm in 10 seconds");
          lcd.setCursor(0, 1);
          lcd.print("Pass>");
        }
      }
    }
  }
}
void ARMEDenterPassword() { //activates keypad and waits for input from user. If entered, turn off alarm
  int k = 5;
  tempPassword = "";
  activated = true;
  lcd.setCursor(0, 0);
  lcd.print("                    ");
  lcd.setCursor(0, 1);
  lcd.print("                    ");
  lcd.setCursor(0, 0);
  lcd.print("Type PW to disable");
  lcd.setCursor(0, 1);
  lcd.print("Pass>");
  while (activated) {
    keypressed = myKeypad.getKey();
    if (keypressed != NO_KEY) {
      if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
          keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
          keypressed == '8' || keypressed == '9' )  {
        tempPassword += keypressed;
        lcd.setCursor(k, 1);
        lcd.print("*");
        k++;
      }
    }
    if (k > 9 || keypressed == '#') {
      tempPassword = "";
      k = 5;
      lcd.setCursor(0, 0);
      lcd.print("                    ");
      lcd.setCursor(0, 1);
      lcd.print("                    ");
      lcd.setCursor(0, 0);
      lcd.print("Type PW to disable");
      lcd.setCursor(0, 1);
      lcd.print("Pass>");
    }
    if (keypressed == '*') {
      if (tempPassword == password ) {
        activated = false;
        alarmActivated = false;
        AWAYalarmActivated = false;
        screenOffMsg = 0;
      }
      else if (tempPassword != password) {
        lcd.setCursor(0, 1);
        lcd.print("Wrong! Try Again");
        delay(2000); //wrong pw
        lcd.setCursor(0, 0);
        lcd.print("                    ");
        lcd.setCursor(0, 1);
        lcd.print("                    ");
        lcd.setCursor(0, 0);
        lcd.print("Type PW to disable");
        lcd.setCursor(0, 1);
        lcd.print("Pass>");
      }
    }
  }
}
