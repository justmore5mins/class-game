from flask import Flask, request
from flask_cors import CORS
from json import load, dump, JSONDecodeError

app = Flask(__name__)
CORS(app)

default = {
    "0":None
}

def updatechat(data):
    with open("chat.json", "r", encoding="utf-8") as read:
        try:
            dataread = load(read)
            print(type(dataread))
            lastkey = list(dataread.keys())[-1]
            lastkey = int(lastkey)
            lastkey += 1
            lastkey = str(lastkey)
            dataalready = {lastkey:data}
            dataread.update(dataalready)
        except JSONDecodeError:
            dataalready = {"1":data}
            dataread.update(dataalready)

    with open("chat.json", "w", encoding="utf-8") as write:
        dump(dataread, write, indent=4)
    return '',200

@app.route('/handle_post', methods=['POST'])
def handle_post():
    if request.method == 'OPTIONS':
        # 返回预检请求的响应
        return '', 200
    
    data = request.get_json()
    updatechat(data)
    return '',200
@app.route("/clearchat", methods=['POST'])
def clearchat():
    if request.method == 'OPTIONS':
        # 返回预检请求的响应
        return '', 200
    
    data = request.get_json
    
    with open("chat.json", "w", encoding="utf-8") as write:
        dump(data, write, indent=4)
    return "()",200

if __name__ == "__main__":
    app.run()