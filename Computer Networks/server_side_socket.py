import socket

host = socket.gethostname() #IP address
port = 5000 #Ensure PORT value same in server and client side
server_socket = socket.socket()
server_socket.bind((host, port))
server_socket.listen(2)
conn, address = server_socket.accept()
conn.recv(1024).decode()
conn.send(data.encode())
