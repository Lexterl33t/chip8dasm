project('Chip8Dasm', 'c')

# Configuration globale
inc = include_directories('src')

# Exécutable
executable('chip8dasm',
           ['src/main.c',
            'src/argparser/argparser.c',
            'src/utils/utils.c',
            'src/rom_parsing/rom_parser.c',
            'src/rom_parsing/binary_rom_parser.c',
            'src/disassembler/decoder.c',
            'src/disassembler/basic_block.c',
            'src/disassembler/instruction.c',
            ],
           include_directories: inc)

