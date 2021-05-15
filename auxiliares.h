/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Data: 15/04/2021
 * Descricao: Laboratório 3 - arquivo .h referente as funcoes auxiliares
 *
 */

#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <vector>

#include "estadual.h"
#include "nacional.h"
#include "dados.h"

using namespace std;

//"A média móvel deverá ser calculada ao menos para os últimos três dias,"
vector <double> calcularMediaMovel(vector<int>);
// Calcula a variação entre a média móvel do dia atual e a de 7 dias atrás
double calcularVariacaoMediaMovel(vector<double>, double);

// funções para cálculo de forma acumulada
int calcularTotalObitosEstado(vector <int>);
int calcularTotalObitosPais(vector <vector<int> >);

#endif //auxiliares.h
