from socket import *

# 创建TCP套接字
client_socket = socket(AF_INET, SOCK_STREAM)

# 与服务器建立连接
server_address = ('localhost', 12000)
client_socket.connect(server_address)

# 与服务器进行交互
message = input('Input lowercase sentence: ')
client_socket.send(message.encode())

modified_message = client_socket.recv(2048)
print('From server: ', modified_message.decode())

# 关闭套接字
client_socket.close()