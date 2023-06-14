import socket

host = socket.gethostname()
port = 5000 #Ensure PORT value same in server and client side
client_socket = socket.socket() 
client_socket.connect((host, port))
client_socket.send(message.encode()) 
data = client_socket.recv(1024).decode()
