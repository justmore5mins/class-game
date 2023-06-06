from flask import Flask, request
from json import load, dump

app = Flask(__name__)

def updatechat(data):
    with open("chat.json", "r", encoding="utf-8") as read:
        dataread = load(read)
        dataread.update(data)
        print(dataread)
    with open("chat.json", "w", encoding="utf-8") as write:
        dump(dataread, write, indent=4)

@app.route('/chat.py', methods=['POST'])
def handle_post():
    data = request.get_json()
    updatechat(data)

if __name__ == "__main__":
    app.run()