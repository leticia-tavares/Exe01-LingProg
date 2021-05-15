/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Data: 15/04/2021
 * Descricao: Laboratório 3 - arquivo .cpp referente aos dados do programa
 * Data oficial de dados: 16/04/2021
 *
 */

#include "dados.h"

using namespace std;


// OBS: todos os dados foram retirados do site https://news.google.com/covid19/map?hl=pt-BR&mid=%2Fm%2F015fr&gl=BR&ceid=BR%3Apt-419


// vetor para armazenar os nomes de cada estado em ordem alfabetica
const vector <string> Dados::vetorNomesEstados = {"Acre", "Alagoas", "Amapa", "Amazonas", "Bahia", "Ceara", "Distrito Federal", "Espirito Santo", "Goias", "Maranhao",
 "Mato Grosso", "Mato Grosso do Sul", "Minas Gerais", "Para", "Paraiba", "Parana", "Pernambuco", "Piaui", "Rio de Janeiro", "Rio Grande do Norte", "Rio Grande do Sul",
 "Rondonia", "Roraima", "Santa Catarina", "Sao Paulo", "Sergipe", "Tocantins"};

//vetor das medias de 7 dias atras para cada estado brasileiro: 09/abril
const vector <double> Dados::vetorMediasPassadas = {7, 23, 9, 26, 107, 144, 67, 68, 120, 45, 89, 56, 291, 63, 43, 231, 56, 35, 260, 35, 221, 37, 5, 107, 743, 24, 18};
const double Dados::mediaMovelPassadaNacional = 2930;

//vetor de vetor: vetor de obitos por estado em ordem alfabetica
// vetor[0] => dados do acre
const vector <vector<int> > Dados::dadosObitos = { {12, 9, 7, 14, 10, 4, 5, 9, 7},
												  {23, 24, 24, 24, 24 ,22, 24, 24, 22},
												  {10, 14, 13, 17, 12, 4, 5, 10, 15},
												  {15, 18, 15, 23, 14, 12, 19, 24, 25},
												  {134, 141,146, 102, 95, 71, 98, 115, 125},
												  {425, 0, 0, 117, 92, 148, 149, 219, 175},
												  {76, 77, 66, 66, 86, 45, 33, 67, 77},
												  {75, 100, 96, 99, 47, 31, 54, 65, 77},
												  {106, 185, 127, 254, 26, 40, 99, 126, 175},
												  {46, 46, 44, 46, 44, 45, 47, 49, 47},
												  {56, 73, 93, 90, 102, 43, 47, 81, 73},
												  {44, 50, 65, 33, 37, 49, 52, 52, 87},
												  {433, 469, 484, 62, 86, 386, 368, 455, 492},
												  {80, 112, 115, 77, 51, 57, 81, 87, 95},
												  {41, 31, 42, 40, 58, 19, 39, 33, 35},
												  {196, 271, 184, 372, 83, 83, 190, 311, 374},
												  {51, 63, 83, 68, 34, 59, 58, 63, 82},
												  {34, 26, 47, 57, 36, 31, 37, 46, 38},
												  {287, 338, 300, 347, 21, 125, 260, 381, 375},
												  {26, 36, 36, 39, 24, 16, 33, 29, 20},
												  {179, 233, 177, 341, 166, 17, 85, 241, 277},
												  {33, 38, 52, 45, 21, 23, 30, 31, 45},
												  {13, 5, 9, 15, 0, 0, 6, 3, 17},
												  {71, 96, 82, 132, 83, 50, 92, 115, 146},
												  {791, 1060, 1095, 1282, 181, 510, 657, 1008, 1299},
												  {27, 27, 27, 26, 26, 26, 25, 26, 25},
												  {21, 18, 20, 20, 21, 21, 23, 23, 24}};
