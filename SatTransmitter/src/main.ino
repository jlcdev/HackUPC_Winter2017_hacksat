#include <VirtualWire.h>

const int pin_telemetry = 3;

void setup()
{
  vw_setup(2000);
  vw_set_tx_pin(pin_telemetry);
  Serial.begin(9600);
  delay(2000);
}

void loop(){
  if(Serial.available() > 0){
    uint8_t content[Serial.available()];
    Serial.readBytes(content, Serial.available());
    vw_send((uint8_t *)content, strlen(content));
    vw_wait_tx();
    delay(500);
  }
}
