#pragma once
#include"Python.h"
#include<iostream>


static PyObject* _print_hello(PyObject* self, PyObject* args)
{
	std::cout << "hello world" << std::endl;
	Py_RETURN_NONE;
}

static PyMethodDef cpp_methods[] = {
    {"print_hello", _print_hello, METH_VARARGS, ""},
    {NULL,NULL}
};

static struct PyModuleDef mydll_moduledef =
{
    PyModuleDef_HEAD_INIT,
    "mydll",
    "Python wrapper for OpenCV.",
    -1,     /* size of per-interpreter state of the module,
               or -1 if the module keeps state in global variables. */
    cpp_methods
};



// !!!看这里, 看这里 !!!
// 3.x要用 PyModule_Create  PyInit_xxx  xxx要与dll名称完全一致
PyMODINIT_FUNC PyInit_mydll(void)
{
	return PyModule_Create(&mydll_moduledef);
}
