#include <iostream>
#include <ctime>
using namespace std;
void preencheVetor(int [], int); //Preenche vetor com número aleatório de 0 ~ 100
void mergesort(int [], int, int, int);
void intercala(int [], int, int, int, int);
void imprimeVetor(int [], int);
int main(){
    int tamanho;
    int v[50];
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;
    preencheVetor(v, tamanho);
    mergesort(v, 0, tamanho - 1, tamanho);
    imprimeVetor(v, tamanho);
    return 0;
}
void preencheVetor(int vetor[], int tamanho_vetor){
    int semente = time(0);
    srand(semente);
    for(int k = 0; k < tamanho_vetor; k++){
        vetor[k] =  (rand() % 100) + 1;
        cout << vetor[k] << " ";
    }
    cout << endl;
}
void mergesort(int vetor[], int inicio, int fim, int tamanho){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergesort(vetor, inicio, meio, tamanho);
        mergesort(vetor, meio + 1, fim, tamanho);
        intercala(vetor, inicio, fim, meio, tamanho);
    }
}
void intercala(int vetor[], int inicio, int fim, int meio, int tamanho){
    int i, aux[tamanho], posLivre = inicio, inicioA1 = inicio, inicioA2 = meio + 1;
    while(inicioA1 <= meio && inicioA2 <= fim){
        if(vetor[inicioA1] > vetor[inicioA2]){
            aux[posLivre] = vetor[inicioA2];
            inicioA2++;
        }
        else{
            aux[posLivre] = vetor[inicioA1];
            inicioA1++;
        }
        posLivre++;
    }
    for(i = inicioA1; i <= meio; i++){
        aux[posLivre] = vetor[i];
        posLivre++;
    }
    for(i = inicioA2; i <= fim; i++){
        aux[posLivre] = vetor[i];
        posLivre++;
    }
    for(i = inicio; i <= fim; i++){
        vetor[i] = aux[i];
    }
}
void imprimeVetor(int vetor[], int tamanho){
    for(int k = 0; k < tamanho; k++){
        cout << vetor[k] << " ";
    }
    cout << endl;
}
