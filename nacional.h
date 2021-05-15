/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Data: 15/04/2021
 * Descricao: Laboratório 3 - arquivo .h referente a classe Nacional
 *
 */

#ifndef NACIONAL_H
#define NACIONAL_H

#include <vector>
#include <string>
#include "estadual.h"

using namespace std;

class Nacional{
	public:
		Nacional(string, vector <Estadual>, double); // construtor da classe Nacional: recebe nome, vetor de objetos da classe Estadual e media movel de 7 dias atras

		void setNomePais(string);
		const string getNomePais();

		void setEstadosDoPais(vector <Estadual>);
		const vector <Estadual> getEstadosDoPais();

		void setObitosNacional();
		const vector <int> getObitosNacional();

		void setMediaMovelPassadaNacional(double);
		const double getMediaMovelPassadaNacional();

		void setMediaMovelNacional();
		const vector <double> getMediaMovelNacional();

		void setVariacaoMediaMovelNacional();
		const double getVariacaoMediaMovelNacional();

	private:
		vector <Estadual> estadosDoPais; //vector para armazenamento dos objetos da classe Estadual
		string nomePais;
		int tamanhoDataSet = 9; //numero de dias datados no programa
		vector <int> obitosNacional; //vector para armazenamento dos dados da série histórica nacional
		double mediaMovelPassadaNacional; //média móvel de 7 dias atrás
		vector <double> mediaMovelNacional;
		double variacaoMediaMovelNacional;
};
#endif //nacional.h
