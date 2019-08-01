//main.c
#include <Python.h>
#include "great_module.h"

int main(int argc, char *argv[]) {
    Py_Initialize();
    PyInit_great_module();
    printf("%c",great_function("Hello",2));
    Py_Finalize();
}