#include <iostream>

using namespace std;

struct no{
    int valor;
    struct no * prox;
};
typedef struct no * noPtr;

bool listaVazia(noPtr);
void inserir(noPtr *);
void consultar(noPtr);

int main(){

    noPtr topo = NULL;
    int op;

    do{
        cin >> op;
        
        switch(op){
            case 1:
                inserir(&topo); break;
            case 2:
                consultar(topo); break;
        }
    }while(op != 0);

    return 0;
}

void consultar(noPtr t){
    int x;
    bool achei = false;

    if(listaVazia(t))
        cout << "A lista está vazia!" << endl;
    else{
        cout << "Digite o valor do elemento a ser achado: ";
        cin >> x;
        while((t != NULL) && (achei == false)){
            if(t->valor == x)
                achei = true;
            t = t->prox;
        }
        if(!achei)
            cout << "Não encontrei o elemento!" << endl;
        else
            cout << "O elemento foi encontrado!" << endl;
    }
}

void inserir(noPtr *t){
    noPtr aux, ant, p = new no;

    cout << "Digite o valor do elemento: ";
    cin >> p->valor;

    if(listaVazia(*t)){
        p->prox = NULL;
        *t = p;
    }
    else{
        aux = *t;
        while((aux != NULL) && (p->valor > aux->valor)){
            ant = aux;
            aux = aux->prox;
        }

        if(aux == *t){
            p->prox = aux;
            *t = p;
        }
        else{
            p->prox = aux;
            ant->prox = p;
        }
    }

}

bool listaVazia(noPtr t){
    if(t == NULL)
        return true;
    else
        return false;
}