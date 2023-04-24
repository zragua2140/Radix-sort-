#include <iostream>
using namespace std;

// Functie om de maximale waarde in de invoerarray te vinden
int vindMaximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Hulpfunctie om Counting Sort toe te passen voor een bepaalde positie in de getallen
void telSorteer(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Tel het aantal voorkomens van elk cijfer in de positie exp
    for (int i = 0; i < n; ++i) {
        ++count[(arr[i] / exp) % 10];
    }

    // Bereken de cumulatieve som van de count array
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Bouw de output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        --count[(arr[i] / exp) % 10];
    }

    // Kopieer de output array naar de input array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Radix Sort implementatie
void radixSort(int arr[], int n) {
    int max = vindMaximum(arr, n);

    // Tel Sorteer voor elke positie van de minst significante naar de meest significante positie
    for (int exp = 1; max / exp > 0; exp *= 10) {
        telSorteer(arr, n, exp);

        // Print de huidige staat van de array
        cout << "Huidige staat van de array: ";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print de oorspronkelijke array
    cout << "Oorspronkelijke array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sorteer de array met Radix Sort
    radixSort(arr, n);

    // Print de uiteindelijk gesorteerde array
    cout << "Uiteindelijk gesorteerde array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

