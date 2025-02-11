#define NO_IMPORT_ARRAY
#define PY_ARRAY_UNIQUE_SYMBOL foobar
#include "jmod.h"

#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()

PyObject* random_array(PyObject* self, PyObject* args) {
    npy_intp dims[1] = {5};
    PyObject* arr = PyArray_SimpleNew(1, dims, NPY_DOUBLE);

    if (!arr) {
        return NULL;
    }

    double* data = (double*)PyArray_DATA((PyArrayObject*)arr);

    // Seed the random number generator
    srand(time(NULL));

    for (int i = 0; i < 5; ++i) {
        data[i] = (double)rand() / RAND_MAX; // Generate random doubles between 0 and 1
    }

    return arr;
}
