# Simple Market - Sistema de Compra de Produtos

## Descrição
Este projeto consiste em um sistema simples de mercado desenvolvido em C, onde o usuário pode cadastrar produtos, listar produtos, comprar produtos e visualizar o carrinho de compras. O sistema oferece funcionalidades de adição ao carrinho, visualização do pedido e cálculo do valor total da compra.

## Funcionalidades

- **Cadastrar Produto**: Permite o cadastro de novos produtos, incluindo nome, preço e código.
- **Comprar Produto**: O usuário pode escolher um produto da lista disponível e adicioná-lo ao carrinho de compras.
- **Listar Produto**: Exibe todos os produtos cadastrados no sistema com código, nome e preço.
- **Visualizar Carrinho**: Permite ao usuário visualizar todos os produtos que foram adicionados ao carrinho, incluindo a quantidade de cada item.
- **Concluir Pedido**: Exibe o resumo do pedido, calcula o valor total da compra e imprime a "nota fiscal".

## Estrutura do Arquivo

O código fonte está organizado em diversas funções que implementam as funcionalidades do sistema. As principais partes do código incluem:

- **Produto**: Estrutura que armazena os dados do produto, como código, nome e preço.
- **Carrinho**: Estrutura que armazena o produto e a quantidade de cada item no carrinho de compras.
- **Funções**:
  - **cadastrarProduto()**: Função responsável pelo cadastro de novos produtos.
  - **comprarProduto()**: Função que permite adicionar produtos ao carrinho de compras.
  - **listarProduto()**: Função que lista todos os produtos cadastrados.
  - **visualizarCarrinho()**: Exibe o conteúdo do carrinho de compras.
  - **ConcluirPedido()**: Exibe o resumo da compra e o valor total.
  - **exibeProduto()**: Exibe os detalhes de um produto.
  - **filtraProduto()**: Filtra o produto com base no código informado pelo usuário.
  - **contemNoCarrinho()**: Verifica se um produto já está presente no carrinho.
  - **menu()**: Exibe o menu principal com opções para o usuário.
    

## Autor

Desenvolvido por **José Otávio Miguel**.

## Licença

Este projeto está sob a **Licença MIT**.
