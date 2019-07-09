project('brisk', 'cpp', 
	version : '3.0',
	default_options : ['cpp_std=c++14']
)

src = ['src/test.cpp']
includes = include_directories('include')

exe = executable('brisk-test', src,
	include_directories : includes,
	install : false)

test('basic', exe)

