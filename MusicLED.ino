

/*
#define LED_RED ...;
#define LED_GREEN ...;
#define LED_BLUE ...;

#define MUSIC_INPUT ...;
*/

int rBright = 0;
int gBright = 0;
int bBright = 0;

int fadeSpeed = 10;
int brightness = 255;

int incomingAudio;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  // configure digital pins
  /*
  pinMode(MUSIC_INPUT, INPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  // test LED-Output
  TurnOn();
  delay(2000); // wait 2 sec
  TurnOff();
/**/
}

void loop() {
  MainLoop();
  delay(1000); // 100 millis

}

void MainLoop() {

  // lese Musiksignal
  // incomingAudio = analogRead(MUSIC_INPUT);
  if(Serial.available()) {
    incomingAudio = (int)Serial.readStringUntil('\n');
  }
  // calculate frequency = Tonhöhe = LED Farbe
  // calculate amplitude = Lautstärke = Helligkeit


  // LED Ausgabe
  Serial.print("LED \t rot: ");
  Serial.print(rBright);
  Serial.print("\t green: ");
  Serial.print(gBright);
  Serial.print("\t blue: ");
  Serial.println(bBright);
  /*
  analogWrite(LED_RED, rBright);
  analogWrite(LED_GREEN, gBright);
  analogWrite(LED_BLUE, bBright);

/**/
}

void TurnOn() {
  for (int i = 0; i < 256; i++) {
       analogWrite(LED_RED, rBright);
       rBright +=1;
       delay(fadeSpeed);
   }
 
   for (int i = 0; i < 256; i++) {
       analogWrite(LED_BLUE, bBright);
       bBright += 1;
       delay(fadeSpeed);
   } 
   for (int i = 0; i < 256; i++) {
       analogWrite(LED_GREEN, gBright);
       gBright +=1;
       delay(fadeSpeed);
   }
}

void TurnOff() {
  brightness = 255;
  for (int i = 0; i < 256; i++) {
       analogWrite(LED_GREEN, brightness);
       analogWrite(LED_RED, brightness);
       analogWrite(LED_BLUE, brightness);
 
       brightness -= 1;
       delay(fadeSpeed);
   }
}
