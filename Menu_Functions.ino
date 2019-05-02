// One Function: mainMenu()
// mainMenu() - Checks if alarm is activated or not. If activated, countdown and start sensors, otherwise display a menu with options
//
void mainMenu() {
  if (activateAlarm) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alarm will be");
    lcd.setCursor(0, 1);
    lcd.print("activated in");

    int countdown = 3; // 3 seconds count down before activating the alarm
    while (countdown != 0) {
      lcd.setCursor(13, 1);
      lcd.print(countdown);
      countdown--;
      delay(1000);
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alarm Activated!");
    activateAlarm = false;
    alarmActivated = true;
  }
  if (AWAYactivateAlarm) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alarm will be");
    lcd.setCursor(0, 1);
    lcd.print("activated in");

    int countdown = 10; // 10 seconds count down before activating the alarm
    while (countdown != 0) {
      lcd.setCursor(14, 1);
      lcd.print(countdown);
      countdown--;
      delay(1000);
      lcd.setCursor(14, 1);
      lcd.print("  ");
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alarm Activated!");
    AWAYactivateAlarm = false;
    AWAYalarmActivated = true;
  }
  if (!alarmActivated && !AWAYalarmActivated) {

    if (screenOffMsg == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("***** Welcome *****");
      lcd.setCursor(0, 1);
      lcd.print("A - Activate Away");
      lcd.setCursor(0, 2);
      lcd.print("B - Activate Stay");
      lcd.setCursor(0, 3);
      lcd.print("C - Change Password");
      screenOffMsg = 1;
    }
    keypressed = myKeypad.getKey();
    if (keypressed == 'A') {    //If A is pressed, activate the AWAY alarm
      AWAYactivateAlarm = true;
    }
    else if (keypressed == 'B') { //If B is pressed, activate the STAY alarm
      activateAlarm = true;
    }
    else if (keypressed == 'C') { //If C is pressed, activate keypad and ask for current password, then new password if current correct
      lcd.clear();
      int i = 1;
      tempPassword = "";
      lcd.setCursor(0, 0);
      lcd.print("Current Password");
      lcd.setCursor(0, 1);
      lcd.print(">");
      passChangeMode = true;
      passChanged = true;
      while (passChanged) {
        keypressed = myKeypad.getKey();
        if (keypressed != NO_KEY) {
          if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
              keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
              keypressed == '8' || keypressed == '9' ) {
            tempPassword += keypressed;
            lcd.setCursor(i, 1);
            lcd.print("*");
            i++;
          }
        }
        if (i > 5 || keypressed == '#') {
          tempPassword = "";
          i = 1;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Current Password");
          lcd.setCursor(0, 1);
          lcd.print(">");
        }
        if ( keypressed == '*') {
          i = 1;
          if (password == tempPassword) {
            tempPassword = "";
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Set New Password");
            lcd.setCursor(0, 1);
            lcd.print(">");
            while (passChangeMode) {
              keypressed = myKeypad.getKey();
              if (keypressed != NO_KEY) {
                if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
                    keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
                    keypressed == '8' || keypressed == '9' ) {
                  tempPassword += keypressed;
                  lcd.setCursor(i, 1);
                  lcd.print("*");
                  i++;
                }
              }
              if (i > 5 || keypressed == '#') {
                tempPassword = "";
                i = 1;
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Set New Password");
                lcd.setCursor(0, 1);
                lcd.print(">");
              }
              if (keypressed == '*') {
                i = 1;
                password = tempPassword;
                passChangeMode = false;
                passChanged = false;
                screenOffMsg = 0;
              }
            }
          }
          else if (tempPassword != password) {
            lcd.setCursor(0, 0);
            lcd.print("Wrong! Try Again");
            tempPassword = "";
            i = 1;
            delay(2000); //current pw
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Current Password");
            lcd.setCursor(0, 1);
            lcd.print(">");
          }
        }
      }
    }
  }
}
