from flask import Flask
from flask_cors import *
path=r'./microDBMS'
from database_operation import database_api
from table_operation import table_api
from crud_operation import crud_api
app = Flask(__name__)
app.register_blueprint(database_api, url_prefix="/database")
app.register_blueprint(table_api, url_prefix="/table")
app.register_blueprint(crud_api, url_prefix="/crud")

CORS(app, supports_credentials=True)

if __name__ == '__main__':
    current_db = ""
    app.run('0.0.0.0', port=80)
