typedef struct{
    int tamanho;
    Cliente *inicio;
}ListaSimplesmenteEncadeada;

ListaSimplesmenteEncadeada *inicializar();

void destruirLista(ListaSimplesmenteEncadeada **lista);
int inserirNoInicio(ListaSimplesmenteEncadeada *lista,char nome[100],int cpf);

int imprimirLista(ListaSimplesmenteEncadeada *lista);

int tamanhoLista(ListaSimplesmenteEncadeada *lista);

int inserirNoFinal(ListaSimplesmenteEncadeada *lista,char nome[100],int cpf);

int inserirNaPosicao(ListaSimplesmenteEncadeada *lista,int posicao,char nome[100],int cpf);

int buscarPeloCpfImprimir(ListaSimplesmenteEncadeada *lista,int cpf);

int removerPeloCpf(ListaSimplesmenteEncadeada *lista,int cpf);

int imprimirPeloCpf(ListaSimplesmenteEncadeada *lista,int cpf);

int imprimirPosicaoPeloCpf(ListaSimplesmenteEncadeada *lista,int cpf);

int editarCliente(ListaSimplesmenteEncadeada *lista,int posicao,char nome[100],int cpf);
