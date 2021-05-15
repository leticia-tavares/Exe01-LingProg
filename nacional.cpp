/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Data: 15/04/2021
 * Descricao: Laboratório 3 - arquivo .cpp referente a classe Nacional
 *
 */

#include <string>
#include <vector>
#include "nacional.h"
#include "auxiliares.h"

using namespace std;

Nacional::Nacional(string nome, vector <Estadual> estados, double mediaPassada) {
	setNomePais(nome);
	setEstadosDoPais(estados);
	setObitosNacional();
	setMediaMovelPassadaNacional(mediaPassada);
	setMediaMovelNacional();
	setVariacaoMediaMovelNacional();
}

void Nacional::setNomePais(string nome){
	nomePais = nome;
}
const string Nacional::getNomePais(){
	return nomePais;
}

void Nacional::setEstadosDoPais(vector <Estadual> estados){
	estadosDoPais = estados;
}
const vector <Estadual> Nacional::getEstadosDoPais(){
	return estadosDoPais;
}

void Nacional::setObitosNacional(){	//soma das mortes por cada dia em todos os estados
	vector <int> obitosDia(tamanhoDataSet,0);
	vector <int> obtsEstadual;
	for (long unsigned int i = 0; i < estadosDoPais.size(); i++) {
			 obtsEstadual = estadosDoPais.at(i).getObitos();
			 for (int j = 0; j < tamanhoDataSet; j++) {
					 obitosDia.at(j) += obtsEstadual.at(j);
			 }
	 }
	 obitosNacional = obitosDia;
}

const vector <int> Nacional::getObitosNacional(){ //retorna um vector com as mortes acumuladas no país por dia de observação
	return obitosNacional;
}

void Nacional::setMediaMovelPassadaNacional(double mediaPassada){
	mediaMovelPassadaNacional = mediaPassada;
}

const double Nacional::getMediaMovelPassadaNacional(){
	return mediaMovelPassadaNacional;
}

void Nacional::setMediaMovelNacional(){
	mediaMovelNacional = calcularMediaMovel(obitosNacional);
}

const vector <double> Nacional::getMediaMovelNacional(){
	return mediaMovelNacional;
}

void Nacional::setVariacaoMediaMovelNacional(){
	variacaoMediaMovelNacional = calcularVariacaoMediaMovel(mediaMovelNacional, mediaMovelPassadaNacional);
}

const double Nacional::getVariacaoMediaMovelNacional(){
	return variacaoMediaMovelNacional;
}
