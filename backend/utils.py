import subprocess
from subprocess import PIPE
from main import path
import flask
import shlex

class err():
    code = 0
    info = ""
    def __init__(self, code, info):
        self.code = code
        self.info = info
    def to_response(self):
        ret_dic = {"code":self.code, "info":self.info, "data":[]}
        res = flask.make_response(flask.jsonify(ret_dic))
        return res

def table_str_prod(info_str,first_attrname_only = False):
    err = None
    data_dic = {"attrName":[], "data":[]}
    info_str = info_str.replace("MICROBASE >> ","") 
    raws = info_str.split("\n")
    split_index = -1
    for i in range(0,len(raws)):
        if "---" in raws[i] and split_index == -1: 
            split_index = i
    if split_index == -1:
        return data_dic,"Unknow error!"
    attr_names = raws[split_index - 1].split()
    data_dic["attrName"] = [x for x in attr_names]
    for i in range(split_index + 1, len(raws)):
        sub_dic = {}
        records = list(shlex.shlex(raws[i]))
        #records = raws[i].split() 
        if not records or len(records) == 0:
            break
        for j in range(len(attr_names)):
            sub_dic[attr_names[j]] = records[j].strip("'")
            if first_attrname_only and i > split_index + 1:
                sub_dic[attr_names[0]] = ""
        data_dic["data"].append(sub_dic)
    return data_dic, err


    






