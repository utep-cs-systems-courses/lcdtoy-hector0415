# LCD Toy
## What It Is
This is a toy that can be loaded onto an MSP430 and draws a figure onto the
screen that can be dynamically moved. As the shapes moves across the screen,
it plays a tone that increases and decreases depending on what direction the
shape is moving in.
## How To Install
1. The first thing that must be done is install the libraries that are
included in the root directory. The following command should be run in the
root directory.
> make
2. After installing the libraries, the program can now be built and loaded
onto the msp430. To do so, enter the following command with the msp430
connected to the computer.
> make load
## Cleaning The Directory
To remove the object files and the program itself from the directory, run the
following command.
## What The Program Does
### Switch One
When the first switch is pressed, the figure moves to the left and the tone
that is being played decreases.
### Switch Two
When the second switch is pressed, the figure moves to the right and the tone
that is being played inceases.
### Switch Three
When the third switch is pressed, the figure moves down and the tone that is
being played decreases.
### Switch Four
When the fourth switch is pressed, the figure moves up and the tone that is
being played increases.
