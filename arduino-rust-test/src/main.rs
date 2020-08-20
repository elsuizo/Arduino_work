#![no_std]
#![no_main]

// Pull in the panic handler from panic-halt
extern crate panic_halt;

use arduino_uno::hal::port::mode::Floating;
use arduino_uno::prelude::*;

use arduino_uno::pwm;

const DELAY: u16 = 3000u16;

#[arduino_uno::entry]
fn main() -> ! {
    let dp = arduino_uno::Peripherals::take().unwrap();

    let mut delay = arduino_uno::Delay::new();

    let mut pins = arduino_uno::Pins::new(dp.PORTB, dp.PORTC, dp.PORTD);

    // this is the console. To see the output do (on mac)
    // screen /dev/tty/<your_tty_here> 57600
    // ls /dev/tty* | grep usb --> get the usb connected
    // 57600 is the baud rate
    let mut serial = arduino_uno::Serial::new(
        // protocol to communicate bytes in 2 directions
        // USART0 is moved to serial, serial becomes the new owner
        // https://rahix.github.io/avr-hal/atmega328p_hal/usart/struct.Usart0.html
        dp.USART0,
        // the values below correspond to :
        // rx: receive pin (hardwired into the MCU)
        // tx : PD1 is the "hardcoded output"
        // the ownership is moved by writing explicitely input, output is enforced at compile time,
        pins.d0,
        pins.d1.into_output(&mut pins.ddr),
        // other well known baud rates are possible (9600)
        57600,
    );
    // downgrading the pins allow to put them in an array and simplify functions:
    // according to docs : Downgrade this pin into a type that is generic over all pins.
    let mut led = pins.d13.into_output(&mut pins.ddr);

    loop {
        delay.delay_ms(DELAY);
        led.toggle();
        delay.delay_ms(DELAY);
    }
}
