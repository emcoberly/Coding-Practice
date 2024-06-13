import socketserver
import http.server

class MyHandler(http.server.SimpleHTTPRequestHandler):
  def do_GET(self):
    self.send_response(200)
    self.send_header('Content-type', 'text/html')
    self.end_headers()
    self.wfile.write(b"I'm a happy carmpr")


PORT = 8080
Handler = MyHandler

with socketserver.TCPServer(("", PORT), Handler) as httpd:
  print("Server started on port", PORT)
  httpd.serve_forever()
