import requests

url = 'https://stuff.mit.edu/afs/sipb/contrib/pi/pi-billion.txt'
response = requests.get(url)
open('Pi1BDP.txt', 'wb').write(response.content)