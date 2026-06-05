# 🌱 Smart Irrigation System

<div align="center">

![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Cost](https://img.shields.io/badge/Total%20Cost-₹625-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Working-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)

**An Arduino-based automatic plant watering system built under ₹1000**

*Automatically detects soil dryness and waters the plant — no human effort needed*

[Live Dashboard](#) · [View Circuit](#circuit-connections) · [Download Code](#arduino-code) · [Bill of Materials](#bill-of-materials)

</div>

---

## 👥 Group Members

| Name | Role |
|---|---|
| Arshan Khan | Circuit design & hardware assembly |
| Anurag Sharma | Arduino programming & testing |
| Gaurav Rawat | Dashboard development & calibration |
| Sahil Bora | Documentation & presentation |
| Jay Manral | Testing, debugging & demonstration |

**Subject:** Environmental Impact Analysis  
**Institution:** Class Project  
**Total Cost:** ₹625 (₹375 under the ₹1000 budget)

---

## 📋 Table of Contents

- [About the Project](#about-the-project)
- [The Problem We Are Solving](#the-problem-we-are-solving)
- [How It Works](#how-it-works)
- [Components Used](#components-used)
- [Bill of Materials](#bill-of-materials)
- [Circuit Connections](#circuit-connections)
- [Arduino Code](#arduino-code)
- [Live Dashboard](#live-dashboard)
- [Calibration Guide](#calibration-guide)
- [Real Life Implementation](#real-life-implementation)
- [Environmental Impact](#environmental-impact)
- [Results](#results)
- [Future Improvements](#future-improvements)

---

## 🎯 About the Project

This project is a **low-cost automatic irrigation system** that uses a soil moisture sensor to detect when a plant needs water and automatically activates a pump to water it. The system is controlled by an Arduino Uno microcontroller and costs only ₹625 to build.

A live web dashboard built in HTML and JavaScript connects to the Arduino via USB and displays real-time moisture readings, pump status, moisture history chart, and sounds an alarm when the plant needs water. The dashboard supports 28 different crops and plants with individual moisture thresholds.

### Key Features

- ✅ Automatic pump activation based on real soil moisture
- ✅ Supports 28 crops across 5 categories with individual thresholds
- ✅ Auto-calibration — no manual threshold setting needed
- ✅ Live web dashboard with real-time chart, gauge and alarm
- ✅ Event logging with timestamps
- ✅ Saves calibration data in browser — no redo needed
- ✅ Built under ₹1000 with easily available components
- ✅ Scalable from single pot to full farm

---

## 🌍 The Problem We Are Solving

Agriculture consumes **70% of the world's freshwater** but traditional irrigation methods waste up to **60% of that water** through over-irrigation, flood irrigation and manual guesswork.

In India specifically:
- 40% of agriculture is rain-dependent with no backup irrigation
- Farmers have no real-time data on soil moisture
- Manual watering leads to inconsistent crop growth
- Groundwater depletion is accelerating due to inefficient irrigation
- Climate change is making rainfall increasingly unpredictable

Our smart irrigation system directly addresses these problems by automating the watering process based on actual soil data rather than guesswork.

---

## ⚙️ How It Works

```
┌─────────────────────────────────────────────────────────┐
│                    SYSTEM FLOW                          │
│                                                         │
│  Soil Sensor  →  Arduino Uno  →  Relay Module  →  Pump │
│  (reads every      (compares      (switches         (waters  │
│   2 seconds)        value)         ON/OFF)          plant)  │
└─────────────────────────────────────────────────────────┘
```

### Logic

```
Every 2 seconds:
  Read soil moisture sensor → get raw value (0-1023)
  
  IF raw value > 600 (soil is DRY):
    Send LOW signal to relay
    Relay turns ON
    Pump starts running
    Water flows to plant
    
  IF raw value ≤ 600 (soil is WET):
    Send HIGH signal to relay
    Relay turns OFF
    Pump stops
    No water wasted
```

### Why Active LOW?

The relay module used in this project is **Active LOW** — meaning it turns ON when it receives a LOW signal and turns OFF when it receives HIGH. This is standard for most Indian Arduino relay modules. The code accounts for this by inverting the usual logic.

---

## 🔧 Components Used

| Component | Specification | Purpose |
|---|---|---|
| Arduino Uno | Clone, ATmega328P | Brain of the system |
| Soil Moisture Sensor | YL-69 module | Detects soil wetness |
| Relay Module | 5V single channel | Switches pump ON/OFF |
| Mini Submersible Pump | 5V DC | Waters the plant |
| Breadboard | Half size | Prototyping |
| Jumper Wires | Male-to-male and male-to-female | Connections |
| 9V Battery + Connector | Standard | Powers pump |
| Silicone Tube | 6mm diameter, 1m | Carries water to plant |
| USB Cable | USB-B type | Powers Arduino and uploads code |

---

## 💰 Bill of Materials

| S.No | Item | Source | Qty | Cost |
|---|---|---|---|---|
| 1 | Arduino Uno (Clone) | Amazon / Local shop | 1 | ₹280 |
| 2 | Soil Moisture Sensor YL-69 | Amazon / Robu.in | 1 | ₹50 |
| 3 | 5V Single Channel Relay | Amazon / Robu.in | 1 | ₹45 |
| 4 | Mini Submersible Pump 5V | Amazon / Local | 1 | ₹85 |
| 5 | Jumper Wires (20 pcs) | Amazon / Robu.in | 1 set | ₹60 |
| 6 | Breadboard (Half size) | Amazon / Local | 1 | ₹45 |
| 7 | 9V Battery + Snap Connector | Hardware shop | 1 | ₹30 |
| 8 | Silicone Tube 1m | Hardware store | 1m | ₹30 |
| 9 | Plastic Water Container | Home reuse | 1 | Free |
| 10 | USB Cable | Already available | 1 | Free |
| | **TOTAL** | | | **₹625** |
| | **Budget remaining** | | | **₹375** |

---

## 🔌 Circuit Connections

### Soil Moisture Sensor → Arduino

| Sensor Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| AO (Analog Out) | A0 |
| DO (Digital Out) | Not used |

### Relay Module → Arduino

| Relay Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| IN | D8 |

### Pump Circuit

| From | To | Note |
|---|---|---|
| 9V Battery (+) | Relay COM terminal | Main power |
| Relay NO terminal | Pump (+) red wire | Switched power |
| 9V Battery (-) | Pump (-) black wire | Direct ground |

> ⚠️ Important: The 9V battery powers the pump directly. Arduino is powered separately via USB. Never power the pump from Arduino's 5V pin — it cannot supply enough current.

---

## 💻 Arduino Code

```cpp
/*
  =============================================
  Smart Irrigation System
  =============================================
  Group: Arshan Khan, Anurag Sharma, Gaurav Rawat, 
         Sahil Bora, Jay Manral
  Subject: Environmental Impact Analysis
  Cost: Under Rs.1000
  
  WIRING:
  Sensor AO  → Arduino A0
  Relay IN   → Arduino D8
  Battery(+) → Relay COM
  Relay NO   → Pump (+)
  Battery(-) → Pump (-)
  
  NOTE: This uses an Active LOW relay module.
  LOW signal = relay ON = pump runs
  HIGH signal = relay OFF = pump stops
  =============================================
*/

int sensorPin = A0;
int pumpPin   = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH);  // Start with pump OFF
}

void loop() {
  int val = analogRead(sensorPin);
  Serial.println(val);           // Dashboard reads this value

  if (val > 600) {
    // Soil is DRY
    digitalWrite(pumpPin, LOW);  // LOW = relay ON = pump runs
    Serial.println("PUMP ON");
  } else {
    // Soil is WET
    digitalWrite(pumpPin, HIGH); // HIGH = relay OFF = pump stops
    Serial.println("PUMP OFF");
  }

  delay(2000);  // Check every 2 seconds
}
```

### How to Upload

1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Connect Arduino to laptop via USB
3. Open `arduino/smart_irrigation.ino`
4. Go to **Tools → Board → Arduino Uno**
5. Go to **Tools → Port → Select your COM port**
6. Click **Upload** (right arrow button)
7. Wait for "Done uploading" message

---

## 📊 Live Dashboard

The project includes a web dashboard built in plain HTML, CSS and JavaScript — no framework needed.

### Features

- Real-time moisture gauge with animated needle
- Live history chart (last 40 readings)
- Plant health illustration that changes with moisture level
- System flow diagram that animates when pump runs
- Alarm sound when moisture drops below threshold
- Auto-calibration wizard for accurate readings
- 28 crops across 5 categories with individual thresholds
- Event log with timestamps
- Calibration saved in browser — no redo needed

### How to Use Dashboard

1. Open `dashboard/index.html` in **Google Chrome**
2. Select your crop from the category grid
3. Click **Connect Arduino** → select COM port
4. Calibration wizard opens automatically
5. Follow 2-step calibration (dry reading then wet reading)
6. Live monitoring begins — everything is automatic

> ⚠️ Web Serial API requires Google Chrome or Microsoft Edge. Does not work in Firefox.

---

## 🎯 Calibration Guide

Every soil sensor reads differently. Auto-calibration teaches the dashboard your exact sensor range.

### Steps

**Step 1 — Connect Arduino and open dashboard in Chrome**

**Step 2 — Click Connect Arduino**

**Step 3 — Calibration wizard opens automatically**

**Step 4 — Dry reading**
- Hold probes in open air or completely dry soil
- Wait for value to stabilise
- Click Capture dry value

**Step 5 — Wet reading**
- Dip probes in water or very wet soil
- Wait for value to drop and stabilise
- Click Capture wet value

**Step 6 — Click Apply and monitor**

Calibration is saved in browser. Never needs to be redone unless you change soil type.

---

## 🌾 Supported Crops

| Category | Crops |
|---|---|
| Vegetables | Tomato, Potato, Onion, Spinach, Chilli, Brinjal, Carrot, Cabbage |
| Cereals & Pulses | Wheat, Rice, Maize, Chickpea, Soybean, Mustard |
| Fruits | Mango, Banana, Papaya, Guava, Watermelon, Strawberry |
| Flowers & Indoor | Rose, Sunflower, Tulsi, Money Plant, Aloe Vera, Marigold, Portulaca |
| Cash Crops | Sugarcane, Cotton, Tea, Jute |

Each crop has individual minimum moisture threshold, optimal range, watering frequency, root depth and farming tips built in.

---

## 🚀 Real Life Implementation

### Phase 1 — This Project (Done ✅)
Single plant pot, Arduino + sensor + pump, working prototype demonstrating core logic.

### Phase 2 — Small Farm Scale
Multiple sensors across a small farm, larger pump, timer-based control, solar panel power.

### Phase 3 — Full Deployment
WiFi-enabled NodeMCU, mobile app monitoring, multiple irrigation zones, cloud data storage, weather API integration.

---

## 🌍 Environmental Impact

### Positive

| Impact | Details |
|---|---|
| Water conservation | Reduces water usage by 30–50% vs manual irrigation |
| Prevents over-irrigation | No waterlogging, soil erosion or nutrient runoff |
| Groundwater protection | Only uses water when actually needed |
| Lower energy use | Pump runs only when required |
| Better crop yield | Consistent moisture improves growth |
| Scalable solution | Same logic works from pot to farm |

### Challenges and Mitigations

| Challenge | Mitigation |
|---|---|
| E-waste from electronics | Use recyclable components, responsible disposal |
| Battery disposal | Switch to solar panel in Phase 2 |
| Sensor accuracy in different soils | Auto-calibration handles this |
| Power dependency | Solar + rechargeable battery for off-grid use |

---

## 📈 Results

After testing the working prototype:

- Sensor correctly detects dry vs wet soil in all conditions
- Pump activates within 2 seconds of soil going below threshold
- Dashboard displays accurate moisture percentage after calibration
- Alarm sounds immediately when moisture drops
- System runs continuously without any manual intervention
- Total cost came to ₹625 — ₹375 under the ₹1000 budget

---

## 🔮 Future Improvements

- [ ] Add solar panel for off-grid operation
- [ ] Replace Arduino with NodeMCU for WiFi monitoring
- [ ] Add temperature and humidity sensors
- [ ] Build mobile app for remote monitoring
- [ ] Add multiple sensor zones for larger plants
- [ ] Implement water level sensor in reservoir
- [ ] Add LCD display to show readings without laptop
- [ ] Integrate weather API to skip watering before rain

---

## 📁 Repository Structure

```
smart-irrigation-system/
│
├── README.md                          ← This file
├── index.html                         ← Live dashboard (GitHub Pages)
├── arduino/
│   └── smart_irrigation.ino           ← Arduino source code
├── presentation/
│   └── Smart_Irrigation_System.pptx   ← Class presentation
└── docs/
    ├── circuit_photo.jpg              ← Photo of built circuit
    └── demo_photo.jpg                 ← Project in action
```

---

## 📄 License

MIT License — free to use, modify and distribute with attribution.

---

## 🙏 Acknowledgements

- Arduino community for open source libraries
- Robu.in and Amazon India for affordable components
- Our teacher for guidance on environmental impact analysis

---

<div align="center">

**Built with ❤️ by Group 5 | Environmental Impact Analysis**

*Arshan · Anurag · Gaurav · Sahil · Jay*

</div>
