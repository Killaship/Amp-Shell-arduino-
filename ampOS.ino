String temp;
String cmd;
void setup() {
  Serial.begin(9600);
  init_cli();
  Serial.print(">>");
}

void loop() {
  cmdline();
}


void init_cli() {
  Serial.println("Amp");
  Serial.println("This is a simple command shell called Amp. The name is inspired by a previous project of VoltOS.");
  Serial.println("Type \"help\" for a list of commands and their uses.");
}
void cmdline() {
  
  while(Serial.available() > 0) {
    cmd = Serial.readString();

    if(cmd.length() > 20) {
      cmd_handle("DRGwe8uWw^gK!W$G5N9L#t597rD@XXpbbw56$T66a7!akh3*DdPPWWXhTfbD"); // Invalid command, cmd_handle() will catch this.    
    }
    else {
      char Buffer[20];
      cmd.toCharArray(Buffer, cmd.length());
      cmd_handle(Buffer);
      Serial.print(">>");
    }
    
  }


 
}

void cmd_handle(const char input) {
  if (strcmp(input, "help") == 0) {
      Serial.println("These are all the commands and their uses.");
      Serial.println("Check the User's Manual for more info");
      Serial.println("\"help\": lists all commands and their uses");
      Serial.println("\"echo\": \"echoes\" back the provided argument to the command."); // TODO: this, consider switching to ESP32 for more RAM and SPIFFS.
      Serial.println("\"systemreq\": IMPORTANT: USE BEFORE OPENING APPS! Tells you the required system requirements to use AmpOS without any memory issues.");
  } 
  else if (strcmp(input, "sytemreq") == 0) {

      Serial.println("Recommended: 4 KB RAM, >100 KB Flash Mem, SPIFFS Filesystem (for most apps). Suitable board: (ESP32 board)");
      Serial.println("Bare Minimum: 2 KB RAM, 32 KB Flash Mem, No Filesystem Suitable board: (Arduino Nano)");
  }
/* more else if clauses */
  else { /* default: */
      Serial.println("Invalid Command.");
}
  
}
