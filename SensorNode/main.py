import requests


def main():
    print 'Hello World'

    base_url = "http://www.google.com"
    portno = 8081

    params = {}
    payload = {'number': 2, 'value': 1}
    response = requests.post(base_url, params=params, data=payload)

    print(response.text) #TEXT/HTML
    print(response.status_code, response.reason) #HTTP


main()