#ifndef JMOD_H
#define JMOD_H

#include<Python.h>
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#define PY_SSIZE_T_CLEAN
#include<numpy/arrayobject.h>
PyObject* random_array(PyObject *self, PyObject *args);


#endif
