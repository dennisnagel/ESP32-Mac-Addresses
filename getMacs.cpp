#include <WiFi.h>

unsigned char hex_to_dec(unsigned char in) { 
   if(((in >= '0') && (in <= '9'))) return in-'0'; 
   in |= 0x20;
   if(((in >= 'a') && (in <= 'f'))) return in-'a' + 10; 
   return 42; 
}

String macAdd(String mac, int add){
  int lastChar = hex_to_dec(mac.charAt(15))*16 + hex_to_dec(mac.charAt(16)) + add;
  String returnData = String(lastChar, HEX);
  returnData.toUpperCase();
  if(lastChar <= 15){
    return mac.substring(0, 15) + "0" + returnData;
  }
  else{
    return mac.substring(0, 15) + returnData;
  }
}

void setup() {
  Serial.begin(115200);
  
  String baseMac = WiFi.macAddress();
  
  Serial.println(baseMac);            // Wi-Fi Station
  Serial.println(macAdd(baseMac, 1)); // Wi-Fi SoftAP
  Serial.println(macAdd(baseMac, 2)); // Bluetooth
  Serial.println(macAdd(baseMac, 3)); // Ethernet
 
}

void loop() {}
