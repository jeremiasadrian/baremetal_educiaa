/* Copyright 2016, XXXXXX
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
 *
 */
/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/
/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */
/*
 * Initials     Name
 * ---------------------------
 *
 */
/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */
/*==================[inclusions]=============================================*/
#include "psicodelia.h"       /* <= own header */
#include "led.h"
/*==================[macros and definitions]=================================*/
#define PERIODO 5000000
#define encendido 255
#define apagado 0
/*==================[internal data declaration]==============================*/
uint32_t i;
/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */

void main(void)
{
 str_LedRGB color;
 color.rojo=apagado;
 color.verde=apagado;
 color.azul=apagado;
 ini_puerto();
 apagar(amarillo);
 apagar(verde);
 apagar(rojo);
 RGB(&color);
 while(TRUE)
 {
  encender(rojo);
  color.rojo=encendido;
  RGB(&color);
  for(i=PERIODO;i!=FALSE;i--)
  {
   asm("nop");
  }
  encender(amarillo);
  color.verde=encendido;
  RGB(&color);
  for(i=PERIODO;i!=FALSE;i--)
  {
   asm("nop");
  }
  encender(verde);
  color.azul=encendido;
  RGB(&color);
  for(i=PERIODO;i!=FALSE;i--)
  {
   asm("nop");
  }
  apagar(amarillo);
  apagar(verde);
  apagar(rojo);
  color.rojo=apagado;
  color.verde=apagado;
  color.azul=apagado;
  RGB(&color);
  for(i=PERIODO;i!=FALSE;i--)
  {
   asm("nop");
  }
 }
}

/*==================[end of file]============================================*/

