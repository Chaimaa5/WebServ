If you want to make your own web server in C++ 98, the first thing you should do is to familiarize yourself with the HTTP protocol, which is the standard protocol used for communication between web servers and web clients.

Once you have a good understanding of the HTTP protocol, the next step would be to design the architecture of your web server. This involves deciding on the server's basic functionality, such as handling incoming requests, processing client data, serving static and dynamic content, and managing connections.

After designing the architecture, you can start implementing your web server in C++ 98. You will need to use socket programming to create the server's network functionality, such as accepting incoming client connections and sending and receiving data over the network.

Some basic steps for creating a web server in C++ 98 include:

Setting up a socket using the socket() function
Binding the socket to a specific IP address and port using the bind() function
Listening for incoming connections using the listen() function
Accepting incoming connections using the accept() function
Receiving and processing HTTP requests from the client
Sending HTTP responses to the client
There are also many libraries available in C++ 98 that can help you to create a web server more easily, such as Boost.Asio and libevent. These libraries provide abstractions for network programming that can simplify the development process.


<!-- STEPS -->

Choose a socket API: You'll need to decide which socket API to use for your server. The most commonly used socket APIs are the BSD sockets API and the Windows Sockets API (WinSock).

Create a socket: Once you have chosen your socket API, the first step is to create a socket. The socket() function is used to create a socket, and it takes three arguments: the address family (e.g., AF_INET for IPv4), the socket type (e.g., SOCK_STREAM for TCP), and the protocol (usually set to 0).

Bind the socket to an IP address and port number: After you have created the socket, you need to bind it to an IP address and port number. The bind() function is used for this, and it takes the socket file descriptor as its first argument, and a sockaddr_in structure as its second argument, which contains the IP address and port number.

Listen for incoming connections: Once the socket is bound, you can start listening for incoming connections using the listen() function. This function takes the socket file descriptor as its first argument, and a backlog parameter as its second argument, which specifies the maximum number of pending connections that can be queued.

Accept incoming connections: When a client tries to connect to the server, the accept() function is used to accept the incoming connection. This function blocks until a client connection is received, and then returns a new socket file descriptor that is used to communicate with the client.

Parse incoming requests: Once a connection is accepted, the server needs to parse the incoming requests to extract the requested resource and other details. The request typically contains a request line, headers, and a message body. The request line contains the HTTP method (e.g., GET, POST), the requested resource (e.g., /index.html), and the HTTP version (e.g., HTTP/1.1).

Generate a response: After the server has parsed the incoming request, it needs to generate an appropriate response based on the request. The response typically contains a status line, headers, and a message body. The status line contains the HTTP version, the status code (e.g., 200 OK, 404 Not Found), and a reason phrase.

Send the response: Once the response is generated, the server sends it back to the client using the socket file descriptor returned by accept(). The send() function is used for this, and it takes the socket file descriptor, a pointer to the response buffer, and the length of the response as its arguments.

Clean up: After the response is sent, the server closes the client socket and waits for the next incoming connection. Steps 5-8 are repeated for each incoming connection.

Add features and security: Once you have a basic web server implementation working, you can start adding additional features such as support for SSL/TLS, virtual hosts, configuration files, and more advanced request parsing and response generation. Additionally, you should implement appropriate security measures to protect your server from attacks, such as input validation, rate limiting, and access controls.

Note that this is a high-level overview of the steps involved in implementing a simple HTTP 1.1 web server in C++ 98. The specific implementation details will depend on the particular socket API, web server library, and programming environment that you choose.

//find server
//parse server
//find location
paarse location