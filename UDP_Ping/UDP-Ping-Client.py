#Steffen Chirichiello

import socket
import timeit
import sys
from sys import argv
from decimal import Decimal


if len(sys.argv) == 3:
    
    client, server_address, server_port = argv

    server_port = int(server_port)
    port = 14001 # has to be different, technically setting up another server
    sequence_number = 1
     
     
    server = (server_address, server_port) # server variable equal to tuple of host and port of server

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.settimeout(1)
    #sock.bind((server_address, port)) #tuple

    ping = 1
    count = 1
    packets_recieved = 10
    rtt_list = []
    ott_list = []
    
    print("Pinging  %s,  %s" % (server_address, server_port)) 
    while count <= 10:
        
        start_RTT =timeit.default_timer()
        start_OTT = timeit.default_timer()
        #OTT sendto srver and then end time is when server receives it, server sends OTT end time tback to server
        sock.sendto(str(ping).encode(), server) # send message to server
        end_OTT = timeit.default_timer()
    
        try:
            
            ping, serverAddress = sock.recvfrom(2048) #store variables received from server with buffer of 2048
            end_RTT = timeit.default_timer()
            
            rtt=(end_RTT-start_RTT)
            rtt_list.append(rtt)
            ott=(end_OTT-start_OTT)
            ott_list.append(ott)
            
            print("ping message number %s: RTT (OTT): %s (%s) secs\n" % (ping.decode(),rtt,ott))
            
            count = count + 1
            ping = str(count)
            continue
        except Exception as e:
        
            print("Ping message number %s: timed out\n" % (ping)) #already decoded
            
            count = count + 1
            ping = str(count)
            packets_recieved -= 1
            continue
else:
    print("Error, program takes 2 arguments")
    sys.exit()
    
print("Number of packets sent: %s" % (count - 1))
print("Number of packets received: %d" % (packets_recieved)) 
print("Number of packets lost: %d" % ((count - 1) - (packets_recieved)))

difference = ((count - 1) - (packets_recieved))
percent_loss = float(((difference) / (count - 1)) * 100)

print("Percent Of Packets Lost: %s" % (percent_loss) + "%\n")

#RTT
rtt_min = rtt_list[0]
rtt_sum = 0
for i in rtt_list:
  
  if i < rtt_min:
    rtt_min = i
    
rtt_max = rtt_list[0]
for i in rtt_list:
  
  if i > rtt_max:
    rtt_max = i

for i in rtt_list:
  
  rtt_sum = rtt_sum + i

rtt_total = (rtt_sum / packets_recieved)
#RTT

#OTT
ott_min = ott_list[0]
ott_sum = 0
for i in ott_list:

  if i < ott_min:
    ott_min = i
    
ott_max = ott_list[0]
for i in ott_list:
  
  if i > ott_max:
    ott_max = i  

for i in ott_list:
  
  ott_sum = ott_sum + i

ott_total = (ott_sum / packets_recieved)  
#OTT 
  
print("RTT MIN: %s" % (rtt_min))
print("RTT MAX: %s" % (rtt_max))
print("RTT AVG: %s\n\n" % (rtt_total))
print("OTT MIN: %s" % (ott_min))
print("OTT MAX: %s" % (ott_max))
print("OTT AVG: %s" % (ott_total))
    
sock.close()
sys.exit()
