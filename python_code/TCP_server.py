from socket import *

# 创建TCP套接字
server_socket = socket(AF_INET, SOCK_STREAM)

# 绑定服务器的IP地址和端口号
server_address = ('', 12000)
server_socket.bind(server_address)

# 设置监听队列的大小
server_socket.listen(1)

print('The server is ready to receive')

while True:
    # 接收客户端发送的数据
    connection_socket, client_address = server_socket.accept()
    message = connection_socket.recv(2048)
    print('Receive message from client: ', message.decode())

    # 将接收到的数据转换成大写后发送回客户端
    modified_message = message.decode().upper()
    connection_socket.send(modified_message.encode())

    # 关闭连接套接字
    connection_socket.close()