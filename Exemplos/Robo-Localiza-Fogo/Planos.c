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

#include <erade.h>

void planos(CRENCA crenca){

	#ifdef _DEBUG
		avrSerialxPrintf_P(&xSerialPort, PSTR("\n\nCRENCA---->: %d\r\n"), crenca );
		delay(1000);
	#endif

	switch (crenca) {
				case 0:
					// não tem nada, procura
					if(!consultaCrenca(TEMFOGO) && !CA_PERTO ){
						Direita(300);
						Frente(2000);
					}else

					//cuidado para nao bater em nada!!
					if(!consultaCrenca(TEMFOGO) && CA_PERTO ){
						Atras(7000);
						Direita(2000);
					}
					break;

				case E_FOGO:
					//achou fogo e esta loge, acredita que tem fogo na direcao
					if ((!CA_PERTO) && (CA_FOGO ))
					{
						incluirCrenca(TEMFOGO);
						A_notificar();
					}else

					//perdeu o fogo de vista, deve reinciar a busca
					if(!CA_FOGO )//&& consultaCrenca(TEMFOGO))
					{
						Esquerda(1000);
						retirarCrenca(TEMFOGO);
					}
					break;

				case TEMFOGO:

					//tem fogo na direcao, avanca até achar
					if(CA_FOGO && !CA_PERTO){
						SubPlanos(APROXIMAR);
					}else

					//ACHOU O FOGO
					if(CA_FOGO && CA_PERTO){
						TocarSirene(1000);
					}else

					//NÃO ACHOU MAIS O FOGO
					if(!CA_FOGO){
						retirarCrenca(TEMFOGO);
						gravar(ULTIMACRENCA, 0);
					}

				default:
					break;
			}
}
