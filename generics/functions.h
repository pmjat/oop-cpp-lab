#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

template<typename T>
void _swap(T& x, T&y) {

    T tmp = x;
    x = y;
    y = tmp;

}

template<typename T>
void sort(T data[], int size) {
    int i, j;
    for (i = 0; i < size-1; i++)
    for (j = 0; j < size-i-1; j++)
        if (data[j] > data[j+1])
            _swap<T>(data[j], data[j+1]);
}

//T tmp = data[j];
//data[j] = data[j+1];
//data[j+1] = tmp;


template<typename T>
int binarySearch(T data[], int size, T x) {
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (data[m] == x)
            return m;

        // If x greater, ignore left half
        if (data[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was not present
    return -1;
}

#endif // FUNCTIONS_H_INCLUDED
