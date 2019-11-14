const express = require('express');
const server = express();
const http = require('http');
const fs = require('fs');
const fsE = require("fs-extra");
const path = require('path');
const bodyParser = require('body-parser');
const cors = require('cors');
server.use(bodyParser.urlencoded({
    extended: true
}));
const corsOptions = {
    'credentials': true,
    'origin': true,
    'methods': 'GET,HEAD,PUT,PATCH,POST,DELETE',
    'allowedHeaders': 'Authorization,X-Requested-With,X-HTTP-Method-Override,Content-Type,Cache-Control,Accept'
};
server.use(cors(corsOptions))
server.use(bodyParser.json())
server.use(express.static(path.join(__dirname, '/json')))
server.listen(3456)
console.log("123")
server.get('/broker', (req, res) => {
    console.log("in")

    fs.readFile(__dirname + "/json/brokers.json", {encoding: 'utf-8'}, function (err, data) {
        if (err) {
            if (err.code == 'ENOENT')
                console.error(err.message)
            else
                console.error(err)
        } else {
            // fs.writeFile(__dirname + "json/brokers.json", JSON.stringify(arr), (err) => {
            //  if (err) throw err
            // })
            res.send(data)
        }
    })
});
server.get('/setting', (req, res) => {
    console.log("in")

    fs.readFile(__dirname + "/json/settings.json", {encoding: 'utf-8'}, function (err, data) {
        if (err) {
            if (err.code == 'ENOENT')
                console.error(err.message)
            else
                console.error(err)
        } else {
            // fs.writeFile(__dirname + "json/brokers.json", JSON.stringify(arr), (err) => {
            //  if (err) throw err
            // })
            res.send(data)
        }
    })
});
server.get('/share', (req, res) => {
    console.log("in")

    fs.readFile(__dirname + "/json/share.json", {encoding: 'utf-8'}, function (err, data) {
        if (err) {
            if (err.code == 'ENOENT')
                console.error(err.message)
            else
                console.error(err)
        } else {
            // fs.writeFile(__dirname + "json/brokers.json", JSON.stringify(arr), (err) => {
            //  if (err) throw err
            // })
            res.send(data)
        }
    })
});

server.post('/broker', (req, res) => {
    let m = req.body;
    fs.readFile(__dirname + "/json/brokers.json", {encoding: 'utf-8'}, function (err, data) {
        if (err) {
            if (err.code == 'ENOENT')
                console.error(err.message)
            else
                console.error(err)
        } else {
            let newArr = JSON.parse(data)
            newArr.forEach(el => {
                if (el.name == m.nameUser) {
                    el.bayShare.push({
                        name: m.name,
                        number: m.number,
                        cost: m.cost
                    })
                }
            })
            fs.writeFileSync(__dirname + "/json/brokers.json", JSON.stringify(newArr), {encoding: 'utf-8'})
        }
    })
    res.send("ok")
});
server.post('/setting', (req, res) => {
    let m = req.body;
    fs.writeFileSync(__dirname + "/json/settings.json", JSON.stringify(m), {encoding: 'utf-8'})
});
server.post('/share', (req, res) => {
    let m = req.body;
    console.log(m);
    fs.writeFileSync(__dirname + "/json/share.json", JSON.stringify(m), {encoding: 'utf-8'})
});

server.put('/broker', (req, res) => {
    let m = req.body;
    fs.readFile(__dirname + "/json/brokers.json", {encoding: 'utf-8'}, function (err, data) {
        if (err) {
            if (err.code == 'ENOENT')
                console.error(err.message)
            else
                console.error(err)
        } else {
            let newArr = JSON.parse(data)
            newArr.forEach(el => {
                if (el.name == m.nameUser) {
                    el.bayShare = el.bayShare.filter(element => element.name !== m.name)
                    console.log(el.bayShare)
                }
            })
            fs.writeFileSync(__dirname + "/json/brokers.json", JSON.stringify(newArr), {encoding: 'utf-8'})
        }
    })
    res.send("ok")
});
