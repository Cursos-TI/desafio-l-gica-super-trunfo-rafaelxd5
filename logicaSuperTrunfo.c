#include <stdio.h>

#define MAX_CIDADES 100

int main() {
    char nomes[MAX_CIDADES][50];      // Nome da cidade
    char estados[MAX_CIDADES][3];    // Sigla do estado
    int populacoes[MAX_CIDADES];     // População
    float areas[MAX_CIDADES];        // Área km2
    float pibs[MAX_CIDADES];         // PIB
    int pontosTuristicos[MAX_CIDADES]; // Pontos turisticos
    int contador = 0;                // Contador de cidades cadastradas
    int opcao;
    float densidade;
    float pibcapita;

    do {

        // Menu inicial
        printf("\n----- Super Trunfo -----\n");
        printf("1. Cadastrar Cidade\n");
        printf("2. Visualizar Cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) { // Cadastrar Cidade
            if (contador >= MAX_CIDADES) {
                printf("Limite de cidades atingido!\n");
                continue;
            }

            // Preencher dados da nova cidade
            printf("\n--- Cadastro de Cidade ---\n");
            printf("Nome da cidade: ");
            scanf("%49s", nomes[contador]);

            printf("Estado : ");
            scanf("%2s", estados[contador]);

            printf("Populacao: ");
            scanf("%d", &populacoes[contador]);

            printf("Area km2: ");
            scanf("%f", &areas[contador]);

            printf("PIB: ");
            scanf("%f", &pibs[contador]);

            printf("Pontos Turisticos: ");
            scanf("%d", &pontosTuristicos[contador]);

            //conta cidade para salvar cada uma em um array
            contador = contador + 1;

            printf("Cidade cadastrada com sucesso!\n");

        } else if (opcao == 2) { // Visualizar Cartas
            if (contador == 0) {
                printf("\nNao ha cidades cadastradas!\n");
            } else {
                printf("\n--- Cartas Cadastradas ---\n");
                for (int i = 0; i < contador; i = i + 1) {
                    printf("\nCarta %d:\n", i + 1);
                    printf("Nome: %s\n", nomes[i]);
                    printf("Estado: %s\n", estados[i]);
                    printf("Populacao: %d habitantes\n", populacoes[i]);
                    printf("Area: %.2f km²\n", areas[i]);
                    printf("PIB: %.2f\n", pibs[i]);
                    printf("Pontos Turisticos: %d\n", pontosTuristicos[i]);

                    // Cálculo da densidade populacional
                    densidade = populacoes[i]/areas[i];

                     // Cálculo do PIB per capita
                    pibcapita = pibs[i] / populacoes[i];

                    printf("densidade: %.2f\n",densidade);
                    printf("pib per capita: %.2f\n",pibcapita);
                }
            }
        } else if (opcao != 0) {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    printf("Programa encerrado.\n");
    return 0;
}