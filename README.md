# Monty Language Interpreter

Monty 0.98 is a scripting language compiled into Monty byte codes, akin to Python, with a unique stack structure and specific instructions to manipulate it. This repository contains an interpreter for Monty ByteCodes files.

## Features

- Supports Monty byte code files with the `.m` extension.
- Single instruction per line format with flexible spacing.
- Handles blank lines and comments.
- Implements various stack manipulation operations.

## Usage

```bash
monty file
```
*where 'file' is the path to the Monty byte code file.*

## Commands

- `push <int>`: Pushes an integer onto the stack.
- `pall`: Prints all values on the stack.
- `pint`: Prints the value at the top of the stack.
- `pop`: Removes the top element of the stack.
- `swap`: Swaps the top two elements of the stack.
- `add`: Adds the top two elements of the stack.
- `nop`: No operation.
- `sub`: Subtracts the top element from the second top element.
- `div`: Divides the second top element by the top element.
- `mul`: Multiplies the top two elements of the stack.
- `mod`: Computes the remainder of the division of the second top element by the top element.
- `pchar`: Prints the ASCII value at the top of the stack as a character.
- `pstr`: Prints the ASCII values on the stack as a string.
- `rotl`: Rotates the stack to the top.
- `rotr`: Rotates the stack to the bottom.
- `stack`: Sets the data format to stack (LIFO).
- `queue`: Sets the data format to queue (FIFO).

