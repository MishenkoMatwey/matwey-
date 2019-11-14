import React from 'react';
import Login from './view/login'
import Admin from './view/admin'
import User from './view/user'
import './App.css';
import {BrowserRouter, Route} from "react-router-dom";
const style={
    container: {
    paddingTop: '3rem',
    width: '600px',
    margin: '0 auto',
}
}
function App() {
    return (
        <BrowserRouter>
            <div style={style.container}>
                <Route path="/login"component={Login}/>
                <Route path="/admin" component={Admin}/>
                <Route path="/user" component={User}/>
            </div>
        </BrowserRouter>
    );
}

export default App;
