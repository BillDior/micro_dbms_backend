import flask
from flask_cors import *
from flask import request
import subprocess
from subprocess import PIPE
import os
from flask import Blueprint
database_api = Blueprint('database_api', __name__)
import utils
from main import path
import core


CORS(database_api, supports_credentials=True)
@database_api.route("/Query", methods=['POST','GET'])
def run_query():
    ret_dic = {"code":0, "info":"SUCCESS!"} 
    query_str = request.args.get("query")
    if not query_str or query_str == "":
        return res

    database = request.args.get("database")
    p=subprocess.Popen(path,stdin = PIPE, stdout = PIPE, stderr = PIPE, bufsize=1, universal_newlines=True)
    print (query_str)
    extra,result=p.communicate(input=query_str)
    print(extra)
    
    res = flask.make_response(flask.jsonify({'code': 0,'info': '%s'%result}))
    res.headers['Access-Control-Allow-Origin'] = '*'
    res.headers['Access-Control-Allow-Method'] = '*'
    res.headers['Access-Control-Allow-Headers'] = '*'
    return res

@database_api.route("/ShowDatabases", methods=['GET'])
def get_databases_api():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    databases = core.get_dabases()
    for db in databases:
        ret_dic["data"].append({"title":db})
    res = flask.make_response(flask.jsonify(ret_dic))
    return res

@database_api.route("/UseDatabase", methods=['GET'])
def use_databases():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    db_str = request.args.get("db_name")
    if not db_str or db_str == "":
        ret_dic['code'] = 1
        ret_dic['info'] = 'ERROR: database name is empty!'
        res = flask.make_response(flask.jsonify(ret_dic))
        return res
    p = subprocess.Popen(path,stdin = PIPE, stdout = PIPE, stderr = PIPE, bufsize=1, universal_newlines=True)
    out,result=p.communicate(input="use %s;"%db_str)
    if "does not exist" in result:
        ret_dic["info"] = result.strip()
        ret_dic["code"] = 1
    else:
        global current_db
        current_db = db_str 

     
    res = flask.make_response(flask.jsonify(ret_dic))
    return res

@database_api.route("/DropDatabase", methods=['GET'])
def drop_databases():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    db_str = request.args.get("db_name")
    if not db_str or db_str == "":
        ret_dic['code'] = 1
        ret_dic['info'] = 'ERROR: database name is empty!'
        res = flask.make_response(flask.jsonify(ret_dic))
        return res
    p = subprocess.Popen(path,stdin = PIPE, stdout = PIPE, stderr = PIPE, bufsize=1, universal_newlines=True)
    out,result=p.communicate(input="drop database %s;"%db_str)
    if  result.strip() != "":
        ret_dic["info"] = result.strip()
        ret_dic["code"] = 1
    elif "Successfully" not in out:
        ret_dic["info"] = out
        ret_dic["code"] = 1
    res = flask.make_response(flask.jsonify(ret_dic))
    return res

@database_api.route("/CreateDatabase", methods=['GET'])
def create_database():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    db_str = request.args.get("db_name")
    if not db_str or db_str == "":
        ret_dic['code'] = 1
        ret_dic['info'] = 'ERROR: database name is empty!'
        res = flask.make_response(flask.jsonify(ret_dic))
        return res
    p = subprocess.Popen(path,stdin = PIPE, stdout = PIPE, stderr = PIPE, bufsize=1, universal_newlines=True)
    out,result=p.communicate(input="create database %s;"%db_str)
    if  result.strip() != "":
        ret_dic["info"] = result.strip()
        ret_dic["code"] = 1
    elif "Successfully" not in out:
        ret_dic["info"] = out
        ret_dic["code"] = 1

    res = flask.make_response(flask.jsonify(ret_dic))
    return res

@database_api.route("/ShowTables", methods=['GET'])
def show_tables():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    db_str = request.args.get("db_name")
    if not db_str or db_str == "":
        res = utils.err(1, 'ERROR: database name is empty!').to_response()
        return res
    p = subprocess.Popen(path,stdin = PIPE, stdout = PIPE, stderr = PIPE, bufsize=1, universal_newlines=True)
    out,result=p.communicate(input="use %s;show tables;"%db_str)
    out = out.replace("MICROBASE >> ","") 
    raws = out.split("\n")
    split_index = -1

    for i in range(0,len(raws)):
        if "-----------------------------------" in raws[i]: 
            split_index = i
    if split_index == -1 :
        ret_dic["code"] = 1
        ret_dic["info"] = "unknown error"
    for i in range(split_index + 1, len(raws)):
        data_dic = {"title":"", "tupleLen":0, "attrCount":0, "indexCount":0, "recordCount":0}
        records = raws[i].split()
        if not records:
            break
        print (records)
        data_dic["title"] = records[0]
        data_dic["tupleLen"] = records[1]
        data_dic["attrCount"] = records[2]
        data_dic["indexCount"] = records[3]
        data_dic["recordCount"] = records[4]
        ret_dic["data"].append(data_dic)
    res = flask.make_response(flask.jsonify(ret_dic))
    return res

