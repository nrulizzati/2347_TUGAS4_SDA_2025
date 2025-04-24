#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>
#include "sorting_algorithms.h"

#define MAX_WORD_LENGTH 100

// Fungsi untuk membaca data angka dari file
void load_numbers(const char *filename, int arr[], int n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Gagal membuka file angka");
        exit(1);
    }
    for (int i = 0; i < n; i++) fscanf(fp, "%d", &arr[i]);
    fclose(fp);
}

// Fungsi untuk membaca data kata dari file
void load_words(const char *filename, char *arr[], int n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Gagal membuka file kata");
        exit(1);
    }
    char buffer[MAX_WORD_LENGTH];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s", buffer);
        arr[i] = strdup(buffer);
    }
    fclose(fp);
}

// Fungsi untuk membebaskan memori kata
void free_words(char *arr[], int n) {
    for (int i = 0; i < n; i++) free(arr[i]);
}

// Fungsi untuk melihat penggunaan memori saat ini (dalam KB)
size_t get_memory_usage_kb() {
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    return pmc.WorkingSetSize / 1024;
}

// Fungsi cetak hasil sebagai baris tabel
void print_execution_and_memory(clock_t start, clock_t end, const char *algoname) {
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    size_t memory_kb = get_memory_usage_kb();
    printf("| %-20s | %14.4f | %16zu KB |\n", algoname, duration, memory_kb);
    fflush(stdout);
}

int main() {
    int n;
    printf("Masukkan jumlah data yang ingin diuji: ");
    scanf("%d", &n);
    printf("\n>>> Program dimulai. Jumlah data: %d\n", n);
    fflush(stdout);

    int *angka = malloc(n * sizeof(int));
    char **kata = malloc(n * sizeof(char*));

    // Header tabel angka
    printf("+----------------------+----------------+---------------------+\n");
    printf("|                 === PENGUJIAN DATA ANGKA ===                |\n");
    printf("+----------------------+----------------+---------------------+\n");
    printf("| Nama Algoritma       | Waktu (detik)  | Penggunaan Memori   |\n");
    printf("+----------------------+----------------+---------------------+\n");

    load_numbers("data_angka.txt", angka, n);
    clock_t start = clock();
    bubble_sort(angka, n);
    clock_t end = clock();
    print_execution_and_memory(start, end, "Bubble Sort");

    load_numbers("data_angka.txt", angka, n);
    start = clock();
    selection_sort(angka, n);
    end = clock();
    print_execution_and_memory(start, end, "Selection Sort");

    load_numbers("data_angka.txt", angka, n);
    start = clock();
    insertion_sort(angka, n);
    end = clock();
    print_execution_and_memory(start, end, "Insertion Sort");

    load_numbers("data_angka.txt", angka, n);
    start = clock();
    merge_sort(angka, 0, n - 1);
    end = clock();
    print_execution_and_memory(start, end, "Merge Sort");

    load_numbers("data_angka.txt", angka, n);
    start = clock();
    quick_sort(angka, 0, n - 1);
    end = clock();
    print_execution_and_memory(start, end, "Quick Sort");

    load_numbers("data_angka.txt", angka, n);
    start = clock();
    shell_sort(angka, n);
    end = clock();
    print_execution_and_memory(start, end, "Shell Sort");

    printf("+----------------------+----------------+---------------------+\n");

    // Header tabel kata
    printf("\n");
    printf("+----------------------+----------------+---------------------+\n");
    printf("|                 === PENGUJIAN DATA KATA ===                 |\n");
    printf("+----------------------+----------------+---------------------+\n");
    printf("| Nama Algoritma       | Waktu (detik)  | Penggunaan Memori   |\n");
    printf("+----------------------+----------------+---------------------+\n");

    load_words("data_kata.txt", kata, n);
    start = clock();
    bubble_sort_str(kata, n);
    end = clock();
    print_execution_and_memory(start, end, "Bubble Sort");
    free_words(kata, n);

    load_words("data_kata.txt", kata, n);
    start = clock();
    selection_sort_str(kata, n);
    end = clock();
    print_execution_and_memory(start, end, "Selection Sort");
    free_words(kata, n);

    load_words("data_kata.txt", kata, n);
    start = clock();
    insertion_sort_str(kata, n);
    end = clock();
    print_execution_and_memory(start, end, "Insertion Sort");
    free_words(kata, n);

    load_words("data_kata.txt", kata, n);
    start = clock();
    merge_sort_str(kata, 0, n - 1);
    end = clock();
    print_execution_and_memory(start, end, "Merge Sort");
    free_words(kata, n);

    load_words("data_kata.txt", kata, n);
    start = clock();
    quick_sort_str(kata, 0, n - 1);
    end = clock();
    print_execution_and_memory(start, end, "Quick Sort");
    free_words(kata, n);

    load_words("data_kata.txt", kata, n);
    start = clock();
    shell_sort_str(kata, n);
    end = clock();
    print_execution_and_memory(start, end, "Shell Sort");
    free_words(kata, n);

    printf("+----------------------+----------------+---------------------+\n");

    free(angka);
    free(kata);

    printf("\n>>> Program selesai.\n");
    fflush(stdout);
    return 0;
}