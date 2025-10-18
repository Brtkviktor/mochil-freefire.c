#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// ===============================
// ESTRUTURA BASE DO INVENTÁRIO
// ===============================
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade; // 1 a 5
} Item;

// ===============================
// PROTÓTIPOS DAS FUNÇÕES
// ===============================
void inserirItem(Item mochila[], int *total);
void removerItem(Item mochila[], int *total, char nome[]);
void listarItens(Item mochila[], int total);
void organizarMochila(Item mochila[], int total, int *ordenadoPorNome);
void ordenarPorNome(Item mochila[], int total);
void ordenarPorTipo(Item mochila[], int total);
void ordenarPorPrioridade(Item mochila[], int total);
int buscarBinariaPorNome(Item mochila[], int total, char nome[]);
void buscarItemMochila(Item mochila[], int total, int ordenadoPorNome);
void trocar(Item *a, Item *b);

// ===============================
// FUNÇÃO PRINCIPAL
// ===============================
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;
    int ordenadoPorNome = 0; // 0 = não ordenado, 1 = ordenado

    do {
        printf("\n--- Menu da Mochila ---\n");
        printf("Itens na mochila: %d/%d\n", total, MAX_ITENS);
        printf("Status de ordenacao por nome: %s\n", 
               ordenadoPorNome ? "ordenado" : "nao ordenado");

        printf("\n1. Adicionar componente\n");
        printf("2. Descartar componente\n");
        printf("3. Listar componentes (inventario)\n");
        printf("4. Organizar mochila (ordenar componentes)\n");
        printf("5. Buscar binaria por componente - chave (por nome)\n");
        printf("0. ATIVAR TORRE DE FUGA (Sair)\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                ordenadoPorNome = 0;
                break;
            case 2: {
                char nome[30];
                printf("\nDigite o nome do componente para descartar: ");
                scanf("%s", nome);
                removerItem(mochila, &total, nome);
                ordenadoPorNome = 0;
                break;
            }
            case 3:
                listarItens(mochila, total);
                break;
            case 4:
                organizarMochila(mochila, total, &ordenadoPorNome);
                break;
            case 5:
                buscarItemMochila(mochila, total, ordenadoPorNome);
                break;
            case 0:
                printf("\nEncerrando simulacao...\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}

// ===============================
// FUNÇÕES AUXILIARES
// ===============================
void trocar(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// ===============================
// CADASTRO E GESTÃO DE COMPONENTES
// ===============================
void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nMochila cheia.\n");
        return;
    }

    printf("\n--- Inserir Componente ---\n");
    printf("Nome: ");
    scanf("%s", mochila[*total].nome);
    printf("Tipo (estrutural, eletronico, energia): ");
    scanf("%s", mochila[*total].tipo);
    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);
    printf("Prioridade de montagem (1 a 5): ");
    scanf("%d", &mochila[*total].prioridade);

    (*total)++;
    printf("Componente adicionado com sucesso.\n");
}

void removerItem(Item mochila[], int *total, char nome[]) {
    int pos = -1;
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nComponente nao encontrado.\n");
        return;
    }

    for (int i = pos; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    (*total)--;

    printf("Componente descartado com sucesso.\n");
}

void listarItens(Item mochila[], int total) {
    if (total == 0) {
        printf("\nMochila vazia.\n");
        return;
    }

    printf("\n--- Inventario Atual ---\n");
    for (int i = 0; i < total; i++) {
        printf("%d) Nome: %s | Tipo: %s | Qtd: %d | Prioridade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade, mochila[i].prioridade);
    }
}

// ===============================
// ORDENAÇÃO (OPÇÃO 4)
// ===============================
void organizarMochila(Item mochila[], int total, int *ordenadoPorNome) {
    int opc;
    if (total == 0) {
        printf("\nNenhum componente para organizar.\n");
        return;
    }

    printf("\n--- Organizar Mochila ---\n");
    printf("1. Por nome (ordem alfabetica)\n");
    printf("2. Por tipo\n");
    printf("3. Por prioridade de montagem\n");
    printf("0. Cancelar\n");
    printf("Escolha: ");
    scanf("%d", &opc);

    switch (opc) {
        case 1:
            ordenarPorNome(mochila, total);
            *ordenadoPorNome = 1;
            printf("\nMochila ordenada por nome.\n");
            break;
        case 2:
            ordenarPorTipo(mochila, total);
            *ordenadoPorNome = 0;
            printf("\nMochila ordenada por tipo.\n");
            break;
        case 3:
            ordenarPorPrioridade(mochila, total);
            *ordenadoPorNome = 0;
            printf("\nMochila ordenada por prioridade.\n");
            break;
        case 0:
            printf("\nOrganizacao cancelada.\n");
            break;
        default:
            printf("\nOpcao invalida.\n");
    }
}

void ordenarPorNome(Item mochila[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0)
                trocar(&mochila[j], &mochila[j + 1]);
        }
    }
}

void ordenarPorTipo(Item mochila[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(mochila[j].tipo, mochila[j + 1].tipo) > 0)
                trocar(&mochila[j], &mochila[j + 1]);
        }
    }
}

void ordenarPorPrioridade(Item mochila[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (mochila[j].prioridade > mochila[j + 1].prioridade)
                trocar(&mochila[j], &mochila[j + 1]);
        }
    }
}

// ===============================
// BUSCA BINÁRIA (OPÇÃO 5)
// ===============================
int buscarBinariaPorNome(Item mochila[], int total, char nome[]) {
    int inicio = 0, fim = total - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(mochila[meio].nome, nome);
        if (cmp == 0)
            return meio;
        else if (cmp < 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

void buscarItemMochila(Item mochila[], int total, int ordenadoPorNome) {
    if (!ordenadoPorNome) {
        printf("\nAlerta: A busca binaria requer que a mochila esteja ordenada por nome.\n");
        printf("Use a opcao 4 para organizar os componentes primeiro.\n");
        return;
    }

    if (total == 0) {
        printf("\nMochila vazia, impossivel buscar.\n");
        return;
    }

    char nome[30];
    printf("\nDigite o nome do componente que deseja usar: ");
    scanf("%s", nome);

    int pos = buscarBinariaPorNome(mochila, total, nome);
    if (pos != -1) {
        printf("\nComponente encontrado:\n");
        printf("Nome: %s | Tipo: %s | Qtd: %d | Prioridade: %d\n",
               mochila[pos].nome, mochila[pos].tipo,
               mochila[pos].quantidade, mochila[pos].prioridade);
    } else {
        printf("\nComponente nao encontrado.\n");
    }
}