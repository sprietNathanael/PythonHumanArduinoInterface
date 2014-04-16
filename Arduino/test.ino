#include "Interpreter.h"




void setup() {
	/*Call the initialisations functions*/
	initSerial();
	initialise();
}


void loop() {
	/*Main loop : call the execute command function*/	
	executeCommand();
}

