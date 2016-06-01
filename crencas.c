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
#include "crencas.h"

void atualizarCrenca(CRENCA crenca, uint8_t valor)
{
	uint8_t crencaAtual;
	crencaAtual = crenca;

	if (ler(crenca) != valor)
	{
		gravar(crenca, valor);
		gravar(ULTIMACRENCA, crencaAtual);
	}
}

void incluirCrenca(CRENCA crenca){
	atualizarCrenca(crenca, 1);
}

boolean consultaCrenca(CRENCA crenca){
	if (ler(crenca)> 0) {
		return 1;
	}
	return 0;
}

void retirarCrenca(CRENCA crenca){
	atualizarCrenca(crenca, 0);
}
