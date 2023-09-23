from coapthon.client.helperclient import HelperClient
from coapthon.messages import response

import time
host = "192.168.43.105"
port = 5683
path = 'tagdata'
data = 0

client = HelperClient(server=(host, port))

while True:
    response = client.get(path)
    response = response.pretty_print()
    print("**********"+response[response.find("Payload") : ]+"***********")
    data = str(response[response.find("Payload") + 10 : ])

    #response = client.put('resdata', "VALID")
    if data == " EC 85 1C 12\n":
        response = client.put('resdata', "VALID")
    elif data == " EC 85 2B 62\n":
        response = client.put('resdata', "INVALID")
    
    time.sleep(1)    
