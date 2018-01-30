#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

/*

int getaddrinfo(const char *node, const char *service,
                       const struct addrinfo *hints,
                       struct addrinfo **res);

           struct addrinfo {
               int              ai_flags;
               int              ai_family;
               int              ai_socktype;
               int              ai_protocol;
               socklen_t        ai_addrlen;
               struct sockaddr *ai_addr;
               char            *ai_canonname;
               struct addrinfo *ai_next;
           };

*/


int main(int argc, char *argv[]){
  struct addrinfo hints, *res;

  hints.ai_family = AF_UNSPEC;
  hints.ai_flags = AI_V4MAPPED | AI_ADDRCONFIG;
  hints.ai_socktype = 0;
  hints.ai_protocol = 0;
  
  int i = getaddrinfo(argv[1], NULL, &hints, &res);

  if(i != 0){
	printf("Error getaddrinfo(): %s\n", gai_strerror(i));
	return -1;
  }

  struct addrinfo *tmp;

  //Voy yendo hacia el siguiente addr
  for(tmp = res; tmp != NULL; tmp = tmp->ai_next){
        char host[NI_MAXHOST];
	getnameinfo(tmp->ai_addr, tmp->ai_addrlen, host, 
		NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
	printf("Host: %s ", host);
	printf("Family: %i ", tmp->ai_family);
	printf("Socktype: %i\n", tmp->ai_socktype);
  }

  freeaddrinfo(res);
  
  return 0;
}
