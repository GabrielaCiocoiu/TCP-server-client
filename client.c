#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

/* codul de eroare returnat de anumite apeluri */
extern int errno;

/* portul de conectare la server*/
int port;

int main (int argc, char *argv[])
{
  int sd, n;			// descriptorul de socket
  struct sockaddr_in server;
  char buffer[256];


  /* exista toate argumentele in linia de comanda? */
  if (argc != 3)
    {
      printf ("Sintaxa: %s <adresa_server> <port>\n", argv[0]);
      return -1;
    }

  /* stabilim portul */
  port = atoi (argv[2]);

  /* cream socketul */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("Eroare la socket().\n");
      return errno;
    }

  /* umplem structura folosita pentru realizarea conexiunii cu serverul */
  /* familia socket-ului */
  server.sin_family = AF_INET;
  /* adresa IP a serverului */
  server.sin_addr.s_addr = inet_addr(argv[1]);
  /* portul de conectare */
  server.sin_port = htons (port);
  
  /* ne conectam la server */
  if (connect (sd, (struct sockaddr *) &server,sizeof (server)) < 0)
    {
      perror ("[client]Eroare la connect().\n");
      return errno;
    }

 int num1, num2, answer, choice;

s:bzero(buffer,256);
  n=read(sd,buffer,255);                           //read server string
  if(n<0) errno("ERROR reading from socket");
  printf("Server - %s\n",buffer);
  scanf("%d", &num1);                              //enter nr 1
  write(sd, &num1, sizeof(int));                    //send nr 1 to server

  bzero(buffer,256);
  n=read(sd,buffer,255);                          //read server string
  if(n<0) errno("ERROR reading from socket");
  printf("Server - %s\n",buffer);
  scanf("%d", &num2);                              //enter nr 2
  write(sd, &num2, sizeof(int));                    //send nr 2 to server

  bzero(buffer,256);
  n=read(sd,buffer,255);                            //read server string
  if(n<0) errno("ERROR reading from socket");
  printf("Server - %s",buffer);
  scanf("%d", &choice);                              //enter choice
  write(sd, &choice, sizeof(int));                    //send choice to server

  if(choise == 5)
          goto Q;

  read(sd, &answer, sizeof(int));
  printf("Server - The answer is: %d\n", answer);

  if(choise != 5)
      goto s;

  Q:
   printf("you have selected to exit. Exit Successful.");

  /* inchidem conexiunea, am terminat */
  close (sd);
}
