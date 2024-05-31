//alunas: Ana Carolina e Marcelly

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// primeira struct
typedef struct {
    char autor[50];
    char titulo[50];
    char cor[20];
    int qntEstoque;
    float preco;
    int idLivro;
} Livraria;

// struct do no 
typedef struct Node {
    Livraria livro;
    struct Node* prox;
} Node;

// struct da pilha
typedef struct {
    Node* topo;
} Pilha;

// criar nova pilha
Pilha* criarPilha() {
    Pilha* nova = (Pilha*)malloc(sizeof(Pilha));
    if (nova == NULL) {
        printf("Nao tem espaco\n");
        exit(1);
    }
    nova->topo = NULL;
    return nova;
}

// inseriri novo livro
void push(Pilha* pilha, Livraria livro) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Nao tem espaco\n");
        exit(1);
    }
    novoNode->livro = livro;
    novoNode->prox = pilha->topo;
    pilha->topo = novoNode;
}

// remover do topo
Livraria pop(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha esta vazia\n");
        exit(1); 
    }
    Node* temp = pilha->topo;
    Livraria livro = temp->livro;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return livro;
}

// ver se a pilha esta vazia
bool ehVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

// ramover livro do topo da pilha
Livraria verTopo(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia! Nenhum livro no topo.\n");
        exit(1);
    }
    return pilha->topo->livro;
}

// Função para excluir todos os elementos da pilha
void excluirPilha(Pilha* pilha) {
    while (!ehVazia(pilha)) {
        pop(pilha);
    }
    free(pilha);
}

// Menu
void menuPrincipal(Pilha* pilha) {
    int opcao;
    do {
        printf("\nMenu\n");
        printf("1. Inserir Livro no Topo\n");
        printf("2. Remover Livro do Topo\n");
        printf("3. Ver Livro do Topo\n");
        printf("4. Verificar se a Pilha esta Vazia\n");
        printf("5. Excluir Todos os Livros da Pilha\n");
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
                novoLivro.idLivro = (pilha->topo == NULL) ? 1 : pilha->topo->livro.idLivro + 1; // Gerar um ID simples
                push(pilha, novoLivro);
                printf("Livro inserido com sucesso!\n");
                break;
            }
            case 2: {
                if (ehVazia(pilha)) {
                    printf("Pilha esta vazia\n");
                } else {
                    Livraria livroRemovido = pop(pilha);
                    printf("Livro removido: Autor: %s, Título: %s\n", livroRemovido.autor, livroRemovido.titulo);
                }
                break;
            }
            case 3: {
                if (ehVazia(pilha)) {
                    printf("Pilha esta vazia\n");
                } else {
                    Livraria livroTopo = verTopo(pilha);
                    printf("Livro no topo: Autor: %s, Título: %s\n", livroTopo.autor, livroTopo.titulo);
                }
                break;
            }
            case 4: {
                if (ehVazia(pilha)) {
                    printf("A pilha esta vazia\n");
                } else {
                    printf("A pilha nao esta vazia\n");
                }
                break;
            }
            case 5: {
                excluirPilha(pilha);
                pilha = criarPilha();
                printf("Livros excluidos da pilha\n");
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
    Pilha* pilha = criarPilha();
    menuPrincipal(pilha);
    excluirPilha(pilha);
    return 0;
}