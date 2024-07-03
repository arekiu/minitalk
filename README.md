# MiniTalk

MiniTalk is a simple client-server application implemented in C, demonstrating inter-process communication using signals.

## Features

- **Server**: Listens for signals from clients and reconstructs messages.
- **Client**: Sends messages to the server by encoding characters into signal bits.

## Requirements

- Linux-based operating system (due to signal handling specifics).
- `cc` compiler.
- `libft` library (included).

## Installation

1. **Clone the repository:**

   ```bash
   git clone <repository-url>
   cd minitalk

2. **Compile the programs:**

   make

## Usage

1. **Start the server:**

   ./server

1. **Send a message to the server:**

   ./client [Server PID] [Message]

   Example: ./client 12345 "Hello, server!"