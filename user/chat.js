function getchat() {
  const ChatElem = document.getElementById("chat");
  const min = 1;
  const max = 10;
  const chat = ChatElem.value;
  const timeelem = new Date();
  var username = localStorage.getItem("username");
  ChatElem.value = "";
  var url = "chat.py";
  var xhr = new XMLHttpRequest();


  if (chat === "/clear console") {
    if (username === "justmore5mins" || "admin" || "Admin") {
      console.clear();
    } else {
      console.log("You don't have so much permission to do it");
    }
  } else if (chat === "/clear chat localstorage") {
    if (username === "justmore5mins" || "admin" || "Admin") {
      localStorage.clear();
      console.log("localstorage cleared");
    } else {
      console.log("You don't have so much permission to do it");
    }
  } else {
    var move = Math.floor(Math.random() * max) + min;
    var sentuser = localStorage.getItem("username");
    let chatdata = {
      "username": sentuser,
      "rawchat":chat,
      "encrypt":caesar(chat,move),
      "move":move,
      "time":{
        "hour": timeelem.getHours(),
        "minutes": timeelem.getMinutes(),
        "seconds": timeelem.getSeconds(),
        "milliseconds": timeelem.getMilliseconds()
      }
    }
    xhr.open('POST',url,true);
    xhr.setRequestHeader('Content-Type','application/json');
    xhr.onreadystatechange = function() {
      if (xhr.readyState === 4 && xhr.status === 200) {
        var response = xhr.responseText;  // 获取响应数据
        console.log("response: ",response)
      }
    };
    xhr.send(JSON.stringify(chatdata)); 
    console.log(chatdata);
  }
}

function caesar(str, num) {
  let newString = '';
  // num %= 26;

  for (let i = 0; i < str.length; i++) {
    let c = str.charCodeAt(i);

    // 大寫
    if (c >= 65 && c <= 90) {
      newString += String.fromCharCode((c - 65 + num) % 26 + 65);
    } else if (c >= 97 && c <= 122) { // 小寫
      newString += String.fromCharCode((c - 97 + num) % 26 + 97);
    } else { // 非字母就直接加到輸出的密文
      newString += str.charAt(i);
    }
  }
  return newString;
}
