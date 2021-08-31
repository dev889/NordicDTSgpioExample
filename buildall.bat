cls
@echo off

set GNUARMEMB_TOOLCHAIN_PATH=C:/Users/amuenger/ncs/v1.5.1/toolchain/opt/bin
set ZEPHYR_TOOLCHAIN_VARIANT=gnuarmemb
set ZEPHYR_BASE=C:\_def\nsc\v1.5.1\zephyr
set JLINK_ROOT="C:\Program Files (x86)\SEGGER\JLink"

set DEVICE=nrf52832
set JLINK_SERIAL=960084090
set GDB_PORT_NUMBER=2331
set JLINKGDBSERVER=%JLINK_ROOT%/GDBServer

west build -p -b nrf52dk_nrf52832 --build-dir build
west flash --build-dir ./build
