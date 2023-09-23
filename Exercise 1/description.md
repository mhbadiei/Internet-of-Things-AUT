The purpose of this exercise is to examine the functions and capabilities of Internet of Things (IoT) nodes. In this exercise, we utilize the NodeMCU board as one of the IoT nodes. NodeMCU is an open-source hardware platform suitable for IoT projects that require wireless connectivity.

Here are the steps for performing the exercise:

Initialize the NodeMCU board and display "Hello, World!"

Explain the applications of PWM and ADC in microcontrollers. Prepare a presentation file for this section and provide explanations based on it.

Use the ADC to read the output voltage of an LDR sensor, convert the reading to a value between 0 and 100, and display it.

Consider the value obtained in the previous step. If the LDR sensor output is greater than 50, turn on the specified LED; otherwise, turn it off.

Write a program using PWM to adjust the LED blink speed proportionally to the ambient light. The program should work in such a way that as the ambient light increases, the LED blinks slower, and as the ambient light decreases, the LED blinks faster.

One of the important considerations when using IoT nodes is power consumption and effective ways to reduce battery usage. In this section, explain the four operational modes of a NodeMCU. Prepare a presentation file for this section and provide explanations based on it.

Based on the four modes discussed in the previous section, write a function that takes a natural number as input (sleep duration) and puts the NodeMCU into deep sleep mode to maximize battery life. To test the function, first turn on the LED for 5 seconds, and then call the function with a 15-second sleep duration to put the Node into deep sleep. After waking up, turn on the LED again.
