//Alunas: Ana Carolina e Marcelly

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Primeira struct
typedef struct {
    char autor[50];
    char titulo[50];
    char cor[20];
    int qntEstoque;
    float preco;
    int idLivro;
} Livraria;

// Struct para os nos da pilha encadeada
typedef struct Node {
    Livraria livro;
    struct Node* next;
} Node;

// Segunda struct (pilha encadeada)
typedef struct {
    Node* head;
    int size;
} Pilha;

// Funcoes para manipulacao da pilha encadeada
Pilha* criarLista();
void menuPrincipal();
void push(Pilha*, Livraria livro);
int pop(Pilha*,char[]);
int verTopo(Pilha*, char[]);
int ehVazia(Pilha*);
void excluirPilha(Pilha*);

int main() {
    Pilha *pilha = criarLista();
    int menu, local, posicao, qntEstoque;
    float preco;
    char autor[50], titulo[50], cor[20], nomeTitulo[50], resposta;
    Livraria livro;

    // Menu
    while (1) {
        printf("O que voce quer fazer? \n1. Inserir livro \n2. Remover livro \n3. Mostrar livros \n4. Pilha ehVazia?\n \n5. Excluir pilha\n");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Digite os seguintes dados sobre o livro que sera adicionado:\n");
                printf("Autor: ");
                scanf("%s", autor);
                printf("Titulo: ");
                scanf("%s", titulo);
                printf("Quantidade em Estoque:  ");
                scanf("%d", &qntEstoque);
                printf("Preco:  ");
                scanf("%f", &preco);
                printf("Cor:  ");
                scanf("%s", cor);

                // Preenchendo a estrutura do livro
                strcpy(livro.autor, autor);
                strcpy(livro.titulo, titulo);
                livro.qntEstoque = qntEstoque;
                livro.preco = preco;
                strcpy(livro.cor, cor);
                livro.idLivro = pilha->size;

                void push(pilha); //precisa ajustar mais
                break;
            case 2:
                if (pilha->size != 0) {
                    printf("Digite o nome do livro que sera removido: \n");
                    scanf("%s", titulo);
                    removerElemento(pilha, titulo);
                } else {
                    printf("Lista vazia\n");
                }
                break;
            case 4:
                verTopo(pilha,nomeTitulo); //vai ser o verTopo
                break;
            case 5:
               
            case 6:
                printf("Deseja mesmo excluir a pilha? (s/n)\n");
                scanf(" %c", &resposta);
                switch (resposta) {
                    case 's':
                    case 'S':
                        excluirPilha(pilha);
                        exit(0);
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        printf("Essa opcao nao e valida!\n");
                        break;
                }
                break;
            default:
                printf("Essa opcao nao e valida!\n");
                break;
        }
    }

    return 0;
}
