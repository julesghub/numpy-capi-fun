#include "jmod.h"

/* Function to create and return a NumPy array from C */
static PyObject* create_numpy_array(PyObject* self, PyObject* args) {
    npy_intp dims[1] = {5};  // Create a 1D NumPy array of size 5
    PyObject* array = PyArray_SimpleNew(1, dims, NPY_DOUBLE);
    
    if (!array) {
        return NULL;  // Handle allocation failure
    }

    double* data = (double*)PyArray_DATA((PyArrayObject*)array);
    for (int i = 0; i < 5; i++) {
        data[i] = i * 1.1;  // Fill array with sample data
    }

    return array;
}

/* Method definitions */
static PyMethodDef MyMethods[] = {
    {"create_numpy_array", create_numpy_array, METH_NOARGS, "Creates a NumPy array and returns it"},
    {"random_array", random_array, METH_NOARGS, "Creates a NumPy array of random numbers"},
    {NULL, NULL, 0, NULL}  // Sentinel
};

/* Module definition */
static struct PyModuleDef jmod = {
    PyModuleDef_HEAD_INIT,
    "jmod",  // Module name
    NULL,        // Module docstring
    -1,          // Size of per-interpreter state of the module, or -1
    MyMethods    // Methods
};

/* Module initialization function */
PyMODINIT_FUNC PyInit_jmod(void) {
    PyObject* m = PyModule_Create(&jmod);
    if (!m) return NULL;

    import_array();  // Initialize NumPy C API
    return m;
}

