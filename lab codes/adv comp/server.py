import socket 
import sys
sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
sock.bind(('localhost',8080))
while True:
	data,addr=sock.recvfrom(1024)
	print(data)
	if data=='quit':
		sock.close()


                     
