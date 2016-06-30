/* Initials     Name
 * ---------------------------
 *
 */
/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */
/*==================[inclusions]=============================================*/
#include "ComSerieADC.h"		/* <= own header */
#include "led.h"
#include "UARTX.h"
#include "ADC.h"
/*==================[macros and definitions]=================================*/
/*==================[internal data declaration]==============================*/
#define PERIODO 300000
#define Vcc 3.3
uint32_t i1;
uint16_t valorCH1;
float voltaje;
/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/
void main(void)
{
 ini_puerto();
 ini_UART2_FTDI();
 ini_ADC();
 while(TRUE)
 {
  for(i1=PERIODO;i1!=FALSE;i1--)
  {
   asm("nop");
  }
  ADC_on();
  while(!fin_de_conversion())
  {}
  valorCH1=leer_ADC();
  ADC_off();
  voltaje=valorCH1*Vcc/1024;
  Enviar_Dato(voltaje);
 }
}

/*==================[end of file]============================================*/

