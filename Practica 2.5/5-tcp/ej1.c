#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


void main(int argc, char *argv[]) {
  struct addrinfo hints, *res;
  struct sockaddr_storage cliente;

  char buf[81], host[NI_MAXHOST], serv[NI_MAXSERV];

  hints.ai_flags = AI_PASSIVE;
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = 0;

  getaddrinfo(argv[1], argv[2], &hints, &res);

  int sd = socket(res->ai_family, res->ai_socktype, 0);

  bind(sd,(struct sockaddr *)res->ai_addr, res->ai_addrlen);

  freeaddrinfo(res);

  listen(sd, 5);

  socklen_t clen = sizeof(cliente);
  int cliente_sd = accept(sd, (struct sockaddr *) &cliente, &clen);
  getnameinfo((struct sockaddr *) &cliente, clen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST);
  printf("Conexión desde Host:%s Puerto:%s\n", host, serv);

  while (1) {
    int c = recv(cliente_sd, buf, 80, 0);

    send(cliente_sd, buf, c, 0);
  }
  close(cliente_sd);

}
