/**

 Programa: M�TODO DA RIGIDEZ DIRETA - MRD

 Disciplina: An�lise de Estruturas II

 Autor: Iggo Guimar�es/David Kennedy/Amanda Lyz

 Professor: Maur�cio Mello

 Arquivo: main.cpp

 Descri��o:
    An�lise de treli�as planas sujeitas a carregamentos n�dais pelo M�todo da Rigidez Direta.
 Crit�rios:
    -As equipes poder�o utilizar qualquer linguagem/ambiente de programa��o para desenvolver o algoritmo;
    -A ferramenta n�o precisa conter interface gr�fica com o usu�rio;
    -A ferramenta dever� ser capaz de calcular deslocamentos, rea��es de apoio e esfor�os internos nas
    barras de uma estrutura com configura��es e par�metros de entrada quaisquer;
    -N�o ser� necess�rio considerar a��es de recalques de apoio, apoio el�stico nem varia��o de
    temperatura. Apenas devem ser consideradas a��es de cargas concentradas em n�s da estrutura.

 Data: 17/12/2019

*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>
#include "matrizes.h"


using namespace std;

int main()
{
    setlocale(LC_ALL,"");

    
    string nome_arq_1;
    cout << "DIGITE O NOME DO ARQUIVO 1: ";
    cin  >> nome_arq_1;

    nome_arq_1 += ".txt";

    ifstream arq_1;
    //cout << nome_nos << endl;

    arq_1.open(nome_arq_1.c_str(), ios::in); // abre o arquivo para leitura

    while(! arq_1)
    {
        cout << "ARQUIVO " << nome_arq_1 << " N�O PODE SER ABERTO!" << endl;
        cout << "DIGITE NOVAMENTE O NOME DO ARQUIVO DE NOS (m�nusculo com a extens�o .txt): ";
        cin >> nome_arq_1;
        nome_arq_1 += ".txt";
        arq_1.open(nome_arq_1.c_str(), ios::in); // abre o arquivo para leitura
    }

    int num_linhas_1, num_colunas_1;
    cout << "linhas: ";
    cin  >> num_linhas_1;
    cout << "colunas: ";
    cin >> num_colunas_1;

    float ** mat_1;
    mat_1 = (float **) malloc(num_linhas_1 * sizeof(float)); //cria��o e aloca��o do vetor de n�s que armazenar� os dados fornecidos pelo usu�rio

    for (int i = 0; i < num_linhas_1; i++) {
        mat_1[i] = (float*) malloc(num_colunas_1 * sizeof(float));
    }

    for (int i = 0; i < num_linhas_1; i++)
        for (int j = 0; j < num_colunas_1; j++)
            arq_1 >> mat_1[i][j];


    arq_1.close();

    imprimir_mat(mat_1, num_linhas_1, num_colunas_1);

    string nome_arq_2;
    cout << "DIGITE O NOME DO ARQUIVO 2: ";
    cin >> nome_arq_2;

    nome_arq_2 += ".txt";

    ifstream arq_2;
    //cout << nome_nos << endl;

    arq_2.open(nome_arq_2.c_str(), ios::in); // abre o arquivo para leitura

    while (!arq_2)
    {
        cout << "ARQUIVO " << nome_arq_1 << " N�O PODE SER ABERTO!" << endl;
        cout << "DIGITE NOVAMENTE O NOME DO ARQUIVO DE NOS (m�nusculo com a extens�o .txt): ";
        cin >> nome_arq_2;
        nome_arq_2 += ".txt";
        arq_1.open(nome_arq_2.c_str(), ios::in); // abre o arquivo para leitura
    }

    int num_linhas_2, num_colunas_2;
    cout << "linhas: ";
    cin >> num_linhas_2;
    cout << "colunas: ";
    cin >> num_colunas_2;

    float** mat_2;
    mat_2 = (float**)malloc(num_linhas_2 * sizeof(float)); //cria��o e aloca��o do vetor de n�s que armazenar� os dados fornecidos pelo usu�rio

    for (int i = 0; i < num_linhas_2; i++) {
        mat_2[i] = (float*)malloc(num_colunas_2 * sizeof(float));
    }

    for (int i = 0; i < num_linhas_2; i++)
        for (int j = 0; j < num_colunas_2; j++)
            arq_2 >> mat_2[i][j];

    arq_2.close();

    imprimir_mat(mat_2, num_linhas_2, num_colunas_2);

    float** matriz;

    matriz = (float**)malloc(num_linhas_1 * sizeof(float)); //cria��o e aloca��o do vetor de n�s que armazenar� os dados fornecidos pelo usu�rio

    for (int i = 0; i < num_linhas_1; i++) {
        matriz[i] = (float*)malloc(num_colunas_2 * sizeof(float));
    }

    //matriz = multi_mat(mat_1, mat_2, num_linhas_1, num_colunas_1, num_linhas_2, num_colunas_2);

    cout << "multiplica��o das  metrizes" << endl;
    imprimir_mat(multi_mat(mat_1, mat_2, num_linhas_1, num_colunas_1, num_linhas_2, num_colunas_2), num_linhas_1, num_colunas_2);

    cout << "matriz 1" << endl;
    imprimir_mat(mat_1, num_linhas_1, num_colunas_1);

    cout << "inversa com a formula original" << endl;
    imprimir_mat(cofactor(mat_1, num_linhas_1), num_linhas_1, num_colunas_1);

    cout << "inversa com a formula alterada" << endl;
    imprimir_mat(inversa(mat_1, num_linhas_1), num_linhas_1, num_colunas_1);

    

    mat_free(mat_1, num_linhas_1, num_colunas_1);
    mat_free(mat_2, num_linhas_2, num_colunas_2);
    mat_free(matriz, num_linhas_1, num_colunas_2);
    
    return 0;
}
