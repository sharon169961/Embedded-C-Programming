### Problem Statement: Adjust LED Blink Rate Using Interrupts and a Pushbutton

#### Objective:
Create a system using an Arduino to change the LED blink rate via a pushbutton,
utilizing hardware interrupts for precise control.

#### Requirements:
- LED - Pin D13
- Pushbutton - Pin D12 
- blink rates - 1000ms, 500ms and 200ms

#### Constraints:
1. Implement debouncing to avoid false triggers.
2. Use hardware interrupts for button presses.
3. Cycle through predefined blink rates.
4. Display the current blink rate on the serial monitor.

#### Methodology:
1. **Setup:**
   - Configure the LED pin as output and the pushbutton pin with an internal pull-up.
   - Attach an interrupt to the pushbutton for detecting button presses.
   - Initialize serial communication.

2. **ISR:**
   - Debounce the button.
   - Cycle through blink rates on each press.
   - Print the new blink rate to the serial monitor.

3. **Main Loop:**
   - Toggle the LED based on the current blink rate.
   - Introduce a delay for smooth operation.

#### Expected Outcome:
The LED blinks at predefined rates, changing with each button press, 
and the current rate is displayed on the serial monitor.

#### Output Format

```
Blink Duration: 500ms
Blink Duration: 200ms
Blink Duration: 1000ms
Blink Duration: 500ms
Blink Duration: 200ms
```
