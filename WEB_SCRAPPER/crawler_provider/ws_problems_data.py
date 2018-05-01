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

def get_num_pages(problems_module_address=PROBLEMS_MODULE_ADDRESS):
    html = urlopen(problems_module_address)
    bsObj = BeautifulSoup(html, 'lxml')

    num_pages_text = bsObj.find("div", {"id" : "table-info"}).text

    try:
        num_pages = int(re.search('[0-9]+$', num_pages_text).group(0))
    except AttributeError:
        num_pages = 1

    return num_pages

def insert_update_problem(id, name, category, solved_num, level):
    
    conn = pymysql.connect(host=HOST, unix_socket=UNIX_SOCKET, user=DBUSER, passwd=DBPASSWRD, db=DB)
    cursor = conn.cursor()

    select_cmd = """SELECT * FROM problems WHERE id=(%s)""";
    insert_cmd = """INSERT INTO problems VALUES(%s,%s,%s,%s,%s)""";
    update_cmd = """UPDATE problems SET name = (%s), id_category = (%s), number_of_user_that_solved = (%s), level = (%s) WHERE id = (%s)""";

    result_sel = cursor.execute(select_cmd, (id))
    
    if(result_sel == 0):
        result_ins = cursor.execute(insert_cmd, (id, name, category, solved_num, level))
        conn.commit()
    else:
        result_upd = cursor.execute(update_cmd, (name, category, solved_num, level, id))
        conn.commit()        

    cursor.close()
    conn.close()
    
    return (cursor.rowcount != 0)

def insert_update_problem(cursor, id, name, category, solved_num, level):
    
    select_cmd = """SELECT * FROM problems WHERE id=(%s)""";# + id + ";"
    #print(select_cmd)
    cursor.execute(select_cmd, (id))
    result_sel = cursor.fetchone()
    
    print("sel: ")
    print(result_sel)

    #insert_cmd = """INSERT INTO problems VALUES(" + id + ", \"" + name + "\", " + category + ", " + solved_num + ", " + level + ");""";
    insert_cmd = """INSERT INTO problems VALUES(%s,\"%s\",%s,%s,%s)""";

    #print(insert_cmd)
    if(result_sel == None):
        cursor.execute(insert_cmd, (id, name, category, solved_num, level))
        result_ins = cursor.fetchall()
        print(insert_cmd)
        print("ins: ")
        print(result_ins)
    return (cursor.fetchone() != None)
>>>>>>> 186b778ab81d81181f0e78868ecd164759003144

def craw_problems():
    print("craw_problems()")
    num_pages = get_num_pages();
    for i in range(1,num_pages+1):
        print("Checking page: " + str(i) + ".. of " + str(num_pages))
        page_idx_address = PROBLEMS_MODULE_ADDRESS + "?page=" + str(i)
        html = urlopen(page_idx_address)
        bsObj = BeautifulSoup(html, 'lxml')
        prob_table_data = bsObj.find("table").tbody.findAll("tr")
        
        for prob in prob_table_data:
            identifier = prob.findAll("td")[0].a.text.strip()
            name = prob.findAll("td")[2].a.text
            category_text = prob.findAll("td")[3].a.text
            solved_by_x_users = re.sub('\.', '', prob.findAll("td")[4].text.strip())
            level = prob.findAll("td")[5].text.strip()
            
            categories = ["Iniciante", "Ad-Hoc", "Strings", "Estruturas e Bibliotecas", "Matemática", "Paradigmas", "Grafos", "Geometria Computacional", "SQL"]

            try:
                category = categories.index(category_text) + 1
            except ValueError:
<<<<<<< HEAD
                category = 10
=======
                category = 0
>>>>>>> 186b778ab81d81181f0e78868ecd164759003144

            #print(identifier + "\t" + name + "\t" + category_text + "\t" + solved_by_x_users + "\t" + level +  "\n")
            category = str(category)
            cursor = get_cursor()
<<<<<<< HEAD
            insert_update_problem(identifier, name, category, solved_by_x_users, level)
=======
            insert_update_problem(cursor, identifier, name, category, solved_by_x_users, level)
>>>>>>> 186b778ab81d81181f0e78868ecd164759003144
