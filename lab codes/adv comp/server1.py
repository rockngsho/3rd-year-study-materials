import socket 
import sys
sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
sock.bind(('localhost',8080))
active=True
while active:
	data,addr=sock.recvfrom(1024)
	data=str(data)
	if data=='quit':
		sock.close()
	print(data)
	d=raw_input("->")
	#sock.sendto(d,addr)
sock.close()



                     
