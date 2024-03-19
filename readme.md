# Web Server with Mongoose

A simple web server implementation using the Mongoose embedded web server library. The server serves static HTML files from the current directory and allows directory listing.

## Dependencies

- Mongoose C library (https://github.com/cesanta/mongoose)

Make sure to include the `mongoose.h` header file and link against the Mongoose library when compiling the code.

## Usage

1. Compile the code with the Mongoose library:

```bash
g++ -o server main.cpp -lmongoose
```

2. Run the compiled executable:

```bash
./server
```

3. Select the server port when prompted. If no valid port is provided, the server will default to port 8000.

4. Access the server in your web browser at `http://localhost:<port>`, where `<port>` is the selected port number.

## Code Structure

### `ev_handler` Function

The `ev_handler` function is the event handler callback for the Mongoose server. It is called for each event, and it serves static HTML files when an HTTP request is received (`MG_EV_HTTP_REQUEST` event).

### `initServer` Function

The `initServer` function initializes the Mongoose event manager, binds to the specified port, sets up the HTTP server options, and enters an event loop to handle incoming requests. The server options are configured to serve files from the current directory and enable directory listing.

### `main` Function

The `main` function prompts the user to select the server port. If an invalid port is entered, it defaults to port 8000. It then calls the `initServer` function with the selected port number.

## Notes

- The server serves files from the current directory, so make sure to place your HTML files in the same directory as the executable.
- Directory listing is enabled, allowing users to browse the file structure of the server's document root.
- The server runs indefinitely until manually stopped (e.g., by pressing Ctrl+C).

Feel free to modify the code to suit your specific needs, such as adding more advanced routing or handling different types of requests.
