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
#include "timers.h"
/*==================[macros and definitions]=================================*/
/*==================[internal data declaration]==============================*/
#define PERIODO 300000
#define Vcc 3.3
uint16_t valorCH1;
uint8_t Um=0;
uint8_t D=0;
uint8_t C=0;
uint8_t U=0;
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
 ini_timerRep(100);
 while(TRUE)
 {
   asm("nop");
 }
}

void ISR_TimerRIT(void)
{
 ADC_on();
 while(!fin_de_conversion())
 {}
 valorCH1=leer_ADC();
 ADC_off();
 voltaje=valorCH1*Vcc/1024;
 voltaje=voltaje*1000;
 while(voltaje>1000)
 {
  voltaje=voltaje-1000;
  Um++;
 }
 while(voltaje>100)
 {
  voltaje=voltaje-100;
  C++;
 }
 while(voltaje>10)
 {
  voltaje=voltaje-10;
  D++;
 }
 while(voltaje>0)
 {
  voltaje=voltaje-1;
  U++;
 }
 Enviar_BCD(Um);
 Enviar_Dato('.');
 Enviar_BCD(C);
 Enviar_BCD(D);
 Enviar_BCD(U);
 Enviar_Dato('\r');
 Um=0;
 C=0;
 D=0;
 U=0;
 BorrarFlag();
}

/*==================[end of file]============================================*/

