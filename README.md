# Racing Car
Hacking RC car to apply self-driving concept for car racing

### RC Car

For this project we bought an rc car. We had multiple options to solve the problem of controlling the wehical from PC (Mac). We could:
  
  * Follow multiple [tutorials](http://www.instructables.com/id/Autonomous-Control-of-RC-Car-Using-Arduino/) to create RC car controlled by Arduino. This would require to solve a problem of how to transmit the signal from the PC to the car (the first problem remains unsloved). We'd had to use either USB or wi-fi modules.
  * Make a radio transmitter on PC. Most of the guides explain how to make a radio transmitter (but only for FM frequency) or using oscillator to find a frequency of the car and basically using brute force checking each and every value until car moves.
  * The best thing is that RC car already has everything - car mechanics and radio transmitter. We only need to hack it. So we bought some pins and prototyping print-board for the POC.

**This is our car.** We chose to buy a mid-zise car with big enough weels, so it could handle hardware weight in the future:

<img src="https://cloud.githubusercontent.com/assets/5836188/24587337/69e984c4-17bd-11e7-8d42-aa7a150eb7c0.jpeg" width="300">

**Radio transmitter board.** You can see that turns and moves forward/backward are handled by buttons on the board. So we needed to solder pins to button and power a board from a PC/controller:

<img src="https://cloud.githubusercontent.com/assets/5836188/24587319/f8fa9dd4-17bc-11e7-893b-158c1033a5cf.jpeg" width="300">

**How to control car digitally**

Each pin from every button on the transmitter board must be connected to a ground in order to close a circuit so car moves or turns. We have 4 pins and they must be controlled from 4 different grounds (so we can control all of them independently). Thus, we decided to get an Arduino controller to control 4 different pins. Here is what we got:

<img src="https://cloud.githubusercontent.com/assets/5836188/24587295/6a7bf350-17bc-11e7-81be-9b1ce2df45f5.jpeg" width="300">

We used [**Arduino Uno Plus**](http://www.waveshare.com/uno-plus.htm) 

All the source code is presented here
