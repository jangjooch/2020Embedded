#include <I2Cdev.h>

#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>

#include <Adafruit_PN532.h>

#include <SPI.h>
#include <Wire.h>

#define PN532_IRQ   44 // (2)  <- changed to D9 for IRQ pin, refer to schematic
#define PN532_RESET 43 // (3)  <- changed to D8 for nReset pin, refer to schematic

Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);
 
#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using
programming port to program the Zero!
// also change #define in Adafruit_PN532.cpp library file
   #define Serial SerialUSB
#endif
 
void setup(void) {
    
    Serial.begin(115200);
    Serial.print("\r\n\r\nPN532 NFC Start by DotoriKing");
 
    nfc.begin();

    Serial.print("begin Done");
    
    uint32_t versiondata = nfc.getFirmwareVersion();
    if (! versiondata)
    {
        Serial.print("\r\nDidn't find PN53x board");
        while (1); // halt
    }
    
    // Got ok data, print it out!
    Serial.print("\r\nFound chip PN5");
    Serial.print((versiondata>>24) & 0xFF, HEX);
    Serial.print("\r\nFirmware ver. ");
    Serial.print((versiondata>>16) & 0xFF, DEC);
    Serial.print('.');
    Serial.print((versiondata>>8) & 0xFF, DEC);
    
    // Set the max number of retry attempts to read from a card
    // This prevents us from waiting forever for a card, which is
    // the default behaviour of the PN532.
    nfc.setPassiveActivationRetries(0xFF);
 
    // configure board to read RFID tags
    nfc.SAMConfig();
 
    Serial.print("\r\nWaiting for an ISO14443A card");
}
 
void loop(void)
{
    boolean success;
    uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };    // Buffer to store the returned UID
    uint8_t uidLength;              // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
 
    // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
    // 'uid' will be populated with the UID, and uidLength will indicate
    // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
    success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
 
    if (success)
    {
        Serial.print("\r\nFound a card!");
        Serial.print("\r\nUID Length: ");
        Serial.print(uidLength, DEC);
        Serial.print(" bytes");
        Serial.print("\r\nUID Value: ");
 
        for (uint8_t i = 0; i < uidLength; i++)
        {
            Serial.print(" 0x");
            Serial.print(uid[i], HEX);
        }
 
        // Wait 1 second before continuing
        delay(1000);
    }
    else
    {
        // PN532 probably timed out waiting for a card
        Serial.print("\r\nTimed out waiting for a card");
    }
}
