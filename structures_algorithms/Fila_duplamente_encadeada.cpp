#include <iostream>

using namespace std;

struct no{
    int valor;
    struct no * prox;
    struct no * ant;
};
typedef struct no * noPtr;

bool listaVazia(noPtr, noPtr);
void inserir(noPtr *, noPtr *); // Inserindo no head
void retirar(noPtr *, noPtr *); // Retirando no Tail O(1)
void listar(noPtr, noPtr);
void retirar_especifico(noPtr *, noPtr *);

int main(){

    noPtr head = NULL, tail = NULL;

    int op;

    do{
        cin >> op;

        switch(op){
            case 1:
                inserir(&head, &tail); break;
            case 2:
                retirar(&head, &tail); break;
            case 3:
                listar(head, tail); break;
            //case 4:
                //retirar_especifico(&head, &tail); break;
        }
    }while(op != 0);

    return 0;
}

bool listaVazia(noPtr h, noPtr t){
    if(h == NULL && t == NULL)
        return true;
    else
        return false;
}

void inserir(noPtr *h, noPtr *t){
    noPtr p = new no;

    cout << "Digite o valor a ser inserido: ";
    cin >> p->valor;
    p->ant = NULL;

    if(listaVazia(*h, *t)){
        p->prox = NULL;
        *h = p;
        *t = p;
    }
    else{
        p->prox = *h;
        (*h)->ant = p;
        *h = p;
    }
}

void retirar(noPtr *h, noPtr *t){
    noPtr aux;

    if(listaVazia(*h, *t))
        cout << "A fila está vazia !" << endl;
    else{
        aux = *t;
        if((*t)->prox == NULL && (*t)->ant == NULL){
            *h = NULL;
            *t = NULL;
        }
        else{
            *t = (*t)->ant;
            (*t)->prox = NULL;
        }
        delete(aux);
    }
}

void listar(noPtr h, noPtr t){
    if(listaVazia(h, t))
        cout << "A fila está vazia!" << endl;
    else
        while(t != NULL){
            cout << t->valor << "<-->";
            t = t->ant;
        }
        cout << endl;
}
// AINDA NÃO ESTÁ PRONTO 
/*
void retirar_especifico(noPtr *h, noPtr *t){
    int valor_procurado;
    noPtr aux, aux2;

    if(listaVazia(*h, *t))
        cout << "A fila está vazia!" << endl;
    else{

        cout << "Digite o valor do elemento procurado: ";
        cin >> valor_procurado;

        aux = *h;
        while(aux->valor != valor_procurado || aux != NULL){
            aux = aux->prox;
        }

        if(aux = NULL)
            cout << "Elemento não foi encontrado!" << endl;
        else
            // Apontando o próximo do (x - 1) para o (x + 1)
            aux2 = aux->ant;
            if(aux2 != NULL)
                aux2->prox = aux->prox;
            aux2 = aux->prox;
            if(aux2 != NULL)
                aux2->ant = aux->ant;

            delete(aux);
    }
}
*/