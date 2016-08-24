#!/usr/bin/env python
# -*- coding:UTF-8 -*-
#
#聊天室服务器主要做下面两件事：
#
#１．接受多个客户端的连接
#２．从每个客户端读入消息并广播到其他已经连接的客户端
#
#在这里定义了一个list类型的变量CONNECTION_LIST，表示监听多个socket
#事件的可读事件，利用select来处理多路I/O
#
#read_sockets, write_sockets, error_sockets = select.select(CONNECTION_LIST,[],[])
#当select方法返回的时候，说明在read_sockets有可以读取的数据
#
#直接判断里面的文件描述符
#
import socket, select

#Function to broadcast char messages to all connected clients
def broadcast_data(sock, message):
	#Do not send the message to master socket and the client who has send us th message
	for socket in CONNECTION_LIST:
		if socket != server_socket and socket != sock:
			try:
				socket.send(message)
			except:
				#broken socket connection may be, char client pressed Ctrl+C for example
				socket.close()
				CONNECTION_LIST.remove(socket)


if __name__ == '__main__':
	CONNECTION_LIST = []    #List to keep track of sockt description
	RECV_BUFFER = 4096 		#Advisable to keep is as an exponent of 2
	PORT = 54321
	server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	server_socket.bind(("0.0.0.0", PORT))
	server_socket.listen(10)
	#add server socket to the list of readable connections
	CONNECTION_LIST.append(server_socket)
	print 'Chat server started on port '+str(PORT)
	while 1:
		#Get the list sockets which are ready to be read through select
		read_sockets, write_sockets, error_sockets = select.select(CONNECTION_LIST, [], [])
		for sock in read_sockets:
			#new connection
			if sock == server_socket:
			#Handle the case in which there is a new connection recieved through server_socket
				sockfd, addr = server_socket.accept()
				CONNECTION_LIST.append(sockfd)
				print "Client(%s, %s)connected" % addr
				broadcast_data(sockfd, "[%s:%s]enter room n" % addr)
			else:
				#Some incoming message from a client
				try:
					#in Windows, sometimes when a TCP program closes abruptly
					#a "Connection reset by peer" exception will be thrown
					data = sock.recv(RECV_BUFFER)
					if data:
						broadcast_data(sock,"r"+''+data)
				except:
					broadcast_data(sock, "Client (%s,%s) is offine"%addr)
					print "Client (%s,%s) is offine"%addr
					sock.close()
					CONNECTION_LIST.remove(sock)
					continue

	server_socket.close()
