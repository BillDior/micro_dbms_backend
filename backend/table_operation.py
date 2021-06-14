import flask
from flask_cors import *
from flask import request
import json
import os
import utils
from flask import Blueprint
import core
table_api = Blueprint('table_api', __name__)


CORS(table_api, supports_credentials=True)

@table_api.route("/ShowTables", methods=['GET'])
def show_table_api():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    db_str = request.args.get("db_name")
    if not db_str or db_str == "":
        res = utils.err(1, 'ERROR: database name is empty!').to_response()
        return res
    out,result = core.run_query("use %s;show tables;"%db_str)
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
        records[0] = records[0].strip("'")
        if records[0] == 'relcat' or records[0] == 'attrcat':
            continue
        data_dic["title"] = records[0]
        data_dic["tupleLen"] = records[1]
        data_dic["attrCount"] = records[2]
        data_dic["indexCount"] = records[3]
        data_dic["recordCount"] = records[4]
        ret_dic["data"].append(data_dic)
    res = flask.make_response(flask.jsonify(ret_dic))
    return res

@table_api.route("/CreateTable", methods=['POST'])
def create_table_api():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    data_json = json.loads(request.args.get('0'))
    db_name = data_json["dbName"]
    if not db_name or db_name == "":
        res = utils.err(1, 'ERROR: database name is empty!').to_response()
        return res
    table_name = data_json["newTableName"]
    inst = "use %s;create table %s(" %(db_name,table_name)
    attrs = data_json["attrs"]
    primary_index = -1
    for i,attr in enumerate(attrs):
        inst += "%s %s(%s)" % (attr["attrName"], attr["typeName"], attr["attrLen"])
        if "NOT NULL" in attr["checkList"]:
            inst += " not null"
        if "PRIMARY KEY" in attr["checkList"]:
            primary_index = i
        if "NOT NULL" not in attr["checkList"] and "PRIMARY KEY" in attr["checkList"]:
            ret_dic['code'] = 1
            ret_dic['info'] = "error: primary key MUST BE not null!"
        if i != len(attrs) - 1:
            inst += ","
    if primary_index != -1:
         inst += ", primary key (%s)" % attrs[primary_index]["attrName"]
        
    inst += ");"
    out,err = core.run_query(inst)

    result_lines = err.split('\n')
    if len(result_lines) > 0 and result_lines[0].strip() != "":
        res = utils.err(1, 'ERROR: more than one attributes specified as primary key').to_response()
        return res
    res = flask.make_response(flask.jsonify(ret_dic))
    return res

@table_api.route("/DropTable", methods=['GET'])
def drop_table_api():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    db_str = request.args.get("db_name")
    if not db_str or db_str == "":
        res = utils.err(1, 'ERROR: database name is empty!').to_response()
        return res
    tb_str = request.args.get("tb_name")
    if not tb_str or tb_str == "":
        res = utils.err(1, 'ERROR: table name is empty!').to_response()
        res = utils.error_response(ret_dic, 1, 'ERROR: tablebase name is empty!')
        return res
        
    out, result = core.run_query("use %s;drop table %s;"%(db_str, tb_str))
    #if reslt
    res = flask.make_response(flask.jsonify(ret_dic))
    return res

@table_api.route("/DescTable", methods=['GET'])
def desc_api():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    db_str = request.args.get("db_name")

    if not db_str or db_str == "":
        res = utils.err(1, 'ERROR: database name is empty!').to_response()
        return res

    tb_str = request.args.get("tb_name")
    if not tb_str or tb_str == "":
        res = utils.err(1, 'ERROR: table name is empty!').to_response()
        return res
        
    data, err = core.desc(db_str, tb_str)
    ret_dic["data"] = data
    #if reslt
    res = flask.make_response(flask.jsonify(ret_dic))
    return res