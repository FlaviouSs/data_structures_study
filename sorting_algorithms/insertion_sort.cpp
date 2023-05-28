#include <iostream>
#include <ctime>

using namespace std;

int main(){

    int semente =  time(0);
    srand(semente);

    int v[10];
    int chave, i, j;

    for(int k = 0; k < 10; k++){
        v[k] = (rand() % 10) + 1;
        cout << v[k] << " ";
    }
    cout << endl;

    for(i = 1; i < 10; i++){
        chave = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }

    for(int k = 0; k < 10; k++){
        cout << v[k] << " ";
    }
    cout << endl;

    return 0;
}
