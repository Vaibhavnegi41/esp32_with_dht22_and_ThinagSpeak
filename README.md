ESP32 + DHT22 + ThingSpeak IoT Project
📌 Project Overview
This project demonstrates how to use an ESP32 microcontroller with a DHT22 sensor to measure temperature and humidity, control an LED based on temperature threshold, and send the collected data to ThingSpeak for real-time cloud visualization.
The project is simulated using Wokwi but can also be implemented on real hardware.

⚙️ Features -----------
-Reads temperature and humidity using a DHT22 sensor.
-Controls an LED — turns ON if temperature exceeds a set threshold.
-Sends sensor data to ThingSpeak cloud using HTTP GET requests.
-Can be run both in simulation (Wokwi) and on real ESP32 hardware.

🛠️ Components Used---------
-ESP32 Development Board
-DHT22 Temperature & Humidity Sensor
-LED (built-in LED on GPIO2 or external)
-ThingSpeak account for cloud visualization
-Wi-Fi connection

🔌 Circuit Connections------
-Component	ESP32 Pin
-DHT22 VCC	3.3V
-DHT22 GND	GND
-DHT22 Data	GPIO 15
-LED (+)	GPIO 2
-LED (–)	GND

📜 How It Works-----
-ESP32 connects to Wi-Fi.
-Reads temperature and humidity values from the DHT22.
-Turns the LED ON if the temperature exceeds a set limit.
-Sends the data to ThingSpeak using its API key.
-Data is visualized on your ThingSpeak channel in real-time.

🖥️ Simulation on Wokwi-------
-You can simulate this project on Wokwi.
-Create a new ESP32 project.
-Add DHT22 and LED components.
-Connect them as per the circuit table above.
-Paste the code from this repository into sketch.ino.

📊 ThingSpeak Setup-------
-Create a free account on ThingSpeak.
-Create a new channel with:
-Field 1: Temperature
-Field 2: Humidity
-Copy the Write API Key and paste it into the code.

🏷️ Skills Used
-IoT Development
-Embedded C++ (Arduino)
-ESP32 Programming
-Cloud Integration (ThingSpeak)
-Sensor Data Acquisition

