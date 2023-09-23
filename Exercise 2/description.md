This exercise consists of two parts. In the first part, you will become familiar with the WiFi capabilities of the NodeMCU board, and in the second part, you will work with the RFID-RC522 module:

Part One: Working with the WiFi Module

Set up the NodeMCU board and display a list of nearby WiFi networks in the Serial Monitor. Then, connect it to one of these networks and display its IP address in the Serial Monitor. (Use the Station mode for this.)

In cases where the NodeMCU board acts as a web server, it's important for its IP address to remain static so that clients can reconnect after power cycles. Write a program to configure the WiFi module in Access Point mode, display its IP address in the Serial Monitor, and assign a specific IP address (within the valid access point range and not already assigned to another device). Then, display this assigned IP address.

Write a program that, when a user enters x.x.x.x/LEDOn in their browser, turns on an LED connected to the NodeMCU board. Similarly, when x.x.x.x/LEDOff is entered, turn off the LED. (Replace x.x.x.x with the IP address you set earlier.) Provide a message indicating the LED's status change to the user so they can see it in their browser. (Note that to send commands to the ESP8266 in Access Point mode, you first need to connect to it in your device's WiFi settings.)

NTP (Network Time Protocol) is one of the oldest protocols used in IP-based networks to synchronize and use accurate time. Using the NTP protocol, display the date and time in the local time zone in the Serial Monitor. (You can refer to this link for assistance.)

Part Two: Working with the RFID Module
5. Explain the operation, application, operating frequency, and functionality of the 8-pin RFID module.

Write a program that reads and displays the information on a card or tag when it is brought close to the RFID module in the Serial Monitor.

One of the applications of RFID is in security systems and access control. To achieve this, design a program that grants access to a card tag and denies access to an unauthorized tag. By reading the UID of the tag and comparing it to a predefined value in the program, determine whether access is allowed or denied. If access is allowed, turn on an LED; otherwise, turn it off.
