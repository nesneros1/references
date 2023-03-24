
# For building the socket
import socket

# For system level commands
import sys

# For doing an array in the TCP checksum
import array

# For establishing the packet structure (Used later on), this will allow direct access to the methods and functions in the struct module
from struct import *

# Create a raw socket.
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_RAW)
except socket.error as msg:
    print(msg)
    sys.exit()

packet = ''

src_ip = "10.50.33.117"
dst_ip = "172.16.40.10"

# Lets add the IPv4 header information
ip_ver_ihl = 69                       # This is putting the decimal conversion of 0x45 for Version and Internet Header Length
ip_tos = 0                            # This combines the DSCP and ECN feilds
ip_len = 0                            # The kernel will fill in the actually length of the packet
ip_id = 2020                         # This sets the IP Identification for the packet
ip_frag = 0                           # This sets fragmentation to off
ip_ttl = 64                           # This determines the TTL of the packet when leaving the machine
ip_proto = 6                          # This sets the IP protocol to 6 (TCP) so additional headers are required
ip_check = 0                          # The kernel will fill in the checksum for the packet
ip_srcadd = socket.inet_aton(src_ip)  # inet_aton(string) will convert an IP address to a 32 bit binary number
ip_dstadd = socket.inet_aton(dst_ip)  # inet_aton(string) will convert an IP address to a 32 bit binary number

ip_header = pack('!BBHHHBBH4s4s' , ip_ver_ihl, ip_tos, ip_len, ip_id, ip_frag, ip_ttl, ip_proto, ip_check, ip_srcadd, ip_dstadd)

# Tcp header fields
tcp_src = 54321                       # source port
tcp_dst = 1234                        # destination port
tcp_seq = 90210                         # sequence number
tcp_ack_seq = 30905                       # tcp ack sequence number
tcp_data_off = 5                      # data offset specifying the size of tcp header * 4 which is 20
tcp_reserve = 0                       # the 3 reserve bits + ns flag in reserve field
tcp_flags = 0                         # tcp flags field before the bits are turned on
tcp_win = 65535                       # maximum allowed window size reordered to network order
tcp_chk = 0                           # tcp checksum which will be calculated later on
tcp_urg_ptr = 0                       # urgent pointer only if urg flag is set

# Combine the left shifted 4 bit tcp offset and the reserve field
tcp_off_res = (tcp_data_off << 4) + tcp_reserve


# Tcp flags by bit starting from right to left
tcp_fin = 0                           # Finished
tcp_syn = 1                           # Synchronization
tcp_rst = 0                           # Reset
tcp_psh = 0                           # Push
tcp_ack = 0                           # Acknowledgment
tcp_urg = 0                           # Urgent
tcp_ece = 0                           # Explicit Congestion Notification Echo
tcp_cwr = 0                           # Congestion Window Reduced

# Combine the tcp flags by left shifting the bit locations and adding the bits together
tcp_flags = tcp_fin + (tcp_syn << 1) + (tcp_rst << 2) + (tcp_psh << 3) + (tcp_ack << 4) + (tcp_urg << 5) + (tcp_ece << 6) + (tcp_cwr << 7)


# The ! in the pack format string means network order
tcp_hdr = pack('!HHLLBBHHH', tcp_src, tcp_dst, tcp_seq, tcp_ack_seq, tcp_off_res, tcp_flags, tcp_win, tcp_chk, tcp_urg_ptr)


user_data = b'This is my message coded into the socket'


# Pseudo header fields
src_address = socket.inet_aton(src_ip)
dst_address = socket.inet_aton(dst_ip)
reserved = 0
protocol = socket.IPPROTO_TCP
tcp_length = len(tcp_hdr) + len(user_data)

# Pack the pseudo header and combine with user data
ps_hdr = pack('!4s4sBBH', src_address, dst_address, reserved, protocol, tcp_length)
ps_hdr = ps_hdr + tcp_hdr + user_data

def checksum(data):
        if len(data) % 2 != 0:
                data += b'\0'
        res = sum(array.array("H", data))
        res = (res >> 16) + (res & 0xffff)
        res += res >> 16
        return (~res) & 0xffff


tcp_chk = checksum(ps_hdr)

# Pack the tcp header to fill in the correct checksum - remember checksum is NOT in network byte order
tcp_hdr = pack('!HHLLBBH', tcp_src, tcp_dst, tcp_seq, tcp_ack_seq, tcp_off_res, tcp_flags, tcp_win) + pack('H', tcp_chk) + pack('!H', tcp_urg_ptr)


# Combine all of the headers and the user data
packet = ip_header + tcp_hdr + user_data

# Send the packet
s.sendto(packet, (dst_ip, 0))
