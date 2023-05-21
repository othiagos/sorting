#pragma once

#include "Sort.hpp"

template <typename T>
class MergeSort : public Sort<T> {
  private:
    void mergeSort(T *vector, const int &left, const int &middle, const int &right) {
        int i, j, k;
        int n1 = middle - left + 1;
        int n2 = right - middle;

        int *L = new int[n1];
        int *R = new int[n2];

        for (i = 0; i < n1; i++)
            L[i] = vector[left + i];
        for (j = 0; j < n2; j++)
            R[j] = vector[middle + 1 + j];

        i = 0;
        j = 0;
        k = left;
        while (i < n1 || j < n2) {
            if (j >= n2 || (i < n1 && L[i] <= R[j])) {
                vector[k] = L[i];
                i++;
            } else {
                vector[k] = R[j];
                j++;
            }
            k++;
        }

        delete[] L;
        delete[] R;
    }

    void sort(T *vector, const int &left, const int &right) {
        if (left < right) {
            int middle = left + (right - left) / 2;
            sort(vector, left, middle);
            sort(vector, middle + 1, right);
            mergeSort(vector, left, middle, right);
        }
    }

  public:
    void sort(T *vector, const int &size) override {
        sort(vector, 0, size - 1);
    }
};
