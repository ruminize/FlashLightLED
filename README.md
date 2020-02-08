# FlashlightLED

<img align="left" width="200" height="200" src="./ledlightstrip.jpg" style="padding-right: 20px;">

<p style="padding-bottom: 180px;">
An Arduino library that can programmatically manipulate the LED color changing light strips controlled by a 44 Key IR Remote.
</p>

<br>
<br>
<br>
<br>
<br>
<br>

## Getting Started
In the Arduino IDE, click **Sketch** >> **Include Library** >> **Manage Libraries...**

With the Arduino **Library Manger** window open, in the *_Filter your search..._* input type: *FlashlightLED*.

Select the *FlashlightLED* library and click *Install*.

Include the *FlashlightLED* library in your Arduino sketch.
```
#include <FlashlightLED.h>
```
---
## Build an Arduino IR Transmitter

Notes:
  - Requires one infrared (IR) LED.
  - The IR LED short leg is ground.
  - Pin #3 **MUST** be used as the transmit pin. This library uses the Arduino IRremote library by Sherriff, which uses pin #3.
  - The resistor value in the image is 100ohm, but higher resistor values may be used to shorten the distance of the transmission when interference is an issue.
  - This library transmits on the IR NEC Protocol.
  <a href="https://exploreembedded.com/wiki/NEC_IR_Remote_Control_Interface_with_8051">NEC Protocol Tutorial</a>

<p align="center">
  <img src="./IRRemoteCircuit.jpg">
</p>

---

## IR Remote Button-To-Method Mapping Diagram

Notes:
- All methods in the library are capitalized e.g. QUICK, DIY3, SLOW, COLOR, RANDOM_COLOR etc...
- Any button with a printed word has a matched method i.e. the button with the word *FLASH* maps to the method FlashlightLED.FLASH().
- Any button with numbers displays the two arguments required to activate the corresponding button via the method displayed in the attached word bubble: method(column, row).

<p align="center">
  <img src="./lightStripRemote.jpg">
</p>

---

## Documentation

#### Luminosity

The following methods change the luminosity of the lights.

Notes:
- The IR Remote has eight luminosity settings. It takes seven clicks to get from full dim to full brightness or vice versa.
- Both the *BRIGHTEN* and *DIM* method default to 10 pulses to over compensate in case of a missed signal.

```
/*
Takes an optional integer parameter.
If no integer is provided ten pulses will be emitted.
When an integer is provided, the integer will be the number of pulses.
*/

BRIGHTEN(int:optional)

DIM(int:optional)
```

##### Additional method

The following method was added to attempt a specific luminosity.

Notes:
- The library cannot keep track of the current luminosity setting as there is no confirmation signal from the LED lights.
- The *LUMENS* method attempts full dim, then applies the default or supplied argument.
- If a level of six out of eight settings is desired, the method will first apply ten dimming pulses, then use the supplied 5 integer to count up from a dim setting of 1.

```
/*
Takes an optional integer parameter.
If no integer is provided four pulses will be emitted to achieve a middle luminosity.
When an integer is provided, the integer will be the number of pulses starting at full dim.
*/

LUMENS(int:optional)
```

---

#### Flash Interval

The following methods change the speed of flashing lights.

Notes:
- The IR Remote has sixty luminosity settings. It takes sixty clicks to get from the longest to the shortest flash interval or vice versa.
- Both the *QUICK* and *SLOW* method default to 65 pulses to over compensate in case of a missed signal.

```
/*
Takes an optional integer parameter.
If no integer is provided 65 pulses will be emitted.
When an integer is provided, the integer will be the number of pulses.
*/

QUICK(int:optional)

SLOW(int;optional)
```

##### Additional method

The following method was added to attempt a specific flash interval.

Notes:
- The library cannot keep track of the current flash interval setting as there is no confirmation signal from the LED lights.
- The *SPEED* method attempts to set the longest flash interval, then applies the default or supplied argument.
- If a level of thirty out of sixty settings is desired, the method will first apply 65 dimming pulses, then use the supplied 30 integer to count up from a slow setting of 1.
```

/*
Takes an optional integer parameter.
If no integer is provided thirty pulses will be emitted to achieve a middle flash interval.
When an integer is provided, the integer will be the number of pulses starting at the longest interval setting.
*/

SPEED(int:optional)
```
---

#### Color Selection

The following method is used to select one of the twenty selectable colors.

Notes:
- The IR Remote has twenty default colors to choose from.
- The *COLOR* method sends one pulse.
- There are four columns and five rows.

```
/*
Takes two required integer parameters: column #, row #.
*/

COLOR(int:required, int:required)
```

##### Additional method

```
/*
Takes one optional integer parameter: column #.
If an integer:column is supplied, the random selection will be confined to that column.
If no integer is provided, a random color will be selected from any column and row with each method call.
*/

RANDOM_COLOR(int:optional)
```
---
#### Color Variation

The following method is used to select a color arrow.

Notes:
- The IR Remote has six color arrows to choose from.
- The *ARROW* method sends one unless the third optional argument is supplied.
```

/*
Takes two required integer parameters: column #, row #.
*/

ARROW(int:required, int:required)
```
---

#### Do It Yourself (DIY)

The following methods map to the DIY# buttons.

Notes:
- The IR Remote has six memory selections.

```
DIY1()

DIY2()

DIY3()

DIY4()

DIY5()

DIY6()
```

#### Remaining Methods

```
PLAY()

POWER()

JUMP3()

JUMP7()

FADE3()

FADE7()

FLASH()

AUTO()
```

#### Method Chaining

Notes:
- All methods can be chained.
- A *DELAY* method is available to separate method chaining with delays.

```
DELAY(int:required)
```

---

## WARNING!!!
<p>
Potential fire hazard!
</p>

<p>
When the lights are coiled and powered on, enough heat is produced to melt the lights and reel. When under power
uncoil lights to prevent high heat condition.
</p>

---

## Sketch 1
Example sketch sends an IR signal equivalent of the *AUTO* button on the remote and then sends 
an IR signal equivalent to the <*increase brightness symbol*> button on the remote.
The LED light strips should enter into *AUTO* mode and set *FULL* brightness.

```
#include <FlashlightLED.h> // Import library;

FlashlightLED lights; // Now referenced as lights throughout sketch.

void setup(){
  // Serial Monitor @ 9600 baud
  Serial.begin(9600);
  lights.AUTO().BRIGHTEN();
  lights.COLOR(0,3).DELAY(5000).COLOR(0,0).DELAY(10000).FLASH();
}

void loop(){}
```
---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.md) file for details