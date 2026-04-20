// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
    T data[Size];
    size_t topIndex;
public:
    TStack(): topIndex(0){}

    void push(const T& value) {
        if (topIndex < Size) {
            data[topIndex++] = value;
        }
    }

    T pop() {
        if (topIndex > 0) {
            return data[--topIndex];
        }
        return T();
    }
    T top() const {
        if (topIndex > 0) {
            return data[topIndex - 1];
        }
        return T();
    }
    bool empty() const {
        return topIndex == 0;
    }
    bool full() const {
        return topIndex >= Size;
    }
};

#endif  // INCLUDE_TSTACK_H_
