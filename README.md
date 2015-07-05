FreeSoC2 FreeRTOS Demo
======================

This is a simple PSOC Creator project for the Sparkfun FreeSoC2 board demonstrating the use of FreeRTOS.

The FreeRTOS files needed to build this demo have been copied into this project.

In real life, **please don't do this**.   You should instead follow the conventions of FreeRTOS and reference FreeRTOS from its installation directory, following the direction of FreeRTOS documentation.

This configuration is placed this way in this project simply to facilitate an easy introduction.

In freesoc.cydsn/ there is a Makefile wrapper that invokes the Cypress Project manager with several useful targets provided to permit running the build and flashing steps from the command line.   This is to facilitate things like running builds under Emacs, etc.

The FreeRTOS files remain licensed under their original terms.  You are free to use the files I wrote under the terms contained in the LICENSE.txt file.
