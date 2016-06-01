/* Copyright (c) 2016, Everton J. da Silva
** Evertonjdasiva@yahoo.com.br
**
** This file is part of the framework ERADE
**
** Permission to use, copy, modify, and/or distribute this software for
** any purpose with or without fee is hereby granted, provided that the
** above copyright notice and this permission notice appear in all copies.
**
** THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
** WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
** BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
** OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
** WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
** ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
** SOFTWARE.
*/
#ifndef AMBIENTE_DISTANCIA_H
#define AMBIENTE_DISTANCIA_H

#include "Ambiente.h"

#define echoPin 13
#define trigPin 12

void AmbienteDistanciaSetup(void){
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

};

void AmbienteDistanciaRun(void){

	#ifdef _DEBUG
		avrSerialxPrint_P(&xSerialPort, PSTR("\r\n\n\nTask Distancia\r\n"));
	#endif

		 long duration;
		 uint8_t distance;
		  suspendAll();
		  digitalWrite(trigPin, LOW);
		  delayMicroseconds(2);
		  digitalWrite(trigPin, HIGH);
		  delayMicroseconds(10);
		  digitalWrite(trigPin, LOW);
		  duration = pulseIn(echoPin, HIGH, 10000);
		  resumeAll();
		  delay(100);

		  #ifdef _DEBUG
		  	  avrSerialxPrintf_P(&xSerialPort, PSTR("\n->DURACAO %u "), duration );
		  #endif

		  distance = (duration/2) / 27;

		  if (distance >= 200 || distance <= 0){
			#ifdef _DEBUG
			  	  avrSerialxPrint_P(&xSerialPort, PSTR("\r\n\n\nFora do range "));
			#endif
			//gravar valor
			gravar(E_DISTANCIA, 999 );

			}
		  else {
			#ifdef _DEBUG
			  	  avrSerialxPrintf_P(&xSerialPort, PSTR("Dustancia-> %u "), distance );
			  	  avrSerialxPrint_P(&xSerialPort, PSTR(" cm\r\n\n"));
			#endif
			//gravar valor
			gravar(E_DISTANCIA, distance );
		  }

		//  portTickType xLastWakeTime;
		  // xLastWakeTime = xTaskGetTickCount();
		 // vTaskDelayUntil( &xLastWakeTime, ( 1000 / portTICK_RATE_MS ) );
};

#endif
