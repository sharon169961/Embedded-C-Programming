### Problem Statement: Blink Two LEDs at Different Intervals Simultaneously

**Objective:**
Write an Arduino program to blink two LEDs connected to digital pins at different intervals: 
  1. one LED should blink with a 1000ms (1 second) delay and 
  2. the other with a 500ms (0.5 second) delay, running simultaneously.

**Requirements:**
1. Connect two LEDs to different digital pins on the Arduino (pin 13 for LED1 and pin 12 for LED2).
2. Write the setup and loop functions to configure both pins as outputs.
3. Implement a non-blocking approach to handle the different blink intervals simultaneously.
4. Use separate timers to manage the blink intervals for each LED.
5. Ensure that both LEDs blink at their respective intervals without interfering with each other.

**Constraints:**
- Do not use any external libraries.
- Ensure that the blinking intervals are precise and consistent.

**Hints:**
- Use the `millis` function to keep track of time without blocking the execution of the program.
- Implement separate timing logic for each LED within the `loop` function.
