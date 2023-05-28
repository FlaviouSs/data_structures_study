#include <iostream>

using namespace std;

struct no{
    int info;
    struct no *proximo;
};
typedef struct no *noPtr;

noPtr topo = NULL;
noPtr ground = NULL;

void menu();
void enqueue();
void dequeue();
int listaVazia();
void listar();

int main(){

    int escolha;

    do{
        menu();
        cout << "Digite sua escolha: ";
        cin >> escolha;
        switch(escolha){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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

int listaVazia(){
    if(topo == NULL)
        return 1;
    else
        return 0;
}

void enqueue(){
    noPtr p = new no;

    cout << "Digite o valor do novo elemento: ";
    cin >> p->info;

    p->proximo = NULL;

    if(listaVazia()){
        topo = p;
        ground = p;
    }    
    else{
        ground->proximo = p;
        ground = p;
    }
}

void dequeue(){
    noPtr p;

    if(listaVazia())
        cout << "Fila está vazia!" << endl;
    else{
        p = topo;
        topo = p-> proximo;
        delete p;
        cout << "O elemento foi retirado da fila!" << endl;
    }
}

void menu(){
    cout << "--------------------------------------------" << endl;
    cout << "1 - Adicionar elemento a filha" << endl;
    cout << "2 - Remover elemento a filha" << endl;
    cout << "3 - Listar elementos da filha" << endl;
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
        }while((p != NULL));
    }
}
