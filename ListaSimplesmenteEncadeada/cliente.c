#include "cliente.h"
#include <stdio.h>
#include "ListaSimplesmenteEncadeada.h"
void imprimirDadosCliente(Cliente* c){
    printf("Nome: %s\n", c->nome);
	printf("ID: %d\n", c->id);
	printf("CPF: %d\n\n", c->cpf);
}

Cliente *inicializarCliente(){
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    return cliente;
}

Cliente *inserirValores(char nome[100], int id,int cpf){
    Cliente *cliente = inicializarCliente();
    strcpy(cliente->nome,nome);
    cliente->id = id;
    cliente->cpf = cpf;
    return cliente;
}

Cliente *buscarPeloCpf(Cliente *inicio,int cpf){
    Cliente *cliente = inicio;
    while(cliente!=NULL){
        if(cliente->cpf == cpf){
            return cliente;
        }
        cliente = cliente->proximo;
    }
    return cliente;
}



