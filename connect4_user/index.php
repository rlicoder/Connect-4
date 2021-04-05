<!DOCTYPE html>
<html lang="en">
<head>
 <meta charset="UTF-8">
 <title>Connect 4 Login</title>
 <script type="newjavascript.js"></script>
 <link href="newcss.css" rel="stylesheet">
 <link rel="stylesheet" href="../static/css/lx.css">
 
</head>
<body>
<div class="box">
    <h2>Connect 4 Login</h2>
 
    <div class="input_box">
        <input id="name" type="text" name="user" placeholder="Username">
    </div>
    <div class="input_box">
        <input id="pass" type="password" name="psw" placeholder="Password">
    </div>
    <div id="error_box"><br></div>
    <div class="input_box">
        <button type="button" class="btn btn-primary" onclick="fnLogin()">Login</button>&nbsp&nbsp&nbsp&nbsp
        <a href="regist.html"><input type="button" class="btn btn-info" name="regist" value="Sign up"></a>
    </div>
</div>
</body>
</html>