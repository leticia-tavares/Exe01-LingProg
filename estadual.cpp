/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Data: 15/04/2021
 * Descricao: Laboratório 3 - arquivo .cpp referente a classe Estadual
 *
 */

#include "estadual.h"
#include "auxiliares.h"

using namespace std;

Estadual::Estadual (string nome, vector <int> obitos, double mediaPassada){
	setNome(nome);
	setObitos(obitos);
	setMediaMovelPassada(mediaPassada);
	setMediaMovel();
	setVariacaoMediaMovel();
}

void Estadual::setNome(string nome){
	nomeEstado = nome;

}
const string Estadual::getNome(){
	return nomeEstado;
}

void Estadual::setObitos(vector <int> obitos){
	obitosPorEstado = obitos;
}

const vector <int> Estadual::getObitos(){
	return obitosPorEstado;
}
void Estadual::setMediaMovelPassada(double mediaPassada){
	mediaMovelPassadaEstado = mediaPassada;
}
const double Estadual::getMediaMovelPassada(){
	return mediaMovelPassadaEstado;
}

void Estadual::setMediaMovel(){
	mediaMovelPorEstado = calcularMediaMovel(obitosPorEstado);
}

const vector <double> Estadual::getMediaMovel(){
	return mediaMovelPorEstado;
}

void Estadual::setVariacaoMediaMovel(){
	variacaoMediaMovelPorEstado = calcularVariacaoMediaMovel(mediaMovelPorEstado, mediaMovelPassadaEstado);
}
const double Estadual::getVariacaoMediaMovel(){
	return variacaoMediaMovelPorEstado;
}
