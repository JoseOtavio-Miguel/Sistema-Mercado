#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;


typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;



Produto filtraProduto();
void visualizarCarrinho();
void listarProduto();
void cadastrarProduto();
void exibeProduto(Produto produto);
void ConcluirPedido();
int *contemNoCarrinho(int codigo);
void menu();


static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main()
{
    menu();
    return 0;
}



void cadastrarProduto(){
    printf("Cadastro de Produto\n");
    printf("===================\n");

    printf("Informe o nome do produto: \n");
    fgets(produtos[contador_produto].nome, 50, stdin);

    printf("Informe o preco do produto: \n");
    scanf("%f", &produtos[contador_produto].preco);

    printf("O produto %s foi cadastro com sucesso.\n", strtok(produtos[contador_produto].nome, "\n"));

    produtos[contador_produto].codigo = (contador_produto + 1);
    contador_produto++;
}


void listarProdutos(){
    if(contador_produto > 0){
        printf("Listagem de produtos.\n");
        printf("---------------------\n");
        for(int i=0; i<contador_produto; i++)
        {
            exibeProduto(produtos[i]);
            printf("---------------------\n");
            sleep(100);
        }
    }
    else{
        printf("Nao foram encontrados produtos.\n");
    }
}


void visualizarCarrinho(){
    if(contador_carrinho > 0 ){
        printf("Produtos do carrinho\n");
        printf("--------------------\n");
        for(int i=0; i<contador_carrinho; i++){
            exibeProduto(carrinho[i].produto);
            printf("Quantidade : %d \n", carrinho[i].quantidade);
            printf("--------------------\n");
            sleep(100);
        }
    }
    else{
        printf("Nao temos ainda produtos no carrinho.\n");
    }
}


void exibeProduto(Produto produto){
    printf("\nCodigo : %d", produto.codigo);
    printf("\nNome : %c", produto.nome);
    printf("\nPreco : %d", produto.preco);
}

void menu(){
    printf("\n+==================================+");
    printf("\n+=========  Bem-vindo(a)  =========+");
    printf("\n+========  Simple Market  =========+");
    printf("\n+==================================+\n");

    printf("\n+==================================+");
    printf("\n| [ 1 ] - Cadastrar Produto       |");
    printf("\n| [ 2 ] - Listar Produto          |");
    printf("\n| [ 3 ] - Exibe Produto           |");
    printf("\n| [ 4 ] - Visualizar Carrinho     |");
    printf("\n| [ 5 ] - Concluir Pedido         |");
    printf("\n+==================================+\n");
    printf("\nSelecione uma Opcao : [0 - Sair]");
}








