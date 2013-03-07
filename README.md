# Reverse shuffle

A quick recalibration of David Carne's *Reverse Engineering the iPod Shuffle 3G headphone remote protocol* from http://david.carne.ca/shuffle_hax/shuffle_remote.html for the stock Arduino Atmega 328 clocked to 16Mhz.

## To compile and write

* Get avrdude and avr-gcc
* Attach AVR-ISP to ISP-port
* Compile with 'make'
* Flash with 'make flash'
* Signal appears on PIN5 on the Arduino (PortB, pin 5)

If avrdude can't find your programmer try editing the makefile l.33 

PROGRAMMER ?= -c avrisp2 -P usb

to point to where the programmer actually show up, /dev/something, instead of just usb.

