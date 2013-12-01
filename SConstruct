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
        CXX='xcrun clang++',
        CXXFLAGS=cxxflags,
        LINKFLAGS=linkflags,
    )

    build('build-tbb',
        CXX='xcrun clang++',
        CXXFLAGS=cxxflags + ' -DPARALLEL_TBB',
        LINKFLAGS=linkflags + ' -ltbb',
    )

else:
    sys.exit('Unsupported system: {}'.format(system))
