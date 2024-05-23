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

// Struct para os nos da lista encadeada
typedef struct Node {
    Livraria livro;
    struct Node* next;
} Node;

// Segunda struct (lista encadeada)
typedef struct {
    Node* head;
    int size;
} Lista;

// Funcoes para manipulacao da lista encadeada
Lista* criarLista();
void menuPrincipal();
void inserirLivro(Lista*, Livraria livro);
void inserirLivroInicio(Lista*, Livraria livro);
void inserirId(Lista*, Livraria livro, int posicao);
void imprimirLivros(Lista*);
int buscarElemento(Lista*, char[]);
int atualizarElemento(Lista*, char[], Livraria livro);
int removerElemento(Lista*, char[]);
void excluirLista(Lista*);

int main() {
    Lista *lista = criarLista();
    int menu, local, posicao, qntEstoque;
    float preco;
    char autor[50], titulo[50], cor[20], nomeTitulo[50], resposta;
    Livraria livro;

    // Menu
    while (1) {
        printf("O que voce quer fazer? \n1. Inserir livro \n2. Remover livro \n3. Buscar livro \n4. Mostrar livros \n5. Atualizar livro \n6. Excluir lista\n");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Onde ira adicionar? \n1. No inicio da lista \n2. No final da lista \n3. Em uma posicao especifica \n");
                scanf("%d", &local);

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
                livro.idLivro = lista->size;

                switch (local) {
                    case 1:
                        inserirLivroInicio(lista, livro);
                        printf("Adicionado no inicio!\n");
                        break;
                    case 2:
                        inserirLivro(lista, livro);
                        printf("Adicionado no final!\n");
                        break;
                    case 3:
                        printf("Qual posicao sera inserido? ");
                        scanf("%d", &posicao);
                        inserirId(lista, livro, posicao);
                        printf("Adicionado na posicao %d!\n\n", posicao);
                        break;
                    default:
                        printf("Essa opcao nao existe!\n");
                        break;
                }
                break;
            case 2:
                if (lista->size != 0) {
                    printf("Digite o nome do livro que sera removido: \n");
                    scanf("%s", titulo);
                    removerElemento(lista, titulo);
                } else {
                    printf("Lista vazia\n");
                }
                break;
            case 3:
                if (lista->size != 0) {
                    printf("Digite o nome do livro para buscar: \n");
                    scanf("%s", titulo);
                    int busca = buscarElemento(lista, titulo);
                    if (busca != -1) {
                        printf("Livro encontrado na posicao %d!\n\n", busca);
                    } else {
                        printf("Livro nao encontrado\n");
                    }
                } else {
                    printf("Lista vazia\n");
                }
                break;
            case 4:
                imprimirLivros(lista);
                break;
            case 5:
                if (lista->size != 0) {
                    printf("Digite o nome do livro que os dados serao atualizados:\n");
                    scanf("%s", nomeTitulo);
                    printf("Agora preencha com os novos dados:\n");
                    printf("Autor: \n");
                    scanf("%s", autor);
                    printf("Titulo: \n");
                    scanf("%s", titulo);
                    printf("Quantidade em Estoque:  \n");
                    scanf("%d", &qntEstoque);
                    printf("Preco:  \n");
                    scanf("%f", &preco);
                    printf("Cor: \n");
                    scanf("%s", cor);

                    // Preenchendo a estrutura do livro
                    strcpy(livro.autor, autor);
                    strcpy(livro.titulo, titulo);
                    livro.qntEstoque = qntEstoque;
                    livro.preco = preco;
                    strcpy(livro.cor, cor);

                    atualizarElemento(lista, nomeTitulo, livro);
                    printf("Atualizado!\n\n");
                } else {
                    printf("Lista vazia\n");
                }
                break;
            case 6:
                printf("Deseja mesmo excluir a lista? (s/n)\n");
                scanf(" %c", &resposta);
                switch (resposta) {
                    case 's':
                    case 'S':
                        excluirLista(lista);
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

Lista* criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    if (nova == NULL) {
        printf("Nao tem espaco\n");
        exit(1);
    }
    nova->head = NULL;
    nova->size = 0;
    return nova;
}

void inserirLivro(Lista* lista, Livraria livro) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Nao tem espaco\n");
        exit(1);
    }
    novo->livro = livro;
    
    if (lista->head == NULL) {
        novo->next = novo; // Aponta para si mesmo
        lista->head = novo;
    } else {
        Node* atual = lista->head;
        while (atual->next != lista->head) {
            atual = atual->next;
        }
        atual->next = novo;
        novo->next = lista->head;
    }
    lista->size++;
}

void inserirLivroInicio(Lista* lista, Livraria livro) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Nao tem espaco\n");
        exit(1);
    }
    novo->livro = livro;

    if (lista->head == NULL) {
        novo->next = novo; // Aponta para si mesmo
        lista->head = novo;
    } else {
        Node* atual = lista->head;
        while (atual->next != lista->head) {
            atual = atual->next;
        }
        novo->next = lista->head;
        atual->next = novo;
        lista->head = novo;
    }
    lista->size++;
}

void inserirId(Lista* lista, Livraria livro, int posicao) {
    if (posicao < 0 || posicao > lista->size) {
        printf("Posicao fora do intervalo permitido\n");
        return;
    }

    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Nao tem espaco\n");
        exit(1);
    }
    novo->livro = livro;

    if (posicao == 0) {
        if (lista->head == NULL) {
            novo->next = novo; // Aponta para si mesmo
            lista->head = novo;
        } else {
            Node* atual = lista->head;
            while (atual->next != lista->head) {
                atual = atual->next;
            }
            novo->next = lista->head;
            atual->next = novo;
            lista->head = novo;
        }
    } else {
        Node* atual = lista->head;
        for (int i = 0; i < posicao - 1; i++) {
            atual = atual->next;
        }
        novo->next = atual->next;
        atual->next = novo;
    }
    lista->size++;
}

void imprimirLivros(Lista* lista) {
    if (lista->head == NULL) {
        printf("Lista vazia\n");
        return;
    }

    Node* atual = lista->head;
    int posicao = 0;
    
    printf("Detalhes dos livros na lista:\n");
    do {
        printf("Livro %d:\n", posicao + 1);
        printf("ID: %d\n", atual->livro.idLivro);
        printf("Autor: %s\n", atual->livro.autor);
        printf("Titulo: %s\n", atual->livro.titulo);
        printf("Quantidade em Estoque: %d\n", atual->livro.qntEstoque);
        printf("Preco: R$%.2f\n", atual->livro.preco);
        printf("Cor: %s\n", atual->livro.cor);
        printf("\n");
        atual = atual->next;
        posicao++;
    } while (atual != lista->head);
}

int buscarElemento(Lista* lista, char titulo[]) {
    if (lista->head == NULL) {
        return -1;
    }

    Node* atual = lista->head;
    int posicao = 0;
    
    do {
        if (strcmp(atual->livro.titulo, titulo) == 0) {
            printf("Esse livro esta na posicao %d\n", posicao);
            return posicao;
        }
        atual = atual->next;
        posicao++;
    } while (atual != lista->head);
    
    return -1;
}

int atualizarElemento(Lista* lista, char titulo[], Livraria novoLivro) {
    if (lista->head == NULL) {
        return 0;
    }

    Node* atual = lista->head;
    
    do {
        if (strcmp(atual->livro.titulo, titulo) == 0) {
            atual->livro = novoLivro;
            printf("Valor atualizado\n");
            return 1;
        }
        atual = atual->next;
    } while (atual != lista->head);
    
    return 0;
}

int removerElemento(Lista* lista, char titulo[]) {
    if (lista->head == NULL) {
        printf("Livro nao foi encontrado\n");
        return 0;
    }

    Node* atual = lista->head;
    Node* anterior = NULL;

    do {
        if (strcmp(atual->livro.titulo, titulo) == 0) {
            if (anterior == NULL) {
                Node* ultimo = lista->head;
                while (ultimo->next != lista->head) {
                    ultimo = ultimo->next;
                }
                if (ultimo == lista->head) {
                    lista->head = NULL;
                } else {
                    ultimo->next = atual->next;
                    lista->head = atual->next;
                }
            } else {
                anterior->next = atual->next;
            }
            free(atual);
            lista->size--;
            printf("Livro removido!\n\n");
            return 1;
        }
        anterior = atual;
        atual = atual->next;
    } while (atual != lista->head);
    
    printf("Livro nao foi encontrado\n");
    return 0;
}

void excluirLista(Lista* lista) {
    if (lista->head == NULL) {
        printf("Lista excluida!\n");
        return;
    }

    Node* atual = lista->head;
    Node* proximo;

    do {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    } while (atual != lista->head);
    
    free(lista);
    printf("Lista excluida!\n");
}
