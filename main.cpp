/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Data: 15/04/2021
 * Descricao: Laboratório 3 - arquivo main.cpp referente ao programa princiapl
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include "dados.h"
#include "menu.h"
#include "auxiliares.h"

using namespace std;

int main(){
		vector<Estadual> vetorEstados;
	   // Criar os objetos de todos os estados brasileiros com nome, obitos e medias de 7 dias atras para serem utilizados na classe Nacional
		 for (int i = 0; i < 27; i++){
			 Estadual estado(Dados::vetorNomesEstados[i], Dados::dadosObitos[i], Dados::vetorMediasPassadas[i]);
			 vetorEstados.push_back(estado);
		 }
  //Criar objeto brasil 
  Nacional brasil("Brasil", vetorEstados, Dados::mediaMovelPassadaNacional);
  menu(brasil);

  return 0;
}
