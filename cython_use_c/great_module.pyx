#!python
#cython: language_level=3
#great_module.pyx
cdef public great_function(a,index):
    return a[index]


# 这其中有非Python关键字cdef和public。这些关键字属于Cython。
# 由于我们需要在C语言中使用“编译好的Python代码”，
# 所以得让great_function从外面变得可见，
# 方法就是以“public”修饰。而cdef类似于Python的def，
# 只有使用cdef才可以使用Cython的关键字public。
# cython great_module.pyx