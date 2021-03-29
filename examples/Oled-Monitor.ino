
#include "Oled-Monitor.h" // include this in each sketch

void setup() {
  SetupOledMonitor(); //include this function in each sketch

  //printoled is the new 'command' to print to the OLED screen
  //clearoled is the new 'command' to clear the OLED screen

  int counter = 1;

  printoled ("Line 1");
  delay(1000);
  printoled ("Line 2");
  delay(1000);
  printoled ("Line 3");
  delay(1000);
  printoled ("Line 4 Pausing 5 Sec");
  delay (5000);
  printoled ("Line 5");
  delay(1000);
  printoled ("Line 6");
  delay(1000);
  printoled ("Line 7");
  delay(1000);
  printoled (" ");
  printoled ("Counting 1 to 200 after 5 Sec from now");
  delay(5000);
  printoled (" ");

  for (counter; counter <= 200; counter++) {
    printoled (String(counter));
    delay (50);
  }

  clearoled ();
  printoled ("DEMO DONE !");
}

void loop() {
}
