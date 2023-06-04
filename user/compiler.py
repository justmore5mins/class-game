from os import system,remove,chdir

chdir("/Users/AustinYu/Library/CloudStorage/GoogleDrive-tno062789@gmail.com/我的雲端硬碟/HTML/遊戲的網頁/user")

remove("chat.run")
system("g++ -std=c++11 -o chat.run chat.cpp src/command.cpp -I'/Users/AustinYu/Library/CloudStorage/GooeDrive-tno062789@gmail.com/我的雲端硬碟/HTML/遊戲的網頁/user/src/jsoncpp/src' '/Users/AustinYu/Library/CloudStorage/GoogleDrive-tno062789@gmail.com/我的雲端硬碟/HTML/遊戲的網頁/user/src/jsoncpp/build/lib/libjsoncpp.a'")