/*Arduino sketch that will respond to the Python
script and execute its requests
Author : Nathanaël SPRIET <nathanael.spriet@gmail.com>
Date : April 16, 2014
Version : 0.0.1
Released on public domain*/

#include "Interpreter.h"
#include "Arduino.h"
#include "string.h"

/*The analogWrite function takes a 8-bits
integer for argument*/
#define VOLT_TO_INT_DIVISER (5.0/255.0)

/*Initialise the serial link*/
void initSerial()
{
	Serial.begin(115200);
}

/*Call the function to read the differents
Arduino inputs and send them on the serial link*/
void sendDatas()
{
	/*String data = readData();
	Serial.print(data);*/
}

/*Read the command on the serial link,
interpret them to call the appropriate function*/
void executeCommand()
{
	char i = '\0';
	String command = "";
	String valueString = "";
	String pinString = "";
	double value = 0;
	int y = 0;

	/*Read only one line*/
	i = Serial.read();
	if(i != -1)
	{
		command += String(i);
		while(i != '\n')
		{
			i = Serial.read();
			if(i != (char)0xFF)
				command += String(i);
		}		

		/*If the read command is "send",
		call the send function*/
		if(command[0] == 'r')
			sendDatas();
		
		/*If the command is other than "send"*/
		else if(command[0] == 'w')
		{
			/*browse it until the '\t' character*/
			for(y = 0; command[y] != '\t'; y++);
			/*The first part correspond to the pin information*/
			pinString += command;
			pinString = pinString.substring(1,y);
			/*decompose the second part*/
			valueString = command.substring(y+1,command.length()-1);
			char valueArray[valueString.length()+1];
			valueString.toCharArray(valueArray,valueString.length()+1);
			if(valueString.length() == 1)
			{
				/*convert the string to a int*/
				value = atoi(valueArray);
				/*Call the function to write datas on the pins*/
				writeDigitalData(pinString,value);
			}
			else
			{
				/*convert the string to a double*/
				value = atof(valueArray);
				/*Call the function to write datas on the pins*/
				writeAnalogData(pinString,value);
			}
		}
	}

}

/*WriteDigitalData function
Arguments :
pin : the pin on which it has to write
data : the data to be written : 1 or 0
*/
void writeDigitalData(String pinName, int data)
{
	int pinOut = pinCorrespondance(pinName);

	/*If the choosen output is a numeric output
	a simple digitalWrite is done*/
	digitalWrite(pinOut,data);
}

/*WriteAnalogData function
Arguments :
pin : the pin on which it has to write
data : the data to be written : 0 to 5 for the voltage analogic ones
*/
void writeAnalogData(String pinName, double data)
{
	int pinOut = pinCorrespondance(pinName);

	/*If the choosen output is a numeric output
	a simple digitalWrite is done*/
	analogWrite(pinOut,(int)(data/(VOLT_TO_INT_DIVISER)));
}

/*Matches the pinName and the Arduino pin
Argument : pinName : a string that represents the pin name
returns : the pin indice that correspond to the pin name*/
int pinCorrespondance(String pinName)
{
	char pinArray[pinName.length()+1];
	pinName.toCharArray(pinArray,pinName.length()+1);
	return(atoi(pinArray));

}

/*Initialise the pins*/
void initialise()
{
	pinMode(11,OUTPUT);
}