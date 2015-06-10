tm4c-ssi-multichanel-audio
==========================

This project presents method how to use SSI units of Tiva microcontroller as left justified I2S audio slave device in 8x8 configuration.

Planed features
---------------

modules:
- SSI based left justified driver (callback interface, no DMA :-(, interrupt driven, standard signal structures and definitions)
- fixed point mixing matrix + mixer api (24 bit input, 32 bit output), mixer API
- biquad filters, processing API
- simple RMS compressor, compressor API
- delay, delay API

examples:
- practical implementation of this module in simple digital audio mixer
- usb audio interface
