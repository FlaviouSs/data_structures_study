#include <iostream>
#include <ctime>

using namespace std;

int main(){

    int semente = time(0);
    srand(semente);
    int array[10];
    int aux;
    int menor;
    //Gerando numéros aleatórios e incicializando o array;
    for(int k = 0; k < 10; k++){
        array[k] =  (rand() % 50) + 1;
        cout << array[k] << " ";
    }
    cout << endl;
    //Parte do Bubble Sort
    for(int i = 0; i < 9; i++){
        menor = i;
        for(int j = i + 1; j < 10; j++){
            if(array[menor] > array[j]){
                menor = j;
            }
        }
        aux = array[i];
        array[i] = array[menor];
        array[menor] = aux;
    }
    //Impriminto array depois do Bublle Sort
    for(int k = 0; k < 10; k++){
        cout << array[k] << " ";
    }
    cout << endl;

    return 0;
}
