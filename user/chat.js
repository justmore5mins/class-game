const messageForm = document.getElementById('chat');
messageForm.addEventListener('submit', sendMessage);

//一堆前置函式
function caesar(str, num) {
  let newString = ''
  // num %= 26

  for (let i = 0;i < str.length;i++) {
    let c = str.charCodeAt(i)

    // 大寫
    if (c >= 65 && c <= 90) {
      newString += String.fromCharCode((c - 65 + num) % 26 + 65)
    } else if (c >= 97 && c <= 122) { // 小寫
      newString += String.fromCharCode((c - 97 + num) % 26 + 97)
    } else { // 非字母就直接加到輸出的密文
      newString += str.charAt(i)
    }
  }
  return newString
}

function showchat(event, chat) {
  event.preventDefault()
  const input = document.getElementById("chat")
  const message = input.value

  const encrypt = chat
  const xhr = new XMLHttpRequest()
  xhr.open('POST', "/sentchat", true)
  xhr.setRequestHeader('Content-Type', 'application/json')
  xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
      // 处理服务器的响应
      const response = JSON.parse(xhr.responseText)
      if (response.status === 'success') {
        // 在前端显示加密后的消息（发送者为自己）
        displayMessage(encryptedMessage, true)
      }
    }
  }
  xhr.send(JSON.stringify({ message: encryptedMessage }))

  messageInput.value = ''
  const box = document.getElementById("chatbox")
  const messagebox = document.createElement('div')
  messagebox.classList.add("message")
  if (sentBySelf) {
    messageDiv.classList.add('sent');
  } else {
    messageDiv.classList.add('received');
  }

  messagebox.textContent = message
  chatContainer.appendChild(messageDiv);
  chatContainer.scrollTop = chatContainer.scrollHeight;
}
var preset = {
  "0": None
}
function clearchat(url) {
  var xhr = new XMLHttpRequest()
  var endpoint = '/clearchat'  // 服务器端的路由路径
  xhr.open('POST', url + endpoint, true)
  xhr.setRequestHeader('Content-Type', "application/x-www-form-urlencoded")
  xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
      var response = xhr.responseText
      // 处理服务器的响应
      console.log(response)
    }
  }

  xhr.send(preset)
}

function readchat() {
  var xhr = new XMLHttpRequest()
  xhr.open('GET', '/sentchat', true)
}

//主程式內容
function getchat() {
  const ChatElem = document.getElementById("chat")
  const min = 1
  const max = 10
  const chat = ChatElem.value
  const timeelem = new Date()
  var username = localStorage.getItem("username")
  ChatElem.value = ""
  var url = "chat.py"
  var xhr = new XMLHttpRequest()


  if (chat === "/clear console") {
    if (username === "justmore5mins" || "admin" || "Admin") {
      console.clear()
    } else {
      console.log("You don't have so much permission to do it")
    }
  } else if (chat === "/clear chat cache") {
    if (username === "justmore5mins" || "admin" || "Admin") {
      localStorage.clear()
      console.log("localstorage cleared")
    } else {
      console.log("You don't have so much permission to do it")
    }
  }
  else if (chat === "/clear chat storage") {
    clearchat("http://127.0.0.1:5000")
  }
  else {
    var move = Math.floor(Math.random() * max) + min
    var sentuser = localStorage.getItem("username")
    let chatdata = {
      "username": sentuser,
      "rawchat": chat,
      "encrypt": caesar(chat, move),
      "move": move,
      "time": {
        "hour": timeelem.getHours(),
        "minutes": timeelem.getMinutes(),
        "seconds": timeelem.getSeconds(),
        "milliseconds": timeelem.getMilliseconds()
      }
    }
    sentdata("http://127.0.0.1:5000", chatdata)
    console.log(chatdata)
  }
}