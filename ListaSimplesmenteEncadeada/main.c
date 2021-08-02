#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "ListaSimplesmenteEncadeada.h"
#include <locale.h>

void opcoesDeTela() {
    printf("\n0 - Sair\n");
    printf("1 - Criar lista duplamente encadeada\n");
    printf("2 - Destruir e desalocar memoria da lista\n");
    printf("3 - Inserir cliente no final da lista\n");
    printf("4 - Inserir cliente no inicio da lista\n");
    printf("5 - Inserir cliente em uma posicao da lista\n");
    printf("6 - Buscar cliente atraves do CPF\n");
    printf("7 - Remover cliente atraves do CPF\n");
    printf("8 - Imprimir os dados de todos os clientes da lista\n");
    printf("9 - Obter tamanho da lista\n");
    printf("10 - Imprimir dados de um cliente atraves do CPF\n");
    printf("11 - Obter a posicao da lista em que um cliente encontra-se cadastrado\n");
    printf("12 - Editar os valores de um cliente em determinada posicao da lista\n");
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcoes,id,cpf,validar,posicao;
    char nome[100];
    ListaSimplesmenteEncadeada *lista = NULL;
    do {
        opcoesDeTela();
        scanf("%d",&opcoes);
        switch(opcoes) {
        case 0:
            printf("\nFim da execução do programa\n");
            break;
        case 1:
            lista = inicializar();
            break;
        case 2:
            destruirLista(&lista);
            break;
        case 3:
            fflush(stdin);
            printf("Nome: ");
            scanf("%[^\n]",nome);
            printf("CPF: ");
            scanf("%d",&cpf);
            printf("\n");
            validar = inserirNoFinal(lista,nome,cpf);
            if(validar == 1) {
                printf("----------------------------------\n");
                printf("Dado Inserido com sucesso no final\n");
                printf("----------------------------------\n");
            } else {
                printf("\nDado inválido\n");
            }
            break;
        case 4:
            fflush(stdin);
            printf("Nome: ");
            scanf("%[^\n]",nome);
            printf("CPF: ");
            scanf("%d",&cpf);
            printf("\n");
            validar = inserirNoInicio(lista,nome,cpf);
            if(validar == 1) {
                printf("-------------------------\n");
                printf("Dado Inserido com sucesso no inicio\n");
                printf("-------------------------\n");
            } else {
                printf("\nDado inválido\n");
            }
            break;
        case 5:
            printf("Posicao: ");
            scanf("%d",&posicao);
            fflush(stdin);
            printf("Nome: ");
            scanf("%[^\n]",nome);
            printf("CPF: ");
            scanf("%d",&cpf);
            validar = inserirNaPosicao(lista,posicao,nome,cpf);
            if(validar == 1) {
                printf("-------------------------\n");
                printf("Dado Inserido com sucesso no inicio\n");
                printf("-------------------------\n");
            } else {
                printf("\nDado inválido\n");
            }
            break;
        case 6:
            printf("\nBuscar Pelo CPF...\n");
            printf("CPF: ");
            scanf("%d",&cpf);
            validar = buscarPeloCpfImprimir(lista,cpf);
            if(validar==0) {
                printf("\nDado inválido\n");
            }
            break;
        case 7:
            printf("\Remover Pelo CPF...\n");
            printf("CPF: ");
            scanf("%d",&cpf);
            validar = removerPeloCpf(lista,cpf);
            if(validar==0) {
                printf("\nDado inválido\n");
            }
            break;
        case 8:
            printf("\nImprimir Lista...\n");

            validar = imprimirLista(lista);
            if(validar == 0) {
                printf("\nDado inválido\n");
            }
            break;
        case 9:
            validar = tamanhoLista(lista);
            if(validar == 0) {
                printf("\nDado inválido\n");
            }
            break;
        case 10:
            printf("\Imprimir Pelo CPF...\n");
            printf("CPF: ");
            scanf("%d",&cpf);
            printf("\n");
            validar = imprimirPeloCpf(lista,cpf);
            if(validar==0) {
                printf("\nDado inválido\n");
            }
            break;
        case 11:
            printf("\nImprimir Posição pelo CPF...\n");
            printf("CPF: ");
            scanf("%d",&cpf);
            printf("\n");
            validar = imprimirPosicaoPeloCpf(lista,cpf);
            if(validar==0) {
                printf("\nDado inválido\n");
            }
            break;
        case 12:
            printf("\n");
            printf("Posicao: ");
            scanf("%d",&posicao);
            fflush(stdin);
            printf("Nome: ");
            scanf("%[^\n]",nome);
            printf("CPF: ");
            scanf("%d",&cpf);
            printf("\n");
            validar = editarCliente(lista,posicao,nome,cpf);
            if(validar == 1) {
                printf("-------------------------\n");
                printf("Dado Alterado com sucesso no inicio\n");
                printf("-------------------------\n");
            } else {
                printf("\nDado inválido\n");
            }
            break;
        default:
            printf("\nOpção inválido\n");
        }
    } while(opcoes != 0);
    return 0;
}
