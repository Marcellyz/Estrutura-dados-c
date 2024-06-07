//Alunas: Ana Carolina e Marcelly

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

// struct da pilha
typedef struct {
    Livraria* livros;
    int topo;
    int tam;
} Pilha;

// criar uma nova pilha
Pilha* criarPilha(int tamanho) {
    Pilha* nova = (Pilha*)malloc(sizeof(Pilha));
    if (nova == NULL) {
        printf("Nao tem espaco\n");
        exit(1);
    }
    nova->livros = (Livraria*)malloc(tamanho * sizeof(Livraria));
    if (nova->livros == NULL) {
        printf("Nao tem espaco\n");
        free(nova);
        exit(1);
    }
    nova->topo = -1;
    nova->tam = tamanho;
    return nova;
}

// inserir no topo
void push(Pilha* pilha, Livraria livro) {
    if (pilha->topo == pilha->tam - 1) {
        printf("Pilha esta cheia\n");
        return;
    }
    pilha->livros[++pilha->topo] = livro;
}

// remover do topo
Livraria pop(Pilha* pilha) {
    if (pilha->topo == -1) {
        printf("Pilha esta vazia\n");
        exit(1);
    }
    return pilha->livros[pilha->topo--];
}

// ver se a pilha esta vazia
bool ehVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

// ver o livro no topo
Livraria verTopo(Pilha* pilha) {
    if (pilha->topo == -1) {
        printf("Pilha esta vazia\n");
        exit(1); 
    }
    return pilha->livros[pilha->topo];
}

// excluir todos os elementos
void excluirPilha(Pilha* pilha) {
    free(pilha->livros);
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
        printf("4. Verificar se a Pilha está Vazia\n");
        printf("5. Excluir Todos os Livros da Pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
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
                novoLivro.idLivro = pilha->topo + 1; // Gerar um ID simples
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
                    printf("A pilha esta vazia.\n");
                } else {
                    printf("A pilha nao esta vazia \n");
                }
                break;
            }
            case 5: {
                excluirPilha(pilha);
                int tamanho;
                printf("Digite o novo tamanho da pilha: ");
                scanf("%d", &tamanho);
                pilha = criarPilha(tamanho);
                printf("Livros foram excluidos da pilha\n");
                break;
            }
            case 0: {
                printf("Saindo\n");
                break;
            }
            default: {
                printf("Essa opcao nao existe\n");
                break;
            }
        }
    } while (opcao != 0);
}

int main() {
    int tamanho; //determinar um tamanho pra pilha que esta sendo criada
    printf("Digite o tamanho da pilha: ");
    scanf("%d", &tamanho);
    Pilha* pilha = criarPilha(tamanho);
    menuPrincipal(pilha);
    excluirPilha(pilha);
    return 0;
}