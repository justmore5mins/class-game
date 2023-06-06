function getchat() {
  const ChatElem = document.getElementById("chat");
  const min = 1;
  const max = 10;
  const chat = ChatElem.value;
  const timeelem = new Date();
  var username = localStorage.getItem("username");
  ChatElem.value = "";

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
      "username": username,
      "rawchat"
    }
  }

  console.log(chatdata);
}