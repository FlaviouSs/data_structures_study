#include <iostream>

using namespace std;

struct no{
    int valor;
    struct no * prox;
};
typedef struct no * noPtr;

bool listaVazia(noPtr, int);
void inserir(noPtr *, int *);
void listar_um_por_um(noPtr);
void remover(noPtr *, int *);

int main(){

    noPtr topo = NULL;
    int quantidade = 0;
    int opcao;

    do {
        cout << "Menu:" << endl;
        cout << "1. Inserir nó" << endl;
        cout << "2. Remover nó" << endl;
        cout << "3. Listar nós" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserir(&topo, &quantidade);
                break;
            case 2:
                int valorRemover;
                remover(&topo, &quantidade);
                break;
            case 3:
                cout << "Listagem dos nós:" << endl;
                listar_um_por_um(topo);
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
        cout << endl;

    } while (opcao != 0);

    return 0;
}

void remover(noPtr * t, int * q){
    noPtr aux = *t;

    if(listaVazia(*t, *q)){
        cout << "A lista está vazia!" << endl;
    }
    else{
        if(*q == 1)
            *t = NULL;
        else{
            while(aux->prox != *t){
                aux = aux->prox;
            }

            aux->prox = (*t)->prox;
            aux = *t;
            *t = (*t)->prox;
        }
        delete(aux);
        *q = *q - 1;
    }
}

void listar_um_por_um(noPtr t){
    int escolha;
    if(listaVazia(t, 0)){
        cout << "A lista está vazia!";
    }
    else{
        do{
            cin >> escolha;
            if(escolha == 1){
                cout << t->valor << " ";
                t = t->prox;
            }
        }while(escolha != 0);
    };
}

void inserir(noPtr * t, int * q){
    noPtr aux, p = new no;
    
    cout << "Digite o valor do elemento: ";
    cin >> p->valor;

    if(listaVazia(*t, *q)){
        *t = p;
        p->prox = *t;
    }
    else{
        p->prox = *t;
        aux = *t;
        
        while(aux->prox != *t){
            aux = aux->prox;
        }
        aux->prox = p;
        *t = p;
    }

    *q = *q + 1;
}

bool listaVazia(noPtr t, int q){
    if(t == NULL && q == 0)
        return true;
    else
        return false;
}
