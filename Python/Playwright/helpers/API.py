import requests


class API:
    def __init__(self):
        self.base_url = 'http://127.0.0.1:8000/json'

    def requests(self, method, endpoint, headers=None, body=None):
        if method == 'GET':
            response = requests.get(self.base_url + endpoint, headers=headers)
            return response
        elif method == 'POST':
            response = requests.post(self.base_url + endpoint, headers=headers, json=body)
            return response
        elif method == 'PUT':
            response = requests.put(self.base_url + endpoint, headers=headers, json=body)
            return response
        elif method == 'DELETE':
            response = requests.delete(self.base_url + endpoint, headers=headers)
            return response
