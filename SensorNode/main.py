import requests
import FakeSensor
import json
import sys

def main():
    if( len(sys.argv) > 2 or len(sys.argv) < 2):
        print "Parameters: <IP Address or URL to HOST server\n"
        return
    else:
        base_url = sys.argv[1]

    value = 0

    indexValue = 0

    while(True):
        value = FakeSensor.collect_data(indexValue)

        response = requests.post(base_url, params=None, data=json.dumps(value, separators=(",",":")))

        indexValue+=1

        print(response.text)  # TEXT/HTML
        print(response.status_code, response.reason)  # HTTP
        print(response.raw.version)


main()