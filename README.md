# Odd and Even Middle Man Project

## Overview

This project demonstrates inter-process communication in C using message queues. It consists of a sender process that generates random 8-bit numbers and two middle man processes that separate these numbers into odd and even categories.

## Components

- **sender.c**: Generates random numbers and sends them to two message queues.
- **odd_middle_man.c**: Receives and processes numbers from the message queue designated for odd numbered indexes.
- **even_middle_man.c**: Receives and processes numbers from the message queue designated for even numbered indexes.

## Prerequisites

- A UNIX-like operating system (Linux, macOS).
- GCC compiler installed.

## Setup Instructions

### Step 1: Clone the Repository

1. Open a terminal.
2. Navigate to the directory where you want to clone the repository.
3. Run the following command:
   ```bash
   git clone https://github.com/YOUR_GITHUB_USERNAME/your-repository-name.git
