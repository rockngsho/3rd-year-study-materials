import sys
import socket
import os
host='localhost'
server=socket.socket()
server.bind((host,5555))
server.listen(5)
print('server is active')
bfound=0
while True:
	c,add=server.accept()
	print(add)
	sfilename=c.recv(1024)
	print(sfilename+'file found')
	fuploadfile=open(sfilename,'r')
	sread=fuploadfile.read(1024)
	while sread:
		c.send(sread)
		sread=fuploadfile.read(1024)
		print('sending complete')
		break
c.close()
server.close()

	
