#include <VirtualWire.h>
void setup()
{
  //Init fake receiver configuration
  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_set_rx_pin(3); //Pin for connect antenna with arduino
  vw_rx_start();
}
void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN]; //Set buffer max size
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) //If new message from SAT -> stores and prints to serial port
  {
    int i;
    for (i = 0; i < buflen; i++)
    {
      Serial.write(buf[i]);
    }
    Serial.println();
  }
}
