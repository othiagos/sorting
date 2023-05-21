#pragma once

template <typename T>
class Sort {
  protected:
    void swap(T &value1, T &value2) {
        T temp = value1;
        value1 = value2;
        value2 = temp;
    }

  public:
    virtual ~Sort() { }
    virtual void sort(T *vector, const int &size) = 0;
};
