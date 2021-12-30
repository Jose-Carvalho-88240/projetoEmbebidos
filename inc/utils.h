#ifndef UTILS_H
#define UTILS_H

#include <linux/types.h>

#define BCM2711_PERI_BASE       0xfe000000
#define GPIO_BASE (BCM2711_PERI_BASE + 0x200000) // GPIO controller

// PIN FUNCTION
#define INPUT 0
#define OUTPUT 1

// PIN VALUE
#define HIGH 1
#define LOW 0

// PIN PULL
#define NO_PULL 0
#define PULL_UP 1
#define PULL_DOWN 2

/**
 * @brief Structure that contains GPIO Registers
 * 
 * 		@ GPFSEL : Set pin function
 * 		@ GPSET : Set pin HIGH
 * 		@ GPCLR : Set pin LOW
 * 		@ GPLEV : Pin value
 * 		@ GPIO_PUP_PDN_CNTRL_REG : Set pin pull
 * 
 */
struct GpioRegisters
{
	uint32_t GPFSEL[6];
	uint32_t Reserved1;
	uint32_t GPSET[2];
	uint32_t Reserved2;
	uint32_t GPCLR[2];
	uint32_t Reserved3;
	uint32_t GPLEV[2];
	uint32_t Reserved4[42];
	uint32_t GPIO_PUP_PDN_CNTRL_REG[4];
};

/**
 * @brief Set GPIO Pin function
 * 
 * @param s_pGpioRegisters : Register structure
 * @param GPIO : GPIO Pin
 * @param functionCode : Function (Input, Output)
 */
void SetGPIOFunction(struct GpioRegisters *s_pGpioRegisters, int GPIO, int functionCode);

/**
 * @brief Set GPIO Pin pull mode
 * 
 * @param s_pGpioRegisters : Register structure
 * @param GPIO : GPIO Pin
 * @param pullCode : Pull mode (No pull, Pull-up, Pull-down)
 */
void SetGPIOPull(struct GpioRegisters *s_pGpioRegisters, int GPIO, int pullCode);

/**
 * @brief Set GPIO Pin value
 * 
 * @param s_pGpioRegisters : Register structure
 * @param GPIO : GPIO Pin
 * @param outputValue : Value desired for pin
 */
void SetGPIOValue(struct GpioRegisters *s_pGpioRegisters, int GPIO, bool outputValue);

/**
 * @brief Get GPIO Pin value
 * 
 * @param s_pGpioRegisters : Register structure
 * @param GPIO : GPIO Pin
 * @return int : GPIO Pin value
 */
int GetGPIOValue(struct GpioRegisters *s_pGpioRegisters, int GPIO);

#endif