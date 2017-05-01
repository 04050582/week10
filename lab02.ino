#include <Keypad.h>
#define NOTE_C3 261
#define NOTE_CS3 139
#define NOTE_D3 294
#define NOTE_DS3 156
#define NOTE_E3 329
#define NOTE_F3 349
#define NOTE_FS3 185
#define NOTE_G3 392
#define NOTE_GS3 329
#define NOTE_A3 440
#define NOTE_AS3 392
#define NOTE_B3 493
#define NOTE_C4 523
#define NOTE_CS4 523
#define NOTE_D4 587
#define NOTE_DS4 644
#define NOTE_E4 659

#define NOTE_F4 698
#define NOTE_FS4 880
#define NOTE_G4 784
#define NOTE_GS4 1046
#define NOTE_A4 880
#define NOTE_AS4 1175
#define NOTE_B4 988
#define WHOLE 1 //全分符
#define HALF 0.5 //半分符
#define QUARTER 0.25
#define EIGHTH 0.125
#define SIXTEENTH 0.0625
int tune[] = { NOTE_B4, NOTE_A4, NOTE_G4,
NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4,
NOTE_B3, NOTE_A3, NOTE_G3, NOTE_F3,
NOTE_E3, NOTE_D3, NOTE_C3,NOTE_GS4, NOTE_AS4};
float duration[] = {QUARTER,
QUARTER, QUARTER, QUARTER,
QUARTER, QUARTER, QUARTER, QUARTER,
QUARTER,QUARTER, QUARTER,
QUARTER, QUARTER, QUARTER, QUARTER, QUARTER};


int length = sizeof(tune);
void setup() 
{
Serial.begin(9600); 
   pinMode(11, OUTPUT);
   int length = sizeof(tune); 
   sizeof(tune[0]);

}
const byte ROWS = 4;
const byte COLS = 4;
char key;
int k;
char keys[ROWS][COLS]={
{'F', 'E', 'D', 'C'}, 
  {'B', '3', '6', '9'},
  {'A', '2', '5', '8'}, 
  {'0', '1', '4', '7'}
  };

byte rowPins[ROWS]={6,7,8,9};
byte colPins[COLS]={2,3,4,5};

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);


void loop() 
{
  
  key = keypad.getKey();
  
  if (key != NO_KEY)
  {
    if(key>='0' && key<='9')
    {
       tone(11, tune[key-48]);
       delay(100);
       noTone(11);
    }
    if(key>='A' && key<='F')
    {
      tone(11, tune[key-65+10]);
       delay(100);
       noTone(11);
     
    }
    Serial.println(key);
 }
}
