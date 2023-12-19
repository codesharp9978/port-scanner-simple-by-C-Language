# port-scanner-simple-by-C-Language
This project is a simple port scanner written using the C programming language. This port scanner allows users to perform port scanning on an IP address to find out the status of certain ports, whether they are open or closed.

## Features

- Port scanning on an IP address.
- Displays the status of each port checked.
- Can be used to identify open or closed ports.

## Prerequisites

- C compiler (gcc or equivalent)
- Operating System: Windows with Winsock or Linux

## Usage

1. **Compile Program:**

   **For Windows:**
   ```bash
   gcc -o port_scanner port_scanner.c -lws2_32

   **For Linux:**
   ```bash
   gcc -o port_scanner port_scanner.c
