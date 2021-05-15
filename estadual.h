/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Data: 15/04/2021
 * Descricao: Laboratório 3 - arquivo .h referente a classe Estadual
 *
 */

#ifndef ESTADUAL_H
#define ESTADUAL_H

#include <string>
#include <vector>

using namespace std;

class Estadual {
	public:
		Estadual(string, vector <int>, double); // construtor da classe Estadual: recebe nome, dados dos obitos e media movel de 7 dias atrás

		void setNome(string);
		const string getNome();

		void setObitos(vector <int>);
		const vector <int> getObitos();

		void setMediaMovelPassada(double);
		const double getMediaMovelPassada();

		void setMediaMovel();
		const vector <double> getMediaMovel();

		void setVariacaoMediaMovel();
		const double getVariacaoMediaMovel();

	private:
		string nomeEstado;
		vector <int> obitosPorEstado; // uso de vector <> para armazenamento dos dados
		double mediaMovelPassadaEstado; //media de 7 dias atrás
		vector <double> mediaMovelPorEstado;
		double variacaoMediaMovelPorEstado;
	};
#endif //estadual.h
