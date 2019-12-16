#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "matrizes.h"

//***************************************************************************
/**CORPO DAS FUNÇÕES DA BIBLIOTECA*/
float determinante(float **matrix, int tam)
{
    //cout << "determinante" << endl;
    float s=1,det=0,**m_minor;

    m_minor = (float **) malloc(tam * sizeof(float *));

    for(int i = 0; i < tam; i++)
    {
        m_minor[i] = (float *) malloc(tam * sizeof(float));
    }

    int i,j,m,n,c;
    if (tam==1)
    {
        return (matrix[0][0]);
    }
    else
    {
        det=0;
        for (c=0; c<tam; c++)
        {
            m=0;
            n=0;
            for (i=0; i<tam; i++)
            {
                for (j=0; j<tam; j++)
                {
                    m_minor[i][j]=0;
                    if (i != 0 && j != c)
                    {
                        m_minor[m][n]=matrix[i][j];
                        if (n<(tam-2))
                            n++;
                        else
                        {
                            n=0;
                            m++;
                        }
                    }
                }
            }
            det=det + s * (matrix[0][c] * determinante(m_minor,tam-1));
            //cout << "DETERMINANTE: "<< det << endl;
            s=-1 * s;
        }
    }
    return (det);

    for(int i = 0; i < tam; i++)
    {
        free(m_minor[i]);
    }
    free(m_minor);

}

float **inversa(float **matriz,int tam)
{
    //cout << "multiplicaçã de cofatores" << endl;
    float **m_cofator,**matriz_cofator;

    m_cofator = (float **) malloc(tam * sizeof(float *));

    for(int i = 0; i < tam; i++)
    {
        m_cofator[i] = (float *) malloc(tam * sizeof(float));
    }

    matriz_cofator = (float **) malloc(tam * sizeof(float *));

    for(int i = 0; i < tam; i++)
    {
        matriz_cofator[i] = (float *) malloc(tam * sizeof(float));
    }

    int p,q,m,n,i,j;
    for (q=0; q<tam; q++)
    {
        for (p=0; p<tam; p++)
        {
            m=0;
            n=0;
            for (i=0; i<tam; i++)
            {
                for (j=0; j<tam; j++)
                {
                    if (i != q && j != p)
                    {
                        m_cofator[m][n]=matriz[i][j];
                        if (n<(tam-2))
                            n++;
                        else
                        {
                            n=0;
                            m++;
                        }
                    }
                }
            }
            matriz_cofator[q][p]=pow(-1,q + p) * determinante(m_cofator,tam-1);
        }
    }
    return transposta(matriz,matriz_cofator,tam);

    for(int i = 0; i < tam; i++)
    {
        free(m_cofator[i]);
    }
    free(m_cofator);

    for(int i = 0; i < tam; i++)
    {
        free(matriz_cofator[i]);
    }
    free(matriz_cofator);
}

/*Finding transpose of cofactor of matrix*/
float **transposta(float **matriz,float **matriz_cofator,int tam)
{
    //cout << "transposta de matrizes" << endl;

    int i,j;
    float **m_transposta, **m_inversa,d;

    m_transposta = (float **) malloc(tam * sizeof(float *));

    for(int i = 0; i < tam; i++)
    {
        m_transposta[i] = (float *) malloc(tam * sizeof(float));
    }

    m_inversa = (float **) malloc(tam * sizeof(float *));

    for(int i = 0; i < tam; i++)
    {
        m_inversa[i] = (float *) malloc(tam * sizeof(float));
    }

    for (i=0; i<tam; i++)
    {
        for (j=0; j<tam; j++)
        {
            m_transposta[i][j]=matriz_cofator[j][i];
        }
    }
    d=determinante(matriz,tam);
    for (i=0; i<tam; i++)
    {
        for (j=0; j<tam; j++)
        {
            m_inversa[i][j]=m_transposta[i][j] / d;
        }
    }

    //imprimir_mat(m_inversa,tam);

    return  m_inversa;

    for(int i = 0; i < tam; i++)
    {
        free(m_transposta[i]);
    }
    free(m_transposta);

    for(int i = 0; i < tam; i++)
    {
        free(m_inversa[i]);
    }
    free(m_inversa);
}

float **multi_mat(float ** mat_1, float ** mat_2, int lin_1, int col_1, int lin_2 ,int col_2)
{
    if (col_1 != lin_2) {
        cout << "MULTIPLICAÇÃO DE MATRIZES NÃO FOI POSSÍVEL DE SER REALIZADA!" << endl;
        abort();
    }
        
    float **mat_saida;
    mat_saida = (float **)malloc(lin_1 * sizeof(float*));

    for (int i = 0; i < lin_1; i++)
        mat_saida[i] = (float*)malloc(col_2 * sizeof(float));

    for (int i = 0; i < lin_1; i++)
        for (int j = 0; j < col_2; j++)
            mat_saida[i][j] = 0;

    for(int i = 0; i < lin_1; i++)
        for(int j = 0; j < col_2; j++)
            for (int k = 0; k < lin_2; k++) {
                mat_saida[i][j] += mat_1[i][k] * mat_2[k][j];
                cout << k << " " << i << " " << j << endl;
            }
    return mat_saida;

}

void imprimir_mat(float ** matriz, int linhas, int colunas)
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void mat_free(float** matriz, int lin, int col) {
    for (int i = 0; i < lin; i++)
        free(matriz[i]);
    free(matriz);
}

/********************************************************************/
float determinant(float **matrix, float size)
{
    float s = 1, det = 0, **m_minor;

    m_minor = (float**)malloc(size * sizeof(float*));

    for (int i = 0; i < size; i++)
    {
        m_minor[i] = (float*)malloc(size * sizeof(float));
    }

    int i, j, m, n, c;
    if (size == 1)
    {
        return (matrix[0][0]);
    }
    else
    {
        det = 0;
        for (c = 0; c < size; c++)
        {
            m = 0;
            n = 0;
            for (i = 0; i < size; i++)
            {
                for (j = 0; j < size; j++)
                {
                    m_minor[i][j] = 0;
                    if (i != 0 && j != c)
                    {
                        m_minor[m][n] = matrix[i][j];
                        if (n < (size - 2))
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            det = det + s * (matrix[0][c] * determinant(m_minor, size - 1));
            s = -1 * s;
        }
    }

    return (det);
}


/*calculate cofactor of matrix*/
float **cofactor(float **matrix, float size)
{
    float **m_cofactor, **matrix_cofactor;

    m_cofactor = (float**)malloc(size * sizeof(float*));

    for (int i = 0; i < size; i++)
    {
        m_cofactor[i] = (float*)malloc(size * sizeof(float));
    }

    matrix_cofactor = (float**)malloc(size * sizeof(float*));

    for (int i = 0; i < size; i++)
    {
        matrix_cofactor[i] = (float*)malloc(size * sizeof(float));
    }

    int p, q, m, n, i, j;
    for (q = 0; q < size; q++)
    {
        for (p = 0; p < size; p++)
        {
            m = 0;
            n = 0;
            for (i = 0; i < size; i++)
            {
                for (j = 0; j < size; j++)
                {
                    if (i != q && j != p)
                    {
                        m_cofactor[m][n] = matrix[i][j];
                        if (n < (size - 2))
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            matrix_cofactor[q][p] = pow(-1, q + p) * determinant(m_cofactor, size - 1);
        }
    }
    return transpose(matrix, matrix_cofactor, size);
}

/*Finding transpose of cofactor of matrix*/
float ** transpose(float **matrix, float **matrix_cofactor, float size)
{
    int i, j;
    float **m_transpose, **m_inverse, d;

    m_transpose = (float**)malloc(size * sizeof(float*));

    for (int i = 0; i < size; i++)
    {
        m_transpose[i] = (float*)malloc(size * sizeof(float));
    }

    m_inverse = (float**)malloc(size * sizeof(float*));

    for (int i = 0; i < size; i++)
    {
        m_inverse[i] = (float*)malloc(size * sizeof(float));
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            m_transpose[i][j] = matrix_cofactor[j][i];
        }
    }
    d = determinant(matrix, size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            m_inverse[i][j] = m_transpose[i][j] / d;
        }
    }
    return m_inverse;

    mat_free(m_inverse, size, size);
    mat_free(m_transpose, size, size);

}