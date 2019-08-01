
#!/usr/bin/env python3
# encoding: utf-8

from distutils.core import setup, Extension

great_module = Extension('great_module', sources = ['great_module.c'])

setup(name='great_module',
      version='0.1.0',
      description='great_module written in C',
      ext_modules=[great_module])