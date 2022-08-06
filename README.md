# RFQ Temperature Cube
* mirrotron-rfq-temp-cube <a href="https://github.com/bl-mirrotron/mirrotron-rfq-temp-cube" target="_blank">source code</a>
* [Cooling System Overview](https://bl-mirrotron.github.io/#cooling-system)
The function of the RFQ Temperature Cube is to measure the temperature of the cooling channels on both the upstream and downstream headers. The temperature is measured with <a href="https://www.maximintegrated.com/en/products/sensors/DS18B20.html#:~:text=The%20DS18B20%20communicates%20over%20a,for%20an%20external%20power%20supply." target="_blank">DS18B20</a> One-wire probes connected to a <a href="https://www.pjrc.com/teensy/teensyLC.html" target="_blank">Teensy LC</a> as the micro-controller. The Teensy LC communicates to a Blinky-Lite<sup>TM</sup> tray via the Blinky-Bus protocol.
