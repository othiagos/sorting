#pragma once

#include "Sort.hpp"

template <typename T>
class QuickSort : public Sort<T> {
  private:
    int partition(T *vector, const int &size, const int &low, const int &high) {
        T x = vector[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (vector[j] <= x) {
                i++;
                this->swap(vector[i], vector[j]);
            }
        }
        this->swap(vector[i + 1], vector[high]);
        return i + 1;
    }

    void sort(T *vector, const int &size, const int &low, const int &high) {
        if (low < high) {
            int p = partition(vector, size, low, high);
            sort(vector, p - 1, low, p - 1);
            sort(vector, high - p - 1, p + 1, high);
        }
    }

  public:
    void sort(T *vector, const int &size) override {
        sort(vector, size, 0, size - 1);
    }
};
