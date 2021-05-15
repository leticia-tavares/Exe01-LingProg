/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Data: 15/04/2021
 * Descricao: Laboratório 3 - arquivo .cpp referente ao menu de exibicao
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "menu.h"
#include "auxiliares.h"

#define DIAS_OBSERVACAO             9
#define LIMIAR_ALTA                15
#define LIMIAR_BAIXA              -15

using namespace std;

void exibeOp1(Nacional pais){
  vector <double> mediaMovelPais,mediaMovelEstados;
  vector <Estadual> estados = pais.getEstadosDoPais();

  cout << "\n\n------------------------------ P A I S ------------------------------\n" << endl;
  mediaMovelPais = pais.getMediaMovelNacional();
  cout << pais.getNomePais() << ": " << mediaMovelPais.at(0) << " - " << mediaMovelPais.at(1) << " - " << mediaMovelPais.at(2) << endl;

  cout << "\n\n------------------------------ E S T A D O S ------------------------------\n" << endl;
  for (long unsigned int j = 0; j < estados.size(); j++) {
        mediaMovelEstados = estados.at(j).getMediaMovel();
        cout << estados.at(j).getNome() << ": "<< mediaMovelEstados.at(0) << " - "<< mediaMovelEstados.at(1) << " - "<< mediaMovelEstados.at(2) << endl;

    }
}

void exibeOp2(Nacional pais){
  vector <Estadual> alta, queda, estavel;
  vector <Estadual> estados = pais.getEstadosDoPais();
  double variacao;

  for(long unsigned int i = 0; i < estados.size(); i++){
    variacao = estados[i].getVariacaoMediaMovel();

    if (variacao < LIMIAR_BAIXA){
      queda.push_back(estados[i]);
    }
    else if (variacao > LIMIAR_ALTA){
      alta.push_back(estados[i]);
    }
    else
      estavel.push_back(estados[i]);

  }
  cout << "\n-------------------- E S T A D O S  E M  E S T A B I L I D A D E --------------------\n" << endl;
  for (long unsigned int j = 0; j < estavel.size(); j++){
    cout << estavel.at(j).getNome() << endl;
  }
  cout << "\n-------------------- E S T A D O S  E M  B A I X A --------------------\n" << endl;
  for (long unsigned int k = 0; k < queda.size(); k++){
    cout << queda.at(k).getNome() << endl;
  }
  cout << "\n-------------------- E S T A D O S  E M  A L T A  --------------------\n" << endl;
  for (long unsigned int w = 0; w < alta.size(); w++){
    cout << alta.at(w).getNome() << endl;
  }
  cout << "\n" << endl;
}

void exibeOp3(Nacional pais){
  double variacao = pais.getVariacaoMediaMovelNacional();
  if (variacao < LIMIAR_BAIXA){
      cout << "Dados observados mostram queda nos números de óbitos!\n";
      cout << "Variação atual da média móvel é de "<< variacao << "%\n" << endl;
  }
  else if (variacao > LIMIAR_ALTA){
      cout << "Dados observados mostram alta nos números de óbitos!\n" << endl;
      cout << "Variação atual da média móvel é de "<< variacao << "%\n" << endl;
  }
  else{
    cout << "Dados observados mostram estabilidade em relação ao número de óbitos!\n";
    cout << "Variação atual da média móvel é de "<< variacao << "%\n" << endl;
  }
}

void exibeOp4(Nacional pais){
  string estadoEmAlta, estadoEmQueda, nome;
  vector <Estadual> estados = pais.getEstadosDoPais();
  double variacao, variacaoAlta, variacaoQueda;

  variacaoAlta = 0;
  variacaoQueda = 0;

  for (long unsigned int i = 0; i < estados.size(); i++) {
    nome = estados.at(i).getNome();
    variacao = estados.at(i).getVariacaoMediaMovel();

    if (variacao > variacaoAlta) {
        estadoEmAlta = nome;
        variacaoAlta = variacao;
      }

      if (variacao < variacaoQueda) {
        estadoEmQueda = nome;
        variacaoQueda = variacao;
      }
  }

  cout << "Estados do país que estão com os maiores índices: \n";
  cout << "\nEstado com maior alta: "<< estadoEmAlta << " | Variação atual: " << variacaoAlta << "%"<< endl;
  cout << "\nEstado com maior baixa: "<< estadoEmQueda << " | Variação atual: " << variacaoQueda << "%"<< endl;
}

void exibeOp5(Nacional pais){
  int totalObitosNacional = 0;
  int totalObitosPorEstado = 0;
  vector <int> obitosPorDiaNacional;
  vector <Estadual> estados = pais.getEstadosDoPais();

  cout << "\n------------------------------ P A Í S ------------------------------\n" << endl;
  totalObitosNacional = calcularTotalObitosPais(Dados::dadosObitos);
  cout << "\nÓbitos acumulados no " << pais.getNomePais() << ": " << totalObitosNacional << endl;

  obitosPorDiaNacional = pais.getObitosNacional();
  cout << "Óbitos acumulados por dia de observação no " << pais.getNomePais() << ": " << obitosPorDiaNacional.at(0) <<", ";
  cout << obitosPorDiaNacional.at(1) <<", " << obitosPorDiaNacional.at(2) <<", " << obitosPorDiaNacional.at(3) <<", " << obitosPorDiaNacional.at(4) <<", ";
  cout << obitosPorDiaNacional.at(5) <<", " << obitosPorDiaNacional.at(6) <<", " << obitosPorDiaNacional.at(7) <<", " << obitosPorDiaNacional.at(8) << "." << endl;

  cout << "\n------------------------------ E S T A D O S ------------------------------\n" << endl;
  for (long unsigned int j = 0; j < estados.size(); j++) {
      totalObitosPorEstado = 0;
      totalObitosPorEstado = calcularTotalObitosEstado(Dados::dadosObitos.at(j));
      cout << "Óbitos acumulados em " << estados.at(j).getNome() << ": " << totalObitosPorEstado << endl;
  }
  cout << "\n"<< endl;
}

void menu(Nacional pais) {
    int opcao = 0;

    cout << "\n---------------Programa de manipulacao de dados referentes ao avanço da COVID-19 no Brasil---------------\n"<< endl;
    cout << "Opções de entrada disponíveis: \n(1) Exibição da evolução do número de óbitos no Brasil, e nos estados individualmente, usando a estratégia de média móvel." << endl;
    cout << "(2) Exibição de forma agrupada dos estados em alta, estabilidade e baixa segundo a média móvel do dia atual." << endl;
    cout << "(3) Exibição do status do País se em alta, baixa ou estabilidade." << endl;
    cout << "(4) Exibição do estado com maior alta e maior baixa segundo a média móvel do dia atual calculada no item 1" << endl;
    cout << "(5) Exibir os dados acumulados de número de óbitos (soma desde o início do período de observação) no Brasil e nos estados individualmente." <<endl;
    cout << "\nEntre com a opcao desejada: " << endl;
    cin >> opcao;

    switch (opcao) {
        case 1: {
          cout << "\n------------------------------ O P Ç Ã O  (1)------------------------------" << endl;
          cout << "\n(1) Exibição da evolução do número de óbitos no Brasil, e nos estados individualmente, usando a estratégia de média móvel." << endl;
          cout << "\nValores calculados a partir de um conjunto de dados referente ao intervalo de dias 08/04 - 16/04 .\n" << endl;
          cout << "As médias móveis foram calculadas (e exibidas respectivamente) para o dia atual, anterior e anterior ao anterior.";
          exibeOp1(pais);
          cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
          break;
        }
        case 2: {
          cout << "\n ------------------------------O P Ç Ã O  (2)------------------------------" << endl;
          cout << "\n(2) Exibição de forma agrupada dos estados em alta, estabilidade e baixa segundo a média móvel do dia atual." << endl;
          cout << "\nCálculo em relação a média de 7 dias atrás." << endl;
          exibeOp2(pais);
          cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
          break;
        }
        case 3: {
          cout << "\n ------------------------------O P Ç Ã O  (3)------------------------------" << endl;
          cout << "\n(3) Exibição do status do Pais se em alta, baixa ou estabilidade." << endl;
          cout << "\nCálculo em relação a média de 7 dias atrás." << endl;
          exibeOp3(pais);
          cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
          break;
        }
        case 4: {
          cout << "\n ------------------------------O P Ç Ã O  (4)------------------------------" << endl;
          cout << "\n(4) Exibição do estado com maior alta e maior baixa segundo a média móvel do dia atual calculada no item 1" << endl;
          exibeOp4(pais);
          cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
          break;
        }
        case 5: {
          cout << "\n ------------------------------O P Ç Ã O  (5)------------------------------" << endl;
          cout << "\n(5) Exibir os dados acumulados de número de óbitos (soma desde o início do período de observação) no Brasil e nos estados individualmente." <<endl;
          exibeOp5(pais);
          cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
          break;
        }
        default: {
          cout << "\nEntrada invalida!" << endl;
          cout << "\n ------------------------------N O V A  T E N T A T I V A------------------------------" << endl;
          cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
          menu(pais);
          break;
        }
    }
}
