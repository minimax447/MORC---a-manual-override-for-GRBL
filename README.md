# MORC---a-manual-override-for-GRBL

MORC came out of a first attempt to use GRBL and crashing the tool into the test piece.
Sometimes it is a better idea to drive a mill manually. Setting up the position manually and then disconnecting UGS will re establish the system at zero, for example. The ability to run the steppers on manual without having to cad draw a component was a big driver for this.
So this is a three axis stepper driver that connects to GRBL that uses a joystick or buttons to run the motors continuously at a speed determined by a pot connected to A0. This is a more convenient way of using the machine than jogging in my opinion.
The outputs are gated to GRBL to avoid hurting the GRBL or MORC boards so the GRBL stepper enable(active low) passes through MORC.
It is cheap, uses a Nano and a scrap of stripboard to construct it and it uses very simple source code (Written for beginners by beginners!)
