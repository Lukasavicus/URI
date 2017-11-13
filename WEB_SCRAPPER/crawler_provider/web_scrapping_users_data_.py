# -*- coding: utf-8 -*-
"""
Created on Fri Nov  3 13:40:06 2017

@author: lucas
"""

from urllib2 import urlopen
from bs4 import BeautifulSoup
import requests

address = "https://www.urionlinejudge.com.br/"

html = urlopen(address)
bsObj = BeautifulSoup(html, 'lxml')

loginForm = bsObj.find("form",{"action":"/judge/en/login"})

params = {}

for input_tag in bsObj.find("form",{"action":"/judge/en/login"}).findAll("input"):
    if 'name' in input_tag.attrs:
        if 'value' in input_tag.attrs:
            params[input_tag.attrs['name']] = input_tag.attrs['value']
        else:
            params[input_tag.attrs['name']] = ""
            
params['email'] = "lukasavicus@gmail.com"
params['password'] = "password"
 
# In order to try understand how the submission of data is made for URI's server you migth be interested in tools like this:
#   https://www.hurl.it/
#   https://www.wireshark.org/

urlToSend = address + loginForm.attrs['action'][1:]

req = requests.post(urlToSend, data=params)

print(req.text)