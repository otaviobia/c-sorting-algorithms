# Algoritmos de Ordenação em C
Implementação de 9 algoritmos de ordenação em C.

## Instruções de Compilação e Execução dos Algoritmos de Ordenação:

- Para compilar qualquer um dos algoritmos utilize o comando:

gcc nome_do_algoritmo.c -o saida -Wall -std=c99

- Para executar um algoritmo já compilado utilize:

./saida < test-cases/<tipo>/<elementos>.txt

Onde <tipo> é a pasta que indica o tipo do caso teste, que pode ser "aleatorios", "ordenados" e "ordenadosinversamente".
Onde <elementos> é a quantidade de elementos no caso teste, que pode ser 100, 1000, 10000 ou 100000. Sendo que para casos teste aleatórios as 5 versões diferentes por quantidade de elemento são nomeadas como 100v1, 100v2, ..., 100v5 e assim por diante para os demais tamanhos.

## Instruções de Compilação e Execução do Gerador de Casos:

- Para compilar o gerador de casos utilize o comando:

gcc gerador_casos.c -o casoteste -Wall -std=c99

- Para executar o gerador de casos utilize:

./casoteste <tamanho> <tipo: random/ordasc/orddes> <arquivo de saida>

Onde <tamanho> é a quantidade de elementos do caso teste a ser gerado.
Onde <tipo> é o tipo das chaves dos elementos, que podem ser ordenadas crescentemente (ordasc), ordenadas decrescentemente (orddes) ou aleatórias (random).
Onde <arquivo de saida> é o nome do arquivo do caso teste gerado com extensão.

Exemplo de uso:
./casoteste 1000 random caso1000aleatorio.txt
