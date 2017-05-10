import requests


def main():

    base_url = "localhost"
    portno = 8081

    params = {}
    payload = {'number': 2, 'value': 1}
    response = requests.post(base_url, params=params, data=payload)

    print(response.text) #TEXT/HTML
    print(response.status_code, response.reason) #HTTP


main()