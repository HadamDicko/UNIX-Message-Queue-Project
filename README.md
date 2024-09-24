# Odd and Even Middle Man Project

## Overview

This project demonstrates inter-process communication in C using message queues. It consists of a sender process that generates random 8-bit numbers and two middle man processes that separate these numbers into odd and even categories based on index.

## Components

- **sender.c**: Generates random numbers and sends them to two message queues.
- **odd_middle_man.c**: Receives and processes numbers from the message queue designated for odd numbered indexes.
- **even_middle_man.c**: Receives and processes numbers from the message queue designated for even numbered indexes.
- **receiver.c**: Executable file.

## Prerequisites

- A UNIX-like operating system (Linux, macOS).
- GCC compiler installed.

## Setup 

- Putty terminal for each process
- WinSCP for file transfer

## Compilation

-To compile the source code, open 5 Putty terminals
-One for sender.c, one for each middle man, one for each receiver

# sender.c (terminal 1)
```bash
cc sender.c
./a.out
```
# odd_middle_man.c (terminal 2)
```bash
cc odd_middle_man.c
./a.out
```
# even_middle_man.c (terminal 3)
```bash
cc even_middle_man.c
./a.out
```
# receiver.c (terminal 4)
```bash
cc receiver.c
./a.out
```
# receiver.c (terminal 5)
```bash
cc receiver.c
./a.out
```
# sender.c (terminal 4)
```bash
Press any key: 
```

