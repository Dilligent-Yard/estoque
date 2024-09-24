# Sistema de Controle de Estoque

Este é um programa simples em C para gerenciar o estoque de produtos. Ele permite adicionar produtos, exibir o estoque atual e registrar vendas.

## Funcionalidades

1. Adicionar Produto: Permite adicionar um novo produto ao estoque, informando nome, quantidade e preço.
2. Exibir Estoque: Mostra uma lista de todos os produtos no estoque, incluindo nome, quantidade e preço.
3. Registrar Venda: Permite registrar a venda de um produto, atualizando a quantidade em estoque.

## Como usar

1. Compile o programa usando um compilador C (por exemplo, GCC):
   ```
   gcc controleestoque.c -o controleestoque
   ```

2. Execute o programa:
   ```
   ./controleestoque
   ```

3. Siga as instruções no menu para utilizar as diferentes funcionalidades:
   - Digite 1 para adicionar um novo produto
   - Digite 2 para exibir o estoque atual
   - Digite 3 para registrar uma venda
   - Digite 0 para sair do programa

## Estrutura do código

- O programa utiliza uma estrutura `Produto` para armazenar informações sobre cada item.
- A alocação de memória é dinâmica, permitindo um número flexível de produtos.
- As funções principais são:
  - `adicionarProduto`: Adiciona um novo produto ao estoque
  - `exibirEstoque`: Mostra todos os produtos no estoque
  - `registrarVenda`: Registra a venda de um produto

## Notas

- O programa usa alocação dinâmica de memória para gerenciar o array de produtos.
- Há verificações básicas de erro, como verificação de memória insuficiente.
- O programa não salva os dados em arquivo, então todas as informações são perdidas ao encerrar o programa.

## Melhorias futuras

- Implementar salvamento e carregamento de dados em arquivo.
- Adicionar mais funcionalidades, como atualização de preços e remoção de produtos.
- Melhorar a interface do usuário.
