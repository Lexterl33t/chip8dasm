project('Chip8Dasm', 'c')

# Configuration globale
inc = include_directories('src')

# Exécutable
executable('chip8dasm',
           ['src/main.c',
            'src/argparser/argparser.c',
            'src/argparser/errors.c',
            ],
           include_directories: inc)

