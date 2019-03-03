#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* codul de eroare returnat de anumite apeluri */
extern int errno;

int main ()
{
  struct sockaddr_in server;	// structura folosita de server
  struct sockaddr_in from;	
  char msg[100];		//mesajul primit de la client 
  char msgrasp[100]=" ";        //mesaj de raspuns pentru client
  int sd;			//descriptorul de socket 

  /* crearea unui socket */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("[server]Eroare la socket().\n");
      return errno;
    }

  /* pregatirea structurilor de date */
  bzero (&server, sizeof (server));
  bzero (&from, sizeof (from));
  
  /* umplem structura folosita de server */
  /* stabilirea familiei de socket-uri */
    server.sin_family = AF_INET;	
  /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl (INADDR_ANY);
  /* utilizam un port utilizator */
    server.sin_port = htons (PORT);
  
  /* atasam socketul */
  if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
      perror ("[server]Eroare la bind().\n");
      return errno;
    }

  /* punem serverul sa asculte daca vin clienti sa se conecteze */
  if (listen (sd, 5) == -1)
    {
      perror ("[server]Eroare la listen().\n");
      return errno;
    }

  /* servim in mod iterativ clientii... */
  while (1)
    {
      int client;
      int length = sizeof (from);

      printf ("[server]Asteptam la portul %d...\n",PORT);
      fflush (stdout);

      /* acceptam un client (stare blocanta pina la realizarea conexiunii) */
      client = accept (sd, (struct sockaddr *) &from, &length);

      /* eroare la acceptarea conexiunii de la un client */
      if (client < 0)
	{
	  perror ("[server]Eroare la accept().\n");
	  continue;
	}
	  
newsockfd = accept(sd, (struct sockaddr *) &server, sizeof (struct sockaddr));
if(newsockfd < 0)
errno("Error on accept");

int num1, num2, answer, choice;

s: n=write(newsockfs,"Enter Number 1: ",strlen("Enter Number 1")); //Ask for number 1
if(n < 0) errno("ERROR writing to socket");
read(newsockfd, &num1, sizeof(int));            //Read No 1
printf("Client - Number 1 is: %d\n" , num1);  

n=write(newsockfs,"Enter Number 2: ",strlen("Enter Number 2")); //Ask for number 2
if(n < 0) errno("ERROR writing to socket");
read(newsockfd, &num2, sizeof(int));            //Read No 2
printf("Client - Number 2 is: %d\n" , num2);   

n=write(newsockfs,"Enter your choice: \n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n",strlen("Enter your choice : : \n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n"));   //Ask for choice
if(n < 0) errno("ERROR writing to socket");
read(newsockfd, &choice, sizeof(int));            //Read choice
printf("Client - Choise is: %d\n" , choice); 

switch(choice)
{
   case 1:
          answer = num1 + num2;
          break;
   case 2:
          answer = num1 - num2;
          break;
   case 3:
          answer = num1*num2;
          break;
   case 4:
          answer = num1/num2;
          break;
   case 5:
          goto Q;
          break;
}

write(newsockfd, &answer, sizeof(int));
if(choise != 5)
      goto s;

Q: close(newstockfd);
   close(sd);	  
   close(client);	  
  }	  
}				
