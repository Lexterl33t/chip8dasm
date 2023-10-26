# chip8dasm - Chip-8 Disassembly

![chip8dasm logo](https://github.com/lexterl33t/chip8dasm/logo.png)

chip8dasm is a disassembler for the Chip-8 programming language. It allows you to convert Chip-8 machine code into human-readable assembly code.

## Overview

The chip8dasm disassembler is a powerful tool built in C and designed to help programmers analyze and understand Chip-8 programs. It provides a way to translate the binary instructions of Chip-8 programs into human-readable assembly code.

## Features

- **Easy-to-use**: The chip8dasm disassembler is straightforward to use, making it accessible to begginer.
- **Open-source**: chip8dasm is an open-source project, allowing developers to contribute, modify, and improve the disassembler as needed.
- **Linear view:**  TUI linear view 


## TODO
- **Graph view**
- **Super chip-48 instruction support**

## Getting Started

### Installation


```
git clone https://github.com/Lexterl33t/chip8dasm
cd chip8dasm/ && meson build && ninja -C build
```

### Using

```
./build/chip8dasm --disassemble example/example.ch8

=>
* 0x200 | 00e0 | cls
* 0x202 | 6c00 | ld v12, 0
* 0x204 | 4c00 | sne v12, 0
* 0x206 | 6e0f | ld v14, 15
* 0x208 | a203 | ld i, #3
* 0x20a | 6020 | ld v0, 32
* 0x20c | f055 | ld [i], v0
* 0x20e | 00e0 | cls
* 0x210 | 22be | call #190
* 0x212 | 2276 | call #118
* 0x214 | 228e | call #142
* 0x216 | 225e | call #94
* 0x218 | 2246 | call #70
* 0x21a | 1210 | jp #16
* 0x21c | 6100 | ld v1, 0
* 0x21e | 6217 | ld v2, 23
* 0x220 | 6304 | ld v3, 4
* 0x222 | 4110 | sne v1, 16
* 0x224 | 00ee | ret
* 0x226 | a2e8 | ld i, #232
* 0x228 | f11e | add i, v1
* 0x22a | f065 | ld v0, [i]
* 0x22c | 4000 | sne v0, 0
* 0x22e | 1234 | jp #52
* 0x230 | f029 | ld f, v0
......
```

## Contributions

If you're interested in contributing to chip8dasm, you can fork the repository, make your changes, and submit a pull request. All contributions are welcome and greatly appreciated!

## Resources

For more information about the Chip-8 programming language and how to use chip8dasm, you can refer to the following resources:

1. [Chip-8 Wikipedia](https://en.wikipedia.org/wiki/CHIP-8) - Provides an overview of the Chip-8 programming language.
2. [chip8dasm GitHub Repository](https://github.com/lexterl33t/chip8dasm) - The official GitHub repository for chip8dasm. Contains the source code, documentation, and more.



