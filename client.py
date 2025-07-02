import argparse
from typing import Tuple
import struct
import socket

LENGTH_TYPE = "I"


def setup_connection(ip, port):
    """Set up a TCP connection to the server"""
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((ip, port))
    return sock


def send_message(sock: socket.socket, message: str) -> None:
    """Send a message to the server"""
    # once again, i dont care about endianess this time :)
    sock.sendall(struct.pack('I', len(message)) + message.encode())


def receive_message(sock: socket.socket) -> str:
    """Receive a message from the server"""
    message_length_bytes = sock.recv(struct.calcsize(LENGTH_TYPE))
    if not message_length_bytes:
        return ""
    message_length = struct.unpack(LENGTH_TYPE, message_length_bytes)[0]    
    return sock.recv(message_length).decode()


def parse_args() -> Tuple[str, int, str]:
    """Parse command line arguments"""
    parser = argparse.ArgumentParser(description="Technician client")
    parser.add_argument("ip", type=str, help="IP address of the server")
    parser.add_argument("port", type=int, help="Port of the server")
    parser.add_argument("command", type=str, help="Command to send to the server")
    args = parser.parse_args()
    return args.ip, args.port, args.command


def main() -> None:
    ip, port, command = parse_args()
    sock = setup_connection(ip, port)
    print(f"Connected to server at {ip}:{port}")
    print(f"Sending command: {command}")
    send_message(sock, command)
    response = receive_message(sock)
    print(f"Server response: {response}")

if __name__ == "__main__":
    main()
