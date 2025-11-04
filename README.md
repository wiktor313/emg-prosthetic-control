# kod_do_sterowania (Arduino)

This folder contains the Arduino sketch `kod_do_sterowania.ino` used to read an EMG sensor and control a servo.

## Hardware
- Arduino Uno / Nano / compatible
- EMG sensor connected to analog input A0
- Servo motor connected to digital PWM pin 9
- Power the servo appropriately (external supply recommended for higher-current servos). Share ground between Arduino and servo power supply.

## Sketch behavior
- Analog EMG readings are taken from `A0`.
- A moving average filter of 10 samples is applied to reduce noise.
- The averaged value is mapped from the range `[50, 800]` to servo angles `[0, 180]`. Adjust these bounds to fit your sensor/calibration.
- The servo is controlled on pin 9 using the Arduino `Servo` library.
- The sketch prints the averaged EMG value to Serial at 9600 baud (one integer per line). The PC app (Biomonitor) can read these values.

## Usage
1. Open `kod_do_sterowania.ino` in the Arduino IDE.
2. Connect the Arduino to your PC.
3. Select the correct board and COM port in the Arduino IDE.
4. Upload the sketch.
5. Open Serial Monitor (baud 9600) to inspect raw averaged values. The Biomonitor app can read these same values.

## Calibration tips
- The mapping limits `50` and `800` are example thresholds — change them if your sensor outputs a different baseline or saturation.
- Increase `numReadings` for stronger smoothing at the cost of response speed.
- Add a hardware RC filter or use shielding if EMG is very noisy.

## Safety
- Make sure servo power does not draw more current than your supply can provide.
- Avoid pin conflicts and ensure ground common between systems.

## License
Add license info here if needed.
