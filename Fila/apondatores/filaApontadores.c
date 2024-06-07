#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura do livro
typedef struct {
    char autor[50];
    char titulo[50];
    char cor[20];
    int qntEstoque;
    float preco;
    int idLivro;
} Livraria;

// Estrutura do no
typedef struct Node {
    Livraria livro;
    struct Node* prox;
} Node;

// Estrutura da fila
typedef struct {
    Node* inicio;
    Node* fim;
} Fila;

// Criar nova fila
Fila* criarFila() {
    Fila* nova = (Fila*)malloc(sizeof(Fila));
    if (nova == NULL) {
        printf("Nao tem espaco\n");
        return NULL;
    }
    nova->inicio = NULL;
    nova->fim = NULL;
    return nova;
}

// Inserir novo livro na fila
void enqueue(Fila* fila, Livraria livro) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Nao tem espaco\n");
        exit(1);
    }
    novoNode->livro = livro;
    novoNode->prox = NULL;
    if (fila->fim == NULL) {
        fila->inicio = novoNode;
    } else {
        fila->fim->prox = novoNode;
    }
    fila->fim = novoNode;
}

// Remover livro do inicio da fila
Livraria dequeue(Fila* fila) {
    if (fila == NULL){
        printf("A filha não foi criada\n");
        exit(1);
    }
    
    if (fila->inicio == NULL) {
        printf("Fila esta vazia\n");
        exit(1);
    }
    Node* temp = fila->inicio;
    Livraria livro = temp->livro;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return livro;
}

// Função para excluir todos os elementos da fila
void excluirFila(Fila* fila) {
    while (fila->inicio != NULL) {
        dequeue(fila);
    }
    free(fila);
}

// Menu principal
void menuPrincipal(Fila* fila) {
    int opcao;
    do {
        printf("\nMenu\n");
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Excluir Todos os Livros da Fila\n");
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
                novoLivro.idLivro = (fila->fim == NULL) ? 1 : fila->fim->livro.idLivro + 1; // Gerar um ID simples
                enqueue(fila, novoLivro);
                printf("Livro inserido com sucesso!\n");
                break;
            }
            case 2: {
                if (fila->inicio == NULL) {
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
