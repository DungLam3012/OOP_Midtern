from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        'zoo_module',  # Tên module
        sources=[
            'bindings/bindings.cpp',
            'src/animal.cpp',
            'src/cage.cpp',
            'src/zoo.cpp'
        ],
        include_dirs=[
            pybind11.get_include(),
            'include'
        ],
        language='c++',
        extra_compile_args=['-std=c++11'],
    ),
]

setup(
    name='zoo_module',
    version='0.1',
    ext_modules=ext_modules,
)