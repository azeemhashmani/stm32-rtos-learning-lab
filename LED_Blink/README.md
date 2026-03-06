# STM32 RTOS Learning Lab

STM32F407 Discovery board - bare-metal LED control without HAL drivers.

## LED_Blink
- Register-level GPIO control on GPIOD
- No HAL, no CubeMX - direct register access
- Software delay loop (to be replaced with SysTick/RTOS delays)

## Board
- STM32F407G-DISC1
- PD12 Green | PD13 Orange | PD14 Red | PD15 Blue
