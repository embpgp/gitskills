#!/usr/bin/env python
# -*- coding:UTF-8 -*-
#
#1.监听服务器是否有消息发送过来
#2.检查用户的输入，如果用户输入某条消息，需要发送到服务器
#
#这里有两个事件需要监听：连接到服务器的socket和标准输入，同样用select
#
#rlist = [sys.stdin, s]
#
#Get the list socket which are readable
#
#read_list, wirte_list, error_list = select.select(rlist, [], [])
#
#

import socket, select, string, sys

def prompt():
	sys.stdout.write('<You>')
	sys.stdout.flush()

#main function
if __name__ == '__main__':
	if(len(sys.argv) < 3):
		print "Usage:python telnet.py hostname port"
		sys.exit()

	host = sys.argv[1]
	port = int(sys.argv[2])

	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.settimeout(2)

	#connect to remote host
	try:
		s.connect((host, port))
	except:
		print 'Unable to connect'
		sys.exit()
	print 'Connected to remote host.Start sending message'
	prompt()
	while 1:
		socket_list = [sys.stdin, s]
		#Get the list sockets which are readable
		read_sockets, write_sockets, error_sockets = select.select(socket_list, [], [])
		for sock in read_sockets:
			if sock == s:
				data = sock.recv(4096)
				if not data:
					print '\nDisconnected from chat server'
					sys.exit()
				else:
					sys.stdout.write(data)
					prompt()
			else:
				msg = sys.stdin.readline()
				s.send(msg)
				prompt()	
