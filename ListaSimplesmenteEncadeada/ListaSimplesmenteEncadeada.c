#include "cliente.h"
#include <stdio.h>
#include "ListaSimplesmenteEncadeada.h"

ListaSimplesmenteEncadeada *inicializar() {
    ListaSimplesmenteEncadeada *li;
    li = (ListaSimplesmenteEncadeada *)malloc(sizeof(ListaSimplesmenteEncadeada));
    if (li != NULL) {
        li->inicio = NULL;
        printf("\nLista Criada com sucesso!\n");
        li->tamanho = 0;
    }
    return li;
}
void destruirLista(ListaSimplesmenteEncadeada **lista) {
    if (*lista != NULL) {
        Cliente *nodo;
        while ((*lista)->inicio != NULL) {
            nodo = (*lista)->inicio;
            (*lista)->inicio = nodo->proximo;
            free(nodo);
        }
        (*lista)->inicio = NULL;
        free(*lista);
        printf("\nLista destruida!\n");
    } else {
        printf("\nNao existe uma lista para destruir!\n");
    }

    *lista = NULL;
}
int inserirNoInicio(ListaSimplesmenteEncadeada *lista,char nome[100],int cpf) {
    if(lista == NULL) {
        printf("\nLista não existe\n");
        return 0;
    }
    Cliente *cliente = inserirValores(nome,lista->tamanho+1,cpf);
    cliente->proximo = lista->inicio;
    lista->inicio = cliente;
    lista->tamanho++;
    return 1;
}

int inserirNoFinal(ListaSimplesmenteEncadeada *lista,char nome[100], int cpf) {
    if(lista == NULL) {
        printf("\nLista não existe\n");
        return 0;
    }
    Cliente *no,*cliente = inserirValores(nome,lista->tamanho+1,cpf);
    cliente->proximo = NULL;
    if(lista->inicio == NULL) {
        lista->inicio = cliente;
    } else {
        no = lista->inicio;
        while(no->proximo!=NULL) {
            no = no->proximo;
        }
        no->proximo = cliente;
    }
    lista->tamanho++;
    return 1;
}

int inserirNaPosicao(ListaSimplesmenteEncadeada *lista,int posicao,char nome[100],int cpf) {
    if(lista == NULL) {
        printf("\nLista não existe\n");
        return 0;
    }
    Cliente *inicio,*anterior,*novo = inserirValores(nome,lista->tamanho+1,cpf);
    if(posicao == 1) {
        inserirNoInicio(lista, nome,cpf);
        return 1;
    }
    if(posicao > lista->tamanho) {
        printf("Posição maior que a lista");
        return 0;
    }
    inicio = lista->inicio;
    int contador = 1;
    while(inicio!=NULL) {
        if(contador == posicao) {
            anterior->proximo = novo;
            novo->proximo = inicio;
            lista->tamanho++;
            return 1;
        }
        contador++;
        anterior = inicio;
        inicio = inicio->proximo;
    }

    return 0;

}


int imprimirLista(ListaSimplesmenteEncadeada *lista) {
    if(lista == NULL) {
        printf("\nLista não existe\n");
        return 0;
    }
    Cliente *inicio = lista->inicio;

    while(inicio != NULL) {
        imprimirDadosCliente(inicio);
        inicio = inicio->proximo;
    }
    return 1;
}

int tamanhoLista(ListaSimplesmenteEncadeada *lista) {
    if(lista == NULL) {
        printf("\nLista não existe\n");
        return 0;
    }
    printf("\nTamanho da lista: %d\n",lista->tamanho);
    return 1;
}

int buscarPeloCpfImprimir(ListaSimplesmenteEncadeada *lista,int cpf) {
    if(lista == NULL) {
        printf("\nLista não existe\n");
        return 0;
    }
    Cliente *cliente = buscarPeloCpf(lista->inicio,cpf);
    if(cliente->cpf!=cpf) {
        printf("\nCPF não existe!\n");
        return 0;
    } else {
        printf("\nEsse CPF %d pertence a %s\n",cpf,cliente->nome);
        return 1;
    }
}

int removerPeloCpf(ListaSimplesmenteEncadeada *lista,int cpf) {
    if(lista == NULL) {
        printf("\nLista não existe\n");
        return 0;
    }
    Cliente *remover,*cliente = buscarPeloCpf(lista->inicio,cpf);
    if(cliente->cpf != cpf) {
        printf("\nCPF não existe!\n");
        return 0;
    } else {
        if(cliente == lista->inicio) {
            lista->inicio = cliente->proximo;
            cliente = NULL;
            return 1;
        }
        Cliente *inicio = lista->inicio;
        while(inicio!=NULL) {
            if(inicio->proximo == cliente) {
                inicio->proximo = cliente->proximo;
                cliente = NULL;
                lista->tamanho--;
                return 1;
            }
            inicio = inicio->proximo;
        }
        return 0;
    }

}

int imprimirPeloCpf(ListaSimplesmenteEncadeada *lista,int cpf) {
    if(lista == NULL) {
        printf("\nLista não existe\n");
        return 0;
    }
    Cliente *cliente = buscarPeloCpf(lista->inicio,cpf);
    if(cliente->cpf!=cpf) {
        printf("\nCPF não existe!\n");
        return 0;
    } else {
        imprimirDadosCliente(cliente);
        return 1;
    }
}

int imprimirPosicaoPeloCpf(ListaSimplesmenteEncadeada *lista,int cpf) {
    if(lista == NULL) {
        printf("\nLista não existe\n");
        return 0;
    }
    Cliente *cliente = buscarPeloCpf(lista->inicio,cpf);
    if(cliente->cpf!=cpf) {
        printf("\nCPF não existe!\n");
        return 0;
    } else {
        Cliente *inicio = lista->inicio;
        int posicao = 1;
        while(inicio!=NULL) {
            if(inicio == cliente) {
                printf("\nO cliente com o CPF: %d se encontra na posicao: %d da lista", cpf, posicao);
                return 1;
            }
            posicao++;
            inicio = inicio->proximo;
        }
        return 1;
    }
}

int editarCliente(ListaSimplesmenteEncadeada *lista,int posicao,char nome[100],int cpf) {
    if(lista == NULL) {
        printf("\nLista não existe\n");
        return 0;
    }
    Cliente *inicio,*anterior,*novo = inserirValores(nome,0,cpf);
    if(posicao > lista->tamanho) {
        printf("\nPosição maior que a lista\n");
        return 0;
    };
    inicio = lista->inicio;
    int contador = 1;
    while(inicio!=NULL) {
        if(contador == posicao) {

            novo->id = inicio->id;
            novo->proximo = inicio ->proximo;
            if(posicao == 1) {
                lista->inicio = novo;
            }else{
                anterior->proximo = novo;
            }
            inicio = NULL;
            imprimirDadosCliente(novo);
            return 1;
        }
        contador++;
        anterior = inicio;
        inicio = inicio->proximo;
    }

    return 0;
}
/*
ListaSimplesmenteEncadeada createPadrao(ListaSimplesmenteEncadeada *lista){
    Cliente *c1 = inicializarCliente();
    Cliente *c2 = inicializarCliente();
    Cliente *c3 = inicializarCliente();
    Cliente *c4 = inicializarCliente();
    Cliente *c5 = inicializarCliente();
    //Pessoa uma
    c1->cpf = 123456;
    strcpy(c1->nome,"Matheus ");
    c1->id = 1;
    c1->proximo = c2;
    //Pessoa dois
    c2->cpf = 12345678;
    c2->nome = "Alex Silva";
    c2->id = 2;
    c2->proximo = c3;
    //Pessoa tres
    c3->cpf = 456778;
    c3->nome = "Renan";
    c3->id = 3;
    c3->proximo = c4;
    // Pessoa quatro
    c4->cpf = 65789;
    c4->nome = "Giovanna Sobrenome Dificil";
    c4->id = 4;
    c4 -> proximo = c5;
    //Pessoa Cinco
    c5->cpf = 65789;
    c5->nome = "Giovanna Sobrenome Dificil";
    c5->id = 5;
    c5->proximo = NULL;
    lista->inicio = c1;
    lista->tamanho = 5;
}
*/
