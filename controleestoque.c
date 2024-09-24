#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para armazenar dados do produto
typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

// Função para adicionar um novo produto
void adicionarProduto(Produto *produtos, int *totalProdutos) {
    Produto novoProduto;
    printf("Digite o nome do produto: ");
    scanf("%49s", novoProduto.nome);
    printf("Digite a quantidade inicial do produto: ");
    scanf("%d", &novoProduto.quantidade);
    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);
    
    produtos[*totalProdutos] = novoProduto;
    (*totalProdutos)++;
    printf("Produto adicionado com sucesso!\n");
}

// Função para exibir o estoque
void exibirEstoque(const Produto *produtos, int totalProdutos) {
    printf("\n--- Estoque Atual ---\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Produto: %s | Quantidade: %d | Preco: R$ %.2f\n", 
               produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }
}

// Função para registrar uma venda
void registrarVenda(Produto *produtos, int totalProdutos) {
    char nomeProduto[50];
    int quantidadeVendida;

    printf("Digite o nome do produto vendido: ");
    scanf("%49s", nomeProduto);

    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            printf("Digite a quantidade vendida: ");
            scanf("%d", &quantidadeVendida);

            if (quantidadeVendida <= produtos[i].quantidade) {
                produtos[i].quantidade -= quantidadeVendida;
                printf("Venda registrada com sucesso!\n");
            } else {
                printf("Quantidade insuficiente em estoque.\n");
            }
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

int main() {
    Produto *produtos = NULL;
    int totalProdutos = 0;
    int capacidade = 0;
    int opcao;

    do {
        printf("\n--- Sistema de Controle de Estoque ---\n");
        printf("1. Adicionar Produto\n");
        printf("2. Exibir Estoque\n");
        printf("3. Registrar Venda\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalProdutos == capacidade) {
                    capacidade = capacidade == 0 ? 1 : capacidade * 2;
                    produtos = realloc(produtos, capacidade * sizeof(Produto));
                    if (produtos == NULL) {
                        fprintf(stderr, "Erro de alocação de memória.\n");
                        exit(1);
                    }
                }
                adicionarProduto(produtos, &totalProdutos);
                break;
            case 2:
                exibirEstoque(produtos, totalProdutos);
                break;
            case 3:
                registrarVenda(produtos, totalProdutos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    free(produtos);
    return 0;
}
