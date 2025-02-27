# PIC16F1705 Temperature Sensor Display Project

This project demonstrates how to sample multiple analog temperature sensors on a PIC16F1705 microcontroller and display the temperature readings in Celsius on a 16x2 LCD display.

## Hardware Requirements

- PIC16F1705 microcontroller
- 16x2 LCD display (with HD44780 compatible controller)
- Temperature sensors connected to ANINx pins (RA0, RA1, RA2, RA4)
  - Sensors must output 10mV/K with 0K = 0V
- Appropriate power supply and decoupling capacitors

## Connections

### LCD Connections
- RS: Connected to RC0
- EN: Connected to RC1
- D4: Connected to RC2
- D5: Connected to RC3
- D6: Connected to RC4
- D7: Connected to RC5

### Temperature Sensor Inputs
- ANIN0: Connected to RA0 (Temperature Sensor 0)
- ANIN1: Connected to RA1 (Temperature Sensor 1)
- ANIN2: Connected to RA2 (Temperature Sensor 2)
- ANIN3: Connected to RA4 (Temperature Sensor 3)

## Software Description

The software performs the following functions:

1. Initializes the system, ADC, FVR (Fixed Voltage Reference), and LCD
2. Samples all temperature sensors connected to ANIN channels (ANIN0, ANIN1, ANIN2, ANIN3) every 500ms
3. Converts the ADC readings to temperature values in Celsius
4. Displays the temperature readings on the LCD display

### Code Structure

All functionality is contained in the main.c file, including:
- LCD interface and control functions
- ADC sampling and conversion routines
- Temperature calculation functions
- Main application loop

### LCD Display Format

The LCD displays the temperature readings in the following format:

```
0:  23.5C  1:  24.2C
2: -10.8C  3:  95.6C
```

Where values are formatted with one decimal place, proper alignment, and sign display for negative temperatures.

## Temperature Conversion

The temperature sensor outputs a voltage proportional to temperature:
- 10mV per Kelvin (K)
- 0V at 0K

### Optimized Calculation Method

The conversion uses optimized integer math for improved accuracy and performance:

1. **ADC to Millivolts**: 
   - `millivolts = (adcValue * 4096) / 1023`
   - This directly calculates millivolts from the ADC reading using integer math

2. **Millivolts to Decikelvin**:
   - Since 1mV = 0.1K with our 10mV/K sensor, millivolts directly represent decikelvin (K×10)

3. **Decikelvin to Decidegrees Celsius**:
   - `decidegC = millivolts - 2732` (273.2°C * 10)
   - Uses only integer subtraction

4. **Final Conversion to Float**:
   - `celsius = decidegC / 10.0`
   - Only one floating-point operation in the entire calculation

This approach:
- Minimizes floating-point operations (only one at the end)
- Reduces rounding errors by using integer math
- Increases calculation speed on the PIC microcontroller
- Maintains high precision throughout the calculation

## Functions

- **LCD_Initialize()**: Initializes the LCD in 4-bit mode
- **LCD_WriteString()**: Writes a string to the LCD
- **LCD_WriteFloat()**: Writes a floating-point value to the LCD
- **SampleAndDisplayTemperature()**: Reads an ADC channel and displays the temperature
- **ADC_ConvertToTemperature()**: Converts ADC reading to temperature in Celsius using optimized integer math

## Notes

- The ADC uses the Fixed Voltage Reference (FVR) set to 4.096V as reference
- The LCD is driven in 4-bit mode to save I/O pins
- All analog pins are configured as inputs
- The temperature display formats negative values with a minus sign
- The calculation is optimized for maximum accuracy on 8-bit microcontrollers

## Building and Running

1. Open the project in MPLAB X IDE
2. Build the project (F11)
3. Program the PIC16F1705 (F6)
4. The device will start sampling and displaying the temperature readings

## Modifications

To modify the project:
- Change the sampling interval by modifying the delay in the main loop
- Adjust the temperature calculation by modifying the ADC_ConvertToTemperature() function
- Customize the display format by modifying the SampleAndDisplayTemperature() function 