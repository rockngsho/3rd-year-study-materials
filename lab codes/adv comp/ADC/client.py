Python 3.6.5 (v3.6.5:f59c0932b4, Mar 28 2018, 17:00:18) [MSC v.1900 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> import socket
>>> socket.gethostbyname(socket.gethostname())
'127.0.0.1'
>>> client=socket.socket()
>>> client.connect(('127.0.1.1',5555))
>>> client.recv(1000).decode()
'hello'
>>> client.recv(1000).decode()
'socket programming'
>>> client.send("msg from client".encode())
15
>>> 
