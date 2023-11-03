# Using the 'requests' library to make an HTTP GET request
import requests
URL = "https://www.scrapethissite.com/"
response = requests.get(URL)
print(response.text)
print(response.status_code)