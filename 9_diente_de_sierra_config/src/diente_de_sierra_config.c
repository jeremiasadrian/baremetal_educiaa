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
#include "diente_de_sierra_config.h"		/* <= own header */
#include "timers.h"
#include "teclas.h"
#include "DAC.h"
#include "led.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/
#define tecla1 0b00000001
#define tecla2 0b00000010
#define tecla3 0b00000100
#define tecla4 0b00001000
uint8_t teclado;
uint32_t salidaDAC=0;
uint16_t tiempo=0;
uint8_t tiempo2=1;
uint16_t Vmax=1023;
uint8_t Vinc=1;
uint8_t Tinc=1;
uint16_t Amp=0;

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
 uint8_t teclado=0;
 if(tiempo==200)
 {
  tiempo=0;
  toggle(verde);
  teclado=leer_teclado();
  switch(teclado)
   {
    /*Disminuye la amplitud.*/
    case tecla1:if(Tinc<10)
   	  	  	  {
  	  	  	   Tinc++;
   	  	  	  }
   	  	  	  else
   	  	  	  {
   	  	  	   asm("nop");
   	  	  	  }
   	  	  	  break;
    /*Aumenta la amplitud*/
    case tecla2:if(Tinc>1)
   	  	  	  {
  	  	  	   Tinc--;
   	  	  	  }
   	  	  	  else
   	  	  	  {
   	  	  	   asm("nop");
   	  	  	  }
   	  	  	  break;
    /*Disminuye el periodo.*/
    case tecla3:if(Vinc<10)
    	  	  	  {
  	  	  	   Vinc++;
    	  	  	  }
    	  	  	  else
    	  	  	  {
    	  	  	   asm("nop");
    	  	  	  }
    	  	  	  break;
    /*Aumenta el periodo.*/
    case tecla4:if(Vinc>1)
    	  	  	  {
  	  	  	   Vinc--;
    	  	  	  }
    	  	  	  else
    	  	  	  {
    	  	  	   asm("nop");
    	  	  	  }
    	  	  	  break;
   }
 }
 else
 {
  tiempo++;
 }
 Amp=Vmax/Tinc;
 if(salidaDAC>=Amp)
 {
  salidaDAC=0;
  toggle(rojo);
 }
 else
 {
  if(tiempo2==Tinc)
  {
   salidaDAC=salidaDAC+Vinc;
   tiempo2=1;
  }
  else
  {
   tiempo2++;
  }
 }
 cargar_DAC(salidaDAC);
 BorrarFlag();
}

/*==================[end of file]============================================*/

