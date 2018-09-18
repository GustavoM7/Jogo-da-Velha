#include <stdio.h>
#include <stdlib.h>
//Jogo da Velha em C, por GustavoM7


//Função para checagem de fim de jogo:
int check(char matriz[3][3]){
	int i = 0, j = 0, cont = 0;

	while(matriz[i][j] != ' ' && i < 3){
		j = 0;
		while(matriz[i][j] != ' ' && j < 3){
			j++;
			cont++;			
		}
		i++;
	}

	if (cont == 9){
		return 0;
	} else {
		return 1;
	}
}

//Função para imprimir tabela no terminal:
void imprime(char matriz[3][3]){
	printf("\e[H\e[2J");
	printf("\n\n	 %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("	--- --- ---\n");
	printf("	 %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
	printf("	--- --- ---\n");
	printf("	 %c | %c | %c \n\n\n", matriz[2][0], matriz[2][1], matriz[2][2]);
}

//printf("\e[H\e[2J");
int main (){
	int linha, coluna;
	int pause;
	printf("\n---Bem vindo ao Jogo da Velha em C---\n\n");	
	printf("Entre qualquer numero para continuar...\n");
	printf("Encerre o jogo com comando Ctrl + C\n");
	scanf("%d", &pause);
	char matriz[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	system("PAUSE");
	imprime(matriz);
	while(check(matriz)){
		printf("Jogador X: Entre linha e coluna\nLinha: ");
		scanf("%d", &linha);
		printf("Coluna: ");
		scanf("%d", &coluna);
		matriz[linha][coluna] = 'X';
		imprime(matriz);
	}
		
	system("PAUSE");
	return 0;
}
