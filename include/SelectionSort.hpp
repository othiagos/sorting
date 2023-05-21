#pragma once

#include "Sort.hpp"

template <typename T>
class SelectionSort : public Sort<T> {
  public:
    void sort(T *vector, const int &size) override {
        int i, j, min;

        for (i = 0; i < size - 1; i++) {
            min = i;
            for (j = i + 1; j < size; j++) {
                if (vector[j] < vector[min])
                    min = j;
            }
            this->swap(vector[i], vector[min]);
        }
    }
};
