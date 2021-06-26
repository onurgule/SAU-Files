#include <stdlib.h>
#include <stdio.h>
#include <pcap.h>


int main(int argc, char **argv)
{

    char *dev = NULL;
    pcap_t *fp;
    char errbuffer[PCAP_ERRBUF_SIZE];
    u_char packet[42];
    int i;

    dev = pcap_lookupdev(errbuffer);
    if (dev == NULL) {
        printf("Error finding device: %s\n", errbuffer);
        exit(EXIT_FAILURE);
    }
	

    printf("Active ethernet device: %s\n", dev);
    fp = pcap_open_live(dev, 100, 1, 1000, errbuffer);



    // Ethernet Header

    // Destination MAC - 6 octets: ff:ff:ff:ff:ff:ff
    packet[0]=0xff;
    packet[1]=0xff;
    packet[2]=0xff;
    packet[3]=0xff;
    packet[4]=0xff;
    packet[5]=0xff;
   
	//00-1E-65-8B-4F-FE

    // Source MAC - 6 octets: 54:42:49:02:31:8c
    packet[6]=0x54;
    packet[7]=0x42;
    packet[8]=0x49;
    packet[9]=0x02;
    packet[10]=0x31;
    packet[11]=0x8c;

    // Ethernet Type - 2 octets: 0x0806 (ARP)
    packet[12]=0x08;
    packet[13]=0x06;


    // ARP Packet

    // Hardware type - 2 octets: Ethernet : 0x0001=Request
    packet[14]=0x00;
    packet[15]=0x01;

    // Protocol type - 2 octets: IP: 0x0800
    packet[16]=0x08;
    packet[17]=0x00;
    
    // Hardware size: 1 octet: 6
    packet[18]=0x06;

    // Protocol size: 1 octet: 4
    packet[19]=0x04;

    // Opcode: 2 octets: request - 0x0001
    packet[20]=0x00;
    packet[21]=0x01;

    // Sender MAC address: 6 octets
    packet[22]=0x54;
    packet[23]=0x42;
    packet[24]=0x49;
    packet[25]=0x02;
    packet[26]=0x31;
    packet[27]=0x8c;

    // Sender IP address: 4 octets: 10.9.27.225 - 0a.09.1b.e1
    packet[28]=0x0a;
    packet[29]=0x09;
    packet[30]=0x1b;
    packet[31]=0xe1;

    // Target MAC address: 6 octets: 00:00:00:00:00:00
    packet[32]=0x00;
    packet[33]=0x00;
    packet[34]=0x00;
    packet[35]=0x00;
    packet[36]=0x00;
    packet[37]=0x00;

    // Target IP address: 4 octets: 10.9.27.100 - 0a.09.1b.64
    packet[38]=0x0a;
    packet[39]=0x09;
    packet[40]=0x1b;
    packet[41]=0x64;


    /* Send down the packet */
    if (pcap_sendpacket(fp, packet, 42 /* size */) != 0)
    {
        fprintf(stderr,"\nError sending the packet: \n", pcap_geterr(fp));
        return;
    }

    return;
}
