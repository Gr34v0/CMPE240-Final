import requests


def main():
    print 'Hello World'

    base_url = "http://www.google.com"
    portno = 8081
    # final_url="/{0}/friendly/{1}/url".format(base_url,any_value_here)

    params = {}
    payload = {'number': 2, 'value': 1}
    response = requests.post(base_url, params=params, data=payload)

    print(response.text) #TEXT/HTML
    print(response.status_code, response.reason) #HTTP

main()