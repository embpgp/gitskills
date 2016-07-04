#!/usr/bin/env python
# *-* coding:UTF-8 *-*


import optparse
import socket
import threading

screenLock = threading.Semaphore(value = 1)

def connScan(tgHost, tgPort):
	try:
		connSkt = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
		connSkt.connect((tgHost,tgPort))
		connSkt.send('ViolenPython\r\n')
		result = connSkt.recv(256)
		screenLock.acquire()
		print('[+]%d/tcp open' % tgPort)
		print('[+]'+str(result))
	except:
		screenLock.acquire()
		print('[-]%d/tcp closed'%tgPort)

	finally:
		screenLock.release()
		connSkt.close()


def portScan(tgHost,tgPorts):
	try:
		tgIP = socket.gethostbyname(tgHost)
	except:
		print("[-]Cannot resolve'%s':Unknown host"%tgHost)
		return
	try:
		tgName = socket.gethostbyaddr(tgIP)
		print('\n[+]Scan Results for:'+tgName[0])

	except:
		print('\n[+]Scan Results for:'+tgIP)
	socket.setdefaulttimeout(1)
	for tgPort in tgPorts:
		print('Scanning port'+str(tgPort))
		t=threading.Thread(target=connScan,args=(tgHost,int(tgPort)))
		t.start()


def main():
	parser = optparse.OptionParser("Usage %prog -H <target host> -p <target port>")
	parser.add_option('-H',dest='tgHost',type='string',help='specify target host')
	parser.add_option('-p',dest='tgPort',type='int',help='specify target port')
	(options,args) = parser.parse_args()

	tgHost = options.tgHost
	tgPort = options.tgPort
	args.append(tgPort)
	if(tgHost == None) | (tgPort == None):
		print('[-]You must specify a target host and port[s]!')
		exit(0)
	portScan(tgHost,args)


if __name__ == '__main__':
	main()
