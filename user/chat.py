import argparse
import json
import re

def writechat(chat:dict):
    with open("chat.json","r", encoding="utf-8") as read:
        data = json.load(read)
        data.update(chat)
        print(data)
    with open("chat.json","w", encoding="utf-8") as write:
        json.dump(data,write,indent=4)

parser = argparse.ArgumentParser(description='Add a chat')
parser.add_argument('chattype', help='Chat type (chat.raw or chat.encrypt)')
args = parser.parse_args()

chattype = re.match(r'chat\.(raw|encrypt|username)', args.chattype).group(1)

print(chattype)