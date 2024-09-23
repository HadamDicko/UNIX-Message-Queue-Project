# Odd and Even Middle Man Project

## Overview

This project demonstrates inter-process communication in C using message queues. It consists of a sender process that generates random 8-bit numbers and two middle man processes that separate these numbers into odd and even categories based on index.

## Components

- **sender.c**: Generates random numbers and sends them to two message queues.
- **odd_middle_man.c**: Receives and processes numbers from the message queue designated for odd numbered indexes.
- **even_middle_man.c**: Receives and processes numbers from the message queue designated for even numbered indexes.

## Prerequisites

- A UNIX-like operating system (Linux, macOS).
- GCC compiler installed.

## Setup 

- Putty terminal for each process
- WinSCP for file transfer

## Compilation

To compile the source code, run the following commands in the terminal:

```bash
gcc -o sender sender.c
gcc -o even_middle_man even_middle_man.c
gcc -o odd_middle_man odd_middle_man.c
gcc -o receiver_even receiver_even.c
gcc -o receiver_odd receiver_odd.c
