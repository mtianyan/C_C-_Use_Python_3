//main.c
#include <Python.h>
#include "great_module.h"

int main(int argc, char *argv[]) {
    PyObject *tuple;
    Py_Initialize();
    PyInit_great_module();
    printf("%s\n",PyUnicode_AsUTF8(
                great_function(
                    PyUnicode_FromString("hello"),
                    PyLong_FromLong (1)
                )
            ));
    tuple = Py_BuildValue("(iis)", 1, 2, "three");
    printf("%d\n",PyLong_AsLong(
                great_function(
                    tuple,
                    PyLong_FromLong (1)
                )
            ));
    printf("%s\n",PyUnicode_AsUTF8(
                great_function(
                    tuple,
                    PyLong_FromLong (2)
                )
            ));
    Py_Finalize();
}