# -*- coding: utf-8 -*-
"""
Created on Fri Nov  3 13:40:06 2017

@author: lucas
"""

ADDRESS_BASE = "https://www.urionlinejudge.com.br/judge/"
LANG = "pt"

PROBLEMS_MODULE = "/problems/all"
USERS_MODULE = "/rank" # notice that is not RANK_MODULE
USER_MODULE = "/profile/" # id of user -> "/profile/{id}"

PROBLEMS_MODULE_ADDRESS = ADDRESS_BASE + LANG + PROBLEMS_MODULE
USERS_MODULE_ADDRESS = ADDRESS_BASE + LANG + USERS_MODULE
USER_MODULE_ADDRESS = ADDRESS_BASE + LANG + USER_MODULE

HOST = 'localhost'
UNIX_SOCKET = '/var/run/mysqld/mysqld.sock' #/tmp/mysql.sock
DBUSER = 'root'
DBPASSWRD = 's400'
DB = 'URIOJ'