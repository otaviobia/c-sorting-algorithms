/* Programa que gera casos testes para algoritmos de ordenação de inteiros
 * Uso: casoteste <tamanho> <tipo> <outputfile>
 * Tipo pode ser: "random", "ordasc" ou "orddes"
 *
 * Autor: Otávio Biagioni - 18/11/2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *criar_arquivo(char* path) {
	FILE *ct = fopen(path, "w");
	if (ct == NULL) {
		printf("Erro ao criar o arquivo do caso teste.\n");
		exit(1);
	}

	return ct;
}

void escrever_casos(FILE* ct, int tamanho, char* tipo) {
	// Valor mínimo e máximo da geração aleatória de chaves
	int valor_min = 1;
	int valor_max = 1000;

	// Primeira linha é a quantidade de elementos gerado
	fprintf(ct, "%d\n", tamanho);

	// As próximas "tamanho" linhas são os elementos
	if (!strcmp(tipo, "random")) {
		srand(time(NULL));
		for (int i = 1; i <= tamanho; i++) {
			int valor_aleatorio = ((double)rand() / RAND_MAX) * (valor_max - valor_min) + valor_min;
			if (i != tamanho)
				fprintf(ct, "%d\n", valor_aleatorio);
			else
				fprintf(ct, "%d", valor_aleatorio);
		}
	}
	else if (!strcmp(tipo, "ordasc")) {
		for (int i = 1; i <= tamanho; i++) {
			if (i != tamanho)
				fprintf(ct, "%d\n", i);
			else
				fprintf(ct, "%d", i);
		}
	}
	else if (!strcmp(tipo, "orddes")) {
		for (int i = tamanho; i > 0; i--) {
			if (i != 1)
				fprintf(ct, "%d\n", i);
			else
				fprintf(ct, "%d", i);
		}
	}
	else {
		printf("Tipo invalido.\n");
		fclose(ct);
		exit(1);
	}
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("Uso: casoteste <tamanho> <tipo: random/ordasc/orddes> <arquivo de saida>\n");
		exit(1);
	}

	FILE *ct = criar_arquivo(argv[3]);
	escrever_casos(ct, atoi(argv[1]), argv[2]);
	fclose(ct);

	exit(0);
}