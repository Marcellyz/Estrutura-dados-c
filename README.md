# Estrutura de Dados 🎲🥇✨

Repositório destinado à disciplina de Estrutura de Dados, onde realizamos a implementação de Listas, Pilhas e Filas.

## Estrutura do projeto
````
Estrutura_dados_c/
├── Fila/                                
|   ├── apontadores/
|   └── vetores/
├── Lista/                               
|   ├── DuplamenteEncadeada/
|   ├── SimplesmenteEncadeada/
|   ├── circular/
|   └── vetores/
└── Pilha/                                   
|   ├── apontadores/
|   └── vetores/
└── README.md
````

## Listas📝🌟
### Lista com Vetores

Uma lista com vetores armazena elementos em um array, permitindo acesso direto aos elementos por meio de índices. As operações básicas incluem inserção, remoção e busca de elementos.

- **Inserção**: Adiciona um elemento ao final da lista ou em uma posição específica, deslocando os elementos subsequentes.
- **Remoção**: Remove um elemento de uma posição específica, deslocando os elementos subsequentes para preencher o espaço.
- **Busca**: Encontra e retorna a posição de um elemento específico na lista.

### Lista Simplesmente Encadeada

Uma lista simplesmente encadeada consiste em uma série de nós onde cada nó contém um valor e um ponteiro para o próximo nó da sequência.

- **Inserção**: Adiciona um novo nó ao início, fim ou em uma posição específica da lista.
- **Remoção**: Remove um nó de uma posição específica, ajustando os ponteiros dos nós adjacentes.
- **Busca**: Percorre a lista para encontrar um elemento específico.

### Lista Duplamente Encadeada

Uma lista duplamente encadeada é semelhante à lista simplesmente encadeada, mas cada nó contém dois ponteiros: um para o próximo nó e outro para o nó anterior.

- **Inserção**: Adiciona um novo nó ao início, fim ou em uma posição específica da lista, ajustando ambos os ponteiros.
- **Remoção**: Remove um nó de uma posição específica, ajustando os ponteiros dos nós adjacentes.
- **Busca**: Permite busca em ambas as direções (para frente e para trás).

### Lista Circular

Uma lista circular é uma lista encadeada em que o último nó aponta para o primeiro nó, formando um ciclo.

- **Inserção**: Adiciona um novo nó ao início, fim ou em uma posição específica da lista, mantendo a estrutura circular.
- **Remoção**: Remove um nó de uma posição específica, ajustando os ponteiros dos nós adjacentes para manter a circularidade.
- **Busca**: Permite percorrer a lista de forma circular, voltando ao início após alcançar o final.

## Pilhas🪆🪫
### Pilha com Vetores

Uma pilha com vetores utiliza um array para armazenar elementos, seguindo o princípio LIFO (Last In, First Out).

- **Push**: Adiciona um elemento ao topo da pilha.
- **Pop**: Remove e retorna o elemento do topo da pilha.
- **Topo**: Retorna o elemento do topo sem removê-lo.
- **Verificar se está vazia**: Verifica se a pilha contém elementos.

### Pilha com Apontadores

Uma pilha com apontadores utiliza uma estrutura encadeada (nós) para armazenar elementos.

- **Push**: Adiciona um novo nó ao topo da pilha.
- **Pop**: Remove e retorna o nó do topo da pilha.
- **Topo**: Retorna o nó do topo sem removê-lo.
- **Verificar se está vazia**: Verifica se a pilha contém elementos.

## Filas 🔴✨
### Fila com Vetores

Uma fila com vetores utiliza um array para armazenar elementos, seguindo o princípio FIFO (First In, First Out).

- **Enqueue**: Adiciona um elemento ao final da fila.
- **Dequeue**: Remove e retorna o elemento do início da fila.

### Fila com Apontadores

Uma fila que utiliza ponteiros para armazenar elementos, seguindo o princípio FIFO (First In, First Out).

- **Enqueue**: Adiciona um elemento ao final da fila.
- **Dequeue**: Remove e retorna o elemento do início da fila.

Cada uma dessas implementações será explicada em detalhes nas respectivas seções de código deste repositório.
