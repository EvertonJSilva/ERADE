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
#ifndef ERADECONFIG_H
#define ERADECONFIG_H

#include "erade.h"

//sensores habilitados
#define E_FOGO  200
#define E_DISTANCIA 201

//Atuadores habilitados
#define A_MOTOR_L298 1001
#define A_SIRENE 1002

//Comunicação
#define COMUNICACAO_SERIAL 1

///////////////////// CRENCAS /////////////////////////////////////////

//crencas variaveis
#define CA_PERTO (ler(E_DISTANCIA) < 15)
#define CA_FOGO (ler(E_FOGO) != 0)

//crencas do agente
#define TEMFOGO 51

//crenca de subplanos
#define APROXIMAR 52

//endereço da ultima crença ocorrida
#define ULTIMACRENCA 150

//utilizando debug
//#define _DEBUG 1

#endif
