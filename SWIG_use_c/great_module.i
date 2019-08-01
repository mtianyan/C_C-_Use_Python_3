/* great_module.i */
%module great_module
%{
int great_function(int a) {
    return a + 1;
}
%}
int great_function(int a);