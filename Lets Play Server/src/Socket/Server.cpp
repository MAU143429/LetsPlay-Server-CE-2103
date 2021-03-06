#include "Server.h"
#include "Server_Manager.h"

Server* Server::unique_instance{ nullptr };
mutex Server::mutex_;

Server::Server()
{
}

Server::~Server(){}
/**
 * @brief Getter for the static instance of the server class 
 * @return the static instance
*/
Server* Server::getInstance()
{
	lock_guard<std::mutex> lock(mutex_);
	if (unique_instance == nullptr) { unique_instance = new Server(); }
	return unique_instance;
}
/**
 * @brief Method that initializes the server
*/
void Server::initServer()
{
	// Initialze winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		cerr << "Can't Initialize winsock! Quitting" << endl;
		return;
	}

	// Create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Can't create a socket! Quitting" << endl;
		return;
	}

	// Bind the ip address and port to a socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // Could also use inet_pton .... 
	
	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// Tell Winsock the socket is for listening 
	listen(listening, SOMAXCONN);

	// Wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);

	clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST];		// Client's remote name
	char service[NI_MAXSERV];	// Service (i.e. port) the client is connect on

	ZeroMemory(host, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		cout << host << " connected on port " << service << endl;
	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port " <<
			ntohs(client.sin_port) << endl;
	}

	// Close listening socket
	closesocket(listening);

	// While loop: accept and echo message back to client
	char buf[4096];

	while (true)
	{
		ZeroMemory(buf, 4096);

		// Wait for client to send data
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == SOCKET_ERROR)
		{
			cerr << "Error in recv(). Quitting" << endl;
		}

		if (bytesReceived == 0)
		{
			cout << "Client disconnected " << endl;
			break;
		}
		cout << string(buf, 0, bytesReceived) << endl;

		
		client_message = string(buf, 0, bytesReceived);
		if (!client_message.empty()) {
			const string& response = Server_Manager::Select_GameController(client_message);
			Send(response.c_str());

		}
		

	}

	// Close the socket
	closesocket(clientSocket);

	// Cleanup winsock
	WSACleanup();

	system("pause");

}
	/**
	 * @brief Sends a message to the client.
	 * @param msg const char pointer containing the message.
	 */
void Server::Send(const char* msg) {
	int sendRes = send(clientSocket, msg, strlen(msg), 0);
	if (sendRes == -1) {
		std::cout << "Send message failed" << std::endl;
	}
}

string Server::ReadString()
{
	return client_message;
}
