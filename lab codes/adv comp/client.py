import socket 
import sys
sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
print("enter quit to exit")
c=str(raw_input("->"))
while c!='quit':
	sock.sendto(c,('localhost',8080))
	c=str(raw_input('->'))
#sock.sendto(c,('localhost',5555))
sock.close()
