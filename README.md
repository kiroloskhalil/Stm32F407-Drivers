# Multi-Sensor and Peripherals System Using STM32F407

This project demonstrates the integration of various **sensors**, **displays**, and **communication modules** with the **STM32F407 microcontroller**. All drivers are implemented from scratch without external libraries to provide precise control over each peripheral. The goal is to develop a multi-functional embedded system that collects sensor data, displays it on different screens, and communicates wirelessly or through Ethernet.

---

## Supported Sensors and Peripherals

### **Sensors:**
- **Barometer**: Measures atmospheric pressure.
- **DHT11**: Measures temperature and humidity.
- **DS18B20**: Measures temperature using a digital protocol.
- **Gyroscope**: Measures angular velocity.
- **IR Reflective Sensor**: Detects reflective surfaces or objects.
- **IR Remote Control**: Receives signals from an infrared remote.
- **Knock Sensor**: Detects physical vibrations or knocks.
- **PIR Sensor**: Detects motion.
- **Sound System**: Captures audio signals.
- **Ultrasonic Sensor**: Measures distance using sound waves.
- **Vibration Sensor**: Detects physical vibrations.
- **Water Sensor**: Detects the presence of water.

### **Displays and Interfaces:**
- **7-Segment Display**: Displays numbers (0-9) using multiple segments.
- **LCD**: Alphanumeric display for text.
- **GLCD**: Graphical display for custom images and shapes.
- **TFT Touch Screen**: Touch-enabled graphical interface.

### **Peripherals:**
- **ADC (Analog-to-Digital Converter)**: Reads analog values (e.g., from sensors).
- **PWM (Pulse-Width Modulation)**: Controls LEDs, motors, and more.
- **UART Communication**: For serial communication.
- **EEPROM**: Stores data non-volatilely.
- **SD Card**: For data logging and storage.
- **Audio System**: Plays sounds or audio files.
- **UART-WiFi Module**: Enables WiFi communication.
- **UART-Ethernet Module**: Enables Ethernet communication.

---

## Circuit Connections

Below is an overview of connections between the STM32F407 and the peripherals:

| **Component**        | **STM32 Pin**   | **Description** |
|----------------------|-----------------|-----------------|
| Barometer            | I2C (PB6, PB7)  | Communicates via I2C |
| DHT11                | GPIO (PA1)      | Digital sensor for temperature & humidity |
| DS18B20              | GPIO (PA2)      | One-wire temperature sensor |
| Gyroscope            | I2C (PB6, PB7)  | Measures angular velocity |
| IR Reflective Sensor | GPIO (PA3)      | Detects reflective surfaces |
| IR Remote Receiver   | GPIO (PA4)      | Receives IR signals |
| Knock Sensor         | GPIO (PA5)      | Detects physical knocks |
| PIR Sensor           | GPIO (PA6)      | Detects motion |
| Sound System         | ADC (PA7)       | Captures audio signals |
| Ultrasonic Sensor    | GPIO (PB0, PB1) | Measures distance |
| Vibration Sensor     | GPIO (PB2)      | Detects vibrations |
| Water Sensor         | GPIO (PB3)      | Detects water presence |
| 7-Segment Display    | GPIO (PC0-PC6)  | Displays numbers 0-9 |
| LCD Display          | GPIO (PC7-PC12) | Displays text and messages |
| GLCD                 | SPI (PA5, PA6)  | Graphical LCD interface |
| TFT Touch Screen     | SPI (PA5, PA6)  | Displays UI and detects touch |
| EEPROM               | I2C (PB6, PB7)  | Non-volatile memory |
| SD Card              | SPI (PA5, PA6)  | Data storage |
| Audio System         | PWM (PB4)       | Controls audio output |
| UART-WiFi            | UART (PA9, PA10)| Wireless communication |
| UART-Ethernet        | UART (PB10, PB11)| Ethernet communication |

---

## Software Implementation Overview

1. **GPIO Initialization**: Configures GPIO pins for various sensors and peripherals.
2. **ADC Configuration**: Reads analog inputs from the sound system and other sensors.
3. **PWM Control**: Generates signals to control LEDs, motors, or audio output.
4. **UART Communication**: Sends data over WiFi, Ethernet, or to other serial devices.
5. **I2C & SPI Communication**: Manages communication with displays, EEPROM, and other I2C/SPI devices.
6. **Data Logging**: Stores sensor data on SD Card.
7. **Interrupts & Timers**: Ensures fast responses to external events (e.g., knocks, motion, remote control signals).

---

---

## How to Compile and Flash

1. **Set up Toolchain**: Use ARM GCC or STM32CubeIDE.
2. **Compile the Code**: Build the project using your preferred toolchain.
3. **Flash the Binary**: Use ST-Link or a USB-to-serial adapter to flash the code to the STM32F407 board.

---

## Usage Instructions

1. Connect all sensors and peripherals as described in the circuit diagram.
2. Power the STM32F407 board.
3. Monitor sensor readings via UART or display them on the LCD/GLCD/TFT screen.
4. Use WiFi/Ethernet modules to send data remotely.

---

## Troubleshooting

1. **Sensor Data Not Displayed**: Check GPIO configurations and wiring.
2. **Communication Issues**: Ensure correct UART settings.
3. **Display Issues**: Verify SPI/I2C connections and configurations.

---

## Future Improvements

- Add **DMA** for faster data transfers.
- Implement **RTOS** for task management.
- Integrate **MQTT** or **HTTP** protocols for IoT functionality.

---

## License

This project is licensed under the MIT License – feel free to use, modify, and distribute it.

---

## Author

Developed by [kirolos khalil]. For any questions or suggestions, please contact [kiroloskhalil38@gmail.com].
LinkedIn : https://www.linkedin.com/in/carl-khalil-544755134/
