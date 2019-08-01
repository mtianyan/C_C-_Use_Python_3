//my_python.c
#include <Python.h>

int main(int argc, char *argv[])
{
  Py_SetProgramName(argv[0]);
  Py_Initialize();
  PyRun_SimpleString("print('Hello Python!')");
  Py_Finalize();
  return 0;
}

// C:\Users\tiany\Desktop\c_python>cl my_python.c -IC:\Users\tiany\AppData\Local\Pr
// ograms\Python\Python37\include C:\Users\tiany\AppData\Local\Programs\Python\Pyth
// on37\libs\python37.lib

// gcc my_python.c -o my_python -I/usr/include/python2.7/ -lpython2.7

