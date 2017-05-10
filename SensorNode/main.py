import requests


def main():

    base_url = "ws://localhost:8081"
    portno = 8081

    params = {}
    payload = {'number': 2, 'value': 1}
    response = requests.post(base_url, params=params, data=payload)

    print(response.text) #TEXT/HTML
    print(response.status_code, response.reason) #HTTP


main()