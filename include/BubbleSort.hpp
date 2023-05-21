#pragma once

#include "Sort.hpp"

template <typename T>
class BubbleSort : public Sort<T> {
  public:
    void sort(T *vector, const int &size) override {
        int i, j;
        bool change;

        for (i = 0; i < size - 1; i++) {
            change = false;
            
            for (j = 1; j < size - i; j++) {
                if (vector[j] < vector[j - 1]) {
                    this->swap(vector[j - 1], vector[j]);
                    change = true;
                }
            }
            if (!change)
                break;
        }
    }
};
