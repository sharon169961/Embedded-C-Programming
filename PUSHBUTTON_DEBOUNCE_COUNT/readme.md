# Problem Statement - Pushbutton Debouncing

Design and implement an Arduino program that counts the number of times a 
button is pressed and displays the count on the Serial Monitor. 
The program should include debouncing logic to ensure that each button press is accurately counted.


### Requirements:
1. **Button Input**: The button is connected to pin 12 with an internal pull-up resistor.
2. **Debouncing**: Implement debouncing logic with a debounce time of 50 milliseconds.
3. **Counting Presses**: Increment a counter each time the button is pressed and released.
4. **Serial Output**: Print the current count to the Serial Monitor each time the button is pressed.

### Sample Output

```
Pressed 1 times
Pressed 2 times
Pressed 3 times
Pressed 4 times
Pressed 5 times
Pressed 6 times
