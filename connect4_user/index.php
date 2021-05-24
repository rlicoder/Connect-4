<!DOCTYPE html>
<html lang="en">
<head>
 <meta charset="UTF-8">
 <title>Connect 4</title>
 <script src="newjavascript.js"></script>
 <link href='https://fonts.googleapis.com/css?family=Aclonica' rel='stylesheet'>
 <link href="style.css" rel="stylesheet">
 
</head>
<body>
<div class="box">
    
    <div id="header">
            <h2 align="center">Connect 4 Login</h2>
    </div>
    <div class="input_box">
        <input id="name" type="text" name="user" placeholder="Username">
    </div>
    <div class="input_box">
        <input id="pass" type="password" name="psw" placeholder="Password">
    </div>
    <div id="error_box"><br></div>
    <label>
        <input type="checkbox" checked="checked" name="remember"> Remember me
    </label>
    <div class="input_box">
        <button type="button" class="btn btn-primary" onclick="fnLogin()">Login</button>
        &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
        <a href="regist.html"><input type="button" class="btn btn-info" name="regist" value="Sign up"></a>
    </div>
</div>
</body>
</html>