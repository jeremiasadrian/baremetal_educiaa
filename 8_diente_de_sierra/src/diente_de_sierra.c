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
#include "diente_de_sierra.h"		/* <= own header */
#include "timers.h"
#include "DAC.h"
#include "led.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/
uint32_t salidaDAC=0;
uint8_t tiempo=0;

/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/
void main(void)
{
 ini_puerto();
 ini_teclas();
 ini_timerRep(1);
 ini_DAC();
 while(TRUE)
 {
  asm("nop");
 }
}

void ISR_Termporizador(void)
{
 if(tiempo==200)
 {
  tiempo=0;
  toggle(rojo);
 }
 else
 {
  tiempo++;
 }
 if(salidaDAC==1023)
 {
  salidaDAC=0;
 }
 else
 {
  salidaDAC++;
 }
 cargar_DAC(salidaDAC);
 BorrarFlag();
}

/*==================[end of file]============================================*/

