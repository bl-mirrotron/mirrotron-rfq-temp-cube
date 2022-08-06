# RFQ Temperature Cube
* mirrotron-rfq-temp-cube <a href="https://github.com/bl-mirrotron/mirrotron-rfq-temp-cube" target="_blank">source code</a>
* [Cooling System Overview](https://bl-mirrotron.github.io/#cooling-system)
The function of the RFQ Temperature Cube is to measure the temperature of the cooling channels on both the upstream and downstream headers. The temperature is measured with <a href="https://www.maximintegrated.com/en/products/sensors/DS18B20.html#:~:text=The%20DS18B20%20communicates%20over%20a,for%20an%20external%20power%20supply." target="_blank">DS18B20</a> One-wire probes connected to a <a href="https://www.pjrc.com/teensy/teensyLC.html" target="_blank">Teensy LC</a> as the micro-controller. The Teensy LC communicates to a Blinky-Lite<sup>TM</sup> tray via the <a href="https://github.com/bl-mirrotron/mirrotron-rfq-temp-cube/blob/master/cubeCode/BlinkyBus.h" target="_blank">Blinky-Bus protocol</a> over the Serial1 port.

The schematic for the electrical cirucit is shown in Figure 1.

 <p></p><p style="text-align:center;font-size: large;"><span style="font-weight: bold;color: green;">Figure 1. </span> <span style="font-style: italic;">Electrical Schematic for rfq-temp-cube board</span></p>
 <div style="width:100%;text-align:center;"><img style="border-style:solid;border-color:#1c6e97;" src="doc/TempCubeSchematic.png"/></div><br>



<a href="" target="_blank">ipsofacto</a>
