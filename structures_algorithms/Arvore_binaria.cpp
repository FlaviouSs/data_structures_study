#include <iostream>

using namespace std;

struct no{
    int valor;
    struct no * dir;
    struct no * esq; 
};
typedef struct no * noPtr;

bool enderecoVazio(noPtr);
void inserir(noPtr *, int);
void listar_em_ordem(noPtr);

int main(){

    noPtr raiz_arvore = NULL;
    int escolha;
    int x;

    do{
        cout << "=====MENU=====" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Inserir elemento" << endl;
        cout << "2. Listar em ordem os elementos" << endl;
        cout << "==============" << endl;
        cout << "Digite sua escolha: ";
        cin >> escolha;
        switch(escolha){
            case 0:
                cout << "Saindo ..." << endl; break;
            case 1:
                cout << "Digite o valor do elemento: ";
                cin >> x;
                inserir(&raiz_arvore, x);
                cout << "Elemento adicionado!" << endl; break;
            case 2:
                listar_em_ordem(raiz_arvore);
                cout << endl;
        }


    }while(escolha != 0);

    return 0;
}

bool enderecoVazio(noPtr p){
    if(p == NULL)
        return true;
    else
        return false;
}

void inserir(noPtr *p , int x){
    if(enderecoVazio(*p)){
        *p = new no;
        (*p)->valor = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
    }else{
        if(x < ((*p)->valor))
            inserir(&((*p)->esq), x);
        else
            inserir(&((*p)->dir), x);
    }
}

void listar_em_ordem(noPtr p){
    if(!enderecoVazio(p)){
        listar_em_ordem(p->esq);
        cout << "\t" << p->valor;
        listar_em_ordem(p->dir);
    }
}
