#include <iostream>

using namespace std;

struct no{
    int valor;
    struct no * prox;
    struct no * ant;
};
typedef struct no * noPtr;

void retirar(noPtr *, noPtr *);
void inserir(noPtr *, noPtr *);
bool listaVazia(noPtr, noPtr);
void listar(noPtr, noPtr);
void listar_um_a_um(noPtr, noPtr);

int main(){

    noPtr head = NULL, tail = NULL;

    int opcao;

    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Inserir nó" << endl;
        cout << "2. Retirar nó" << endl;
        cout << "3. Listar os nós" << endl;
        cout << "4. Listar um a um" << endl;
        cout << "0. Sair" << endl;
        cout << "Digite sua opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserir(&head, &tail);
                break;
            case 2:
                retirar(&head, &tail);
                break;
            case 3:
                listar(head, tail);
                break;
            case 4:
                listar_um_a_um(head, tail);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }

        cout << endl;

    } while (opcao != 0);

    return 0;
}

void retirar(noPtr *h, noPtr *t){

    noPtr aux;

    if(listaVazia(*h, *t))
        cout << "A lista está vazia!" << endl;
    else{
        if(*h == *t){
            aux = *h;
            *h = NULL;
            *t = NULL;
        }
        else{
            aux = *h; // A aux aponta para o primeiro nó
            *h = (*h)->prox; // O Head aponta para o próximo nó, fanzendo dele o primeiro nó
            (*h)->ant = *t; // O 'ant' do novo primeiro nó aponta para o ultimo nó 
            (*t)->prox = *h; // O 'prox' do ultimo nó aponta para o novo primeiro nó
        }
        delete(aux); // Desalocamos o antigo primeiro nó, retirando ele da lista
    }
}

void inserir(noPtr * h, noPtr * t){
    
    noPtr p = new no;

    cout << "Digite o valor do novo nó: ";
    cin >> p->valor;
    
    if(listaVazia(*h, *t)){
        *h = p; p->ant = *h; // Head aponta para o primeiro nó da lista, 'ant' do nó aponta para head, ou seja, ele mesmo
        *t = p; p->prox = *t; // Tail aponta para o primeiro nó da lista, 'prox' do nó aponta para tail, ou seja, ele mesmo
    }
    else{
        (*t)->prox = p; // O 'prox' do ultimmo nó aponta pro novo nó
        p->ant = *t; // O 'ant' do novo nó aponta para o ultimo nó
        p->prox = *h; // O 'prox' do novo nó aponta para o primeiro nó
        *t = p; // Tail finalmente aponta para o mais novo ultimo nó
        (*h)->ant = p; // O 'ant' do primeiro nó aponta para o mais novo ultimo nó
    }
}

bool listaVazia(noPtr h, noPtr t){
    if(h == NULL && t == NULL)
        return true;
    else
        return false;
}

void listar(noPtr h, noPtr t) {
    if (listaVazia(h, t)) {
        cout << "A lista está vazia!" << endl;
    }else{
        noPtr atual = h;
        do {
            cout << atual->valor << "  ";
            atual = atual->prox;
        } while (atual != h);
        cout << endl;
    }
}

void listar_um_a_um(noPtr h, noPtr t){
    int escolha;
    if(listaVazia(h, t))
        cout << "A lista está vazia!" << endl;
    else{
        do{
            cout << h->valor << endl;
            cin >> escolha;
            switch(escolha){
                case 1:
                    h = h->ant; break;
                case 2:
                    h = h->prox; break;
            }
        }while(escolha != 0);
    }
}
