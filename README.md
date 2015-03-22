Project based on https://code.google.com/p/u8glib to dispay data on an oled spi display, 
on A0 it's connected a power clamp, 50A with an output in a range of 0-5v. 
The voltage of the power clamp is measured by an arduino UNO and a conversion is done to display: 
- input value on A0 (range 0-1023)
- voltage (input val converted in voltage)
- watt of instant consumption
- cost of F1 (mon-fri 8-19) 
- cost of F23 (mon-fri 19-8 + sat-sun + festives)
