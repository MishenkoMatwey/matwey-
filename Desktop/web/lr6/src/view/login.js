import React from 'react';
import * as axios from "axios";


const Login = () => {
    function f() {
        let login = document.getElementById("login").value;
        axios.get('http://localhost:3456/broker')
            .then(res => {
                res.data.forEach((elm) => {
                    if (login === 'admin') {
                        document.location.href = 'http://localhost:3000/admin';
                        return;
                    }
                    if (login === elm.name) {
                        document.location.href = 'http://localhost:3000/user?name='+login;
                        return;
                    }
                })
            })
            .catch(function (error) {
                console.log(error);
            })
        document.getElementById("login").value = ('')
        document.getElementById("password").value = ('')

    }

    return (
        <div>
            <h1>Login</h1>
            <input id="login"/>
            <input id="password"/>
            <button type="submit" onClick={f}>wergwrgwergw</button>
        </div>
    )
}
export default Login;
