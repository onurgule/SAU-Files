#include <stdlib.h>
#include <stdio.h>

#include <pcap.h>


int main(int argc, char **argv)
{

    char *dev = NULL;
    pcap_t *fp;
    char errbuffer[PCAP_ERRBUF_SIZE];
    u_char packet[50];
    int i;

    dev = pcap_lookupdev(errbuffer);
    if (dev == NULL) {
        printf("Error finding device: %s\n", errbuffer);
        exit(EXIT_FAILURE);
    }
	

    printf("Active ethernet device: %s\n", dev);
    fp = pcap_open_live(dev, 100, 1, 1000, errbuffer);



    // Ethernet Header

    //Destination Mac-00:50:56:FC:18:27

    packet[0]=0x00;
    packet[1]=0x50;
    packet[2]=0x56;
    packet[3]=0xfc;
    packet[4]=0x18;
    packet[5]=0x27;
 
    //Source Mac-00:0C:29:cd:27:50

    packet[6]=0x00;
    packet[7]=0x0c;
    packet[8]=0x29;
    packet[9]=0xcd;
    packet[10]=0x27;
    packet[11]=0x50;

	
    //Tip
		

    packet[12]=0x08;
    packet[13]=0x00;


    //IP BAŞLIK YAPISI

    //versiyon+header lenght
    packet[14]=0x45;

    //servis alanı

    packet[15]=0x00;

    // total length

    packet[16]=0x00;
    packet[17]=0x24;

    //identification

    packet[18]=0x10;
    packet[19]=0xfd;

    //Fragmantaston

    packet[20]=0x00;
    packet[21]=0x00;

    //ttl değeri

    packet[22]=0x40;
    
    //protocol bilgisi

    packet[23]=0x01;


    //header cheksum

    packet[24]=0x00;
    packet[25]=0x00;

    //kaynak IP-192.168.11.128
    packet[26]=0xc0;
    packet[27]=0xa8;
    packet[28]=0x0b;
    packet[29]=0x80;


    //hedef IP-216.58.206.196
    packet[30]=0xd8;
    packet[31]=0x3a;
    packet[32]=0xce;
    packet[33]=0xc4;


    //ICMP REQUEST

    //tip alanı
    packet[34]=0x08;
    
    //kod
    packet[35]=0x00;

    //checksum

    packet[36]=0x00;
    packet[37]=0x00;

    //rest of header

    packet[38]=0x11;
    packet[39]=0x8d;
    packet[40]=0x00;
    packet[41]=0x1b;

    //zaman damgası
    packet[42]=0xa6;
    packet[43]=0x5d;
    packet[44]=0x4d;
    packet[45]=0x5e;
    packet[46]=0x00;
    packet[47]=0x00;
    packet[48]=0x00;
    packet[49]=0x00;



    /* Send down the packet */
    if (pcap_sendpacket(fp, packet, 50 /* size */) != 0)
    {
        fprintf(stderr,"\nError sending the packet: \n", pcap_geterr(fp));
        return;
    }

    return;
}
