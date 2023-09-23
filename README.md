# IoT-Course-AUT
This repository contains resources, projects, and code examples related to the Internet of Things (IoT) course offered at computer engineering department of AUT.

# Exercise 1
The purpose of this exercise is to examine the functions and capabilities of Internet of Things (IoT) nodes. In this exercise, we utilize the NodeMCU board as one of the IoT nodes. NodeMCU is an open-source hardware platform suitable for IoT projects that require wireless connectivity.

Here are the steps for performing the exercise:

Initialize the NodeMCU board and display "Hello, World!"

Explain the applications of PWM and ADC in microcontrollers. Prepare a presentation file for this section and provide explanations based on it.

Use the ADC to read the output voltage of an LDR sensor, convert the reading to a value between 0 and 100, and display it.

Consider the value obtained in the previous step. If the LDR sensor output is greater than 50, turn on the specified LED; otherwise, turn it off.

Write a program using PWM to adjust the LED blink speed proportionally to the ambient light. The program should work in such a way that as the ambient light increases, the LED blinks slower, and as the ambient light decreases, the LED blinks faster.

# Exercise 2
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

One of the important considerations when using IoT nodes is power consumption and effective ways to reduce battery usage. In this section, explain the four operational modes of a NodeMCU. Prepare a presentation file for this section and provide explanations based on it.

Based on the four modes discussed in the previous section, write a function that takes a natural number as input (sleep duration) and puts the NodeMCU into deep sleep mode to maximize battery life. To test the function, first turn on the LED for 5 seconds, and then call the function with a 15-second sleep duration to put the Node into deep sleep. After waking up, turn on the LED again.

# Exercise 3
The goal of this exercise is to gain a deeper understanding and explore the LoRaWAN communication network as one of the Low Power Wide Area Network (LPWAN) options in the Internet of Things (IoT). In this exercise, we will utilize the OMNET++ simulator to implement and investigate some of its parameters through the FLoRa framework.

Initially, you need to install the OMNET++ simulator and the FLoRa framework, along with any other necessary frameworks. To install OMNET++, visit their website and choose the appropriate version for your operating system. (Instructions for installing OMNET++ and configuring the FLoRa framework for various operating systems will be provided in the course communication channel.)

Inside the FLoRa framework directory, you will find a default scenario named "loRaNetworkTest.ini," which simulates a LoRaWAN communication network with 10 nodes, one gateway, and a network server. You can observe the default simulation parameters in this file. Provide a brief explanation of each of these parameters.

Execute the default scenario. Running the simulation will generate results in the "simulations/results" directory with the name "General-avg-#0". Selecting this file, provide statistics for the following items:

The last transmitted power by each node (finalTP)
The last spreading factor transmitted by each node (finalSP)
The number of packets sent by each node (sentPackets)
Energy consumption for each node (totalEnergyConsumed)
The total number of packets received at the gateway (LoRa_GWPacketReceived:count)
The total number of packets received at the network server (totalReceivedPackets)
In this section, you should run various scenarios by changing simulation parameters and then store the results. Based on these results, create the requested plots in part (b).

a) These parameters include the spreading factor, transmission power, bandwidth, and the number of end nodes. The parameters initiallyLoRaSF, initiallyLoRaTP, initiallyLoRaBW, and numberOfNodes can be observed in the default scenario. Two parameters, spreading factor and transmission power, are randomly selected for each node in the default scenario. For example, one configuration could be setting these values to 7 for spreading factor, 14 dBm for transmission power, 5 nodes, and 125 kHz for bandwidth. Run the scenario, record the results, and remember to run the simulation for each change. Keep the values of the other parameters (except spreading factor, transmission power, the number of nodes, and bandwidth) the same as in the default test file. In total, you need to perform 16 simulations (2 scenarios for the number of nodes, 2 for spreading factor, 2 for transmission power, and 2 for bandwidth). Change the parameters as follows:

numberOfNodes {5, 15}
initialLoRaSF {7, 12}
initialLoRaTP {7 dBm, 14 dBm}
initialLoRaBW {125 kHz, 250 kHz}
b) Based on the criteria mentioned below and the simulation results, create the requested plots.

Received Packets Ratio: This ratio is defined as the total number of received packets at the network server (totalReceivedPackets) divided by the total number of packets sent by all nodes (sentPackets).

Received Packets Ratio = (totalReceivedPackets) / (∑_(n=1)^(number of nodes)▒sentPackets(n))

Energy Consumption (mJ): The total energy consumption of all nodes divided by the total number of received packets.

Based on the simulation results and the generated plots, answer the following questions:
a) Explain the impact of increasing or decreasing each of the parameters (spreading factor, transmission power, bandwidth, and the number of nodes) on the received packet rate and energy consumption.
b) Investigate which combination of parameters resulted in the highest and lowest received packet rates and explain the reasons behind these outcomes.

Research the concept of Adaptive Data Rate (ADR) in LoRaWAN communication networks. Explain which parameters affect ADR and how these changes are applied.

# Exercise 4
Section One: Setting Up the MQTT Protocol

The MQTT protocol's architecture includes a broker that communicates with one or more devices. Communication is based on messages and topics (publish/subscribe) sent to a node. Other nodes can also receive these messages. A central server is responsible for network management and message transmission.

Install an MQTT broker on your personal system and specify the IP address and port used for the MQTT server. You can use an open-source broker like Mosquitto, EMQ, or Mosca. It is recommended to use the Mosquitto MQTT broker.
Install the necessary MQTT client libraries and run the provided scenario. This protocol has client libraries available for almost all programming languages. For Node 1, it is recommended to use a library suitable for NodeMCU, and for Node 2, implement it in Python.
Explain the parameters present in the sent packet from the client to the server and vice versa.
Section Two: Setting Up the CoAP Protocol

Install a CoAP server on your personal system and specify the IP address and port used for the CoAP server. You can use any open-source CoAP server.
Install the required CoAP client libraries and run the provided scenario. This protocol also has client libraries available for most programming languages. You can use any library for Node 1 and Node 2.
Compare the architecture, energy consumption, security, service quality, and packet size of MQTT and CoAP.
Section Three: Setting Up the HTTP Protocol

The HTTP protocol uses handshaking for sending and receiving data. Several requests and responses are exchanged between the server and the client to initiate and conclude data exchange operations. It should be noted that TCP/IP protocols are used in this process to enhance security and ensure data transmission.

Install an HTTP server on your personal system and specify the IP address and port used for the HTTP server. Nginx is recommended for an HTTP server.
Install the required HTTP client libraries and run the provided scenario.
Explain the reasons for replacing MQTT and CoAP with HTTP in many IoT applications.
Section Four: Setting Up the AMQP Protocol (Optional)

The Advanced Message Queuing Protocol (AMQP) is an open-source standard for message transmission between nodes. The AMQP architecture includes a broker that communicates with one or more devices. Two operations, exchanges and queues, are used to transfer data from the message publisher to the message subscriber in this protocol.

Install an AMQP broker on your personal system and specify the IP address and port used for the AMQP broker. You can use any open-source AMQP broker.
Install the required AMQP client libraries and run the provided scenario.
Section Five: Sending and Receiving to the Platform (Extra Credit)

In general, an IoT platform plays a significant role in the IoT architecture. An IoT platform facilitates communications, data streaming, device management, and the efficiency of applications. Many open-source IoT platforms have been introduced, each with different capabilities. Some of these platforms have been incorporated into commercial products and have been developed as top-tier alternatives.

Evaluate three open-source IoT platforms, outlining their advantages and disadvantages, and compare them.
Choose one of the explained platforms and have Node 1 send packets to the platform. Display received data from Node 1 in real-time on the platform (the choice of programming language and protocol for communication with the platform is optional).
Utilize a section within the platform for data analysis and visualization. Display the data sent by Node 1 in graphs.
Use the platform's embedded services to receive the data sent by Node 1 and display it in a mobile or web application. Issue confirmation commands through this application.

