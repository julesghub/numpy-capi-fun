"""A setuptools based setup module.

See:
https://packaging.python.org/guides/distributing-packages-using-setuptools/
https://github.com/pypa/sampleproject
"""

# Always prefer setuptools over distutils
from setuptools import setup, Extension
import numpy

extensions = [
    Extension( name = "jmod",
               sources = ['./jmod.c', 'jbit.c'],
               include_dirs = [numpy.get_include()]),
]
setup(
    ext_modules = extensions
)
