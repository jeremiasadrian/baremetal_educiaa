
/* Initials     Name
 * ---------------------------
 */
/* modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */
/*==================[inclusions]=============================================*/
#include "parpadeo_p_tecla.h"       /* <= own header */
#include "led.h"
#include "teclas.h"
/*==================[macros and definitions]=================================*/
#define PERIODO 3000000
#define tecla1 0b00000001
#define tecla2 0b00000010
#define tecla3 0b00000100
#define tecla4 0b00001000
#define L123 5
#define nada 4
/*==================[internal data declaration]==============================*/
uint32_t i=0;
/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/
/* Main function
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */
void main(void)
{
 uint8_t teclado;
 ini_teclas();
 ini_puerto();
 apagarL123();
 while(TRUE)
 {
  teclado=leer_teclado();
  switch(teclado)
  {
  case tecla1: encenderL123();
  	  	  	   break;
  case tecla2: encender(amarillo);
   	   	   	   break;
  case tecla3: encender(verde);
  	  	  	   break;
  case tecla4: encender(rojo);
 			   break;
  default: apagarL123();
  }
  for(i=PERIODO;i==0;i--);
  {
   asm("nop");
  }
  apagarL123();
  for(i=PERIODO;i==0;i--);
  {
   asm("nop");
  }
 }
}
/*==================[end of file]============================================*/

