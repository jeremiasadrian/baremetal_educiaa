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
#include "ComSerie.h"		/* <= own header */
#include "led.h"
#include "UARTX.h"
/*==================[macros and definitions]=================================*/
/*==================[internal data declaration]==============================*/
#define PERIODO 30000
uint8_t datoRX=0;
uint32_t i1;
uint32_t i2;
const char mensaje[]="Hola Mundo";

/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/
void main(void)
{
 ini_puerto();
 ini_UART2_FTDI();
 while(TRUE)
 {
  for(i1=PERIODO;i1!=FALSE;i1--)
  {
   asm("nop");
  }
  datoRX = Leer_Dato();
  switch(datoRX)
  {
   case 'a': toggle(amarillo);
   	   	     for(i2=0;i2<10;i2++)
   	   	     {
   	   	      Enviar_Dato(mensaje[i2]);
   	   	     }
             break;
   case 'r': toggle(rojo);
	         for(i2=0;i2<10;i2++)
	         {
	          Enviar_Dato(mensaje[i2]);
	         }
  	   	     break;
   case 'v': toggle(verde);
	         for(i2=0;i2<10;i2++)
	         {
	          Enviar_Dato(mensaje[i2]);
	         }
   	   	     break;
  default: 0;
  }
 }
}

/*==================[end of file]============================================*/

