import requests
import FakeSensor
import json


def main():

    base_url = "http://129.21.207.229:8081"

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