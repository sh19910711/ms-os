GPIO API
=======

GPIO API provides an interface to interact with GPIO pins.


Digital Pins
------------

### set_pin_mode ###
```api:c++
int GPIO::set_pin_mode(int pin, int mode);
```

Changes the mode of `pin` to `mode`.

Available `mode` are: `GPIO_INPUT_PIN` or `GPIO_OUTPUT_PIN`.

__Example:__ Change the mode of a digital pin #3.
```example:c++
GPIO.set_pin_mode(3, GPIO_INPUT_PIN);
```

### read ###
```api:c++
int GPIO::read(int pin);
```

Returns a value (`GPIO_HIGH` or `GPIO_LOW`) read from `pin`.

__Example:__ Read from GPIO digital pin #3.
```example:c++
GPIO.set_pin_mode(3, GPIO_INPUT_PIN);
Logging.printlnf("value: %s", GPIO.read(3) ? "HIGH" : "LOW");
```

### write ###
```api:c++
void GPIO::write(int pin, int value);
```

Change a output of `pin` to `value` (`GPIO_HIGH` or `GPIO_LOW`).

__Example:__ Turn a LED on.
```example:c++
/* connect a LED to pin #3. */
GPIO.set_pin_mode(3, GPIO_OUTPUT_PIN);
GPIO.write(3, GPIO_LOW);
```

Analog Pins
-----------

### read ###
```api:c++
int GPIO::read_analog(int pin);
```

Returns an integer value read from analog input (A/D converter) `pin`.

```note
The the range of a return value depends on the A/D converter.
```

__Example:__ Read from GPIO analog input pin #17.
```example:c++
/* No need to call `set_pin_mode()`. */
Logging.printlnf("value: %d", GPIO.read_analog(17));
```
