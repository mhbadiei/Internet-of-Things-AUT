from coapthon.server.coap import CoAP

from coapthon.resources.resource import Resource


class DataResource(Resource):
    def __init__(self, name="DataResource", coap_server=None):
        super(DataResource, self).__init__(name, coap_server, visible=True,
                                            observable=True, allow_children=True)
        self.payload = "We dont have any data"

    def render_GET(self, request):
        return self

    def render_PUT(self, request):
        self.payload = request.payload
        return self

class InstructionResource(Resource):
    def __init__(self, name="InstructionResource", coap_server=None):
        super(InstructionResource, self).__init__(name, coap_server, visible=True,
                                            observable=True, allow_children=True)
        self.payload = "We dont have any data"

    def render_GET(self, request):
        return self

    def render_PUT(self, request):
        self.payload = request.payload
        return self



class CoAPServer(CoAP):
    def __init__(self, host, port):
        CoAP.__init__(self, (host, port))
        self.add_resource('tagdata/', DataResource())
        self.add_resource('resdata/', InstructionResource())


def main():
    server = CoAPServer("192.168.43.105", 5683)
    try:
        server.listen(10)
    except KeyboardInterrupt:
        print("Server Shutdown")
        server.close()
        print("Exiting...")


if __name__ == '__main__':
    main()
