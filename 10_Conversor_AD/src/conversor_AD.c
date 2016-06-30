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
#include "conversorAD.h"		/* <= own header */
#include "ADC.h"
#include "led.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/
uint16_t valorCH1;

/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/
void main(void)
{
 ini_puerto();
 ini_ADC();
 while(TRUE)
 {
  ADC_on();
  while(!fin_de_conversion())
  {}
  valorCH1=leer_ADC();
  if(valorCH1>1000)
  {
   encender(rojo);
  }
  if(valorCH1<10)
  {
   encender(verde);
  }
  if((valorCH1<=1000)&(valorCH1>=10))
  {
   apagar(rojo);
   apagar(verde);
  }
  ADC_off();
 }
}

/*==================[end of file]============================================*/

