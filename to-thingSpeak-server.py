import requests
import numpy as np
import random
import time

// Can be grabed from the thingSpeak channel data
THINGSPEAK_API_KEY = 'XXXXXXXXXXXXXXXXXXXXX'
THINGSPEAK_CHANNEL_ID = 'XXXXXXXXXX'


// Function that write to thingSpeak channel
def post_to_thingspeak(data):
    # Construct the ThingSpeak API URL
    url = f'https://api.thingspeak.com/update?api_key={THINGSPEAK_API_KEY}'

    # Add the data to the URL
    for key, value in data.items():
        url += f'&{key}={value}'

    # Send a POST request to the ThingSpeak API
    response = requests.post(url)

    # Check if the request was successful
    if response.status_code == 200:
        print('Data posted successfully')
    else:
        print('Failed to post data')


// sending the data every 5 minutes to the thing speak server
while(1):
    d = np.loadtxt('CoolTerm Capture 2023-06-06 12-32-06.txt', delimiter=',')
    data = {
        'field1': d[-1][0], 'field2': d[-1][1], 'field3': d[-1][2], 
        'field4': d[-1][3], 'field5': d[-1][4], 'field6': d[-1][5]
    }
    post_to_thingspeak(data)
    time.sleep(300)
