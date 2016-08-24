#!/usr/bin/env python
# -*- coding : UTF-8 -*-

import socket

HOST = ''  #Symbolic name meaning all avaliable interface
PORT = 8888 #Arbitrary non-privileged port 

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print 'start create...'
s.bind((HOST, PORT))
print 'start bing...'
s.listen(1)
print 'start listen...'
conn, addr = s.accept()
print 'Connected by', addr
while 1:
	data = conn.recv(1024)
	if not data: 
		break
	print 'recv a message is', data
	conn.sendall(data)
conn.close()
