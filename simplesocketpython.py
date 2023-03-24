import socket
def send(x):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	#can be accomplished with socket.socket since its the default 
        ipaddr = '127.0.0.1'
        port = 12345
        s.connect((ipaddr, port))
        s.send(x.encode())
        s.close()
while True:
        open = input("Enter your message:\n")
        if open != "":
                send(open)
        else:
                break
