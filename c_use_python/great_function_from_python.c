#include <Python.h>

int great_function_from_python(int a) {
    int res;
    PyObject *pModule,*pFunc;
    PyObject *pArgs, *pValue;
    
    /* import */
    pModule = PyImport_Import(PyUnicode_FromString("great_module"));

    /* great_module.great_function */
    pFunc = PyObject_GetAttrString(pModule, "great_function"); 
    
    
    // 所有Python元素，module、function、tuple、string等等，实际上都是PyObject。C语言里操纵它们，一律使用PyObject *。

    /* build args */
    // 若a是Tuple，则a[i] = b对应于 PyTuple_SetItem(a,i,b)，有理由相信还有一个函数PyTuple_GetItem完成取得某一项的值。
    pArgs = PyTuple_New(1);
    PyTuple_SetItem(pArgs,0, PyLong_FromLong(a));

    // Python的类型与C语言类型可以相互转换。Python类型XXX转换为C语言类型YYY要使用PyXXX_AsYYY函数；C类型YYY转换为Python类型XXX要使用PyXXX_FromYYY函数。
      
    /* call */
    pValue = PyObject_CallObject(pFunc, pArgs);
    
    // 也可以创建Python类型的变量，使用PyXXX_New可以创建类型为XXX的变量。

    res = PyLong_AsLong(pValue);
    return res;
}

// 不仅Python语言很优雅，Python的库函数API也非常优雅。

int great_function_from_python(int a); 

int main(int argc, char *argv[]) {
    Py_Initialize();
    printf("%d",great_function_from_python(2));
    Py_Finalize();
}

// bash:

// export PYTHONPATH=.:$PYTHONPATH
// csh:

// setenv PYTHONPATH .:$PYTHONPATH

// C:\Users\tiany\Desktop\c_python>cl great_function_from_python.c -IC:\Users\tiany
// \AppData\Local\Programs\Python\Python37\include C:\Users\tiany\AppData\Local\Pro
// grams\Python\Python37\libs\python37.lib