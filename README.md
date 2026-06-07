# tcp — TCP networking for Zeta

**Namespace:** `@net/tcp`

TCP socket creation, binding, listening, and non-blocking configuration.
Async accept/connect/send/recv via `@io/uring` opcodes.

## Usage

```zeta
use net::tcp::{TcpSocket, AF_INET, SOCK_STREAM};

let sock: TcpSocket = TcpSocket_new();
TcpSocket_bind_v4(&sock, 8080, 0);
TcpSocket_listen(&sock, 128);
TcpSocket_set_nonblocking(&sock);

// Accept via io_uring SQE
// Connect via io_uring SQE
```

## API

| Function | Description |
|----------|-------------|
| `TcpSocket_new()` | Create a TCP socket |
| `TcpSocket_bind_v4(port, addr)` | Bind to IPv4 address |
| `TcpSocket_listen(backlog)` | Start listening |
| `TcpSocket_set_nonblocking()` | Enable non-blocking mode |
| `TcpSocket_close()` | Close the socket |

## Dependencies

- `@io/uring` — for async accept/connect/send/recv operations

## License

MIT — The Zeta Foundation
