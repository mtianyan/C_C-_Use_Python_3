

C:\Users\tiany\Desktop\c_python>cl my_python.c -IC:\Users\tiany\AppData\Local\Pr
ograms\Python\Python37\include C:\Users\tiany\AppData\Local\Programs\Python\Pyth
on37\libs\python37.lib



C:\Users\tiany\AppData\Local\Programs\Python\Python37\libs\python37.lib : warnin
g LNK4272:库计算机类型“x64”与目标计算机类型“x86”冲突
my_python.exe : fatal error LNK1120: 4 个无法解析的外部命令



使用64位开发人员控制台



great_function_from_python.obj : error LNK2019: 无法解析的外部符号 PyString_From
String，该符号在函数 great_function_from_python 中被引用
great_function_from_python.obj : error LNK2019: 无法解析的外部符号 PyInt_FromLon
g，该符号在函数 great_function_from_python 中被引用
great_function_from_python.obj : error LNK2019: 无法解析的外部符号 PyInt_AsLong
，该符号在函数 great_function_from_python 中被引用
great_function_from_python.exe : fatal error LNK1120: 3 个无法解析的外部命令

PyString_From -> PyUnicode_FromString

PyInt_FromLon -> PyLong_FromLong 

PyInt_AsLong -> PyLong_FromLong 



- 包裹函数_great_function。它负责将Python的参数转化为C的参数（PyArg_ParseTuple），调用实际的great_function，并处理great_function的返回值，最终返回给Python环境。
- 导出表GreateModuleMethods。它负责告诉Python这个模块里有哪些函数可以被Python调用。导出表的名字可以随便起，每一项有4个参数：第一个参数是提供给Python环境的函数名称，第二个参数是_great_function，即包裹函数。第三个参数的含义是参数变长，第四个参数是一个说明性的字符串。导出表总是以{NULL, NULL, 0, NULL}结束。
- 导出函数initgreat_module。这个的名字不是任取的，是你的module名称添加前缀init。导出函数中将模块名称与导出表进行连接。





5



Works for me on 2.7.2, Python 2 or 3? For example, for a module called Example:
Python 2:

```
/* Module entry point Python 2 */

PyMODINIT_FUNC initExample(void)
{
    (void) Py_InitModule("Example", ExampleMethods);
}
```

Python 3:

```
/* Module entry point Python 3 */

PyMODINIT_FUNC PyInit_Example(void)
{
    return PyModule_Create(&Example_module);
}
```

在Linux下面，则用gcc编译：

```text
gcc -fPIC -shared great_module.c -o great_module.so -I/usr/include/python2.7/ -lpython2.7
```

在当前目录下得到great_module.so，同理可以在Python中直接使用。



```
static struct PyModuleDef fizzbuzzModuleDef =
{
    PyModuleDef_HEAD_INIT,
    "fizzbuzz", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    fizzbuzzModule_methods
};

PyMODINIT_FUNC PyInit_exmod(void) {
    return PyModule_Create(&fizzbuzzModuleDef);
}
```

![mark](http://myphoto.mtianyan.cn/mdblog/20190801/K4yvsmv4fCw6.png?imageslim)



python setup.py build install



新建一个目录。 
在里面创建一个dbr的文件夹。dbr就是包名。 
在dbr的文件夹里放入我编译好的dbr.pyd和和依赖的DynamsoftBarcodeReaderx64.dll文件。另外还要包含一个初始化文件__init__.py:



**from** .dbr **import** *



pip install cython



n exists in python 3.3, with [`char* PyUnicode_AsUTF8`](http://docs.python.org/3/c-api/unicode.html#PyUnicode_AsUTF8)



```text
cl main.c great_module.c -IC:\Users\tiany\AppData\Local\Programs\Python\Python37\include C:\Users\tiany\AppData\Local\Programs\Python\Python37\libs\python37.lib
```

```text
cl /LD dllmain.c great_module.c -IC:\Users\tiany\AppData\Local\Programs\Python\Python37\include C:\Users\tiany\AppData\Local\Programs\Python\Python37\libs\python37.lib
```



![mark](http://myphoto.mtianyan.cn/mdblog/20190801/UKtoY7il7hRU.png?imageslim)



![mark](http://myphoto.mtianyan.cn/mdblog/20190801/WpINPwrHeG7F.png?imageslim)



1. 定义module名称mymodule，通常，module名称要和文件名保持一致。
2. %{ %} 包裹的部分是C语言的代码，这段代码会原封不动的复制到mymodule_wrap.c
3. 欲导出的函数签名列表。直接从头文件里复制过来即可。



SWIG自动完成了诸如Python类型转换、module初始化、导出代码表生成的诸多工作。



![mark](http://myphoto.mtianyan.cn/mdblog/20190801/dwz2H3GfQrIk.png?imageslim)



也就是说C++的class会直接映射到Python class

SWIG非常强大，对于Python接口而言，简单类型，甚至指针，都无需人工干涉即可自动转换，而复杂类型，尤其是自定义类型，SWIG提供了typemap供转换。而一旦使用了typemap，配置文件将不再在各个语言当中通用。