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
#ifndef ACAO_MOTOR_L298N_H
#define ACAO_MOTOR_L298N_H

#include "Acao.h"
//#include  <Arduino.h>

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7


void AcaoMotorL298NSetup(void) {
	 pinMode(IN1, OUTPUT);
	 pinMode(IN2, OUTPUT);
	 pinMode(IN3, OUTPUT);
	 pinMode(IN4, OUTPUT);
};

void Frente(int tempo) {
	 Freiar();
	 for ( int i = 0;  i < tempo; i++) {
		 //Gira o Motor A no sentido horario
		 digitalWrite(IN1, HIGH);
		 digitalWrite(IN2, LOW);

		 //Gira o Motor B no sentido horario
		 digitalWrite(IN3, HIGH);
		 digitalWrite(IN4, LOW);
	 }
	 Freiar();
//	 delay(2000);
};

void Freiar(void) {
	 //Para o motor A
	 digitalWrite(IN1, HIGH);
	 digitalWrite(IN2, HIGH);
	 //Para o motor B
	 digitalWrite(IN3, HIGH);
	 digitalWrite(IN4, HIGH);
	// delay(500);
};

void Atras(int tempo) {

	Freiar();
	//suspendAll();
	for ( int i = 0;  i < tempo; i++) {
	//Gira o Motor A no sentido anti-horario
	 digitalWrite(IN1, LOW);
	 digitalWrite(IN2, HIGH);
	 //Gira o Motor B no sentido anti-horario
	 digitalWrite(IN3, LOW);
	 digitalWrite(IN4, HIGH);
	 //delay(1000);
	}
	Freiar();
	 //resumeAll();
};

void Direita(int tempo) {

	Freiar();
	//suspendAll();
	for ( int i = 0;  i < tempo; i++) {
	//Gira o Motor A no sentido anti-horario
	 digitalWrite(IN1, LOW);
	 digitalWrite(IN2, HIGH);
	 //Gira o Motor B no sentido anti-horario
	 digitalWrite(IN3, HIGH);
	 digitalWrite(IN4, LOW);
	 //delay(1000);
	}
	Freiar();
	 //resumeAll();
};

void Esquerda(int tempo) {

	Freiar();
	//suspendAll();
	for ( int i = 0;  i < tempo; i++) {
	//Gira o Motor A no sentido anti-horario
	 digitalWrite(IN1, HIGH);
	 digitalWrite(IN2, LOW);
	 //Gira o Motor B no sentido anti-horario
	 digitalWrite(IN3, LOW);
	 digitalWrite(IN4, HIGH);
	 //delay(1000);
	}
	Freiar();
	 //resumeAll();
};
#endif

