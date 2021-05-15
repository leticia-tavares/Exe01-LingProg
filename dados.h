/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Data: 15/04/2021
 * Descricao: Laboratório 3 - arquivo .h referente aos dados do programa
 * Data oficial de dados: 16/04/2021
 *
 */

#ifndef DADOS_H
#define DADOS_H

#include <string>
#include <vector>

using namespace std;

//classe criada puramente para armazenar dados
// OBS: todos os dados foram retirados do site https://news.google.com/covid19/map?hl=pt-BR&mid=%2Fm%2F015fr&gl=BR&ceid=BR%3Apt-419
class Dados {
    public:
        static const vector <string> vetorNomesEstados; // vetor para armazenar os nomes de cada estado brasileiro em ordem alfabetica
        static const vector <vector<int> > dadosObitos; // vetor de vetor: vetor de obitos por estados em ordem alfabetica, dadosObitos[0] => dados do acre
        static const vector <double> vetorMediasPassadas; // medias moveis de 7 dias atras de todos os estados agrupadas num vetor
        static const double mediaMovelPassadaNacional; // // media movel nacional de 7 dias atras
};
#endif //	dados.h
