# 🐔 CocciCare: Solar-Powered  Poultry Monitoring System
> **Focus:** Environmental Sensing and Resource-Efficient Hardware.

CocciCare is an intelligent health monitoring system designed for poultry farms. The project focuses on bridging the gap between practical agricultural management and **on-device inference**, using a multi-sensor array to maintain operational integrity in high-entropy, resource-constrained environments.

## 🚀 The Challenge
Poultry environments are harsh, with high levels of dust and ammonia that can cause sensor failure. This project investigates how to maintain accurate data collection and provide real-time behavioral alerts while operating on a **solar-powered budget**.

## 🛠️ Technical Implementation
* **Hardware Stack:** ESP32, DHT22 (Temp/Humidity), MQ-135 (Ammonia), and RGB Status LEDs
* **Connectivity:** Integrated **Blynk IoT** for remote monitoring and real-time event logging
* **Firmware Logic:**
    * **Tiered Alert System:** Implemented logic to trigger distinct "Warning" vs "Critical" states based on comfort-level thresholds
    * **Air Quality Monitoring:** Calibrated MQ-135 thresholds to detect poor air quality (NH3) using analog sensing on the ESP32
    * **Visual Feedback:** RGB LED indicators (Active Low/High) for immediate on-site status reporting

## 🎯 Results & Metrics
* **Robustness:** Evaluated sensor performance under prolonged exposure to high-ammonia concentrations
* **Latency:** Optimized the control loop to ensure environmental alerts and Blynk virtual writes occur within seconds of threshold breach
* **Compute Efficiency:** Managed multi-sensor acquisition and WiFi stack on a single ESP32 core without blocking critical alert triggers

## 📂 Project Workflow
1. **Sensor Calibration:** Individual testing of DHT22 and MQ-135 for baseline threshold determination.
2. **Integration:** Merging sensing logic with the Blynk IoT framework for cloud-based logging
3. **Firmware Optimization:** Finalizing the integrated control law for agricultural deployment
