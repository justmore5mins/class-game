from flask_cors import CORS
from flask import Flask,request,jsonify
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

@app.route('/writechat', methods=['POST'])
def writechat():
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

@app.route("/sentdata",methods=['GET'])
def sentdata():
    sentdata = {}
    with open("chat.json") as file:
        data = load(file)
        
    for key,value in data.items():
        message = value["encrypt"]
        user = value["username"]
        dataprepare = {
            "username":user,
            "message":message,
        }
        sentdata.update(dataprepare)
    return sentdata

if __name__ == "__main__":
    app.run()