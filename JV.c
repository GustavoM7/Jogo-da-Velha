#include <stdio.h>
#include <stdlib.h>
//Jogo da Velha em C, por GustavoM7


//Função para checagem de fim de jogo:
int check(char **matriz);

//Função para imprimir tabela no terminal:
void imprime(char **matriz);

//Função para pausar o jogo;
void pausar();

int main (){
	int linha, coluna, i, j;

	printf("\n---Bem vindo ao Jogo da Velha em C---\n\n");	
	printf("Encerre o jogo com comando Ctrl + C\n");
	pausar();

	char **matriz = (char**) malloc(3 * sizeof(char*));

	for (i = 0; i < 3; i++){
		matriz[i] = (char*) malloc(3 * sizeof(char));

		for (j = 0; j < 3; j++){
			matriz[i][j] = ' ';
		}

	}

	imprime(matriz);

	while(check(matriz) == 1){
		printf("Jogador X: Entre linha e coluna\nLinha: ");
		scanf(" %d", &linha);

		while(linha > 3 || linha < 1){
			printf("Entrada inválida!\n");
			printf("\nLinha(1 <--> 3): ");
			scanf(" %d", &linha);

		}

		printf("Coluna: ");
		scanf(" %d", &coluna);

		while(coluna > 3 || coluna < 1){
			printf("Entrada inválida!\n");
			printf("\nColuna(1 <--> 3): ");
			scanf(" %d", &coluna);

		}

		matriz[linha-1][coluna-1] = 'X';
		imprime(matriz);

		printf("Jogador O: Entre linha e coluna\nLinha: ");
		scanf(" %d", &linha);

		while(linha > 3 || linha < 1){
			printf("Entrada inválida!\n");
			printf("\nLinha(1 <--> 3): ");
			scanf(" %d", &linha);

		}

		printf("Coluna: ");
		scanf(" %d", &coluna);

		while(coluna > 3 || coluna < 1){
			printf("Entrada inválida!\n");
			printf("\nColuna(1 <--> 3): ");
			scanf(" %d", &coluna);

		}

		matriz[linha-1][coluna-1] = 'O';
		imprime(matriz);
	}
	
	printf("\nJogo ecerredo, Parabéns ao vencedor!\n");
	free(matriz);
	return 0;
}

void pausar(){
	char pause[41];
	printf("Pressione Enter para continuar...");
	scanf("%[^\n]", pause);
}

int check(char **matriz){
	int i, j, k;

	k = 0;
	//Procurando vitoria de X na diagonal 1:
	for (i = 0; i < 3; i++){
		if (matriz[i][i] == 'X'){
			k++;
		}
		
		if (k == 3){
			//Jogador X vencedor:
			return 2;
		}
	}

	k = 0;
	//Procurando vitoria de X na diagonal 2:
	for (i = 0; i < 3; i++){
		if (matriz[i][3 - i] == 'X'){
			k++;
		}
		
		if (k == 3){
			//Jogador X vencedor:
			return 2;
		}
	}

	k = 0;
	//Procurando vitoria de O na diagonal 1:
	for (i = 0; i < 3; i++){
		if (matriz[i][i] == 'O'){
			k++;
		}
		
		if (k == 3){
			//Jogador O vencedor:
			return 3;
		}
	}

	k = 0;
	//Procurando vitoria de O na diagonal 2:
	for (i = 0; i < 3; i++){
		if (matriz[i][3 - i] == 'O'){
			k++;
		}
		
		if (k == 3){
			//Jogador O vencedor:
			return 3;
		}
	}


	//Procurando espaços vazios:
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (matriz[i][j] == ' '){
				//Jogo em progresso:
				return  1;
			}
		
		}

	}

	//Velha:
	return 0;
}

void imprime(char **matriz){
	printf("\e[H\e[2J");
	printf("\n\n	 %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("	--- --- ---\n");
	printf("	 %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
	printf("	--- --- ---\n");
	printf("	 %c | %c | %c \n\n\n", matriz[2][0], matriz[2][1], matriz[2][2]);
}

