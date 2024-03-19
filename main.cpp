#include "mongoose.h";
#include <iostream>
#include <string>

// Struct containings settings for how to server HTTP with mpngoose 
static struct mg_serve_http_opts s_http_server_opts;


// It is only visible within the translation unit(source file)
// Event handler
static void ev_handler(struct mg_connection* mc, int ev, void* p) {
	// If event is a http_request
	if (ev == MG_EV_HTTP_MSG) {
		// serve static html files
		mg_serve_http(mc, (struct http_message *) p, s_http_server_opts);
	}
}

int initServer(int port) {
	// Mongoose event manager
	struct mg_mgr mgr;
	// Mongoose connection
	struct mg_connection* mc;

	// convert port variable to char
	std::string portToChar = std::to_string(port);

	//sPort will retain its value even after the function in which it is defined(initServer) exits
	static char const* sPort = portToChar.c_str();

	// Init MONGO(OSE
	mg_mgr_init(&mgr);
	std::cout << "starting web server on port " << sPort << std::endl;

	mc = mg_connect(&mgr, sPort, ev_handler);

	// If the connection fails
	if (mc == NULL) {
		std::cout << "Failed to create listener" << std::endl;
		return 1;
	}
	// Set up HTTP server options
	mg_set_protocol_http_websocket(mc);

	mg_http_serve_opts_document_root = ".";

	mg_http_serve_opts_directory_listing = "yes";

	for (;;) {
		mg_mgr_poll(&mgr, 1000);
	}

	// free up all memory allocated
	mg_mgr_free(&mgr);
}




int main(void) {
	int port;
	std::cout << "Select server port" << std::endl;

	std::cin >> port;

	// fail case
	if (std::cin.fail()) {
		port = 1000;
	}

	initServer(port);

	return 0;
}