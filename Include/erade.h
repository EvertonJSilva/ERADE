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
#ifndef ERADE_H
#define ERADE_H

#include "EEPROM.h"
#include <stdarg.h>
#include <FreeRTOS.h>
#include <Arduino.h>
#include <lib_serial.h>
#include "ERADEConfig.h"
#include "crencas.h"

typedef int CRENCA;
typedef int ACAO;

#define ler( address) eepromRead(address)
#define gravar( address,value)  eepromWrite(address,value)

#define M(name) \
static inline void name##_Acoes() __attribute__((__section__(".lowtext"),__naked__,__always_inline__)); \
void name##_Crencas() __attribute__((__section__(".lowtext"))); \
void name##_Crencas(void)\
{\
	avrSerialxPrintf_P(&xSerialPort, PSTR("\n\n\n\entrou na funcao"), 1 ); \
		if (name##_Contexto() == 1)\
	{ \
		avrSerialxPrintf_P(&xSerialPort, PSTR("\n\n\n\vai agir"), 1 ); \
		name##_Acoes(); \
	} \
};\
int name##_Contexto(void); \
int name##_Contexto(){ \
	avrSerialxPrintf_P(&xSerialPort, PSTR("\n\n\n\verificando contexto"), 1 ); \
	if (ler(name) != 0){ \
		return 1; \
	} \
	return 0; \
} \
static inline void name##_Acoes()

static inline int _Condicao();

int _Condicao(CRENCA name, CRENCA condicoes[]) \
{ \
	avrSerialxPrintf_P(&xSerialPort, PSTR("TAMANHO? : -> %u  \r\n"), &condicoes[0]);\
	if (ler(name) != 0){ \
		avrSerialxPrintf_P(&xSerialPort, PSTR("JA TEM? : -> %u  \r\n"), name);\
		return 1; \
	} \
	else \
	{ \
		int i; \
		uint8_t resultado = 0; \
		for(i=1 ;i < &condicoes[0]; i++){ \
			avrSerialxPrintf_P(&xSerialPort, PSTR("Array : %u -> %u  \r\n"), condicoes[0],i ); \
			 if ( (condicoes[i]) ){ \
				resultado += 1 ; \
				} \
		} \
		if(resultado == condicoes[0]){ \
			gravar(name, 1); \
			return 1; \
		}else{ \
			return 0; \
		} \
	} \
}

static inline int _Interogacao();

int _Interogacao(CRENCA name)\
{\
	if (ler(name) != 0){ \
		return 1;
	} \
	else \
	{ \
		return 0; \
	} \
} \

static inline CRENCA * _Lista(CRENCA, ...);

CRENCA* _Lista(CRENCA num,...) \
{ \
   va_list valist; \
   CRENCA* crencas[num+1]; \
   int i; \
   va_start(valist, num); \
\
   crencas[0]= num; \
\
   for (i = 1; i < num+1; i++) { \
      crencas[i] = va_arg(valist, int); \
   } \
\
   va_end(valist); \
   return * crencas; \
}

/*
ACAO _A(ACAO num,...) {
   va_list valist;
   ACAO acoes[num+1];
   int i;
   va_start(valist, num);

   //TAMANHO do array
   acoes[0]= num;

   for (i = 0; i < num; i++) {
	   acoes[i+1] = va_arg(valist, int);
   }

   va_end(valist);

   return * acoes;
}
*/
/*
void A_AVISAR(void){
	avrSerialxPrintf_P(&xSerialPort, PSTR("\n\n\n\SUCESSO ***-> %u "), 1 );
}
*/

void planos(CRENCA);
void Subplanos(CRENCA);


#endif
