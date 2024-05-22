//Alunas: Ana Carolina e Marcelly


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

// Primeira struct
typedef struct {
    char autor[50];
    char titulo[50];
    char cor[20];
    int qntEstoque;
    float preco;
    int idLivro;
} Livraria;

// Segunda struct
typedef struct {
    int id;
    Livraria *livros;
} Lista;

//declarando para o menu
Lista* criarLista();
void menuPrincipal();
int inserirLivro(Lista*, char[], char[], int, float, char[]);
int inserirLivroInicio(Lista*, char[], char[], int, float, char[]);
int inserirId(Lista*, char[], char[], int, float, char[], int);
void imprimirLivro(Lista*);
int buscarElemento(Lista*, char[]);
int atualizarElemento(Lista*, char[], char[], char[], int, float, char[]);
int removerElemento(Lista*, char[]);
void excluirLista(Lista*);

int main() {
    Lista *lista = criarLista();
    int menu, local, posicao, qntEstoque;
    float preco;
    char autor[50], titulo[50], cor[20], nomeTitulo[50], resposta;//declarando os elemntos do menu
//menu
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

                switch (local) {
                    case 1:
                        inserirLivroInicio(lista, autor, titulo, qntEstoque, preco, cor);
                        printf("Adicionado!\n");
                        break;
                    case 2:
                        inserirLivro(lista, autor, titulo, qntEstoque, preco, cor);
                        printf("Adicionado!\n");
                        break;
                    case 3:
                        printf("Qual posicao sera inserido? ");
                        scanf("%d", &posicao);
                        inserirId(lista, autor, titulo, qntEstoque, preco, cor, posicao);
                        printf("Adicionado!\n\n");
                        break;
                    default:
                        printf("Essa opcao nao existe!\n");
                        break;
                }
                break;
            case 2:
                if (lista->id != 0) {
                    printf("Digite o nome do livro que sera removido: \n");
                    scanf("%s", titulo);
                    removerElemento(lista, titulo);
                } else {
                    printf("Lista vazia\n");
                }
                break;
            case 3:
                if (lista->id != 0) {
                    printf("Digite o nome do livro para buscar: \n");
                    scanf("%s", titulo);
                    int busca = buscarElemento(lista, titulo);
                    if (busca != -1) {
                        printf("Encontrado!\n\n");
                    } else {
                        printf("Elemento nao encontrado\n");
                    }
                } else {
                    printf("Lista vazia\n");
                }
                break;
            case 4:
                imprimirLivro(lista);
                break;
            case 5:
                if (lista->id != 0) {
                    printf("Digite o nome do livro que os dados serao atualizados:\n");
                    scanf("%s", nomeTitulo);
                    printf("Agora preencha com os novos dados:\n");
                    printf("Autor: \n1");
                    scanf("%s", autor);
                    printf("Titulo: \n2");
                    scanf("%s", titulo);
                    printf("Quantidade em Estoque:  \n3");
                    scanf("%d", &qntEstoque);
                    printf("Preco:  \n4");
                    scanf("%f", &preco);
                    printf("Cor: \n5");
                    scanf("%s", cor);
                    atualizarElemento(lista, nomeTitulo, autor, titulo, qntEstoque, preco, cor);
                    printf("Atualizado!\n\n");
                } else {
                    printf("Lista vazia\n");
                }
                break;
            case 6: //verificando se o usuario deseja realmente excluir a lista apenas com um char
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
// Funcao para criar uma nova lista
Lista* criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));

    if (nova == NULL) {
        printf("Nao tem espaco\n");
        return NULL;
    }
    nova->id = 0;
    nova->livros = (Livraria*)malloc(TAM * sizeof(Livraria));
    if (nova->livros == NULL) {
        printf("Nao tem espaco\n");
        free(nova);  // Free the allocated memory for Lista structure
        return NULL;
    }
    return nova;
}
//inserir livro
int inserirLivro(Lista* lista, char autor[], char titulo[], int qntEstoque, float preco, char cor[]) {
	//vendo se a lista foi criada
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }
//vendo se tem espaco na lista
    if (lista->id < TAM) {
        lista->livros[lista->id].idLivro = lista->id;
        strcpy(lista->livros[lista->id].autor, autor);
        strcpy(lista->livros[lista->id].titulo, titulo);
        lista->livros[lista->id].qntEstoque = qntEstoque;
        lista->livros[lista->id].preco = preco;
        strcpy(lista->livros[lista->id].cor, cor);
        ++(lista->id);
    } else {
        printf("Espaco esgotado\n");
        return 0;
    }

    return 1;
}
//inserindo no inicio
int inserirLivroInicio(Lista* lista, char autor[], char titulo[], int qntEstoque, float preco, char cor[]) {
    int i;
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }
    if (lista->id < TAM) {
        for (i = lista->id; i > 0; --i) {
            lista->livros[i] = lista->livros[i-1];
        }
        lista->livros[0].idLivro = 0;
        strcpy(lista->livros[0].autor, autor);
        strcpy(lista->livros[0].titulo, titulo);
        lista->livros[0].qntEstoque = qntEstoque;
        lista->livros[0].preco = preco;
        strcpy(lista->livros[0].cor, cor);
        ++(lista->id);
    } else {
        printf("Espaco esgotado\n");
        return 0;
    }

    return 1;
}
//inserindo o id do livro
int inserirId(Lista *lista, char autor[], char titulo[], int qntEstoque, float preco, char cor[], int posicao) {
    int i;

    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }//contando o id para q seja colocado de acordo com o inserir
    if (lista->id < TAM) {
        if (posicao < lista->id) {
            for (i = lista->id; i > posicao; --i) {
                lista->livros[i] = lista->livros[i-1];
            }
            lista->livros[posicao].idLivro = posicao;
            strcpy(lista->livros[posicao].autor, autor);
            strcpy(lista->livros[posicao].titulo, titulo);
            lista->livros[posicao].qntEstoque = qntEstoque;
            lista->livros[posicao].preco = preco;
            strcpy(lista->livros[posicao].cor, cor);
            ++(lista->id);
        } else {
            printf("Posicao fora do intervalo permitido\n");
        }
    } else {
        printf("Espaco esgotado\n");
        return 0;
    }
    return 1;
}
//imprimir a lista
void imprimirLivro(Lista* lista) {
    int i;

    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return;
    }

    if (lista->id == 0) {
        printf("Lista vazia\n");
        return;
    }
    
    //vendo cada item dos livros
    printf("Detalhes dos livros na lista:\n");
    for (i = 0; i < lista->id; ++i) {
        printf("Livro %d:\n", i + 1);
        printf("ID: %d\n", lista->livros[i].idLivro);
        printf("Autor: %s\n", lista->livros[i].autor);
        printf("Titulo: %s\n", lista->livros[i].titulo);
        printf("Quantidade em Estoque: %d\n", lista->livros[i].qntEstoque);
        printf("Preco: R$%.2f\n", lista->livros[i].preco);
        printf("Cor: %s\n", lista->livros[i].cor);
        printf("\n");
    }
}

//buscando elemento pelo titulo
int buscarElemento(Lista *lista, char inserir[]) {
    int i;
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }
    //dando a posicao ao qual o livro esta
    for (i = 0; i < lista->id; ++i) {
        if (strcmp(lista->livros[i].titulo, inserir) == 0) {
            printf("Esse livro esta na posicao %d\n", i);
            return i;
        }
    }
    return -1;
}
//atualizando um elemento na lista

int atualizarElemento(Lista *lista, char busca[], char autor[], char titulo[], int qntEstoque, float preco, char cor[]) {
    int i;
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }//percorrendo para trocar os elementos
    for (i = 0; i < lista->id; ++i) {
        if (strcmp(lista->livros[i].titulo, busca) == 0) {
            strcpy(lista->livros[i].autor, autor);
            strcpy(lista->livros[i].titulo, titulo);
            lista->livros[i].qntEstoque = qntEstoque;
            lista->livros[i].preco = preco;
            strcpy(lista->livros[i].cor, cor);
            printf("Valor atualizado\n");
            return i;
        }
    }
    return 0;
}
//removendo um elemto
int removerElemento(Lista *lista, char remover[]) {
    int i;
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }
//percorrendo para ver qual ira remover e se ele esta na lista
    for (i = 0; i < lista->id; ++i) {
        if (strcmp(lista->livros[i].titulo, remover) == 0) {
            for (; i < lista->id-1; ++i) {
                lista->livros[i] = lista->livros[i+1];
            }//removendo
            --(lista->id);
            printf("Livro removido!\n\n");
            return 1;
        }
    }
    printf("valor nao foi encontrado\n");
    return 0;
}
//excluir lista
void excluirLista(Lista *lista) {
    if (lista != NULL)/*verificando se alista n esta vazia*/ {
        if (lista->livros != NULL) {
            free(lista->livros); //liberando o espaco da lista
        }
        free(lista);
    }
    printf("Lista excluida!\n");
}

