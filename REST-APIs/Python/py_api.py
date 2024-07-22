from http.server import BaseHTTPRequestHandler, HTTPServer
import json

clients = [
    {'id': 1, 'name': 'Carmen'},
    {'id': 2, 'name': 'Tin'},
    {'id': 3, 'name': 'Vicente'},
    {'id': 4, 'name': 'Luna'}
]


class SimpleHTTPRequestHandler(BaseHTTPRequestHandler):

    def _send_response(self, code: int, message: list | dict):
        self.send_response(code)
        self.send_header('Content-Type', 'application/json')
        self.end_headers()
        self.wfile.write(json.dumps(message).encode())

    def do_GET(self):
        if self.path == '/clients':
            self._send_response(200, clients)
        elif self.path.startswith('/clients/'):
            try:
                client_id = int(self.path.split('/')[-1])
                # Generator expression
                client = next((client for client in clients if client['id'] == client_id), None)
                if client:
                    self._send_response(200, client)
                else:
                    self._send_response(404, {'message': 'Client not found'})
            except ValueError:
                self._send_response(400, {'message': 'Invalid ID'})
        else:
            self._send_response(404, {'message': 'Not found'})



    def do_POST(self):
        if self.path == '/clients':
            content_length = int(self.headers['Content-Length'])
            post_data = self.rfile.read(content_length)
            new_client = json.loads(post_data)
            clients.append(new_client)
            self._send_response(201, new_client)
        else:
            self._send_response(404, {'message': 'Not found'})


    def do_PUT(self):
        if self.path.startswith('/clients/'):
            try:
                client_id = int()
                client = next((client for client in clients if client['id'] == client_id), None)
                if client:
                    content_length = int(self.headers['Content-Length'])
                    put_data = self.rfile.read(content_length)
                    updated_data = json.loads(put_data)
                    client.update(updated_data)
                    self._send_response(200, client)
                else:
                    self._send_response(404, {'message': 'Client not found'})
            except ValueError:
                self._send_response(400, {'message': 'Invalid ID'})
        else:
            self._send_response(404, {'message': 'Not found'})


    def do_DELETE(self):
        if self.path.startswith('/clients/'):
            try:
                client_id = int(self.path.split('/')[-1])
                global clients
                clients = [client for client in clients if client['id'] != client_id]
                self._send_response(200, {'message': 'Book deleted'})
            except ValueError:
                self._send_response(400, {'message': 'Invalid ID'})
        else:
            self._send_response(404, {'message': 'Not found'})


def run(server_class=HTTPServer, handler_class=SimpleHTTPRequestHandler, port=8000):
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    print(f'Starting httpd server on port {port}')
    httpd.serve_forever()


if __name__ == '__main__':
    run()
