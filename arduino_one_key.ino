/*
	Arduino 1-Key Keyboard

	Usage:
	Set the SWITCH_PIN and the KEY_CHAR to the desired values, then build and upload to your Pro Micro.
	Uncomment the DEBUG define to view key state via serial montior.

	References:
	https://www.arduino.cc/reference/en/language/functions/usb/keyboard/

	Keyboard.begin()      - Start keyboard emulation
	Keyboard.end()        - Stop keyboard emulation
	Keyboard.press()      - Press a key (does not release)
	Keyboard.print()      - Sends a char or string as keystrokes
	Keyboard.println()    - Sends a char or string as keystrokes, followed by a newline and carriage return
	Keyboard.release()    - Release a pressed key
	Keyboard.releaseAll() - Release all pressed keys
	Keyboard.write()      - Sends a keystroke (press and release)
*/

//#define DEBUG
#define SWITCH_PIN 8
#define KEY_CHAR '`'

#include <Keyboard.h>

void setup() {
#ifdef DEBUG
	Serial.begin(115200);
	Serial.println("Begin keyboard");
#endif
	pinMode(SWITCH_PIN, INPUT_PULLUP);
	Keyboard.begin();
}

void loop() {
#ifdef DEBUG
  Serial.print("Key state: ");
  Serial.println(digitalRead(SWITCH_PIN));
#endif
  if (digitalRead(SWITCH_PIN) == LOW)
    Keyboard.press(KEY_CHAR);
  else
    Keyboard.release(KEY_CHAR);
}
