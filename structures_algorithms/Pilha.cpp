#include <iostream>

using namespace std;

struct no{
    int info;
    struct no *proximo;
};
typedef struct no *noPtr;

noPtr topo = NULL;

void listar();
void menu();
void push();
void pop();
int listaVazia();

int main(){

    int escolha;

    do{
        menu();
        cout << "Digite sua escolha: ";
        cin >> escolha;
        switch(escolha){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                listar();
                break;
            default:
                break;
        }

    }while(escolha != 0);

    return 0;
}

void push(){
    noPtr p;
    int valor;

    p = new no;

    cout << "Digite o valor do elemento: ";
    cin >> p->info;

    p->proximo = topo;

    topo = p;
}

void pop(){
    noPtr p = topo;
    if(!listaVazia()){
        topo = topo->proximo;
        delete(p);
        cout << "O elemento foi retirado da pilha" << endl;
    }
    else
        cout << "Pilha vazia!" << endl;
}

int listaVazia(){
    if(topo == NULL)
        return 1;
    else
        return 0;
}

void menu(){
    cout << "--------------------------------------------" << endl;
    cout << "1 - Adicionar elemento a pilha" << endl;
    cout << "2 - Remover elemento a pilha" << endl;
    cout << "3 - Listar elementos da pilha" << endl;
    cout << "--------------------------------------------" << endl;
}

void listar(){
    if(!listaVazia()){
        int k = 1;
        noPtr p = topo;
        do{
            cout << k << " elemento: " << p->info << endl;
            k++;
            p = p->proximo;
        }while(p != NULL);
    }
    else
        cout << "A pilha está vazia!" << endl;
}
