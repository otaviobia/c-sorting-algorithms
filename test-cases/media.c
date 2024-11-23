//Função que recebe um array de strings contendo nomes de arquivos e número de arquivos
//A função foi criada com o intuito de facilitar o cálculo da média dos vetores 
void processa_arquivos(const char *arquivos[], int total_arquivos) {
    unsigned long long total_comparacoes = 0, total_movimentos = 0;
    double total_tempo = 0.0;

    for (int k = 0; k < total_arquivos; k++) {
        FILE *file = fopen(arquivos[k], "r");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo %s\n", arquivos[k]);
            continue;
        }

        int tam;
        fscanf(file, "%d", &tam);
        int *v = (int *)malloc(tam * sizeof(int));
        if (v == NULL) {
            printf("Erro ao alocar memória para o vetor.\n");
            fclose(file);
            continue;
        }

        for (int i = 0; i < tam; i++) {
            fscanf(file, "%d", &v[i]);
        }

        comparacoes = 0;
        movimentos = 0;

        clock_t start = clock();
        selectionSort(v, tam); //Aqui é necessário inserir o método de ordenação escolhido 
        clock_t end = clock();

        double tempo = ((double)(end - start)) / CLOCKS_PER_SEC;

      
        total_comparacoes += comparacoes;
        total_movimentos += movimentos;
        total_tempo += tempo;

        fclose(file);
    }

    printf("\n=== Médias ===\n");
    printf("Média de Comparacoes: %.2f\n", (double)total_comparacoes / total_arquivos);
    printf("Média de Movimentos: %.2f\n", (double)total_movimentos / total_arquivos);
    printf("Média de Tempo: %.6fs\n", total_tempo / total_arquivos);
}
