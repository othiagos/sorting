#pragma once

#include "Sort.hpp"

#include <iostream>

template <typename T>
class RadixSort : public Sort<T> {
  private:
    T getMaxElement(T *a, const int &size) {
        T max = a[0];

        for (int i = 1; i < size; i++) {
            if (a[i] > max)
                max = a[i];
        }
        return max;
    }

    int calculateNumBits(T num) {
        int count;
        for (count = 0; num > 0; count++)
            num >>= 1;

        return count;
    }

    int digit(T num, int pos) {
        return (num >> pos) & 1;
    }

    void quicksortB(T *vec, const int &left, const int &right, const int &position) {
        int i = left, j = right;

        if (right <= left || position < 0) return;

        while (j != i) {
            while (digit(vec[i], position) == 0 && (i < j)) i++;
            while (digit(vec[j], position) == 1 && (j > i)) j--;
            this->swap(vec[i], vec[j]);
        }

        if (digit(vec[right], position) == 0) j++;

        quicksortB(vec, left, j - 1, position - 1);
        quicksortB(vec, j, right, position - 1);
    }

  public:
    void sort(T *vector, const int &size) override {
        quicksortB(vector, 0, size - 1, calculateNumBits(getMaxElement(vector, size)));
    }
};
