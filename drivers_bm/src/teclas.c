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
 *
 */

/** \brief Blinking Bare Metal driver led
 **
 **
 **
 **/
/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal LED Driver
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

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "teclas.h"

/*==================[macros and definitions]=================================*/
#define PAQUETE1 1
#define PUERTO0 0
#define PUERTO1 1
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN6 6
#define TEC1 1<<4
#define TEC2 1<<8
#define TEC3 1<<9
#define TEC4 1<<9
#define Bit_TEC1 4
#define Bit_TEC2 8
#define Bit_TEC3 9
#define Bit_TEC4 9
/*==================[internal data declaration]==============================*/
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
void ini_teclas(void)
{
 Chip_GPIO_Init(LPC_GPIO_PORT);
 Chip_SCU_PinMux(PAQUETE1,PIN0,MD_PUP|MD_EZI|MD_ZI,FUNC0);
 Chip_SCU_PinMux(PAQUETE1,PIN1,MD_PUP|MD_EZI|MD_ZI,FUNC0);
 Chip_SCU_PinMux(PAQUETE1,PIN2,MD_PUP|MD_EZI|MD_ZI,FUNC0);
 Chip_SCU_PinMux(PAQUETE1,PIN6,MD_PUP|MD_EZI|MD_ZI,FUNC0);
 Chip_GPIO_SetDir(LPC_GPIO_PORT,PUERTO0,TEC1,FALSE);
 Chip_GPIO_SetDir(LPC_GPIO_PORT,PUERTO0,TEC2,FALSE);
 Chip_GPIO_SetDir(LPC_GPIO_PORT,PUERTO0,TEC3,FALSE);
 Chip_GPIO_SetDir(LPC_GPIO_PORT,PUERTO1,TEC4,FALSE);
}

uint8_t leer_teclado(void)
{
 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,PUERTO0,Bit_TEC1))
 {
  return 0b00000001;
 }
 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,PUERTO0,Bit_TEC2))
 {
  return 0b00000010;
 }
 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,PUERTO0,Bit_TEC3))
 {
  return 0b00000100;
 }
 if(!Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,PUERTO1,Bit_TEC4))
 {
  return 0b00001000;
 }
 else
  asm("nop");
}

/*==================[end of file]============================================*/

