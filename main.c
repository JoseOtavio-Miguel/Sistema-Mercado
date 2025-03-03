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


void cadastrarProduto();
void comprarProduto();
void listarProduto();
void comprarProduto();
void visualizarCarrinho();
void exibeProduto(Produto produto);

int *contemNoCarrinho(int codigo);
void ConcluirPedido();
void menu();
Produto filtraProduto(int codigo);


static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];



int main()
{
    int opcao;
    menu();
    while ((scanf("%d", &opcao) != 1 || opcao != 0)){

        switch (opcao){
        case 0:
            printf(" Saindo do Programa... \n");
            sleep(2);
            exit(0);
        case 1:
            cadastrarProduto();
            break;
        case 2:
            comprarProduto();
            break;
        case 3:
            listarProduto();
            break;
        case 4:
            visualizarCarrinho();
            break;
        case 5:
            ConcluirPedido();
            break;
        default:
            printf("\nEntrada invalida!\nPor favor, Selecione uma Opcao : [0 - Sair]: \n");
            sleep(2);
            break;
        }
        sleep(1);
        system("cls");
        menu();
    }

    return 0;
}


void cadastrarProduto() {
    printf("Cadastro de Produto\n");
    printf("===================\n");

    printf("Informe o nome do produto: \n");
    while (getchar() != '\n' && !feof(stdin));
    fgets(produtos[contador_produto].nome, 50, stdin);

    size_t len = strlen(produtos[contador_produto].nome);
    if (len > 0 && produtos[contador_produto].nome[len - 1] == '\n') {
        produtos[contador_produto].nome[len - 1] = '\0';
    }

    printf("Informe o preco do produto: \n");
    while (scanf("%f", &produtos[contador_produto].preco) != 1 || produtos[contador_produto].preco < 0) {
        printf("Preco invalido! Digite um numero positivo: \n");

        while (getchar() != '\n');
    }

    produtos[contador_produto].codigo = contador_produto + 1;
    printf("\nO produto foi cadastrado com sucesso!\n");
    printf("Codigo : %d\n", produtos[contador_produto].codigo);
    printf("Nome : %s\n", produtos[contador_produto].nome);
    printf("Preco : %.2f\n", produtos[contador_produto].preco);

    contador_produto++;
}


void listarProduto(){
    if(contador_produto > 0){
        printf("Listagem de produtos.\n");
        printf("---------------------\n");
        for(int i=0; i<contador_produto; i++)
        {
            printf("\nCodigo : %d", produtos[i].codigo);
            printf("\nNome : %s", produtos[i].nome);
            printf("\nPreco : %.2f", produtos[i].preco);
            printf("\n---------------------\n");
            printf("\nAguarde...\n");
        }
    }
    else{
        printf("\nNao foram encontrados produtos.\n");
    }
}


void comprarProduto() {
    if (contador_produto > 0) {
        printf("\nInforme o codigo do produto que deseja adicionar ao carrinho.\n");
        printf("\n=========== Produtos Disponiveis =============\n");

        for (int i=0; i<contador_produto; i++) {
            exibeProduto(produtos[i]);
        }

        int codigo;
        printf("Digite o codigo do Produto : ");
        scanf("%d", &codigo);

        Produto novo_produto = filtraProduto(codigo);
        int *prod_no_carrinho = contemNoCarrinho(codigo);

        if(prod_no_carrinho[0] == 1) {
            carrinho[prod_no_carrinho[1]].quantidade++;
            printf("Produto adicionado com Sucesso !");
        }
        else {
            carrinho[contador_carrinho].produto = novo_produto;
            carrinho[contador_carrinho].quantidade = 1;
            contador_carrinho++;
            printf("Produto registrado com Sucesso !");
        }
    }
    else {
        printf("Produtos nao Cadastrados");
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
            sleep(2);
        }
    }
    else{
        printf(" Carrinho esta Vazio ! \n");
        sleep(2);
    }
}


void exibeProduto(Produto produto){
    printf("\nCodigo : %d", produto.codigo);
    printf("\nNome : %s", produto.nome);
    printf("\nPreco : %.2f", produto.preco);
    printf("\n---------------------\n");
}


int *contemNoCarrinho(int codigo){
    int static posicao[] = {0, 0};
    for(int i=0; i< contador_carrinho; i++){
        if(carrinho[i].produto.codigo == codigo){
            //Retorna a posicao do produto no carrinho
            posicao[0] = 1;
            posicao[1] = i;
        }
    }
    return posicao;
}

void ConcluirPedido(){
    //Verifica se o carrinho esta vazio
    if (contador_carrinho > 0 ){
        float valorTotal = 0.0;
        for(int i=0; i<contador_carrinho; i++){
            valorTotal += carrinho[i].produto.preco * carrinho[i].quantidade;
        }

        printf(" Produtos no carrinho : ");
        visualizarCarrinho();

        printf("\n VALOR TOTAL : R$: %.2f", valorTotal);
        printf("\n IMPRIMINDO NOTA FISCAL ...");

    }
    else{
        printf("Carrinho Vazio");
        sleep(3);
    }
}

Produto filtraProduto(int codigo) {
    for (int i = 0; i < contador_produto; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i];
        }
    }
}


void menu(){
    printf("\n+==================================+");
    printf("\n+=========  Bem-vindo(a)  =========+");
    printf("\n+========  Simple Market  =========+");
    printf("\n+==================================+\n");

    printf("\n+==================================+");
    printf("\n| [ 1 ] - Cadastrar Produto       |");
    printf("\n| [ 2 ] - Comprar Produto         |");
    printf("\n| [ 3 ] - Listar Produto          |");
    printf("\n| [ 4 ] - Visualizar Carrinho     |");
    printf("\n| [ 5 ] - Concluir Pedido         |");
    printf("\n+==================================+\n");
    printf("\nSelecione uma Opcao : [0 - Sair]");
}








