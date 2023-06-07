from flask import Flask, request
from flask_cors import CORS
from json import load, dump,loads

app = Flask(__name__)
CORS(app)

def updatechat(data):
    with open("chat.json", "r", encoding="utf-8") as read:
        dataread = load(read)
        print(dataread)
        """
        lastkey = list()[-1]
        lastkey = int(lastkey)
        lastkey += 1
        lastkey = str(lastkey)
        dataread.update(data)
        writedata = {lastkey:dataread}
        print(dataread)
        """
        dataread.update(data)
    with open("chat.json", "w", encoding="utf-8") as write:
        dump(dataread, write, indent=4)

@app.route('/handle_post', methods=['POST'])
def handle_post():
    if request.method == 'OPTIONS':
        # 返回预检请求的响应
        return '', 200
    
    data = request.get_json()
    updatechat(data)

if __name__ == "__main__":
    app.run()