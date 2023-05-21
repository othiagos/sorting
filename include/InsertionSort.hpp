#pragma once

#include "Sort.hpp"

template <typename T>
class InsertionSort : public Sort<T> {
  public:
    void sort(T *vector, const int &size) override {
        int i, j;
        T aux;

        for (i = 1; i < size; i++) {
            aux = vector[i];
            j = i - 1;
            
            while (j >= 0 && aux < vector[j]) {
                vector[j + 1] = vector[j];
                j--;
            }
            vector[j + 1] = aux;
        }
    }
};
