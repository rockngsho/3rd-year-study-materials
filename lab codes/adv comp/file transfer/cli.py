import sys
import socket
client=socket.socket()
client.connect(('localhost',5555))
sfilename=input('enter filename to download from server')
sdate='temp'
while True:
	client.send(sfilename)
	sdata=client.recv(1024)
	fdownloadfile=open(sfilename,'w')
	while sdata:
		fdownloadfile.write(sdata)
		sdata=client.recv(1024)
	print('download completed')
	break
client.close()

n
