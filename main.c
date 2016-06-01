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
#include <FreeRTOS.h>
#include <Arduino.h>
#include <lib_serial.h>
#include "erade.h"
#include "crencas.h"
#include "ERADEConfig.h"
#include "Comunicacao.h"
#include "Comunicacao-Serial.h"

#include <Acao-Sirene.h>
#include <Acao-MotorL298N.h>
#include "Ambiente-Distancia.h"
#include "Ambiente-Fogo.h"

static void interpretador(void *pvParameters);
static void ambiente(void *pvParameters);
static void comunicacao(void *pvParameters);

/* Main program loop */
int main(void) __attribute__ ((OS_main));

int main(void)
{
	setup();

    xTaskCreate(
		interpretador
		,  (const portCHAR *)PSTR("interpretador")
		,  200
		,  NULL
		,  3
		,  NULL );

    xTaskCreate(
		ambiente
		,  (const portCHAR *)"Ambiente"
		,  300
		,  NULL
		,  3
		,  NULL );

    xTaskCreate(
		comunicacao
		,  (const portCHAR *)"Comunicacao"
		,  300
		,  NULL
		,  3
		,  NULL );

	vTaskStartScheduler();

	#ifdef _DEBUG
		enviar( PSTR("\r\n\n\nFalta de espaço!!\r\n"));
	#endif
}

void setup()
{
	//TocarSirene(100);
	carregarAcoes();

	 for (int i = 0 ; i < 1024 ; i++) {
	    gravar(i, 0);
	  }

	 xSerialPort = xSerialPortInitMinimal( USART0, 9600, portSERIAL_BUFFER_TX, portSERIAL_BUFFER_RX);

	#ifdef _DEBUG
	 	 avrSerialxPrint_P(&xSerialPort, PSTR("\r\n\n\nIniciando sistema\r\n")); // Ok, so we're alive...
	#endif
}

static void ambiente(void *pvParameters){

	carregarAmbiente();

	for(;;){
		#ifdef E_DISTANCIA
			AmbienteDistanciaRun();
		#endif
		#ifdef E_FOGO
			AmbienteFogoRun();
		#endif

		#ifdef _DEBUG
			delay(1000);
		#endif
	}
}

static void comunicacao(void *pvParameters)
{
	for (;;) {

//		xSerialFlush(&xSerialPort);
		//int8_t recebido = avrSerialxRead(&xSerialPort);
		int8_t recebido = &xSerialPort.serialWorkBufferInUse;

	//	xSerialFlush(&xSerialPort);

	//	avrSerialxPrintf_P(&xSerialPort, PSTR("\n\nRecebido ---> %u\r\n"), recebido  ); // needs heap_1,  heap_2 or heap_4 for this function to succeed.
		#ifdef _DEBUG
			enviar(PSTR("\n\n\n\n task comunicacao \n\n"));
			delay(1000);
		#endif
	}
}


static void interpretador(void *pvParameters)
{
	for(;;){

		CRENCA crenca;
		crenca = (int) ler(ULTIMACRENCA);

		planos(crenca);

		#ifdef _DEBUG
			avrSerialxPrintf_P(&xSerialPort, PSTR("Memoria Heap livre: %u\r\n"), xPortGetFreeHeapSize() ); // needs heap_1,  heap_2 or heap_4 for this function to succeed.
			delay(200);
		#endif
		//    nextTask();
	}
}


/*
void vApplicationStackOverflowHook( pvTaskCode xTask,  portCHAR *pcTaskName )
{
	//avrSerialxPrint_P(&xSerialPort, PSTR("\r\n\n\nEstouro de memória!!!!\r\n"));
	DDRB  |= _BV(DDB5);
	PORTB |= _BV(PORTB5);       // main (red PB5) LED on. Arduino LED on and die.
	while(1);
}*/


