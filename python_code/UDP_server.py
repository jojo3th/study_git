import socket

# 创建UDP套接字
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 绑定服务器的IP地址和端口号
server_address = ('localhost', 12000)
server_socket.bind(server_address)

print('The server is ready to receive')

while True:
    # 接收客户端发送的数据
    message, client_address = server_socket.recvfrom(2048)
    print('Receive message from client: ', message.decode())

    # 将接收到的数据转换成大写后发送回客户端
    modified_message = message.decode().upper()
    server_socket.sendto(modified_message.encode(), client_address)