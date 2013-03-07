# Chord Keyboard firmware for AVR Atmega 328p

## Support

Will run on any standard Arduino with a 328p processor.

## Getting started

    $ make
    $ make flash

## Connecting

Switches connects between GND and digital input pins on port B. The inputs are programmed with internal pull up resistors so the buttons should close the circuit when pressed.

Finger: AVR Port / Arduino Port:

- Little finger: PB0 / Digital 8
- Ring finger: PB1 / Digital 9
- Middle finger: PB2 / Digital 10
- Index finger: PB3 / Digital 11
- Thumb: PB4 / Digital 12

## Modules

### scanner

Reads the input port and keeping track of time generating a stream of chord-events that is fed to the parser.

### parser

Maintains a queue of unprocessed chording events and employ a battery of heuristics in an attempt to determine
what is intentional and what is artifacts of neurons and muscles.

### predictor

Uses statistics to tell if a given character is likely in a given situation. Currently supports a two level markov
chain generated from the Brown corpus. Given two letters it can tell the rank of the five most likely characters
to follow. The source data is generated by `./scripts/generate_trigram_map.rb` and the results can be found in 
`trigram_map.h`.

### Generating `trigram_map.h`

You need ruby installed

    $ gem install bundler
    $ bundler install
    $ ruby ./scripts/generate_trigram_map.rb