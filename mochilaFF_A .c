#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// ===============================
// ESTRUTURAS
// ===============================
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// ===============================
// PROTÓTIPOS DAS FUNÇÕES
// ===============================
void inserirItem(Item mochila[], int *total);
void listarItens(Item mochila[], int total);
int buscarItem(Item mochila[], int total, char nome[]);
void removerItem(Item mochila[], int *total, char nome[]);

// ===============================
// FUNÇÃO PRINCIPAL
// ===============================
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;
    char nome[30];

    do {
        printf("=======================================================\n");
        printf("\n      MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA      \n");
        printf("=======================================================\n");
        printf("Itens na mochila: %d/%d\n", total, MAX_ITENS);
        printf("1. Inserir item (Loot)\n");
        printf("2. Listar itens\n");
        printf("3. Buscar item por nome\n");
        printf("4. Remover item\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                break;
            case 2:
                listarItens(mochila, total);
                break;
            case 3:
                printf("\nDigite o nome do item: ");
                scanf("%s", nome);
                if (buscarItem(mochila, total, nome) != -1)
                    printf("\nItem encontrado na mochila!\n");
                else
                    printf("\nItem não encontrado.\n");
                break;
            case 4:
                printf("\nDigite o nome do item para remover: ");
                scanf("%s", nome);
                removerItem(mochila, &total, nome);
                break;
            case 0:
                printf("\nSaindo do sistema da mochila...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

// ===============================
// FUNÇÕES
// ===============================

// Inserir item na mochila
void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nMochila cheia!\n");
        return;
    }

    printf("\n--- Inserir Item ---\n");
    printf("Nome: ");
    scanf("%s", mochila[*total].nome);
    printf("Tipo: ");
    scanf("%s", mochila[*total].tipo);
    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    (*total)++;
    printf(" Item adicionado com sucesso!\n");
}

// Listar todos os itens
void listarItens(Item mochila[], int total) {
    if (total == 0) {
        printf("\nMochila vazia.\n");
        return;
    }

    printf("\n--- Itens na Mochila ---\n");
    for (int i = 0; i < total; i++) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Buscar item por nome (busca sequencial)
int buscarItem(Item mochila[], int total, char nome[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0)
            return i;
    }
    return -1;
}

// Remover item da mochila
void removerItem(Item mochila[], int *total, char nome[]) {
    int pos = buscarItem(mochila, *total, nome);
    if (pos == -1) {
        printf("\nItem nao encontrado!\n");
        return;
    }

    for (int i = pos; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    (*total)--;

    printf("\nItem removido com sucesso!\n");
}