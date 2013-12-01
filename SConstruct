import os
import sys

def build(dir, **d):
    env = Environment(**d)
    SConscript('src/SConscript', variant_dir=dir, exports='env')

system = os.uname()[0]

if system == 'Darwin':
    cxx = 'xcrun clang++'
    cxxflags = '-g -std=c++11 -stdlib=libc++ -march=native -O4 -Weverything -Werror -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-weak-vtables -Wno-unused-function -Wno-sign-conversion'
    linkflags = '-stdlib=libc++'

    build('build',
        CXX=cxx,
        CXXFLAGS=cxxflags,
        LINKFLAGS=linkflags,
    )

    build('build-tbb',
        CXX=cxx,
        CXXFLAGS=cxxflags,
        LINKFLAGS=linkflags,
        CPPDEFINES=['PARALLEL_TBB'],
        LIBS='tbb',
    )

elif system == 'Linux':
    cxx = 'g++-4.7'
    cxxflags = '-g -std=c++11 -march=native -O3 -Werror -Wall -Wextra -Wunused -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Wdouble-promotion -Wconversion -Wsign-conversion -Wmissing-declarations -Wredundant-decls'

    build('build',
        CXX=cxx,
        CXXFLAGS=cxxflags,
    )

    build('build-tbb',
        CXX=cxx,
        CXXFLAGS=cxxflags,
        CPPDEFINES=['PARALLEL_TBB'],
        LIBS='tbb',
    )

    build('build-omp',
        CXX=cxx,
        CXXFLAGS=cxxflags + ' -fopenmp',
        LINKFLAGS='-fopenmp',
        CPPDEFINES=['PARALLEL_OPENMP'],
    )

else:
    sys.exit('Unsupported system: {}'.format(system))
