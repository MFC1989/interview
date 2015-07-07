// testPing.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


 #include <winsock2.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

int __cdecl main(int argc, char **argv)  {

    // Declare and initialize variables
    
    HANDLE hIcmpFile;
    unsigned long ipaddr = INADDR_NONE;
    DWORD dwRetVal = 0;
    char SendData[32] = "Data Buffer";
    LPVOID ReplyBuffer = NULL;
    DWORD ReplySize = 0;
    
    // Validate the parameters
    //if (argc != 2) {
    //    printf("usage: %s IP address\n", argv[0]);
    //    return 1;
    //}

    ipaddr = inet_addr("180.97.33.108");
    if (ipaddr == INADDR_NONE) {
        printf("usage: %s IP address\n", argv[0]);
       // return 1;
    }
    
    hIcmpFile = IcmpCreateFile();
    if (hIcmpFile == INVALID_HANDLE_VALUE) {
        printf("\tUnable to open handle.\n");
        printf("IcmpCreatefile returned error: %ld\n", GetLastError() );
      //  return 1;
    }    

    ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
    ReplyBuffer = (VOID*) malloc(ReplySize);
    if (ReplyBuffer == NULL) {
       // printf("\tUnable to allocate memory\n");
        return 1;
    }    
    
    
	for (int i=0;i<100;i++)
	{
		dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr, SendData, sizeof(SendData), 
			NULL, ReplyBuffer, ReplySize, 5000);
		if (dwRetVal != 0) {
			PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;
			struct in_addr ReplyAddr;
			ReplyAddr.S_un.S_addr = pEchoReply->Address;
			printf("\tSent icmp message to %s\n", argv[1]);
			if (dwRetVal > 1) {
				printf("\tReceived %ld icmp message responses\n", dwRetVal);
				printf("\tInformation from the first response:\n"); 
			}    
			else {    
				printf("\tReceived %ld icmp message response\n", dwRetVal);
				printf("\tInformation from this response:\n"); 
			}    
			printf("\t  Received from %s\n", inet_ntoa( ReplyAddr ) );
			printf("\t  Status = %ld\n", 
				pEchoReply->Status);
			printf("\t  Roundtrip time = %ld milliseconds\n", 
				pEchoReply->RoundTripTime);
		}
		else {
			printf("\tCall to IcmpSendEcho failed.\n");
			printf("\tIcmpSendEcho returned error: %ld\n", GetLastError() );
			//return 1;
		}
	}
   
    return 0;
}    
    

