#include <iostream>
#include <random>
using namespace std;

void randomize(int* x, int arrLen);
void sort(int* x, int arrLen);
void printArr(int* x, int arrLen);


int main() {
    srand(time(0));

    int x[10];
    int arrLen = sizeof(x) / 4;
    bool change;

    randomize(x, arrLen);

    cout << "Tablica przed sortowaniem: " << endl;
    printArr(x, arrLen);

    sort(x, arrLen);

    cout << "\nTablica po sortowaniu: " << endl;
    printArr(x, arrLen);


    return 0;
}

void randomize(int* x, int arrLen) {
    for(int i = 0; i < arrLen; i++) {
        x[i] = rand() % 1000;
    }
}

void sort(int* x, int arrLen) {
    bool change = false;
    int temp;

    char rodzajSortowania = 'D'; // Czy ma sortować od największej liczby czy od najmiejszej
    while(rodzajSortowania != 'W' && rodzajSortowania != 'M') {
        cout << "\nPodaj 'W' Jesli liczby mają być ułozone od najwiekszej do najmiejszej" <<
                "\nPodaj 'M' Jesli liczby mają być ułozone od najmiejszej do najwiekszej: ";
        cin >> rodzajSortowania;
    }
    
    if(rodzajSortowania == 'W') {
        do {
            change = false;
            for(int i = 0; i < arrLen - 1; i++) {
                if(x[i] < x[i + 1]) {
                    change = true;
    
                    temp = x[i];
                    x[i] = x[i + 1];
                    x[i + 1] = temp;
                }
            }
        } while(change);
    } else {
        do {
            change = false;
            for(int i = 0; i < arrLen - 1; i++) {
                if(x[i] > x[i + 1]) {
                    change = true;
    
                    temp = x[i];
                    x[i] = x[i + 1];
                    x[i + 1] = temp;
                }
            }
        } while(change);
    }
}

void printArr(int* x, int arrLen) {
    for(int i = 0; i < arrLen; i++) {
        cout << x[i] << ", ";
    }
}