#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h> // Pour les fonctions socket Windows
#include <ws2tcpip.h> // Pour inet_pton

// Configuration des constantes
#define LISTENING_PORT 502
#define BUFFER_SIZE 1024
#define CONNECTION_HOST "192.168.64.200" // Adresse IP du serveur

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
    int socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketFD == -1)
    {
        fprintf(stderr, "(CLIENT) Failed. Error Code : %d\n", WSAGetLastError());
        exit(1);
    }

    // Étape 3: Configuration de l'adresse du serveur
    struct sockaddr_in socketAddr;
    socketAddr.sin_family = AF_INET;             // Famille d'adresses IPv4
    socketAddr.sin_port = htons(LISTENING_PORT); // Port du serveur

    // Conversion de l'adresse IP texte en format binaire
    int inetReturnCode = inet_pton(AF_INET, CONNECTION_HOST, &socketAddr.sin_addr);
    if (inetReturnCode == -1)
    {
        fprintf(stderr, "(CLIENT) Failed. Error invalide ou non prise en charge : %d\n", WSAGetLastError());
        exit(1);
    }
    socketAddr.sin_addr.s_addr = inet_addr(CONNECTION_HOST); // Adresse IP du serveur
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

    while (1)
    {
        // Envoi du message
        printf("Entrez votre message (ou 'quit' pour quitter) : ");
        fgets(message, BUFFER_SIZE, stdin);

        // Vérification si l'utilisateur veut quitter
        if (strncmp(message, "quit", 4) == 0)
        {
            printf("Fermeture de la connexion...\n");
            break;
        }
        // Vérification si l'utilisateur veut envoyer la trame d'allumage tapis
            if (strncmp(message, "tapisON", 7) == 0)
            {
                printf("Envoi trame allumage tapis\n");

                // Création de la trame Modbus
                unsigned char trame[] = {
                    0x00, 0x01, // Transaction ID
                    0x00, 0x00, // Protocol ID
                    0x00, 0x06, // Length
                    0xFF,       // Unit ID
                    0x06,       // Function code (write)
                    0x00, 0x00, // Address
                    0xFF, 0x00  // Value (FF00 pour ON)
                };

                // Affichage de la trame pour debug
                printf("Trame envoyée : ");
                for (int i = 0; i < sizeof(trame); i++)
                {
                    printf("%02X ", trame[i]);
                }
                printf("\n");

                // Envoi de la trame
                int sentBytes = send(socketFD, (const char *)trame, sizeof(trame), 0);
                if (sentBytes == -1)
                {
                    fprintf(stderr, "(CLIENT) Failed. Error envoi de la trame : %d\n", WSAGetLastError());
                    break;
                }
                printf("Trame envoyée avec succès (%d bytes)\n", sentBytes);

                // Attente de la réponse
                memset(buffer, 0, BUFFER_SIZE);
                int receivedBytes = recv(socketFD, buffer, BUFFER_SIZE, 0);
                if (receivedBytes == -1)
                {
                    fprintf(stderr, "(CLIENT) Failed. Error réception de la réponse : %d\n", WSAGetLastError());
                    break;
                }

                // Affichage de la réponse en hexadécimal
                printf("Réponse reçue : ");
                for (int i = 0; i < receivedBytes; i++)
                {
                    printf("%02X ", (unsigned char)buffer[i]);
                }
                printf("\n");
                continue;
            }
            if (strncmp(message, "tapisOFF", 8) == 0)
            {
                printf("Envoi trame allumage tapis\n");
    
                // Création de la trame Modbus
                unsigned char trame[] = {
                    0x00, 0x01, // Transaction ID
                    0x00, 0x00, // Protocol ID
                    0x00, 0x06, // Length
                    0xFF,       // Unit ID
                    0x06,       // Function code (write)
                    0x00, 0x00, // Address
                    0xFF, 0x01  // Value (FF01 pour OFF)
                };
                // Affichage de la trame pour debug
                printf("Trame envoyée : ");
                for (int i = 0; i < sizeof(trame); i++)
                {
                    printf("%02X ", trame[i]);
                }
                printf("\n");

                // Envoi de la trame
                int sentBytes = send(socketFD, (const char *)trame, sizeof(trame), 0);
                if (sentBytes == -1)
                {
                    fprintf(stderr, "(CLIENT) Failed. Error envoi de la trame : %d\n", WSAGetLastError());
                    break;
                }
                printf("Trame envoyée avec succès (%d bytes)\n", sentBytes);

                // Attente de la réponse
                memset(buffer, 0, BUFFER_SIZE);
                int receivedBytes = recv(socketFD, buffer, BUFFER_SIZE, 0);
                if (receivedBytes == -1)
                {
                    fprintf(stderr, "(CLIENT) Failed. Error réception de la réponse : %d\n", WSAGetLastError());
                    break;
                }

                // Affichage de la réponse en hexadécimal
                printf("Réponse reçue : ");
                for (int i = 0; i < receivedBytes; i++)
                {
                    printf("%02X ", (unsigned char)buffer[i]);
                }
                printf("\n");
                continue;
            }
            // Vérification si l'utilisateur veut envoyer la trame d'allumage tapis
            if (strncmp(message, "tapisOFF", 8) == 0)
            {
                printf("Envoi trame eteinte tapis\n");
                int sentBytes = send(socketFD, message, strlen(message), 0);
                if (sentBytes == -1)
                {
                    fprintf(stderr, "(CLIENT) Failed. Error envoi du message au serveur : %d\n", WSAGetLastError());
                    break;
                }
                break;
            }

            // Réception de la réponse du serveur
            memset(buffer, 0, BUFFER_SIZE); // Réinitialisation du buffer
            int receivedBytes = recv(socketFD, buffer, BUFFER_SIZE, 0);
            if (receivedBytes == -1)
            {
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