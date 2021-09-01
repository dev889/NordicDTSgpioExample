.. _dts custom gpio example:

Blinky
######

Repo to the ticket in the Nordic devzone
https://devzone.nordicsemi.com/f/nordic-q-a/77528/missing-binding-for-out-of-tree-driver

Overview
********
C:\_def\nsc\v1.5.1\zephyr\samples\basic\blinky was changed to a custom port 
called "valves instead of "gpio-leds". See the valve.yaml.

It works with compatible = "gpio-leds"; but it failes with compatible = "valve";

../src/main.c: In function 'main':
zephyr/include/generated/devicetree_unfixed.h:4089:32: error: 'DT_N_S_valve_S_p017_P_gpios_IDX_0_PH_P_label' undeclared (first use in this function)
 4089 | #define DT_N_ALIAS_valve1      DT_N_S_valve_S_p017

West version: v0.11.0
NSC V1.5.1.

Finally the problem is solved:  

The valve.yaml has to be placed (out-of-tree-project)\dts\bindings

Another improvement is not to use a costume board but define nrf52dk_nrf52832.overlay and compile with west build -p -b nrf52dk_nrf52832 --build-dir build. The nrf52dk_nrf52832.overlay is placed in (out-of-tree-project)\boards

Requirements
************
The example was tested on nrf52-DK

Building and Running
********************
west build -p -b nrf52dk_nrf52832 --build-dir build

For windows run buildall.bat

You must change the buildall.bat for your machine. The three paths have to be changed:
set GNUARMEMB_TOOLCHAIN_PATH=C:/Users/yourName/ncs/v1.5.1/toolchain/opt/bin
set ZEPHYR_BASE=C:\Users\yourName\ncs\v1.5.1\zephyr
set JLINK_ROOT="C:\Program Files (x86)\SEGGER\JLink


After flashing, the LED starts to blink. Blinky does not print to the console.
