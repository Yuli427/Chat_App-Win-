# TCP Chat Application (Windows)

This is a TCP chat application I built using C and Winsock2 on Windows.

I made this project to learn more about socket programming, TCP communication, and multithreading. The application allows multiple clients to connect to a server and send messages to each other.

## Features

- Multiple clients can connect to the server
- Real-time messaging between connected users
- Multithreading to handle incoming messages
- Username registration
- Join and leave notifications

## Technologies Used

- C
- TCP/IP
- Winsock2
- Windows API (CreateThread)

## How to Run

### 1. Compile the Server and Client

Make sure GCC (MinGW-w64) is installed.

From the project folder, compile the server:

```bash
gcc Server/main.c Server/server.c Util/socketutil.c -o server.exe -lws2_32
```

Compile the client:

```bash
gcc Client/main.c Client/client.c Util/socketutil.c -o client.exe -lws2_32
```

### 2. Run the Server

Open a terminal and run:

```bash
.\server.exe
```

Enter `127.0.0.1` as the server IP address for local testing.

### 3. Run the Client

Open another terminal and run:

```bash
.\client.exe
```

You can open multiple client terminals to test the chat application.

## What I Learned

While working on this project, I learned more about:

- How TCP sockets work
- Client-server communication
- Sending and receiving messages using sockets
- Using threads to handle multiple clients
- Socket programming with Winsock2 on Windows
