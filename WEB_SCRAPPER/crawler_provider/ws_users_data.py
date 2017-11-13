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

from difflib import SequenceMatcher
import jellyfish
from fuzzywuzzy import fuzz

def get_num_pages(users_module_address=USERS_MODULE_ADDRESS):
    html = urlopen(users_module_address)
    bsObj = BeautifulSoup(html, 'lxml')

    num_pages_text = bsObj.find("div", {"id" : "table-info"}).text

    try:
        num_pages = int(re.search('[0-9]+,[0-9]+$', num_pages_text).group(0))
    except AttributeError:
        num_pages = 1

    return num_pages

def calculate_distance(str1, str2):
    uni1 = re.sub(r'[^\x00-\x7F]+',' ', str1).decode("utf-8","ignore")
    uni2 = re.sub(r'[^\x00-\x7F]+',' ', str2).decode("utf-8","ignore")

    sm_score = SequenceMatcher(None, str1.lower(), str2.lower()).ratio()
    jar_score = jellyfish.jaro_distance(uni1, uni2)

    lev_score = jellyfish.levenshtein_distance(uni1, uni2)
    dl_score = jellyfish.damerau_levenshtein_distance(uni1, uni2)

    fr_score = fuzz.ratio(str1, str2)
    fpr_score = fuzz.partial_ratio(str1, str2)
    ftsortr_score = fuzz.token_sort_ratio(str1, str2)
    ftsetr_score = fuzz.token_set_ratio(str1, str2)

    fmean_score = (fr_score + fpr_score + ftsortr_score + ftsetr_score) / 400.00
    jar_sm_score = (sm_score + jar_score) / 2

    #print(str(fmean_score) + "\t" + str(jar_sm_score))

    mean = (fmean_score + jar_sm_score) / 2

    return mean

def craw_users(username):
    print("craw_users()")
    users_results = {}
    num_pages = get_num_pages();
    for i in range(1,num_pages+1):
        print("Checking page: " + str(i) + ".. of " + str(num_pages))
        page_idx_address = USERS_MODULE_ADDRESS + "?page=" + str(i)
        html = urlopen(page_idx_address)
        bsObj = BeautifulSoup(html, 'lxml')
        user_table_data = bsObj.find("table").tbody.findAll("tr")

        for user in user_table_data:

            identifier = user.findAll("td")[2].a.attrs["href"].split("/")[-1]
            name = user.findAll("td")[2].a.text.strip() 

            #print(identifier + "\t (" + name + ", " + username + ")")

            # Calculate the probability of name provide by the user be the same as the founded
            # adds to an array if the probability founded is greater than a parameter

            d = calculate_distance(username, name) 
            #print(str(identifier) + name + str(d))
            if(d > 0.75):
                users_results[identifier] = (name, d)
                #print(str(identifier) + "\t" +  name + "\t" + str(d))

    #return list_of_names (w/ probabilities)
    return sorted(users_results, key=lambda x : users_results[x][1], reverse=True)
