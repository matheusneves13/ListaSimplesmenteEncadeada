typedef struct{
    char nome[100];
    int id;
    int cpf;
    struct Cliente *proximo;
}Cliente;

void imprimirDadosCliente(Cliente* c);

Cliente *inicializarCliente();

Cliente *inserirValores(char nome[100], int id,int cpf);

Cliente *buscarPeloCpf(Cliente *inicio,int cpf);

