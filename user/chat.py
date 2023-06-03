import argparse
from json import load,dump
from re import match

username = None

parser = argparse.ArgumentParser(description='Add a chat')
parser.add_argument('chat', help='Chat type (chat.raw or chat.encrypt)')
args = parser.parse_args()

chat = match(r'chat\.(raw|encrypt|username)', args.chat).group(1)

for arg in args.chat:
    if arg.startswith("chat.username="):
        username = match(r'chat\.username=(.+)', getattr(args, arg)).group(1)
        print(username)
        