#include <Python.h>
#include <Windows.h>
#include "great_module.h"

extern __declspec(dllexport) int __stdcall _great_function(const char * a, int b) {
    return great_function(a,b);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpReserved) {
    switch( fdwReason ) { 
        case DLL_PROCESS_ATTACH:
            Py_Initialize();
            PyInit_great_module();
            break;
        case DLL_PROCESS_DETACH:
            Py_Finalize();
            break;
    }
    return TRUE;
}

// cl /LD dllmain.c great_module.c -IC:\Users\tiany\AppData\Local\Programs\Python\Python37\include C:\Users\tiany\AppData\Local\Programs\Python\Python37\libs\python37.lib