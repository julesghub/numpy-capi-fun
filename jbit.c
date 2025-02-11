#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#define PY_SSIZE_T_CLEAN
#define NO_IMPORT_ARRAY
#include <Python.h>
#include <numpy/arrayobject.h>

#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()

static PyObject *
random_array(PyObject *self, PyObject *args)
{
    int size;

    if (!PyArg_ParseTuple(args, "i", &size))
        return NULL;

    if (size <= 0) {
        PyErr_SetString(PyExc_ValueError, "Size must be positive");
        return NULL;
    }

    npy_intp dims[1] = {size};
    PyObject *array = PyArray_SimpleNew(1, dims, NPY_DOUBLE);

    if (array == NULL)
        return NULL;

    double *data = (double *)PyArray_DATA((PyArrayObject *)array);

    // Seed the random number generator
    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        data[i] = (double)rand() / RAND_MAX; // Generate random doubles between 0 and 1
    }

    return array;
}


static PyMethodDef RandomArrayMethods[] = {
    {"random_array",  random_array, METH_VARARGS, "Generate a random array."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMethodDef *get_random_array_methods() {
    return RandomArrayMethods;
}
