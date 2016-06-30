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
#include "cuboPWM.h"		/* <= own header */
#include "timers.h"
#include "teclas.h"
#include "led.h"
/*==================[macros and definitions]=================================*/
#define encendido 255
#define apagado 0
#define tecla1 0b00000001
#define tecla2 0b00000010
#define tecla3 0b00000100
#define tecla4 0b00001000
#define periodoRGB 10
/*==================[internal data declaration]==============================*/
uint8_t i=0;
uint8_t teclado=0;
uint8_t tiempo=0;
str_LedRGB color;
uint8_t dutyR;
uint8_t dutyG;
uint8_t dutyB;
uint8_t tiempo_duty=0;
/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/
void main(void)
{
 color.rojo=apagado;
 color.verde=apagado;
 color.azul=apagado;
 ini_puerto();
 ini_teclas();
 /*Inicializo con periodo de 1ms.*/
 ini_timerRep(1);
 toggle(verde);
 while(TRUE)
 {
  if(tiempo_duty==10)
  {
   tiempo_duty=0;
   color.rojo=encendido;
   color.verde=encendido;
   color.azul=encendido;
   RGB(&color);
  }
  else
  {
   if(tiempo_duty==5)
   {
	if(dutyR==128)
	{
     apagar(rojoRGB);
	}
	else
	{
	 asm("nop");
	}
	if(dutyG==128)
	{
     apagar(verdeRGB);
	}
    else
	{
	 asm("nop");
	}
	if(dutyB==128)
	{
	 apagar(azulRGB);
	}
   }
   if(tiempo_duty==0)
   {
	if(dutyR==apagado)
	{
	 apagar(rojoRGB);
	}
 	else
	{
     asm("nop");
 	}
	if(dutyG==apagado)
    {
	 apagar(verdeRGB);
	}
	else
 	{
 	 asm("nop");
 	}
  	if(dutyB==apagado)
	{
	 apagar(azulRGB);
	}
	else
	{
	 asm("nop");
	}
   }
   else
   {
	asm("nop");
   }
   tiempo_duty++;
  }
 }
}

void ISR_Termporizador(void)
{
 if(tiempo==200)
 {
  tiempo=0;
  toggle(verde);
  toggle(rojo);
  teclado=leer_teclado();
  if(teclado==tecla1)
  {
   switch(i)
   {
     case 0: dutyR=apagado;
    	   	 dutyG=apagado;
             dutyB=apagado;
             i++;
             break;
     case 1: dutyR=encendido;
     	 	 dutyG=encendido;
     	 	 dutyB=128;
             i++;
             break;
     case 2: dutyR=encendido;
     	 	 dutyG=128;
     	 	 dutyB=encendido;
             i++;
             break;
     case 3: dutyR=128;
     	 	 dutyG=encendido;
     	 	 dutyB=encendido;
             i++;
             break;
     case 4: dutyR=encendido;
     	 	 dutyG=128;
     	 	 dutyB=128;
             i++;
             break;
     case 5: dutyR=128;
     	 	 dutyG=encendido;
     	 	 dutyB=128;
             i++;
             break;
     case 6: dutyR=128;
     	 	 dutyG=128;
     	 	 dutyB=encendido;
             i++;
             break;
     case 7: dutyR=encendido;
    	   	 dutyG=encendido;
             dutyB=apagado;
             i++;
             break;
     case 8: dutyR=encendido;
     	 	 dutyG=apagado;
     	 	 dutyB=encendido;
             i++;
             break;
     case 9: dutyR=apagado;
     	 	 dutyG=encendido;
     	 	 dutyB=encendido;
             i++;
             break;
     case 10:dutyR=encendido;
     	 	 dutyG=apagado;
     	 	 dutyB=apagado;
             i++;
             break;
     case 11:dutyR=apagado;
     	 	 dutyG=encendido;
     	 	 dutyB=apagado;
             i++;
             break;
     case 12:dutyR=apagado;
     	 	 dutyG=apagado;
     	 	 dutyB=encendido;
             i++;
             break;
     case 13:dutyR=encendido;
     	 	 dutyG=apagado;
     	 	 dutyB=128;
             i++;
             break;
     case 14:dutyR=encendido;
     	 	 dutyG=128;
     	 	 dutyB=apagado;
             i++;
             break;
     case 15:dutyR=128;
     	 	 dutyG=apagado;
     	 	 dutyB=encendido;
             i=0;
             break;
    }
   }
   else
   {
    asm("nop");
   }
 }
 else
 {
  tiempo++;
 }
 BorrarFlag();
}

/*==================[end of file]============================================*/

