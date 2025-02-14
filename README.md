# Arduino Distance Measurement Project with I2C LCD Display (EN)

## Table of Contents
1. Project Overview
2. Components Used
3. Working Principle
4. How It Works
5. Pin Configuration
6. Installation and Setup
7. I2C Address Scanning
8. Conclusion

---

## Project Overview
This project measures the distance to an object using an ultrasonic sensor and provides feedback through:
- **Visual feedback**: An LED connected to pin 13.
- **Auditory feedback**: An active buzzer connected to pin 8.
- **Display**: An I2C 16x2 LCD screen to show the measured distance in real-time.

---

## Components Used
- **Arduino Uno**: The main microcontroller.
- **Ultrasonic Distance Sensor** (Trig: Pin 7, Echo: Pin 6): Measures the distance to an object.
- **I2C 16x2 LCD Display** (SDA: Pin A4, SCL: Pin A5): Displays the measured distance.
- **Active Buzzer** (Pin 8): Provides auditory feedback.
- **LED** (Pin 13): Provides visual feedback.
- **Breadboard**: Used for easy prototyping.
- **Current-limiting resistor**: Protects the LED from excessive current.

---

## Working Principle
The ultrasonic sensor sends out a pulse and measures the time it takes for the echo to return. The distance is calculated using the formula:

```
distance = (duration * 0.0343) / 2
```

where `duration` is the time taken for the echo to return.

Based on the distance:
- The **LED and buzzer** provide feedback (e.g., continuous light and sound for close distances).
- The **LCD** displays the distance in centimeters.

---

## How It Works
1. **Ultrasonic Sensor Measurement:**
   - The Arduino sends a pulse to the Trig pin.
   - The sensor emits an ultrasonic wave and waits for the echo.
   - The Echo pin receives the reflected signal.
2. **Distance Calculation:**
   - The Arduino calculates the distance using the duration of the echo.
3. **Feedback Mechanism:**
   - The LED and buzzer respond based on the measured distance.
4. **LCD Display:**
   - The LCD continuously updates to show the real-time distance.

---

## Pin Configuration
| Component          | Pin |
|-------------------|-----|
| Ultrasonic Trig   | 7   |
| Ultrasonic Echo   | 6   |
| Buzzer           | 8   |
| LED             | 13  |
| LCD SDA          | A4  |
| LCD SCL          | A5  |

---

## Installation and Setup
### LiquidCrystal_I2C Library Installation
1. Open the Arduino IDE.
2. Go to **Tools > Manage Libraries**.
3. Search for `LiquidCrystal_I2C` in the Library Manager.
4. Click **Install** to add the library.

---

## I2C Address Scanning
To find the I2C address of your LCD:
1. Upload the I2C Scanner code (provided in the .ino file) to your Arduino.
2. Open the **Serial Monitor** (9600 baud).
3. Note the I2C address displayed (e.g., `0x27`).
4. Update the address in your code:

```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2); // Replace 0x27 with your address
```

---

## Conclusion
This project demonstrates how to use an Arduino Uno with an ultrasonic sensor, I2C LCD display, LED, and buzzer to create a distance measurement system. It can be extended with additional sensors or more complex feedback logic for advanced applications.

---

## License
This project is open-source and available under the **MIT License**.

---

## How to Use the Code
1. Download the `.ino` files from the repository.
2. Open the files in the **Arduino IDE**.
3. Upload the code to your **Arduino Uno**.
4. Connect the components as described in the **Pin Configuration** section.
5. Enjoy your **distance measurement system**!

---

# Arduino I2C LCD Ekranlı Mesafe Ölçüm Projesi (TR)

## İçindekiler
1. Proje Özeti
2. Kullanılan Bileşenler
3. Çalışma Prensibi
4. Nasıl Çalışır?
5. Pin Konfigürasyonu
6. Kurulum ve Yapılandırma
7. I2C Adres Tarama
8. Sonuç

---

## Proje Özeti
Bu proje, ultrasonik sensör kullanarak bir nesneye olan mesafeyi ölçer ve aşağıdaki yollarla geri bildirim sağlar:
- **Görsel geri bildirim**: 13 numaralı pine bağlı bir LED.
- **Sesli geri bildirim**: 8 numaralı pine bağlı bir aktif buzzer.
- **Ekran**: Gerçek zamanlı mesafeyi göstermek için bir I2C 16x2 LCD ekran.

---

## Kullanılan Bileşenler
- **Arduino Uno**: Ana mikrodenetleyici.
- **Ultrasonik Mesafe Sensörü** (Trig: Pin 7, Echo: Pin 6): Nesneye olan mesafeyi ölçer.
- **I2C 16x2 LCD Ekran** (SDA: Pin A4, SCL: Pin A5): Ölçülen mesafeyi gösterir.
- **Aktif Buzzer** (Pin 8): Sesli geri bildirim sağlar.
- **LED** (Pin 13): Görsel geri bildirim sağlar.
- **Breadboard**: Kolay prototipleme için kullanılır.
- **Akım sınırlayıcı direnç**: LED'in aşırı akımdan korunmasını sağlar.

---

## Çalışma Prensibi
Ultrasonik sensör bir darbe gönderir ve yankının geri dönmesi için geçen süreyi ölçer. Mesafe şu formülle hesaplanır:

```
mesafe = (süre * 0.0343) / 2
```

Burada `süre`, yankının geri dönme süresidir.

Ölçülen mesafeye bağlı olarak:
- **LED ve buzzer** geri bildirim verir (örneğin, yakın mesafelerde sürekli ışık ve ses).
- **LCD ekranda** mesafe santimetre cinsinden gösterilir.

---

## Pin Konfigürasyonu
| Bileşen          | Pin |
|-----------------|-----|
| Ultrasonik Trig | 7   |
| Ultrasonik Echo | 6   |
| Buzzer         | 8   |
| LED            | 13  |
| LCD SDA        | A4  |
| LCD SCL        | A5  |

---

## Sonuç
Bu proje, Arduino Uno, ultrasonik sensör, I2C LCD ekran, LED ve buzzer kullanarak bir mesafe ölçüm sistemi oluşturmayı gösterir. Daha gelişmiş uygulamalar için ek sensörler veya daha karmaşık geri bildirim mantıkları eklenebilir.

Bu proje **MIT Lisansı** altında **açık kaynaklıdır**.
