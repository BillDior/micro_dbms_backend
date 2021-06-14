import subprocess
from subprocess import PIPE
from main import path
import utils

def run_query(q):
    p=subprocess.Popen(path,stdin = PIPE, stdout = PIPE, stderr = PIPE, bufsize=1, universal_newlines=True)
    out,err=p.communicate(input=q)
    return out,err
    
def desc(db_name, tb_name):
    q = "use %s;desc %s;" % (db_name, tb_name)
    out, err = run_query(q)
    return utils.table_str_prod(out, first_attrname_only = True)

def get_dabases():
    q = "show databases;" 
    out1, out2= run_query(q)
    return out2.split()

def get_datatype(db_name, tb_name, rel_name):
    q = "use %s;select attrType from attrcat where relName='%s' and attrName='%s';" %(db_name , tb_name, rel_name)
    out, err = run_query(q)
    return utils.table_str_prod(out) 

def _select(db_name, rels, table, cond = None):
    q = "use %s;select " %db_name 
    if len(rels) == 1 and rels[0] == '*':
        q += '*'
    else:
        for r in rels:
            q += r + ','
        q.strip(',')
    q += " from %s " %table
    if cond:
        q += "where "
        for k,v in cond.items():
            q += "%s=%s and" %(k,v)
        q = q[:-4]
    q += ';'
    out, err = run_query(q)
    if err:
        return out, err
    table_data, err = utils.table_str_prod(out)
    if err:
        return out, err

    return table_data, None

def _delete(db_name, table, cond):
    q = "use %s;delete from %s" % (db_name, table)
    q += " where "
    for k,v in cond.items():
        t, err = get_datatype(db_name, table, k)
        if err :
            return err 
        if t['data'][0]["attrType"] == '2':
            q += "%s='%s' and " %(k,v)
        else:
            q += "%s=%s and " %(k,v)
    q = q[:-4]
    q += ';'
    out, err = run_query(q)
    if err:
        return err
    return None
    



