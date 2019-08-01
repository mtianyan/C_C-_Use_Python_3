#include <Python.h>

int great_function(int a) {
    return a + 1;
}

static PyObject * _great_function(PyObject *self, PyObject *args)
{
    int _a;
    int res;

    if (!PyArg_ParseTuple(args, "i", &_a))
        return NULL;
    res = great_function(_a);
    return PyLong_FromLong(res);
}

static PyMethodDef GreateModuleMethods[] = {
    {
        "great_function",_great_function,METH_VARARGS, "great_function in a C extension"
    },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef GreateModule_definition = { 
    PyModuleDef_HEAD_INIT,
    "great_module",
    "A Python module that great_module from C code.",
    -1, 
    GreateModuleMethods
};


PyMODINIT_FUNC PyInit_great_module(void) {
    Py_Initialize();
    return PyModule_Create(&GreateModule_definition);
}


// /LD 即生成动态链接库。编译成功后在当前目录可以得到 great_module.pyd（实际上是dll）。这个pyd可以在Python环境下直接当作module使用。

// cl /LD great_module.c /o great_module.pyd -IC:\Users\tiany\AppData\Local\Programs\Python\Python37\include C:\Users\tiany\AppData\Local\Programs\Python\Python37\libs\python37.lib

// gcc -fPIC -shared great_module.c -o great_module.so -I/usr/include/python2.7/ -lpython2.7

// https://gist.github.com/physacco/2e1b52415f3a964ad2a542a99bebed8f