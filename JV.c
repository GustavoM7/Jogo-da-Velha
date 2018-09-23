#include <stdio.h>
#include <stdlib.h>
//Jogo da Velha em C, por GustavoM7


//Subfunções para função 'check':
int diagSCheck(char **matrz, char jogador);
int diagPCheck(char **matrz, char jogador);
int linhaCheck(int linha, char **matriz, char jogador);
int colunaCheck(int linha, char **matriz, char jogador);

//Função para checagem de fim de jogo:
int check(char **matriz);

//Função para imprimir tabela no terminal:
void imprime(char **matriz);

//Função para pausar o jogo;
void pausar();

int main (){
	int linha, coluna, i, j, RParcial;

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

		RParcial = check(matriz); //Recebendo resultado parcial após jogada.

		//Jogador 2 jogará se jogador 1 não tiver ganho.
		if(RParcial == 1){

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

		RParcial = check(matriz); //Recebendo resultado parcial após jogada.
	}
	
	printf("\nJogo ecerredo!\n");


	//Respostas aos resultados possíveis do jogo:
	if(RParcial == 2){
		printf("Parabéns Jogador X!\n");
	} else if (RParcial == 3){
		printf("Parabéns Jogador O!\n");
	} else {
		printf("Deu velha!\n");
	}

	free(matriz);
	return 0;
}

void pausar(){
	char pause[41];
	printf("Pressione Enter para continuar...");
	scanf("%[^\n]", pause);
}


int diagPCheck(char **matriz, char jogador){
	int i = 0;
	while (i < 3 && matriz[i][i] == jogador){
		i++;
	}

	if (i == 3) 
		return 1;
	return 0;
}

int diagSCheck(char **matriz, char jogador){
	int i = 0;
	while (i < 3 && matriz[i][2 - i] == jogador){
		i++;
	}

	if (i == 3) 
		return 1;
	return 0;
}

int linhaCheck(int linha, char **matriz, char jogador){
	int coluna = 0;
	while (coluna < 3 && matriz[linha][coluna] == jogador){
		coluna++;
	}
	if (coluna == 3)
		return 1;
	return 0;
}

int colunaCheck(int coluna, char **matriz, char jogador){
	int linha = 0;
	while (linha < 3 && matriz[linha][coluna] == jogador){
		linha++;
	}
	if (linha == 3)
		return 1;
	return 0;
}

int check(char **matriz){
	int i, j;

	//Procurando vitoria de X na diagonal principal:
	if(diagPCheck(matriz, 'X') == 1)
		return 2;
	
	//Procurando vitoria de X na diagonal secundária:
	if(diagSCheck(matriz, 'X') == 1)
		return 2;

	//Procurando vitoria de X em cada linha:
	for(i = 0; i < 3; i++){
		if(linhaCheck(i, matriz, 'X') == 1)
			return 2;
	}

	//Procurando vitoria de X em cada coluna:
	for(i = 0; i < 3; i++){
		if(colunaCheck(i, matriz, 'X') == 1)
			return 2;
	}

	//Procurando vitoria de O na diagonal principal:
	if(diagPCheck(matriz, 'O') == 1)
		return 3;

	//Procurando vitoria de O na diagonal secundária:
	if(diagPCheck(matriz, 'O') == 1)
		return 3;

	//Procurando vitoria de O em cada linha:
	for(i = 0; i < 3; i++){
		if(linhaCheck(i, matriz, 'O') == 1)
			return 3;
	}

	//Procurando vitoria de O em cada coluna:
	for(i = 0; i < 3; i++){
		if(colunaCheck(i, matriz, 'O') == 1)
			return 3;
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

