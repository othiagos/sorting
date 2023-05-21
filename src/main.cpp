#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "BubbleSort.hpp"
#include "HeapSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "SelectionSort.hpp"

void write_file(std::string name, const int &tamanho, const float &tempo) {
    std::ofstream file;

    file.open(name, std::ios::app);
    if (file.is_open()) {
        file << std::fixed;
        file << tamanho << ';' << tempo << '\n';
        file.close();
    }
}

int main(int argc, char const *argv[]) {

    if (argc < 4)
        return -1;

    srand(std::stoi(argv[3]));
    int size = std::stoi(argv[2]);
    int *vec = new int[size];

    for (int i = 0; i < size; i++)
        vec[i] = rand() % (size * 10);

    Sort<int> *s;
    clock_t t;

    char command = argv[1][0];
    switch (command) {
    case 'B':
        s = new BubbleSort<int>();

        t = clock();
        s->sort(vec, size);
        t = clock() - t;

        delete s;
        write_file("./bubblesort.csv", size, (float)t / CLOCKS_PER_SEC);
        break;
    case 'H':
        s = new HeapSort<int>();

        t = clock();
        s->sort(vec, size);
        t = clock() - t;

        delete s;
        write_file("./heapsort.csv", size, (float)t / CLOCKS_PER_SEC);
        break;
    case 'I':
        s = new InsertionSort<int>();

        t = clock();
        s->sort(vec, size);
        t = clock() - t;

        delete s;
        write_file("./insertionsort.csv", size, (float)t / CLOCKS_PER_SEC);
        break;
    case 'M':
        s = new MergeSort<int>();

        t = clock();
        s->sort(vec, size);
        t = clock() - t;

        delete s;
        write_file("./mergesort.csv", size, (float)t / CLOCKS_PER_SEC);
        break;
    case 'Q':
        s = new QuickSort<int>();

        t = clock();
        s->sort(vec, size);
        t = clock() - t;

        delete s;
        write_file("./quicksort.csv", size, (float)t / CLOCKS_PER_SEC);
        break;
    case 'S':
        s = new SelectionSort<int>();

        t = clock();
        s->sort(vec, size);
        t = clock() - t;

        delete s;
        write_file("./selectionsort.csv", size, (float)t / CLOCKS_PER_SEC);
        break;
    }

    delete[] vec;

    return 0;
}
