project('sudoku_gen', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c23'])

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : true)
#ncurses_dep = cc.find_library('ncurses', required : true)
menu_dep = cc.find_library('menu', required : true)

if cc.get_id() == 'gcc'
    message('Compiler: GCC')
    libs_compiler = ['-lstdc++fs']
    libs_linker   = ['-lstdc++fs']
elif cc.get_id() == 'clang'
    message('Compiler: LLVM/clang')
    libs_compiler = ['-stdlib=libc++']
    libs_linker   = ['-stdlib=libc++', '-lstdc++fs']
endif

sudoku_gen = executable(
        'sudoku_gen',
        'src/main.c',
        'src/sudoku.c',
        install : true,
        dependencies: [
                m_dep,
#                ncurses_dep,
#                menu_dep,
        ],
)

test('test', sudoku_gen)