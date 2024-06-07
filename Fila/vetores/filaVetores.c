#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 5

// Estrutura do livro
typedef struct {
    char autor[50];
    char titulo[50];
    char cor[20];
    int qntEstoque;
    float preco;
    int idLivro;
} Livraria;

// Estrutura da fila
typedef struct {
    Livraria livros[TAM];
    int inicio;
    int fim;
    int tamanho;
} Fila;

// Criar nova fila
Fila* criarFila() {
    Fila* nova = (Fila*)malloc(sizeof(Fila));
    if (nova == NULL) {
        printf("Nao tem espaco\n");
        exit(1);
    }
    nova->inicio = 0;
    nova->fim = 0;
    nova->tamanho = 0;
    return nova;
}

// Inserir novo livro na fila
void enqueue(Fila* fila, Livraria livro) {
    if (fila->tamanho == TAM) {
        printf("Fila esta cheia\n");
        return;
    }
    fila->livros[fila->fim] = livro;
    fila->fim = (fila->fim + 1) % TAM;
    fila->tamanho++;
}

// Remover livro do inicio da fila
Livraria dequeue(Fila* fila) {
    if (fila->tamanho == 0) {
        printf("Fila esta vazia\n");
        exit(1);
    }
    Livraria livro = fila->livros[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM;
    fila->tamanho--;
    return livro;
}

// Função para excluir todos os elementos da fila
void excluirFila(Fila* fila) {
    free(fila);
}

// Menu principal
void menuPrincipal(Fila* fila) {
    int opcao;
    do {
        printf("\nMenu\n");
        printf("1. Inserir Livro no Final\n");
        printf("2. Remover Livro do Inicio\n");
        printf("4. Excluir Todos os Livros da Fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Livraria novoLivro;
                printf("Digite o autor do livro: ");
                scanf(" %[^\n]", novoLivro.autor);
                printf("Digite o titulo do livro: ");
                scanf(" %[^\n]", novoLivro.titulo);
                printf("Digite a cor do livro: ");
                scanf(" %[^\n]", novoLivro.cor);
                printf("Digite a quantidade em estoque do livro: ");
                scanf("%d", &novoLivro.qntEstoque);
                printf("Digite o preco do livro: ");
                scanf("%f", &novoLivro.preco);
                novoLivro.idLivro = (fila->tamanho == 0) ? 1 : fila->livros[(fila->fim - 1 + TAM) % TAM].idLivro + 1; // Gerar um ID simples
                enqueue(fila, novoLivro);
                printf("Livro inserido com sucesso!\n");
                break;
            }
            case 2: {
                if (fila->tamanho == 0) {
                    printf("Fila esta vazia\n");
                } else {
                    Livraria livroRemovido = dequeue(fila);
                    printf("Livro removido: Autor: %s, Título: %s\n", livroRemovido.autor, livroRemovido.titulo);
                }
                break;
            }
            case 3: {
                excluirFila(fila);
                fila = criarFila();
                printf("Livros excluidos da fila\n");
                break;
            }
            case 0: {
                printf("Saindo\n");
                break;
            }
            default: {
                printf("Opcao nao valida\n");
                break;
            }
        }
    } while (opcao != 0);
}

int main() {
    Fila* fila = criarFila();
    menuPrincipal(fila);
    excluirFila(fila);
    return 0;
}
