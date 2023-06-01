function redirect() {
  localStorage.clear();
  var username = document.getElementById("username").value;

  if (username === "Justmore5mins") {
    window.open("justmore5mins.html");

    var myagent = {
      username: "Justmore5mins",
      permission: "Justmore5mins",
    };
    localStorage.setItem("username", JSON.stringify(myagent));
  } else if (username === "@dm1n") {
    window.open("admin.html");
    var adminagent = {
      username: "admin",
      permission: "admin",
    };
    localStorage.setItem("username", JSON.stringify(adminagent));
  } else {
    window.open("user/user.html");
    var username = {
      name: username,
      permission: "user",
    };
    localStorage.setItem("username", JSON.stringify(username));
  }
}
