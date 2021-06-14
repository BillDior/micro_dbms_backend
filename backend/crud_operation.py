import flask
from flask_cors import *
from flask import request
from flask import Blueprint
import json
import os
import utils
import core
import re
crud_api = Blueprint('crud_api', __name__)


CORS(crud_api, supports_credentials=True)

@crud_api.route("/RunQueries", methods=['POST'])
def run_crud_query_api():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    data_json = json.loads(request.args.get('0'))
    db_name = data_json["db_name"]
    if not db_name or db_name == "":
        res = utils.err(1, 'ERROR: database name is empty!').to_response()
        return res
    query_str = data_json["queries"]
    queries_raw = query_str.split(';')
    support_prefix = "(^select)|(^insert)|(^delete)|(^update)|(^create)"
    show_prefix = re.compile("^select\s+(\w+|\*)\s+from\s+(\w+)\s*")
    pat = re.compile(support_prefix, re.I)
    ignore_queries = ""
    for q in queries_raw:
        if not q:
            continue
        q_s = q.strip()
        tokens = q_s.split()
        if not pat.search(tokens[0]):
            ignore_queries += "%s;" % q_s
        else:
            out, err = core.run_query("use %s;%s;" %(db_name, q_s))
            if err:
                res = utils.err(1, 'ERROR: %s' %err).to_response()
                return res
            if re.match(show_prefix, q_s):
                tb_name = re.findall(show_prefix, q_s)[0][1]
                table_data, err = utils.table_str_prod(out)
                if err:
                    res = utils.err(1, 'ERROR: %s' %err).to_response()
                    return res
                ret_dic["data"].append(table_data)
                
    if ignore_queries != "":
        ret_dic["info"] = "Warning: only queries which starts with (select)|(insert)|(delete)|(update)|(create) is supported.\
         Your query %s will be ignore"
        ret_dic["code"] = 20001

 
    res = flask.make_response(flask.jsonify(ret_dic))
    return res

@crud_api.route("/SelectAll", methods=['GET'])
def select_all_api():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    db_name =  request.args.get('db_name')
    if not db_name or db_name == "":
        res = utils.err(1, 'ERROR: database name is empty!').to_response()
        return res

    tb_name = request.args.get('tb_name')
    if not tb_name or tb_name == "":
        res = utils.err(1, 'ERROR: table name is empty!').to_response()
        return res
    table_data, err = core._select(db_name, ['*'], tb_name)
    print("error", err)
    if err:
        res = utils.err(1, 'ERROR: %s' %err).to_response()
        return res

    ret_dic["data"].append(table_data)
    print(table_data)
    res = flask.make_response(flask.jsonify(ret_dic))
    return res

@crud_api.route("/DeleteRecord", methods=['GET'])
def delete_record_api():
    ret_dic = {"code":20000, "info":"SUCCESS!", "data":[]}
    db_name =  request.args.get('db_name')
    if not db_name or db_name == "":
        res = utils.err(1, 'ERROR: database name is empty!').to_response()
        return res

    tb_name = request.args.get('tb_name')
    if not tb_name or tb_name == "":
        res = utils.err(1, 'ERROR: table name is empty!').to_response()
        return res
    
    record = json.loads(request.args.get('record'))
    err = core._delete(db_name, tb_name, record)
    print("error", err)
    if err:
        res = utils.err(1, 'ERROR: %s' %err).to_response()
        return res
    res = flask.make_response(flask.jsonify(ret_dic))
    return res