#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

const int BUTTON_C = 12; // Pin for Note C
const int BUTTON_D = 13; // Pin for Note D

bool lastStateC = LOW;
bool lastStateD = LOW;

void setup() {
  Serial.begin(115200); // Standard serial channel to talk to your Mac
  
  tft.init();
  tft.setRotation(1); // Landscape mode
  tft.fillScreen(TFT_BLACK);
  
  tft.setTextColor(TFT_PURPLE, TFT_BLACK);
  tft.drawString("MIT EECS Portfolio", 10, 15, 4);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Mode: Serial MIDI Link", 10, 50, 2);
  tft.drawString("Status: SENDING DATA", 10, 75, 2);

  pinMode(BUTTON_C, INPUT);
  pinMode(BUTTON_D, INPUT);
}

void loop() {
  bool currentStateC = digitalRead(BUTTON_C);
  bool currentStateD = digitalRead(BUTTON_D);

  // Check Button 1 (Note C)
  if (currentStateC == HIGH && lastStateC == LOW) {
    sendMIDINote(0x90, 60, 127); // 0x90 = Note On, 60 = Middle C, 127 = Max Volume
    tft.fillScreen(TFT_BLUE);
    tft.setTextColor(TFT_WHITE);
    tft.drawString("PLAYING: NOTE C", 10, 45, 4);
    delay(20); // Software debounce
  } 
  else if (currentStateC == LOW && lastStateC == HIGH) {
    sendMIDINote(0x80, 60, 0);   // 0x80 = Note Off
    resetDisplay();
  }

  // Check Button 2 (Note D)
  if (currentStateD == HIGH && lastStateD == LOW) {
    sendMIDINote(0x90, 62, 127); // 62 = Note D
    tft.fillScreen(TFT_RED);
    tft.setTextColor(TFT_WHITE);
    tft.drawString("PLAYING: NOTE D", 10, 45, 4);
    delay(20); 
  } 
  else if (currentStateD == LOW && lastStateD == HIGH) {
    sendMIDINote(0x80, 62, 0);   // 0x80 = Note Off
    resetDisplay();
  }

  lastStateC = currentStateC;
  lastStateD = currentStateD;
}

// Low-level function that sends pure musical hex blocks over the USB wire
void sendMIDINote(byte status, byte note, byte velocity) {
  Serial.write(status);
  Serial.write(note);
  Serial.write(velocity);
}

void resetDisplay() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_PURPLE, TFT_BLACK);
  tft.drawString("MIT EECS Portfolio", 10, 15, 4);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Mode: Serial MIDI Link", 10, 50, 2);
  tft.drawString("Status: READY", 10, 75, 2);
}
