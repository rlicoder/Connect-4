/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


function fnLogin() {
    var name = document.getElementById("uname")
    var pass = document.getElementById("upass")
    var error = document.getElementById("error_box")
    var isError = true;
    if (name.value.length > 18 || name.value.length < 6) {
        error.innerHTML = "Please enter username between 6-18 length";
        isError = false;
        return;
    }
    else if((name.value.charCodeAt(0)>=48) && (name.value.charCodeAt(0)<=57)){
        error.innerHTML = "Username must start with a letter";
        return;
    }
    else for(var i=0;i<name.value.charCodeAt(i);i++){
        if((name.value.charCodeAt(i)<48)||(name.value.charCodeAt(i)>57) && (name.value.charCodeAt(i)<97)||(name.value.charCodeAt(i)>122)){
            error.innerHTML = "Username can only contain letters and numbers";
            return;
        }
    }

    if (pass.value.length > 18 || pass.value.length < 6) {
        error.innerHTML = "Please enter password between 6-18 length"
        isError = false;
        return;
    }
    window.alert("Regist successful")
}