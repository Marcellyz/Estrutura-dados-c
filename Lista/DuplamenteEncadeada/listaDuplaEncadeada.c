//Alunas: Ana Carolina e Marcelly


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//primeira struct
typedef struct {
    char autor[50];
    char titulo[50];
    char cor[20];
    int qntEstoque;
    float preco;
    int idLivro;
} Livraria;

// Ssegunda struct
typedef struct Node {
    Livraria livro;
    struct Node* ant;
    struct Node* prox;
} Node;

// terceira struct pra facilitar a lista duplamente
typedef struct {
    Node* comeco;
    Node* final;  
    int tam; //definir o tamanho
} Lista;

// declaracao da funcoes
Lista* criarLista();
void inserirElemento(Lista*, Livraria);
void inserirElementoID(Lista*, Livraria, int);
void inserirElementoInicio(Lista*, Livraria);
void inserirOrdenado(Lista*, Livraria);
void listarElementos(Lista*);
void listarElementosOrdemInversa(Lista*);
int removerElemento(Lista*, int);
int removerElementoNome(Lista*, char[]);
int atualizar(Lista*, int, Livraria);
Node* buscarElemento(Lista*, char[]);
int tamanho(Lista*);
void excluirLista(Lista*);
void menuPrincipal(Lista*);

int main() {
    Lista* lista = criarLista();
    menuPrincipal(lista);
    excluirLista(lista);
    return 0;
}

// funcao para criar uma nova lista
Lista* criarLista() {
    Lista* nova = (Lista*)malloc(sizeof(Lista));
    if (nova == NULL) {
        printf("Sem espaco\n");
        exit(1);
    }
    nova->comeco = NULL;
    nova->final = NULL;
    nova->tam = 0;
    return nova;
}

// inserir no final da lista
void inserirElemento(Lista* lista, Livraria livro) {
    inserirElementoID(lista, livro, lista->tam);
}

// inserir na posicao escolhida
void inserirElementoID(Lista* lista, Livraria livro, int posicao) {
    if (posicao < 0 || posicao > lista->tam) {
        printf("posicao nao existe\n");
        return;
    }

    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Sem espaco\n");
        exit(1);
    }
    novo->livro = livro;
    
//verificando se ja existem elementos para inseriri na posicao desejada
    if (lista->tam == 0) {
        novo->ant = NULL;
        novo->prox = NULL;
        lista->comeco = novo;
        lista->final = novo;
    } else if (posicao == 0) {
        novo->ant = NULL;
        novo->prox = lista->comeco;
        lista->comeco->ant = novo;
        lista->comeco = novo;
    } else if (posicao == lista->tam) {
        novo->ant = lista->final;
        novo->prox = NULL;
        lista->final->prox = novo;
        lista->final = novo;
    } else {
        Node* p = lista->comeco;
        for (int i = 0; i < posicao - 1; i++) {
            p = p->prox;
        }
        novo->ant = p;
        novo->prox = p->prox;
        p->prox->ant = novo;
        p->prox = novo;
    }
    lista->tam++;
}

// inserir  no inicio
void inserirElementoInicio(Lista* lista, Livraria livro) {
    inserirElementoID(lista, livro, 0);
}

// inserir em ordem alfabetica
void inserirOrdenado(Lista* lista, Livraria livro) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    novo->livro = livro;

    if (lista->tam == 0 || strcmp(lista->comeco->livro.titulo, livro.titulo) >= 0) {
        novo->ant = NULL;
        novo->prox = lista->comeco;
        if (lista->comeco != NULL)
            lista->comeco->ant = novo;
        else
            lista->final = novo; // se a lista esta vazia
        lista->comeco = novo;
    } else {
        Node* p = lista->comeco;
        while (p->prox != NULL && strcmp(p->prox->livro.titulo, livro.titulo) < 0) {
            p = p->prox;
        }
        novo->ant = p;
        novo->prox = p->prox;
        if (p->prox != NULL)
            p->prox->ant = novo;
        else
            lista->final = novo;
        p->prox = novo;
    }
    lista->tam++;
}

// visualiza todos os alementos da lista
void listarElementos(Lista* lista) {
    printf("Lista de Livros:\n");
    Node* p = lista->comeco;
    while (p != NULL) {
        printf("Autor: %s, Título: %s, Estoque: %d, Preço: %.2f, Cor: %s\n", p->livro.autor, p->livro.titulo, p->livro.qntEstoque, p->livro.preco, p->livro.cor);
        p = p->prox;
    }
    printf("\n");
}

// lista todos os elementos
void listarElementosOrdemInversa(Lista* lista) {
    printf("Lista de Livros (Ordem Inversa):\n");
    Node* p = lista->final;
    while (p != NULL) {
        printf("Autor: %s, Título: %s, Estoque: %d, Preço: %.2f, Cor: %s\n", p->livro.autor, p->livro.titulo, p->livro.qntEstoque, p->livro.preco, p->livro.cor);
        p = p->ant;
    }
    printf("\n");
}

// remover o elementos pela posicao
int removerElemento(Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tam) {
        printf("posicao nao existe\n");
        return 0;
    }

    Node* p = lista->comeco;
    if (posicao == 0) {
        lista->comeco = p->prox;
        if (lista->comeco != NULL)
            lista->comeco->ant = NULL;
        else
            lista->final = NULL;
        free(p);
    } else if (posicao == lista->tam - 1) {
        p = lista->final;
        lista->final = p->ant;
        lista->final->prox = NULL;
        free(p);
    } else {
        for (int i = 0; i < posicao; i++) {
            p = p->prox;
        }
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        free(p);
    }
    lista->tam--;
    return 1;
}

// remover elemento pelo nome
int removerElementoNome(Lista* lista, char titulo[]) {
    Node* p = lista->comeco;
    int posicao = 0;
    while (p != NULL) {
        if (strcmp(p->livro.titulo, titulo) == 0) {
            removerElemento(lista, posicao);
            return 1;
        }
        p = p->prox;
        posicao++;
    }
    printf("Livro nao encontrado\n");
    return 0;
}

// atualiza os campos
int atualizar(Lista* lista, int posicao, Livraria livro) {
    if (posicao < 0 || posicao >= lista->tam) {
        printf("posicao nao existe\n");
        return 0;
    }

    Node* p = lista->comeco;
    for (int i = 0; i < posicao; i++) {
        p = p->prox;
    }
    p->livro = livro;
    return 1;
}

// busca o elemento
Node* buscarElemento(Lista* lista, char titulo[]) {
    Node* p = lista->comeco;
    while (p != NULL) {
        if (strcmp(p->livro.titulo, titulo) == 0) {
            return p;
        }
        p = p->prox;
    }
    return NULL;
}

// ver a quantidade
int tamanho(Lista* lista) {
    return lista->tam;
}

// excluir a lista
void excluirLista(Lista* lista) {
    Node* p = lista->comeco;
    while (p != NULL) {
        Node* temp = p;
        p = p->prox;
        free(temp);
    }
    free(lista);
}

// menu
void menuPrincipal(Lista* lista) {
    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Inserir Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Listar Livros em Ordem Inversa\n");
        printf("4. Remover Livro\n");
        printf("5. Atualizar Livro\n");
        printf("6. Buscar Livro\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        Livraria livro;
        char titulo[50];
        int posicao;
        Node* resultado;

        switch (opcao) {
            case 1:
                printf("Digite o autor: ");
                scanf(" %[^\n]", livro.autor);
                printf("Digite o titulo: ");
                scanf(" %[^\n]", livro.titulo);
                printf("Digite a cor: ");
                scanf(" %[^\n]", livro.cor);
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &livro.qntEstoque);
                printf("Digite o preco: ");
                scanf("%f", &livro.preco);
                livro.idLivro = lista->tam + 1; // id que atualiza
                inserirElemento(lista, livro);
                break;

            case 2:
                listarElementos(lista);
                break;

            case 3:
                listarElementosOrdemInversa(lista);
                break;

            case 4:
                printf("Digite o titulo do livro a ser removido: ");
                scanf(" %[^\n]", titulo);
                removerElementoNome(lista, titulo);
                break;

            case 5:
                printf("Digite onde deseja colocar a posicao do livro a ser atualizado (começando de 0): ");
                scanf("%d", &posicao);
                printf("Digite o autor: ");
                scanf(" %[^\n]", livro.autor);
                printf("Digite o titulo: ");
                scanf(" %[^\n]", livro.titulo);
                printf("Digite a cor: ");
                scanf(" %[^\n]", livro.cor);
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &livro.qntEstoque);
                printf("Digite o preco: ");
                scanf("%f", &livro.preco);
                livro.idLivro = posicao + 1;
                atualizar(lista, posicao, livro);
                break;

            case 6:
                printf("Digite o título do livro que vai ser procurado: ");
                scanf(" %[^\n]", titulo);
                resultado = buscarElemento(lista, titulo);
                if (resultado != NULL) {
                    printf("Livro encontrado: Autor: %s, Titulo: %s, Estoque: %d, Preco: %.2f, Cor: %s\n", resultado->livro.autor, resultado->livro.titulo, resultado->livro.qntEstoque, resultado->livro.preco, resultado->livro.cor);
                } else {
                    printf("Livro não encontrado!\n");
                }
                break;

            case 7:
                printf("Saindo do sistema\n");
                break;

            default:
                printf("Essa opcao nao existe\n");
                break;
        }
    } while (opcao != 7);
}
