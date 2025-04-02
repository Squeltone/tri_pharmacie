#include <stdio.h>      // Pour les fonctions d'entrée/sortie standard
#include <stdlib.h>     // Pour exit()
#include <string.h>     // Pour strlen()
#include <winsock2.h>   // Pour l'API socket Windows
#include <ws2tcpip.h>   // Extensions TCP/IP pour Windows

// Définition des constantes
#define PENDING_QUEUE_MAXLENGTH 1  // Nombre maximum de connexions en attente
#define LISTENING_PORT 135         // Port d'écoute du serveur
#define BUFFER_SIZE 1024          // Taille du buffer pour les messages

int main(void)
{
    // Étape 1 : Initialisation de la bibliothèque Winsock
    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        fprintf(stderr, "(SERVEUR) Failed. Error Code : %d\n", WSAGetLastError());
        exit(1);
    }

    // Étape 2 : Création du socket TCP/IP
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if(socketFD == -1) {
        fprintf(stderr, "(SERVEUR) Failed. Error Code : %d\n", WSAGetLastError());
        exit(1);
    }

    // Étape 3 : Configuration de l'adresse du serveur
    struct sockaddr_in socketAddr;
    socketAddr.sin_family = AF_INET;           // Famille d'adresses IPv4
    socketAddr.sin_port = LISTENING_PORT;      // Port d'écoute
    socketAddr.sin_addr.s_addr = INADDR_ANY;   // Accepte les connexions sur toutes les interfaces
    int socketAddrLen = sizeof(socketAddr);

    // Liaison du socket avec l'adresse configurée
    int bindReturnCode = bind(socketFD, (struct sockaddr *)&socketAddr, socketAddrLen);
    if(bindReturnCode == -1) {
        fprintf(stderr, "(SERVEUR) Failed. Error liaison pour le socket : %d\n", WSAGetLastError());
        exit(1);
    }

    // Étape 4 : Mise en écoute du socket
    if(listen(socketFD, PENDING_QUEUE_MAXLENGTH) == -1) {
        fprintf(stderr, "(SERVEUR) Failed. Error demarrage de l'ecoute des connexions entrantes : %d\n", WSAGetLastError());
        exit(1);
    }

    puts("En attente de connexions entrantes...");

    // Étape 5 : Acceptation d'une connexion cliente
    int connectedSocketFD = accept(socketFD, (struct sockaddr *)&socketAddr, (socklen_t*) &socketAddrLen);
    if(connectedSocketFD == -1) {
        fprintf(stderr, "(SERVEUR) Failed. Error acceptation de la connexion : %d\n", WSAGetLastError());
        exit(1);
    }

    // Étape 6 : Boucle de communication
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    
    while(1) {
        // Réception du message du client
        memset(buffer, 0, BUFFER_SIZE);
        int receivedBytes = recv(connectedSocketFD, buffer, BUFFER_SIZE, 0);
        if(receivedBytes == -1) {
            fprintf(stderr, "(SERVEUR) Failed. Error reception du message : %d\n", WSAGetLastError());
            break;
        }
        if(receivedBytes == 0) {
            printf("Le client s'est deconnecte.\n");
            break;
        }
        printf("Client : %s", buffer);

        // Vérification si le client veut quitter
        if(strncmp(buffer, "quit", 4) == 0) {
            printf("Le client a demandé la fermeture de la connexion.\n");
            break;
        }

        // Saisie et envoi d'une réponse au client
        printf("Entrez votre message pour le client (ou 'quit' pour quitter) : ");
        fgets(message, BUFFER_SIZE, stdin);

        // Vérification si le serveur veut quitter
        if(strncmp(message, "quit", 4) == 0) {
            printf("Fermeture de la connexion...\n");
            break;
        }
        
        int sentBytes = send(connectedSocketFD, message, strlen(message), 0);
        if(sentBytes == -1) {
            fprintf(stderr, "(SERVEUR) Failed. Error envoi du message : %d\n", WSAGetLastError());
            break;
        }
        printf("Message envoyé au client : %s", message);
    }

    // Étape 7 : Nettoyage et fermeture
    closesocket(connectedSocketFD);    // Fermeture du socket client
    closesocket(socketFD);             // Fermeture du socket serveur
    WSACleanup();                      // Libération des ressources Winsock
    return 0;
}