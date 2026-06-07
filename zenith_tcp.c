/* TCP socket wrappers for @net/tcp Zeta package.
 * Compile with: gcc -O2 -fPIC -c zenith_tcp.c -o zenith_tcp.o
 * Link with: ... zenith_tcp.o zenith_runtime_c.o -lzstd
 */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

long tcp_socket(int domain, int type, int protocol) {
    return socket(domain, type, protocol);
}
long tcp_bind(int fd, int domain, unsigned short port, const char* addr) {
    if (domain == AF_INET) {
        struct sockaddr_in sa = {0};
        sa.sin_family = AF_INET;
        sa.sin_port = htons(port);
        sa.sin_addr.s_addr = addr ? inet_addr(addr) : INADDR_ANY;
        return bind(fd, (struct sockaddr*)&sa, sizeof(sa));
    }
    return -1;
}
long tcp_listen(int fd, int backlog) { return listen(fd, backlog); }
long tcp_set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}
long tcp_close(int fd) { return close(fd); }
