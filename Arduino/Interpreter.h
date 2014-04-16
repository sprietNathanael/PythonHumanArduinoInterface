/*Arduino sketch that will respond to the Python
script and execute its requests
Author : Nathanaël SPRIET <nathanael.spriet@gmail.com>
Date : April 16, 2014
Version : 0.0.1
Released on public domain*/

#ifndef INTERPRETER_H
#define INTERPRETER_H

	#include "Arduino.h"
	#include "string.h"


	/*Initialise the serial link*/
	void initSerial();
	/*Call the function to read the differents
	Arduino inputs and send them on the serial link*/
	void sendDatas();
	/*Read the command on the serial link,
	interpret them to call the appropriate function*/
	void executeCommand();
	/*WriteDigitalData function
	Arguments :
	pin : the pin on which it has to write
	data : the data to be written : 1 or 0
	*/
	void writeDigitalData(String pinName, int data);
	/*WriteAnalogData function
	Arguments :
	pin : the pin on which it has to write
	data : the data to be written : 0 to 5 for the voltage analogic ones
	*/
	void writeAnalogData(String pinName, double data);
	/*Matches the pinName and the Arduino pin
	Argument : pinName : a string that represents the pin name
	returns : the pin indice that correspond to the pin name*/
	int pinCorrespondance(String pinName);

	/*Initialise the pins*/
	void initialise();

#endif INTERPRETER_H