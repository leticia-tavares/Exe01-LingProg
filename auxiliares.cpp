/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Data: 15/04/2021
 * Descricao: Laboratório 3 - arquivo .cpp referente as funcoes auxiliares de calculo
 *
 */

#include <vector>
#include "auxiliares.h"

using namespace std;

vector <double> calcularMediaMovel(vector<int> numeroObitos){
	double mediaMovel = 0;
	int somaObitos = 0;
	vector <double> vetorMediaMovel; //"A média móvel deverá ser calculada ao menos para os últimos três dias,""

	for (int i = 0; i < 3; i++){ //dia atual, anterior e anterior ao anterior
		mediaMovel = 0;
		somaObitos = 0;

		for (int j = (0 + i); j <= (6 + i); j++){ // arrastar o vetor de obitos para obter a media dos outros dias
			somaObitos += numeroObitos.at(j);
		}
		mediaMovel = somaObitos / 7.0;
		vetorMediaMovel.push_back(mediaMovel);

	}
	return vetorMediaMovel;
}

double calcularVariacaoMediaMovel(vector<double> vetorMediaMovel, double mediaAnterior){ //calcula a variacao entre a media movel atual e a de 7 dias atras
	double variacao = 0;

  variacao = ((vetorMediaMovel[0] - mediaAnterior)/mediaAnterior)*100;
  return variacao;
}

int calcularTotalObitosEstado(vector <int> obitos){
	int totalObitosEstado = 0;

	for (long unsigned int i = 0; i < obitos.size(); i++){
		totalObitosEstado += obitos.at(i);
	}
	return totalObitosEstado;
}

int calcularTotalObitosPais(vector<vector<int> > obitos){ // soma acumulada dos obitos durante todo o periodo de observacao
	int totalObitosPais = 0;

	for (long unsigned int i =0; i < obitos.size(); i++){
		totalObitosPais += calcularTotalObitosEstado(obitos.at(i));
	}
	return totalObitosPais;
}
