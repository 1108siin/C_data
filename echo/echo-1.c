//���� ���� :  TCP ���� ���α׷�����, Ŭ���̾�Ʈ�κ��� �޽����� �޾Ƽ� �״�� �ٽ� Ŭ���̾�Ʈ���� ����
#include <stdio.h>
#include <stdlib.h>  // ǥ�� ���̺귯�� �Լ��� ����ϱ� ���� ����
#include <string.h>  // ���ڿ� ó���� ���� �Լ��� ����ϱ� ���� ����
#include <winsock2.h> 

void ErrorHandling(char* message);

int main(int argc, char* argv[])
{
    WSADATA wsaData;  // ������ ���� ���̺귯�� ������ ������ ����ü
    SOCKET hServSock, hClntSock;  // ����(������)����(�ڵ� ��), Ŭ���̾�Ʈ ����(accept ȣ��� ��ȯ�Ǵ� ��) ����
    char message[1024];  //�迭 �� �����͸� ������ ����
    int strLen, i;   // ���ڿ� ���̿� �ݺ������� ����� ����

    SOCKADDR_IN servAdr, clntAdr;  // ��������, Ŭ���̾�Ʈ ������ �ּ����� ����(����ü)
    int clntAdrSize; // Ŭ���̾�Ʈ �ּ� ����ü�� ũ��(������)�� ������ ����

    if (argc != 2) {  // ����� ���ڰ� 2���� �ƴ� ���, �ùٸ� ������ ����ϰ� ����
        printf("�ùٸ� ���� : %s <port>\n", argv[0]);
        exit(1); // ���α׷��� ������ ����
    }


    //��WSAStartup() : ������ ����(����)  �ʱ�ȭ
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        ErrorHandling("ERROR: ������ �ʱ�ȭ �� �� �����ϴ�.");

    //1. socket() : ���Ӵ�� ���� ����
    hServSock = socket(PF_INET, SOCK_STREAM, 0);
    if (hServSock == INVALID_SOCKET)
        ErrorHandling("ERROR: ���� ��� ������ ������ �� �����ϴ�.");

    memset(&servAdr, 0, sizeof(servAdr));  // memset() : ���� �ּ� ����ü�� 0���� �ʱ�ȭ
    //�������� �ּ����� ����
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAdr.sin_port = htons(atoi(argv[1]));

    //2. bind() : ��Ʈ ���ε�
    if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
        ErrorHandling("ERROR: ���Ͽ� IP�ּҿ� ��Ʈ�� ���ε� �� �� �����ϴ�.");

    //3. listen() : ���Ӵ�� ���·� ��ȯ
    if (listen(hServSock, 3) == SOCKET_ERROR)
        ErrorHandling("ERROR: ���� ���·� ��ȯ�� �� �����ϴ�.");

    clntAdrSize = sizeof(clntAdr); // Ŭ���̾�Ʈ �ּ� ����ü�� ũ�⸦ ����   


    //4.1. accept() : Ŭ���̾�Ʈ ������ �޾Ƶ��̰� ���ο� ���� ����(����)
    for (i = 0; i < 3; i++)  //3���� Ŭ���̾�Ʈ���Ը� ����
    {
        hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSize);
        if (hClntSock == -1)
            ErrorHandling("ERROR: ���� ��û�� ������ �� �����ϴ� ");
        else
            printf("�� Ŭ���̾�Ʈ��  �����  %d \n", i + 1);  // ���� ���� �� �޽����� ���, ����Ƚ�� ���


        //4.2. recv() : Ŭ���̾�Ʈ�κ��� ���ڿ��� ������.
        while ((strLen = recv(hClntSock, message, 1024, 0)) != 0) {  //�������κ��� �������� �ƴҶ����� �޽��� ����
            //recv�� 0�� ��ȯ�ϸ� ���濡 ���� ������ ����Ǿ����� ��Ÿ��
            if (strLen == SOCKET_ERROR)
                ErrorHandling("ERROR: Ŭ���̾�Ʈ�� ���� ������ �� �����ϴ�.");

            // ���� �޽��� ���۸� null�� �ʱ�ȭ
            memset(message + strLen, 0, 1024 - strLen); //// message ���ۿ��� ���� ���ŵ� �������� ������ ������ ������ �κ��� 0���� �ʱ�ȭ

            // 4.3. ������ �޽����� ���
            message[strLen] = 0; // ���ڿ� ���� ���� �߰�
            printf("������ �޽���: %s\n", message);


            // 4.3. send() : ������ ���ڿ��� �״�� �ݴ�� ����.
            send(hClntSock, message, strLen, 0);
            printf("�����Ͽ� �ٽ� ������  �޽���: %s\n", message);
        }

        //4.4  closesocket() : Ŭ���̾�Ʈ�� ������ ������.
        closesocket(hClntSock);
        puts("Ŭ���̾�Ʈ ������ ������ϴ�.");

    }
    //5. ���� ���� �ݱ�
    closesocket(hServSock);

    //��  WSACleanup() : ���� ���̺귯�� ����
    WSACleanup();
    return 0;
}

void ErrorHandling(char* message) // ���� �޽����� ����ϴ� �Լ�
{
    fputs(message, stderr); // ���� �޽����� ǥ�� ���� ��¿� ���
    fputc('\n', stderr);
    exit(1);
}