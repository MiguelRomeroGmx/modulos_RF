#include <RCSwitch.h> // Librería modulos RF

RCSwitch mySwitch = RCSwitch();
long int contador = 0;

void  setup(){
	pinMode(13, OUTPUT);
	digitalWrite(13, 1);
	Serial.begin(9600);
	mySwitch.enableReceive(0); // pin 2 arduino como RX
}

void loop(){

	if(contador == 30){
	    digitalWrite(13, 0);
	}
	if(mySwitch.available()){
	    long int value = mySwitch.getReceivedValue();
	    if (value == 0){
	    	Serial.print("Codigo error");
	    }
	    else {
	    	Serial.print("Codigo Recibido: ");
	    	Serial.println(value);

	    	if(value == 11878017){
	    	    contador = 0;
	    	    Serial.print("Contador: ");
	    		Serial.println(contador);
	    	}
	    	delay(500);
	    }
	    mySwitch.resetAvailable();
	}
	contador++;
	delay(500);
	Serial.print("Contador: ");
	Serial.println(contador);
}