# -*- coding: utf-8 -*-
"""
Created on Fri Nov  3 13:40:06 2017

@author: lucas
"""

from urllib2 import urlopen
from bs4 import BeautifulSoup
import re
import pymysql
#import requests

from utils import *
from ws_users_data import *

# ToDo:
# Divide into functions:

#   get_num_pages
#   select the fields in problems's table to insert
#   consult database (select), update the old info (update), and create a new one where doesn't exists (insert)

#   Consult one profile in https://www.urionlinejudge.com.br/judge/pt/profile/29546?page=9 (mine, id=29546)
#   Get all problems solved
#   Update my own list of problems solved

#   Note:
#   - Use the best Data Structures;
#   - Update info

num_pages = 0
num_pages = get_num_pages()

print(num_pages)

cursor = get_connection()

#craw_users("___.___")
a = craw_users("Gabriel")