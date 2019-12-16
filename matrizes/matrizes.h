#ifndef MATRIZES_H_INCLUDED
#define MATRIZES_H_INCLUDED

using namespace std;

//***************************************************************************
/**ASSINATURA DAS FUNÇÕES DA BIBLIOTECA*/
float determinante(float ** matriz, int tamanho);

float ** inversa(float **matrix,int tam);

float ** transposta(float **matriz,float **matriz_cofator,int tam);

float ** multi_mat(float** mat_1, float** mat_2, int lin_1, int col_1, int lin_2, int col_2);

void imprimir_mat(float ** matriz, int linhas, int colunas);

void mat_free(float** matriz, int lin, int col);

/**************************************************************************/
float determinant(float** matrix, float size);

float **cofactor(float** matrix, float size);

float **transpose(float** matrix, float** matrix_cofactor, float size);

#endif // MATRIZES_H_INCLUDED
