#include <SPI.h>
#include <TFT_eSPI.h>
#include <RF24.h>
#include <RadioLib.h>

// ==========================================
// PIN DEFINITIONS
// ==========================================
// RF Shared SPI Bus (HSPI)
#define RF_SCK    14
#define RF_MOSI   13
#define RF_MISO   27

// U6: nRF24L01+ Module #1
#define NRF1_CE   17
#define NRF1_CSN  4

// U7: nRF24L01+ Module #2
#define NRF2_CE   25
#define NRF2_CSN  26

// U5: CC1101 Module
#define CC_CSN    33
#define CC_GDO0   32
// ==========================================

// Initialize Objects
TFT_eSPI tft = TFT_eSPI(); 
RF24 nrf1(NRF1_CE, NRF1_CSN);
RF24 nrf2(NRF2_CE, NRF2_CSN);
CC1101 cc = new Module(CC_CSN, CC_GDO0, RADIOLIB_NC);

void setup() {
  Serial.begin(115200);
  delay(1000);

  // 1. Initialize Display First (Uses standard VSPI defined in User_Setup.h)
  tft.init();
  tft.setRotation(1); // Landscape
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  
  tft.drawString("System Booting...", 10, 10);
  delay(1000);

  // 2. Re-route the global standard SPI object to your RF pins
  // SPI.begin(SCK, MISO, MOSI, SS);
  SPI.begin(RF_SCK, RF_MISO, RF_MOSI, -1);
  tft.drawString("RF SPI Bus Started", 10, 40);
  delay(500);

  // 3. Initialize U6 (nRF24 #1)
  tft.drawString("Checking nRF24 #1...", 10, 70);
  if (nrf1.begin()) {
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.drawString("nRF24 #1: OK     ", 10, 70);
  } else {
    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.drawString("nRF24 #1: FAIL   ", 10, 70);
  }
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Reset color

  // 4. Initialize U7 (nRF24 #2)
  tft.drawString("Checking nRF24 #2...", 10, 100);
  if (nrf2.begin()) {
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.drawString("nRF24 #2: OK     ", 10, 100);
  } else {
    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.drawString("nRF24 #2: FAIL   ", 10, 100);
  }
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  // 5. Initialize U5 (CC1101)
  tft.drawString("Checking CC1101...", 10, 130);
  int cc_state = cc.begin();
  if (cc_state == RADIOLIB_ERR_NONE) {
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.drawString("CC1101: OK       ", 10, 130);
  } else {
    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.drawString("CC1101: FAIL (" + String(cc_state) + ")", 10, 130);
  }
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  // Finish setup
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.drawString("All Modules Checked!", 10, 170);
}

void loop() {
  // In your actual firmware, you would check for received packets here:
  // if(nrf1.available()) { ... }
  // if(nrf2.available()) { ... }
  // if(received_flag_cc1101) { ... }

  // Simple heartbeat to show the ESP32 is running
  static int counter = 0;
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.drawString("Uptime: " + String(counter++) + " s ", 10, 210);
  delay(1000);
}
