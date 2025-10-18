#include <stdio.h>
#include <string.h>

#define TAM 10

// Estrutura para representar um item da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Função para inserir item
void inserirItem(Item mochila[], int *total) {
    if (*total >= TAM) {
        printf("\nMochila cheia!\n");
        return;
    }
    printf("\nNome do item: ");
    scanf("%s", mochila[*total].nome);
    printf("Tipo: ");
    scanf("%s", mochila[*total].tipo);
    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);
    (*total)++;
    printf("\nItem adicionado com sucesso!\n");
}

// Função para listar itens
void listarItens(Item mochila[], int total) {
    if (total == 0) {
        printf("\nMochila vazia!\n");
        return;
    }
    printf("\n=== Itens na Mochila ===\n");
    for (int i = 0; i < total; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Função para buscar item por nome (busca linear)
int buscarItem(Item mochila[], int total, char nome[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) return i;
    }
    return -1;
}

// Função para remover item
void removerItem(Item mochila[], int *total, char nome[]) {
    int pos = buscarItem(mochila, *total, nome);
    if (pos == -1) {
        printf("\nItem não encontrado!\n");
        return;
    }
    for (int i = pos; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    (*total)--;
    printf("\nItem removido com sucesso!\n");
}

int main() {
    Item mochila[TAM];
    int total = 0;
    int opcao;
    char nome[30];

    do {
        printf("=======================================================\n");
        printf("\n      MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA      \n");
        printf("=======================================================\n");
        printf("Itens na mochila: %d/%d\n", total, TAM);  // Mostra o contador atualizado
        printf("1. Inserir item\n2. Listar itens\n3. Buscar item\n4. Remover item\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                break;
            case 2:
                listarItens(mochila, total);
                break;
            case 3: {
                printf("\nDigite o nome do item: ");
                scanf("%s", nome);
                int pos = buscarItem(mochila, total, nome);
                if (pos != -1)
                    printf("\nItem encontrado: %s (%s), Qtd: %d\n",
                           mochila[pos].nome, mochila[pos].tipo, mochila[pos].quantidade);
                else
                    printf("\nItem não encontrado.\n");
                break;
            }
            case 4:
                printf("\nDigite o nome do item para remover: ");
                scanf("%s", nome);
                removerItem(mochila, &total, nome);
                break;
        }
    } while (opcao != 0);

    return 0;
}