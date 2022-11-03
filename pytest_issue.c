#include <Python.h>

static PyObject * pytest_issue_foo(PyObject *unused1, PyObject *unused2, PyObject *unused3) {
    PyErr_SetString(PyExc_RuntimeError, "An exception occurred!");
    fprintf(stderr, "Hello world!\n");
    return NULL;
}

static PyMethodDef pytest_issue_methods[] = {
    {"foo", (PyCFunction)(void(*)(void))pytest_issue_foo, METH_VARARGS | METH_KEYWORDS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef pytest_issue_module = {
    PyModuleDef_HEAD_INIT,
    "pytest_issue",
    NULL,
    -1,
    pytest_issue_methods
};

PyMODINIT_FUNC
PyInit_pytest_issue(void)
{
    return PyModule_Create(&pytest_issue_module);
}
