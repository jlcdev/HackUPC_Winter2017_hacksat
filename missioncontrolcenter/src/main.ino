#include <VirtualWire.h>
void setup()
{
  Serial.begin(9600); //Se inicia la comunicaciÃ³n serial
  vw_set_ptt_inverted(true);
  vw_setup(2000); //Tiempo de espera
  vw_set_rx_pin(3); //Pin donde se conecta el Arduino
  vw_rx_start(); //Se inicia la recepcin de datos
}
void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN]; //TamaÃ±o del mensaje
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) //Se verifica si hay //mensaje disponible para ser leido
  {
    int i;
    for (i = 0; i < buflen; i++) //Se leen todos los caracteres
    {
      Serial.write(buf[i]); //Se guarda la informaciÃ³n en una //matriz
    }
    Serial.println(); //Se imprime el mensaje en el monitor //serial
  }
}
