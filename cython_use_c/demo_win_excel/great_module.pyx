#!python
#cython: language_level=3
cdef public char great_function(const char * a,int index):
    return a[index]

# cython great_module.pyx