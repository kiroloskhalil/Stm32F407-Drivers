# Water Detection Sensor Using STM32F407

This project demonstrates how to build a water detection system using the STM32F407 microcontroller **without using external libraries**. All necessary functions are developed from scratch to manage GPIOs, timers, and interrupts. The sensor detects whether water is present or not, triggering appropriate actions based on the input signal.

## Features
- **Water Detection**: Detects if water is present or absent.
- **No External Libraries**: All drivers and functionalities are implemented from scratch.
- **STM32F407 Microcontroller**: Exploits the power of the STM32 series for precise control.
- **Digital Signal Output**: Simple high/low signal to indicate water detection.
- **Efficient GPIO Control**: Low-latency response through direct register manipulation.

---

## Components Required
1. **STM32F407 Discovery Board** or STM32F407-based custom board  
2. **Water Sensor Module** (with digital output)  
3. **Resistors and Jumper Wires**  
4. **Breadboard** (optional for easy prototyping)  
5. **LED or Buzzer** (for water alert)  
6. **Power Supply (5V)**

---

## Circuit Diagram

1. Connect the **VCC** and **GND** of the sensor to 3.3V and GND of STM32F407.
2. Connect the **digital output** of the water sensor to **PA0** (or another GPIO pin).
3. (Optional) Connect an **LED or Buzzer** to a GPIO pin (e.g., PB5) to indicate water detection.

---

## Pin Configuration

| Component            | Pin on STM32F407 |
|----------------------|------------------|
| Water Sensor VCC     | 3.3V             |
| Water Sensor GND     | GND              |
| Water Sensor Output  | PF8              |
| LED/Buzzer           | PF7              |

---

## Software Implementation

1. **GPIO Initialization**: Configure GPIO pins for the sensor input and LED output.
2. **Polling or Interrupt**: Use polling or external interrupts to detect changes in the sensor state.
3. **Action**: When water is detected, trigger the LED or buzzer.

---

## Code Overview

The project initializes GPIOs and reads the water sensor status directly from the microcontroller registers. If water is detected, an LED lights up or a buzzer sounds.

### Code Example (Main Logic)

```c
#include "stm32f407xx.h"

// Function to initialize GPIO for PA0 (Sensor) and PB5 (LED/Buzzer)
void GPIO_Init(void) {
    // Enable GPIOA and GPIOB clocks
    RCC->AHB1ENR |= (1 << 0); // GPIOA
    RCC->AHB1ENR |= (1 << 1); // GPIOB

    // Configure PA0 as input (Water Sensor)
    GPIOA->MODER &= ~(0x3 << (0 * 2)); // Clear mode bits

    // Configure PB5 as output (LED/Buzzer)
    GPIOB->MODER |= (1 << (5 * 2)); // Set PB5 as output
}

// Function to read the water sensor status
int IsWaterDetected(void) {
    return (GPIOA->IDR & 0x1); // Read PA0 status
}

// Main function
int main(void) {
    GPIO_Init();

    while (1) {
        if (IsWaterDetected()) {
            // Water detected, turn on LED/Buzzer
            GPIOB->ODR |= (1 << 5);
        } else {
            // No water, turn off LED/Buzzer
            GPIOB->ODR &= ~(1 << 5);
        }
    }
}
```

---

## How to Compile and Flash

1. **Set up Toolchain**: Use ARM GCC or STM32CubeIDE.
2. **Compile the Code**: Build the project using the chosen toolchain.
3. **Flash the Binary**: Use a programmer like ST-Link or a USB-to-serial adapter to flash the code to the STM32F407 board.

---

## Usage Instructions

1. Power the STM32F407 board and connect the water sensor.
2. If water is present, the LED or buzzer will turn on.
3. If water is absent, the LED or buzzer will remain off.

---

## Troubleshooting

1. **Sensor Not Responding**: Check the wiring and connections.
2. **LED/Buzzer Not Working**: Ensure GPIO configuration is correct.
3. **Compile Errors**: Make sure you are using the correct toolchain and device settings.

---

## Future Improvements

- Implement **debouncing** for the water sensor input.
- Add **interrupt-based detection** for faster response.
- Integrate an **LCD display** to show sensor status.

---

## License

This project is licensed under the MIT License – feel free to use, modify, and distribute it.

---

## Author

Developed by [Your Name]. For any questions or suggestions, please contact [your.email@example.com].
