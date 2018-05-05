import socket
import random
import sys
import time
#host = socket.gethostname()#IP address of this computer
port = 16000 # port number

# AF_INET is an address family that is used to designate the type of addresses that
# your socket can communicate with (in this case, Internet Protocol v4 addresses).
# When you create a socket, you have to specify its address family, and then you can
# only use addresses of that type with the socket.
# socket diagram UDP(SOCK_DGRAM) is a datagram-based protocol. You send one datagram and get one reply and then the connection terminates.

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 

sock.bind(('', port)) #bind socket to port

print('the server is ready to receive on port ' + str(port))



while True:

    num = (random.randrange(0,11))
    #print(num)
    if num >= 4:
        
        ping, clientAddress = sock.recvfrom(2048) # grab data and address from socket and receive from 2048 buffer 
                                                 # Receive data from the socket. The return value is a string representing the data received. The maximum amount of data to be received at once is specified by bufsize
        print("Responding to ping request with sequence number %s received at %s\n" % (ping.decode(), time.time()))
           # print("client address: " + str(clientAddress))
           # print("message: " + str(message))
    
           # message = str(message).upper()
    
           #print("sending back message: " + str(message))

        sock.sendto(ping, clientAddress) #Send data back to address sent originally
        continue
        sys.exit()  
    else:
        
        ping, clientAddress = sock.recvfrom(2048)
        print("Message with number %s dropped\n" % (ping.decode()))
        continue
        sys.exit()
        
sock.close() #close connection
    
