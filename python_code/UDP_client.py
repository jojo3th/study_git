import socket

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 设置服务器的IP地址和端口号
server_name = 'localhost'
server_port = 12000

message = input('Input lowercase sentence:')

# 发送数据到服务器
client_socket.sendto(message.encode(), (server_name, server_port))

# 接收服务器返回的数据
modified_message, server_address = client_socket.recvfrom(2048)
print(modified_message.decode())

# 关闭套接字
client_socket.close()