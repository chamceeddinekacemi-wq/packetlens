#ifndef PACKET_H
#define PACKET_H

#include <stdint.h>
#include <stdio.h>

typedef struct
{
    uint8_t dst_mac[6];
    uint8_t src_mac[6];
    uint16_t ether_type;
} eth_header_t;

typedef struct 
{
    uint8_t version_ihl;
    uint8_t tos;
    uint16_t total_length;
    uint16_t identification;
    uint16_t flags_frag_offset;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t header_checksum;
    uint32_t src_ip;
    uint32_t dst_ip;

}ip_header_t;

typedef struct 
{
    uint16_t src_port;
    uint16_t dst_port;
    uint16_t length;
    uint16_t checksum;

}udp_header_t;

typedef struct 
{
    uint8_t type;
    uint8_t code;
    uint16_t checkSum;
    uint32_t rest_of_header;
}icmp_header_t;

typedef struct 
{
    uint16_t src_port;
    uint16_t dst_port;
    uint32_t seq_number;
    uint32_t ack_number;
    uint16_t data_offset_flags;
    uint16_t window_size;
    uint16_t checksum;
    uint16_t urgent_pointer;

}tcp_header_t;

typedef struct
{
    eth_header_t eth_header;
    ip_header_t ip_header;
    union
    {
        tcp_header_t tcp;
        udp_header_t udp;
        icmp_header_t icmp;
    }l4;
    uint8_t * payload;
    uint16_t payload_len;

}packet_t;


#endif // PACKETLENS_PARSER_H