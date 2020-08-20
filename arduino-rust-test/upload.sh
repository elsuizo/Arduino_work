# prevent flashing if error
set -e cargo +nightly build

avrdude -p atmega328p -c arduino -P /dev/ttyACM0 -U flash:w:target/avr-atmega328p/release/arduino-rust-test.elf:e
# show on console with baud rate 57600
minicom /dev/ttyACM0 57600
