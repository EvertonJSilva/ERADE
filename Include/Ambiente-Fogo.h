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
#ifndef AMBIENTE_FOGO_H
#define AMBIENTE_FOGO_H

#include "Ambiente.h"

#define PinFire 8

void AmbienteFogoSetup(void) {
	  pinMode(PinFire,INPUT);

}

void AmbienteFogoRun(void) {
		#ifdef _DEBUG
			avrSerialxPrint_P(&xSerialPort, PSTR("\r\n\n\nTask Fogo\r\n")); // Ok, so we're alive...
		#endif

		int sensorReading = digitalRead(PinFire); // read the sensor on digital D2

		  if (sensorReading==1) {       // No Flames Detected
			  retirarCrenca(E_FOGO);
		  }

		  else {                        // Flames detected

			#ifdef _DEBUG
			  avrSerialxPrint_P(&xSerialPort, PSTR("\r\n\n\n*fogo*\r\n")); // Ok, so we're alive...
			#endif

			//gravar
			incluirCrenca(E_FOGO);
		  }
};

#endif

