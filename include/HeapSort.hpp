#pragma once

#include "Sort.hpp"

template <typename T>
class HeapSort : public Sort<T> {
  private:
    void heapify(T *vector, const int &size, const int &i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && vector[left] > vector[largest])
            largest = left;

        if (right < size && vector[right] > vector[largest])
            largest = right;

        if (largest != i) {
            this->swap(vector[i], vector[largest]);
            heapify(vector, size, largest);
        }
    }

  public:
    void sort(T *vector, const int &size) override {
        for (int i = size / 2; i >= 0; i--)
            heapify(vector, size, i);

        for (int i = size - 1; i >= 0; i--) {
            this->swap(vector[0], vector[i]);
            heapify(vector, i, 0);
        }
    }
};
