#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////////////
// BUBBLE SORT
// Metode pengurutan sederhana yang membandingkan dan
// menukar pasangan elemen bersebelahan secara berulang
// hingga tidak ada lagi elemen yang perlu ditukar.
// Cocok untuk data kecil, kompleksitas O(n^2).
/////////////////////////////////////////////////////////
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

/////////////////////////////////////////////////////////
// BUBBLE SORT (STRING)
// Prinsip kerja sama seperti bubble sort angka, namun
// menggunakan strcmp() untuk membandingkan string.
// Digunakan untuk mengurutkan array kata.
/////////////////////////////////////////////////////////
void bubble_sort_str(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

/////////////////////////////////////////////////////////
// SELECTION SORT
// Mengurutkan data dengan cara memilih elemen terkecil
// dari sisa array dan menempatkannya di posisi saat ini.
// Sederhana tapi kurang efisien untuk data besar.
/////////////////////////////////////////////////////////
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        int tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
    }
}

/////////////////////////////////////////////////////////
// SELECTION SORT (STRING)
// Versi string dari selection sort, menggunakan strcmp()
// untuk menentukan posisi kata terkecil dalam sisa array.
/////////////////////////////////////////////////////////
void selection_sort_str(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (strcmp(arr[j], arr[minIdx]) < 0) minIdx = j;
        char *tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
    }
}

/////////////////////////////////////////////////////////
// INSERTION SORT
// Menyisipkan elemen ke bagian array yang sudah terurut
// dengan cara menggeser elemen yang lebih besar.
// Efisien untuk data yang hampir terurut.
/////////////////////////////////////////////////////////
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/////////////////////////////////////////////////////////
// INSERTION SORT (STRING)
// Versi string dari insertion sort, menyisipkan kata
// ke posisi yang tepat di bagian yang sudah terurut.
/////////////////////////////////////////////////////////
void insertion_sort_str(char *arr[], int n) {
    for (int i = 1; i < n; i++) {
        char *key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/////////////////////////////////////////////////////////
// MERGE SORT
// Algoritma divide and conquer: membagi array menjadi
// dua bagian, mengurutkan secara rekursif, lalu menggabung.
// Sangat efisien untuk data besar, kompleksitas O(n log n).
/////////////////////////////////////////////////////////
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L); free(R);
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/////////////////////////////////////////////////////////
// MERGE SORT (STRING)
// Versi string dari merge sort, membandingkan kata
// menggunakan strcmp saat proses penggabungan array.
/////////////////////////////////////////////////////////
void merge_str(char *arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    char **L = malloc(n1 * sizeof(char *));
    char **R = malloc(n2 * sizeof(char *));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (strcmp(L[i], R[j]) <= 0) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L); free(R);
}

void merge_sort_str(char *arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_str(arr, l, m);
        merge_sort_str(arr, m + 1, r);
        merge_str(arr, l, m, r);
    }
}

/////////////////////////////////////////////////////////
// QUICK SORT
// Memilih elemen pivot, membagi array menjadi dua bagian
// (lebih kecil dan lebih besar dari pivot), lalu rekursif.
// Sangat cepat di banyak kasus, rata-rata O(n log n).
/////////////////////////////////////////////////////////
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] <= pivot) {
            int tmp = arr[++i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

/////////////////////////////////////////////////////////
// QUICK SORT (STRING)
// Menggunakan pendekatan yang sama, dengan pivot string
// dan pembanding strcmp antar kata.
/////////////////////////////////////////////////////////
int partition_str(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (strcmp(arr[j], pivot) <= 0) {
            char *tmp = arr[++i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    char *tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

void quick_sort_str(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition_str(arr, low, high);
        quick_sort_str(arr, low, pi - 1);
        quick_sort_str(arr, pi + 1, high);
    }
}

/////////////////////////////////////////////////////////
// SHELL SORT
// Versi pengembangan dari insertion sort dengan membandingkan
// elemen yang berjauhan, kemudian menyempitkan jarak (gap).
// Lebih cepat dari insertion sort biasa.
/////////////////////////////////////////////////////////
void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
}

/////////////////////////////////////////////////////////
// SHELL SORT (STRING)
// Versi shell sort untuk string, menggunakan strcmp
// sebagai pembanding antar kata.
/////////////////////////////////////////////////////////
void shell_sort_str(char *arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            char *temp = arr[i];
            int j;
            for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
}

#endif // SORTING_ALGORITHMS_H