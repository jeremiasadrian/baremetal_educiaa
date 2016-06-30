/* Copyright 2016, XXXXXXXXX  
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * Initials     Name
 * ---------------------------
 *
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */
/*==================[inclusions]=============================================*/

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "timers.h"

/*==================[macros and definitions]=================================*/
/*==================[internal data declaration]==============================*/
/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/

void ini_timerRep(uint32_t Periodo)
{
 Chip_RIT_Init(LPC_RITIMER);
 Chip_RIT_SetTimerInterval(LPC_RITIMER, Periodo);
 NVIC_EnableIRQ(intRIT);
}

void BorrarFlag(void)
{
 Chip_RIT_ClearInt(LPC_RITIMER);
}

void ini_timer(uint8_t Timer, uint32_t Prescaler)
{
 switch (Timer)
 {
  case 0: Chip_TIMER_Init(LPC_TIMER0);
 	   	  Chip_TIMER_PrescaleSet(LPC_TIMER0, Prescaler);
 	 	  break;
  case 1: Chip_TIMER_Init(LPC_TIMER1);
 	 	  Chip_TIMER_PrescaleSet(LPC_TIMER1, Prescaler);
 	 	  break;
  case 2: Chip_TIMER_Init(LPC_TIMER2);
 	 	  Chip_TIMER_PrescaleSet(LPC_TIMER2, Prescaler);
 	 	  break;
  case 3: Chip_TIMER_Init(LPC_TIMER3);
 	 	  Chip_TIMER_PrescaleSet(LPC_TIMER3, Prescaler);
 	 	  break;
  default:Chip_TIMER_Init(LPC_TIMER0);
 	 	  Chip_TIMER_PrescaleSet(LPC_TIMER0, Prescaler);
 	 	  break;
 }
}

void timer_on(uint8_t Timer)
{
 switch (Timer)
 {
  case 0: Chip_TIMER_Enable(LPC_TIMER0);
 	 	  break;
  case 1: Chip_TIMER_Enable(LPC_TIMER1);
  	 	  break;
  case 2: Chip_TIMER_Enable(LPC_TIMER2);
	 	  break;
  case 3: Chip_TIMER_Enable(LPC_TIMER3);
   	 	  break;
  default:Chip_TIMER_Enable(LPC_TIMER0);
	 	  break;
 }
}

void timer_off(uint8_t Timer)
{
switch (Timer)
{
 case 0: Chip_TIMER_DeInit(LPC_TIMER0);
 	 	 break;
 case 1: Chip_TIMER_DeInit(LPC_TIMER1);
  	 	 break;
 case 2: Chip_TIMER_DeInit(LPC_TIMER2);
	 	 break;
 case 3: Chip_TIMER_DeInit(LPC_TIMER3);
 	 	 break;
 default:Chip_TIMER_DeInit(LPC_TIMER0);
 	 	 break;
 }
}

void timer_stop(uint8_t Timer)
{
 switch (Timer)
 {
  case 0: Chip_TIMER_Disable(LPC_TIMER0);
     	  break;
  case 1: Chip_TIMER_Disable(LPC_TIMER1);
	  	  break;
  case 2: Chip_TIMER_Disable(LPC_TIMER2);
	 	 break;
  case 3: Chip_TIMER_Disable(LPC_TIMER3);
	 	 break;
  default:Chip_TIMER_Disable(LPC_TIMER0);
	 	 break;
 }
}

void timer_rst(uint8_t Timer)
{
 switch (Timer)
 {
  case 0: Chip_TIMER_Reset(LPC_TIMER0);
    	  break;
  case 1: Chip_TIMER_Reset(LPC_TIMER1);
   	 	  break;
  case 2: Chip_TIMER_Reset(LPC_TIMER2);
		  break;
  case 3: Chip_TIMER_Reset(LPC_TIMER3);
	 	  break;
  default:Chip_TIMER_Reset(LPC_TIMER0);
	 	  break;
 }
}

uint32_t leer_timer(uint8_t Timer)
{
 switch (Timer)
 {
  case 0: return Chip_TIMER_ReadCount(LPC_TIMER0);
     	  break;
  case 1: return Chip_TIMER_ReadCount(LPC_TIMER1);
   	 	  break;
  case 2: return Chip_TIMER_ReadCount(LPC_TIMER2);
		  break;
  case 3: return Chip_TIMER_ReadCount(LPC_TIMER3);
	 	  break;
  default:return Chip_TIMER_ReadCount(LPC_TIMER0);
	 	  break;
 }
}

/*==================[end of file]============================================*/

