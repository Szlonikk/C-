#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    int **A, **B, **C, m, n, p, i, j, k, s;
    ifstream plik;
    ofstream wynik;
    // odczytujemy wymiary macierzy
    cout << "Podaj w danej kolejnosci wymiary macierzy ilosc wierszy A, ilosc kolumn A, ilosc kolumn B: ";
    cin >> m >> n >> p;

    // tworzymy macierze o odpowiednich rozmiarach

    A = new int *[m];
    B = new int *[n];
    C = new int *[m];

    for (i = 0; i < m; i++)
    {
        A[i] = new int[n];
        C[i] = new int[p];
    }

    for (i = 0; i < m; i++)
    {
        A[i] = new int[n];
        C[i] = new int[p];
    }

    for (i = 0; i < n; i++)
        B[i] = new int[p];

    // odczytujemy dane dla macierzy A
    plik.open("matrixA.txt");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            plik >> A[i][j];
        }
    plik.close();
    // odczytujemy dane dla macierzy B
    plik.open("matrixB.txt");
    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
        {
            plik >> B[i][j];
        }
    plik.close();
    cout << endl;

    // mnożymy macierz A przez B i wynik umieszczamy w C

    for (i = 0; i < m; i++)
        for (j = 0; j < p; j++)
        {
            s = 0;
            for (k = 0; k < n; k++)
                s += A[i][k] * B[k][j];
            C[i][j] = s;
        }

    // wyprowadzamy wynik mnożenia w C

    cout << "C = A x B:\n";

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
            cout << setw(6) << C[i][j];
        cout << endl;
    }
    wynik.open("matrixC.txt");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            wynik << C[i][j] << " ";
        }
        wynik << "\n";
    }
    wynik.close();
    // zwalniamy pamięć zajętą przez macierze

    for (i = 0; i < m; i++)
    {
        delete[] A[i];
        delete[] C[i];
    }

    for (i = 0; i < n; i++)
        delete[] B[i];
    delete[] A;
    delete[] B;
    delete[] C;
}