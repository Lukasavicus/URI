# -*- coding: utf-8 -*-
"""
Created on Fri Nov  3 13:40:06 2017

@author: lucas
"""
from config import *
from utils import *

from urllib2 import urlopen
from bs4 import BeautifulSoup
import re
import pymysql

def get_num_pages(user_id, user_module_address=USER_MODULE_ADDRESS):
    COMPLETE_USER_ADDRESS = USER_MODULE_ADDRESS + user_id
    html = urlopen(COMPLETE_USER_ADDRESS)
    bsObj = BeautifulSoup(html, 'lxml')

    num_pages_text = bsObj.find("div", {"id" : "table-info"}).text

    try:
        num_pages = int(re.search('[0-9]+,[0-9]+$', num_pages_text).group(0))
    except AttributeError:
        num_pages = 1

    return num_pages

def craw_user(user_id):
    print("craw_user()")
    
    COMPLETE_USER_ADDRESS = USER_MODULE_ADDRESS + user_id
    num_pages = get_num_pages(user_id)

    for i in range(1,num_pages+1):
        print("Checking page: " + str(i) + ".. of " + str(num_pages))
        page_idx_address = COMPLETE_USER_ADDRESS + "?page=" + str(i)
        html = urlopen(page_idx_address)
        bsObj = BeautifulSoup(html, 'lxml')
        problem_table_data = bsObj.find("table").tbody.findAll("tr")

        for prob in problem_table_data:
            print(prob.findAll("td"))

            # ======

            #identifier = prob.findAll("td")[2].a.attrs["href"].split("/")[-1]
            #name = prob.findAll("td")[2].a.text.strip() 

            # ======

            #print(identifier)
            #print(name)

            # Calculate the probability of name provide by the user be the same as the founded
            # adds to an array if the probability founded is greater than a parameter

            #return list_of_names (w/ probabilities)