# -*- coding: utf-8 -*-
"""
Created on Fri Nov  3 13:40:06 2017

@author: lucas
"""
from config import *

import pymysql


def get_connection(host=HOST, unix_socket=UNIX_SOCKET, dbuser=DBUSER, dbpasswrd=DBPASSWRD, db=DB):
    conn = pymysql.connect(host=host, unix_socket=unix_socket, user=dbuser, passwd=dbpasswrd, db=db)

    return conn

def get_cursor(host=HOST, unix_socket=UNIX_SOCKET, dbuser=DBUSER, dbpasswrd=DBPASSWRD, db=DB):
    conn = pymysql.connect(host=host, unix_socket=unix_socket, user=dbuser, passwd=dbpasswrd, db=db)
    cur = conn.cursor()
    cur.execute("USE URIOJ")

    return cur