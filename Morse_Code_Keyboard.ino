//#define LED_PIN 8
//#define LED_PIN2 9
#define BUTTON_PIN 2
#define BUTTON_PIN2 3

int data = 8; 
int clock = 10;
int latch = 9;
int speakerPin = 11;

int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

int buttonState = 0;

//Used for single LED manipulation
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

int delayTime = 1000; //the number of milliseconds to delay between LED updates

char morseIn[] = "\0\0\0\0";
int morseIndex = 0;
int morseOut;

// morse code
char c[] = "-*-*";
char d[] = "-**";
char e[] = "*";
char f[] = "**-*";
char g[] = "--*";
char a[] = "*-";
char b[] = "-***";
char k[] = "-*-";

void setup() {
  //pinMode(LED_PIN, OUTPUT);
  //pinMode(LED_PIN2, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);  
  pinMode(latch, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUTTON_PIN2, INPUT);
}

int pushed = 0;
int i = 0;
int isLetter;

void loop() {

  if(!pushed) {
    if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN2) == LOW) {
      morseIn[i] = '*';
      i++;
      pushed = 1;
      changeLED(5, 0);
    }
    // dash
    else if (digitalRead(BUTTON_PIN) == LOW && digitalRead(BUTTON_PIN2) == HIGH) {
      morseIn[i] = '-';
      i++;
      pushed = 1;
    }
  }
  
  if(digitalRead(BUTTON_PIN) == LOW && digitalRead(BUTTON_PIN2) == LOW) {
    pushed = 0;
  }

  if(digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN2) == HIGH) {
    //changeLED(1, 1);

    isLetter = checkCode(morseIn);

    if(isLetter > -1) {
      //changeLED(5, 1);
    }

    i = 0;
    morseIn[0] = '\0';
    morseIn[1] = '\0';
    morseIn[2] = '\0';
    morseIn[3] = '\0';
    /*
    isLetter = checkCode(morseIn);

    if(isLetter) {
      changeLED(isLetter-1, 1);
    }

    i = 0;
    morseIn[0] = '\0';
    morseIn[1] = '\0';
    morseIn[2] = '\0';
    morseIn[3] = '\0';
    */
  }
  
  /*
  if(!pushed) {
    // dot
    if (digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN2) == LOW) {
      morseIn[i] = '*';
      i++;
      pushed = 1;
    }
    // dash
    else if (digitalRead(BUTTON_PIN) == LOW && digitalRead(BUTTON_PIN2) == HIGH) {
      morseIn[i] = '-';
      i++;
      pushed = 1;
    }
    */
    /*
    // submit
    else if(digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN2) == HIGH) {
      isLetter = checkCode(morseIn);

      if(isLetter) {
        playNote(notes[isLetter-1], tempo);
        changeLED(isLetter-1, 1);

        delay(500);
        changeLED(isLetter-1, 0);
      }

      isLetter = 0;
      i = 0;
      morseIn[0] = '\0';
      morseIn[1] = '\0';
      morseIn[2] = '\0';
      morseIn[3] = '\0';
    }
    */
/*
    isLetter = checkCode(morseIn);

    if(isLetter) {
      playNote(notes[isLetter-1], tempo);
      changeLED(isLetter-1, 1);
      isLetter = 0;
      i = 0;
      morseIn[0] = '\0';
      morseIn[1] = '\0';
      morseIn[2] = '\0';
      morseIn[3] = '\0';

      //delay(500);
      changeLED(isLetter-1, 0);
    }
    else if(i >= 4) {
      i = 0;
      morseIn[0] = '\0';
      morseIn[1] = '\0';
      morseIn[2] = '\0';
      morseIn[3] = '\0';
    }
    
  }

  if(digitalRead(BUTTON_PIN) == LOW && digitalRead(BUTTON_PIN2) == LOW) {
    pushed = 0;
  }
  */

/*
  if(digitalRead(BUTTON_PIN) == HIGH && digitalRead(BUTTON_PIN2) == HIGH) {
    isLetter = checkCode(morseIn);

    if(isLetter) {
      playNote(notes[isLetter-1], tempo);
      changeLED(isLetter-1, 1);

      delay(500);
      changeLED(isLetter-1, 0);
    }

    isLetter = 0;
    i = 0;
    morseIn[0] = '\0';
    morseIn[1] = '\0';
    morseIn[2] = '\0';
    morseIn[3] = '\0';
  }
  */

  /*
  if(!pushed) {
    // dot
    if (digitalRead(BUTTON_PIN) == HIGH) {
      //playNote(notes[0], beats[0] * tempo);
      pushed = 1;
      morseIn[morseIndex] = '*';
      morseIndex++;
    }
    // dash
    else if (digitalRead(BUTTON_PIN2) == HIGH) {
      pushed = 1;
      morseIn[morseIndex] = '-';
      morseIndex++;
    }

    if(morseIndex >= 4) {
      playNote(notes[0], beats[0] * tempo);
      printf("\n\n");
      printMorse(morseIn);
      morseIndex = 0;
      morseIn[0] = '\0';
      morseIn[1] = '\0';
      morseIn[2] = '\0';
      morseIn[3] = '\0';
    }
  }
  else if(digitalRead(BUTTON_PIN) == LOW && digitalRead(BUTTON_PIN2) == LOW) {
    pushed = 0;
  }
  */
  /*
  // dot
  if (digitalRead(BUTTON_PIN) == HIGH) {
    playNote(notes[0], beats[0] * tempo);
    //changeLED(0, 1);
    printf("*");
    morseIn[morseIndex] = '*';
    morseIndex++;
  }
  // dash
  else if (digitalRead(BUTTON_PIN2) == HIGH) {
    printf("-");
    morseIn[morseIndex] = '-';
    morseIndex++;
  }

  if(morseIndex >= 4) {
    ///playNote(notes[0], beats[0] * tempo);
    printf("\n\n");
    printMorse(morseIn);
    morseIndex = 0;
    morseIn[0] = '\0';
    morseIn[1] = '\0';
    morseIn[2] = '\0';
    morseIn[3] = '\0';
  }
  */
  //delay(delayTime);

  /*
  // first dot/dash
  delay(delayTime);
  if (digitalRead(BUTTON_PIN) == HIGH) {

  }
  else if (digitalRead(BUTTON_PIN2) == HIGH) {

  }
  */
  /*
  int delayTime = 100; //the number of milliseconds to delay between LED updates
  if (digitalRead(BUTTON_PIN) == HIGH) {
    //digitalWrite(LED_PIN, HIGH);
    for(int i = 0; i < 256; i++){
      if(i < length) {
        if (notes[i] == ' ') {
          delay(beats[i] * tempo); // rest
        } else {
          playNote(notes[i], beats[i] * tempo);
        }
      }
      updateLEDs(i);
      delay(delayTime); 
    }
  }
  if (digitalRead(BUTTON_PIN2) == HIGH) {
    //digitalWrite(LED_PIN2, HIGH);
  }
  else {
    //digitalWrite(LED_PIN, LOW);
    //digitalWrite(LED_PIN2, LOW);
  }
  */
}

int checkCode(char code[]) {
  //changeLED(5, 1);
  if(!strcmp(code, c)){
    changeLED(0, 1);
    playNote(notes[0], tempo);
    changeLED(0, 0);
    return 0;
  }
  if(!strcmp(code, d)){
    changeLED(1, 1);
    playNote(notes[1], tempo);
    changeLED(1, 0);
    return 1;
  }
  if(!strcmp(code, e)){
    changeLED(2, 1);
    playNote(notes[2], tempo);
    changeLED(2, 0);
    return 2;
  }
  if(!strcmp(code, f)){
    changeLED(3, 1);
    playNote(notes[3], tempo);
    changeLED(3, 0);
    return 3;
  }
  if(!strcmp(code, g)){
    changeLED(4, 1);
    playNote(notes[4], tempo);
    changeLED(4, 0);
    return 4;
  }
  if(!strcmp(code, a)){
    changeLED(5, 1);
    playNote(notes[5], tempo);
    changeLED(5, 0);
    return 5;
  }
  if(!strcmp(code, b)){
    changeLED(6, 1);
    playNote(notes[6], tempo);
    changeLED(6, 0);
    return 6;
  }
  if(!strcmp(code, k)){
    changeLED(7, 1);
    playNote(notes[7], tempo);
    changeLED(7, 0);
    return 7;
  }

  return -1;
}

void printMorse(char code[]) {
  if(!strcmp(code, c)){
    playNote('c', 300);
    changeLED(0, 1);
  }
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

/*
 * updateLEDs() - sends the LED states set in ledStates to the 74HC595
 * sequence
 */
void updateLEDs(int value){
  digitalWrite(latch, LOW);     //Pulls the chips latch low
  shiftOut(data, clock, MSBFIRST, value); //Shifts out the 8 bits to the shift register
  digitalWrite(latch, HIGH);   //Pulls the latch high displaying the data
}

/*
 * updateLEDsLong() - sends the LED states set in ledStates to the 74HC595
 * sequence. Same as updateLEDs except the shifting out is done in software
 * so you can see what is happening.
 */ 
void updateLEDsLong(int value){
  digitalWrite(latch, LOW);    //Pulls the chips latch low
  for(int i = 0; i < 8; i++){  //Will repeat 8 times (once for each bit)
  int bit = value & B10000000; //We use a "bitmask" to select only the eighth 
                               //bit in our number (the one we are addressing this time thro
                    //ugh
  value = value << 1;          //we move our number up one bit value so next time bit 7 will
                    // be
                               //bit 8 and we will do our math on it
  if(bit == 128){digitalWrite(data, HIGH);} //if bit 8 is set then set our data pin high
  else{digitalWrite(data, LOW);}            //if bit 8 is unset then set the data pin low
  digitalWrite(clock, HIGH);                //the next three lines pulse the clock pin
  delay(1);
  digitalWrite(clock, LOW);
  }
  digitalWrite(latch, HIGH);  //pulls the latch high shifting our data into being displayed
}


//These are used in the bitwise math that we use to change individual LEDs
//For more details http://en.wikipedia.org/wiki/Bitwise_operation
int bits[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
int masks[] = {B11111110, B11111101, B11111011, B11110111, B11101111, B11011111, B10111111, B01111111};
/*
 * changeLED(int led, int state) - changes an individual LED 
 * LEDs are 0 to 7 and state is either 0 - OFF or 1 - ON
 */
 void changeLED(int led, int state){
   ledState = ledState & masks[led];  //clears ledState of the bit we are addressing
   if(state == ON){ledState = ledState | bits[led];} //if the bit is on we will add it to le
                    //dState
   updateLEDs(ledState);              //send the new LED state to the shift register
 }