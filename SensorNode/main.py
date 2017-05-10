import requests
import FakeSensor
import json
import sys


def main():
    """ initializer of program. Will look for URL in argv, collect sensor data and then send data to said URL
    :return: n/a
    """

    #  Check to see if the user supplied a commandline argument.
    #  cmdline arg should be in form of a URL or Ip Address with specified Port.
    if len(sys.argv) > 2 or len(sys.argv) < 2:
        print "Parameters: <IP Address + Port number or URL to HOST server e.x. http://localhost:8080\n>"
        return
    else:
        #  User supplied cmdline arg, so we assume it's a URL...
        url = sys.argv[1]

    index_value = 0

    while True:

        #  Collecting data value from the sensor module/driver (in this case, FakeSensor
        value = FakeSensor.collect_data(index_value)

        #  Packaging the data collected in a JSON object
        data_parcel = json.dumps(({index_value: value}), separators=(",", ":"))

        #  Calling post from the requests package to send our JSON data to the URL
        response = requests.post(url, params=None, data=json.dumps(data_parcel, separators=(",", ":")))

        #  Incrementing index value so the next pass will provide a new key to the dict
        index_value += 1

        #  Printing various information about the POST requests to the terminal
        print(response.text)
        print(response.status_code, response.reason)
        print(response.raw.version)


main()
