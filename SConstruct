def build(dir, **d):
    env = Environment(**d)
    SConscript('src/SConscript', variant_dir=dir, exports='env')

cxx_clang = '-g -std=c++11 -stdlib=libc++ -march=native -O4 -Weverything -Werror -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-weak-vtables -Wno-unused-function -Wno-sign-conversion'
link_clang = '-stdlib=libc++'

build('build',
    CXX='xcrun clang++',
    CXXFLAGS=cxx_clang,
    LINKFLAGS=link_clang,
)

build('build-tbb',
    CXX='xcrun clang++',
    CXXFLAGS=cxx_clang + ' -DPARALLEL_TBB',
    LINKFLAGS=link_clang + ' -ltbb',
)
