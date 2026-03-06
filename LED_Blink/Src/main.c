/* STM32F407 LED Blink - No HAL, No includes needed */

/* Register addresses */
#define RCC_AHB1ENR   (*((volatile unsigned int*)0x40023830))
#define GPIOD_MODER   (*((volatile unsigned int*)0x40020C00))
#define GPIOD_ODR     (*((volatile unsigned int*)0x40020C14))

/* Simulate the delay for now since no HAL drivers function */
void delay(volatile unsigned int count) {
    while (count--);
}

int main(void) {
    /* Enable GPIOD clock */
    RCC_AHB1ENR |= (1 << 3);

    /* Set PD12, PD13, PD14, PD15 LED pins as outputs */
    GPIOD_MODER |= (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30);

    // Blue LED on continuously
    GPIOD_ODR |= (1 << 15);

    while (1) {
    	// Green LED on and then off in next cycle
        GPIOD_ODR ^= (1 << 12);
        delay(5000000);

        // Orange LED on and off 3 times
        for (int i = 0; i < 6; i++) {
            GPIOD_ODR ^= (1 << 13);
            delay(500000);
        }


        // Red LED on and off 10 times
        for (int i = 0; i < 20; i++) {
            GPIOD_ODR ^= (1 << 14);
            delay(500000);
        }


    }
}
