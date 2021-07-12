#include <stdio.h>
#define LIM 10

int print_matriz(int linha, int coluna, int array[linha][coluna]); // funcao para mostrar a matriz original
int redimencionar(int i, int j, int array[i][j], int ni, int nj, int narray[ni][nj]); // i = linhas do array; j = colunas do array; // ni = linhas do narray; nj = colunas do narray;
void transposta(int array[LIM][LIM], int rows, int columns);  // Rows = linhas, columns = colunas

int main(void){
	
	int array[LIM][LIM] =  {{1,2,3,4},
						   {5,6,7,8},
						   {9,10,11,12},
						   {13,14,15,16},
						   {17,18,19,20}};
						
	int narray[LIM][LIM];
	
	print_matriz(5, 4, array);
	redimencionar(5, 4, array, 1, 20, narray);
	transposta(array, 3, 4);
	
}
/*
	-------------------------------------
	FUNCAO PARA PRINTAR UMA MATRIZ
	-------------------------------------
*/
int print_matriz(int linha, int coluna, int array[linha][coluna]){
	
	int s, *p, g = 0;
	
	printf("\nMATRIZ ORIGINAL[!]\n");
	for(s = 0; s < linha; s++){
		for(p = array[s]; p <= array[s] + coluna-1; p++){
			g++;			
			printf("%3d", g);
		}
		putchar('\n');
	}
}
/*
	-------------------------------------
	FUNCAO PARA REDIMENSIONAR UMA MATRIZ
	-------------------------------------
*/

int redimencionar(int i, int j, int array[i][j], int ni, int nj, int narray[ni][nj]){ // i = linhas do array; j = colunas do array; // ni = linhas do narray; nj = colunas do narray;
																						
	int p, s, n, g = 0, *pointer, *k;
	int r1, r2;
	
	r1 = i * j;
	r2 = ni * nj;
	
	if(r1 == r2){
		for(s = 0; s < i; s++){
			for(pointer = array[s]; pointer <= array[s] + j-1; pointer++){
				g++;			
				narray[n][g] = g;
			}
			putchar('\n');
		}
		printf("\nMATRIZ REDIMENSIONADA[!]\n");
		for(s = 0; s < ni; s++){
				for(k = narray[s]+1; k <= narray[s] + nj; k++){			
					printf("%3d", *k);
				}
				putchar('\n');
			}
	}else{
		printf("\nERROR! PARA REDIMENSIONAR E NECESSARIO QUE O NOVO ARRAY TENHA A MESMA QUANTIDADE DE ELEMENTOS QUE O ARRAY ORIGINAL.\n");
	}
}
/*
	------------------------------
	FUNCAO PARA MATRIZ TRANSPOSTA
	------------------------------
*/
void transposta(int array[LIM][LIM], int rows, int columns){ // Rows = linhas, columns = colunas
	
    int i, j;
    int array_t[LIM][LIM];
    
    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j = j + 1) array_t[j][i] = array[i][j];
    printf("\nTRANSPOSTA[!]\n");
    for (i = 0; i < columns; i = i + 1){
        for (j = 0; j < rows; j = j + 1){
			printf("%3d", array_t[i][j]);
		}
		putchar('\n');
	}
}

