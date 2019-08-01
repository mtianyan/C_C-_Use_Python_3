from setuptools import setup, find_packages, Distribution
from codecs import open
from os import path

here = path.abspath(path.dirname(__file__))

with open(path.join(here, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

class BinaryDistribution(Distribution):
    """Distribution which always forces a binary package with platform name"""
    def has_ext_modules(foo):
        return True

setup(
    name = "great_module",
    version = "0.0.7",
    keywords = ("pip", "great_module"),
    description = "mtianyan's great_module tool",
    long_description = "mtianyan's tool",
    license = "MIT Licence",

    url = "http://blog.mtianyan.cn",
    author = "mtianyan",
    author_email = "mtianyan@qq.com",

    packages = find_packages(exclude=['contrib', 'docs', 'tests']),
        package_data={
        'great_module': ['great_module.pyd']
    },
    platforms = "any",
    install_requires = [],
    distclass=BinaryDistribution
)