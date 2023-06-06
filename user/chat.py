from flask import Flask, request
from json import load, dump

app = Flask(__name__)

@app.route('/chat.py',methods=['POST'])
def handle_post():
    data = request.get_json()
    with open("chat.json","r",encoding="utf-8") as read:
        dataread = load(read)
        dataread.update(data)
    with open("chat.json","w",encoding="utf-8") as write:
        dump(dataread,write, indent=4)
        
while True:
    handle_post()