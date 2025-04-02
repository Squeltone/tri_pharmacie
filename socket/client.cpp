#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>    // Pour les fonctions socket Windows
#include <ws2tcpip.h>    // Pour inet_pton

// Configuration des constantes
#define LISTENING_PORT 135
#define BUFFER_SIZE 1024
#define CONNECTION_HOST "192.168.65.164" // Adresse IP du serveur

int main(void)
{
    // Étape 1: Initialisation de la bibliothèque Winsock
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        fprintf(stderr, "(CLIENT) Failed. Error Code : %d\n", WSAGetLastError());
        exit(1);
    }

    // Étape 2: Création d'un socket TCP/IP
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD == -1)
    {
        fprintf(stderr, "(CLIENT) Failed. Error Code : %d\n", WSAGetLastError());
        exit(1);
    }

    // Étape 3: Configuration de l'adresse du serveur
    struct sockaddr_in socketAddr;
    socketAddr.sin_family = AF_INET;            // Famille d'adresses IPv4
    socketAddr.sin_port = LISTENING_PORT;       // Port du serveur
    
    // Conversion de l'adresse IP texte en format binaire
    int inetReturnCode = inet_pton(AF_INET, CONNECTION_HOST, &socketAddr.sin_addr);
    if (inetReturnCode == -1)
    {
        fprintf(stderr, "(CLIENT) Failed. Error invalide ou non prise en charge : %d\n", WSAGetLastError());
        exit(1);
    }

    int socketAddrLen = sizeof(socketAddr);

    // Étape 4: Connexion au serveur
    int connectionStatus = connect(socketFD, (struct sockaddr *)&socketAddr, socketAddrLen);
    if (connectionStatus == -1)
    {
        fprintf(stderr, "(CLIENT) Failed. Error connexion au serveur : %d\n", WSAGetLastError());
        exit(1);
    }

    // Étape 5: Boucle de communication
    char message[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    
    while(1) {
        // Envoi du message
        printf("Entrez votre message (ou 'quit' pour quitter) : ");
        fgets(message, BUFFER_SIZE, stdin);
        
        // Vérification si l'utilisateur veut quitter
        if(strncmp(message, "quit", 4) == 0) {
            printf("Fermeture de la connexion...\n");
            break;
        }
        
        // Envoi du message au serveur
        int sentBytes = send(socketFD, message, strlen(message), 0);
        if (sentBytes == -1) {
            fprintf(stderr, "(CLIENT) Failed. Error envoi du message au serveur : %d\n", WSAGetLastError());
            break;
        }
        printf("Message envoyé au serveur : %s", message);

        // Réception de la réponse du serveur
        memset(buffer, 0, BUFFER_SIZE);  // Réinitialisation du buffer
        int receivedBytes = recv(socketFD, buffer, BUFFER_SIZE, 0);
        if (receivedBytes == -1) {
            fprintf(stderr, "(CLIENT) Failed. Error reception du message : %d\n", WSAGetLastError());
            break;
        }
        printf("Serveur : %s", buffer);
    }

    // Étape 6: Nettoyage et fermeture
    closesocket(socketFD);
    WSACleanup();
    return 0;
}