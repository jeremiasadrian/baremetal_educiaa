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
#include "examen.h"		/* <= own header */
#include "ADC.h"
#include "DAC.h"
#include "timers.h"
#include "led.h"
#include "teclas.h"
#include "UARTX.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/
#define tecla1 0b00000001
#define tecla2 0b00000010
#define tecla3 0b00000100
#define tecla4 0b00001000
uint8_t teclado;
uint32_t valorCH1;
uint32_t salidaDAC=0;
uint16_t Vinc=0;
uint8_t mute=0;
uint32_t i=0;
uint8_t i1=0;
uint16_t i2=0;
uint8_t rebote=0;
const char mensaje1[]="Aumento la ganancia\n\r";
const char mensaje2[]="Disminuyo la ganancia\n\r";
const char mensaje3[]="MUTE\n\r";
const char mensaje4[]="No se me ocurrio nada creativo para esta tecla\n\r";

/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/
void main(void)
{
 ini_puerto();
 ini_teclas();
 ini_ADC();
 ini_DAC();
 ini_timerRep(100);
 ini_UART2_FTDI();
 while(TRUE)
 {
  asm("nop");
 }
}

void ISR_Temporizador(void)
{
 if(rebote==2)
 {
  rebote=0;
  teclado=leer_teclado();
  switch(teclado)
  {
  /*Aumenta la amplitud*/
  case tecla1:if(Vinc>=50)
	   	   	  {
		       Vinc=Vinc-50;
	   	   	  }
	   	   	  else
	   	   	  {
	   	   	   asm("nop");
	   	   	  }
		   	  for(i1=0;i1<21;i1++)
		   	  {
		   	   Enviar_Dato(mensaje1[i1]);
		   	   while(TX_Fin()){}
		   	  }
	   	   	  break;
  /*Disminuye la amplitud.*/
  case tecla2:if(Vinc<970)
	   	   	  {
	   	   	   Vinc=Vinc+50;
	   	   	  }
	   	   	  else
	   	   	  {
	   	   	   asm("nop");
	   	   	  }
	   	   	  for(i1=0;i1<23;i1++)
	   	   	  {
	   	   	   Enviar_Dato(mensaje2[i1]);
	   	   	   while(TX_Fin()){}
	   	   	  }
	   	   	  break;
  /*Pone a cero la salida*/
  case tecla3:if(mute==1)
	   	   	  {
		   	   mute=0;
	   	   	  }
	   	   	  else
	   	   	  {
	   	   	   mute=1;
	   	   	  }
		   	  for(i1=0;i1<4;i1++)
		   	  {
		   	   Enviar_Dato(mensaje3[i1]);
		   	   while(TX_Fin()){}
		   	  }
	   	   	  break;
  /*Funcion reservada*/
  case tecla4:for(i1=0;i1<46;i1++)
	   	 	  {
	   	 	   Enviar_Dato(mensaje4[i1]);
	   	 	   while(TX_Fin()){}
	   	 	  }
  	  	  	  toggle(verde);
	   	 	  break;
   default: asm("nop");
   }
  }
 else
 {
  rebote++;
 }
 ADC_on();
 while(!fin_de_conversion())
 {}
 valorCH1=leer_ADC();
 salidaDAC=valorCH1;
 if(mute==1)
 {
  cargar_DAC(0);
 }
 else
 {
 if(Vinc<=salidaDAC)
 {
  for(i2=0;i2<Vinc;i2++)
  {
   salidaDAC--;
  }
 }
 else
 {
  asm("nop");
 }
  cargar_DAC(salidaDAC);
 }
 toggle(rojo);
 ADC_off();
 BorrarFlag();
}

/*==================[end of file]============================================*/

