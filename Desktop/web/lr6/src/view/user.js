import React from 'react';
import * as axios from "axios";

const style = {
    divSt: {
        width: "100%",
        display: "flex",
        height: "30px",
        alignItems: "center",
        marginBottom: "1rem",
        marginTop: "1rem"
    },

    divButton: {
        flexBasis: '20%',
        height: '100%',
        border: '1px solid #ccc',
        borderRadius: '5px',
        background: '#eee',
        transition: '0.3s all',
        cursor: 'pointer'
    },
    li: {
        position: "relative",
        border: "1px solid #ccc",
        borderRadius: "5px",
        padding: "0.5rem 1rem",
        marginBottom: "0.5rem",
        display: "flex",
        justifyContent: "space-between"
    },
    modal: {
        display: "none",
        background: "#fefefe",
        padding: "20px",
        border: "1px solid #888",
        width: "15%",
        position: "absolute"
    },
    close: {
        color: "#aaa",
        float: "right",
        fontSize: "28px",
        fontWeight: "bold",
        cursor: 'pointer'
    },
    input:{
        webkitAppearance:"block"
    }
}

class User extends React.Component {

    constructor(prep) {
        super(prep)
        let userName = window.location.search.split("=").pop()
        this.state = {
            share: [],
            myShare: [],
            mySettings: {},
            userName: userName
        }
        this.id = 0;
    }

    sellShare(id) {
        console.log("selShare=", document.getElementById("modalNumber").innerText)
        // if (document.getElementById("number" + id).innerText > document.getElementById("modalNumber" ).value
        //                                                 && document.getElementById("modalNumber").value > 0) {
        //     alert("sosi xui")
        //     return;
        // }
        // axios.put('http://localhost:3456/broker', {
        //     nameUser: this.state.userName,
        //     name: document.getElementById("myname" + id).innerText,
        //     number: document.getElementById("modalNumbe").value,
        //     cost: document.getElementById("myinitial_cost" + id).innerText
        // })
        //     .then(this.componentDidMount())
        //     .catch(function (error) {
        //         console.log(error);
        //     })

    }

    byShare(id) {
        axios.post('http://localhost:3456/broker', {
            nameUser: this.state.userName,
            name: document.getElementById("name" + id).innerText,
            number: document.getElementById("number" + id).innerText,
            cost: document.getElementById("initial_cost" + id).innerText
        })
            .then(this.componentDidMount())
            .catch(function (error) {
                console.log(error);
            })

    }

    componentDidMount() {
        console.log("in")
        axios.get('http://localhost:3456/share')
            .then(res => {
                this.setState({share: res.data});
            })
            .catch(function (error) {
                console.log(error);
            })
        axios.get('http://localhost:3456/broker')
            .then(res => {
                res.data.map((el) => {
                    if (el.name === this.state.userName) {
                        this.setState({mySettings: el})
                        this.setState({myShare: el.bayShare})
                        return
                        console.log(this.state.myShare)
                    }
                })
            })
            .catch(function (error) {
                console.log(error);
            })
    }


    render() {
        return (
            <div>
                <div id="modal" style={style.modal}>

                    <span style={style.close} onClick={() => {
                        document.getElementById("modal").style.display = "none"
                    }}>&times;
                    </span>
                    <input id="modalNumber" style={style.input} type="number"  />
                    <button id="buttonModel"onClick={() => {
                        console.log("selShare=", document.getElementById("modalNumber").value)
                        // if (document.getElementById("buttonModel").innerText === 'bay')
                        //     this.byShare(this.id)
                        // else if (document.getElementById("buttonModel").innerText === 'sell')
                        //     this.sellShare(this.id)
                        document.getElementById("modal").style.display = "none"
                    }}/>
                </div>
                <div>
                    <h1>{this.state.mySettings.name}</h1>
                    <h1>{this.state.mySettings.startBalance}</h1>
                    <h1>{this.state.mySettings.balance}</h1>

                </div>
                <ul>
                    {this.state.myShare.map(el => {
                        return (<li style={style.li}>
                            <div id={`myname${el.id}`} style={style.divSt}>{el.name}</div>
                            <div id={`mynumber${el.id}`} style={style.divSt}>{el.number}</div>
                            <div id={`myinitial_cost${el.id}`} style={style.divSt}>{el.cost}</div>
                            <button onClick={(event) => {
                                this.id = el.id
                                document.getElementById("buttonModel").innerText = "sell"
                                document.getElementById("modal").style.display = "block"
                                document.getElementById("modal").style.left = (event.pageX + 70) + "px"
                                document.getElementById("modal").style.top = (event.pageY - 70) + "px"
                            }} style={style.divButton}>Купить
                            </button>
                        </li>)

                    })}
                    <h1>dfghfdghdfghdfgh</h1>
                </ul>
                <ul>
                    {this.state.share.map(el => {
                        return (<li style={style.li}>
                            <div id={`name${el.id}`} style={style.divSt}>{el.name}</div>
                            <div id={`number${el.id}`} style={style.divSt}>{el.number}</div>
                            <div id={`initial_cost${el.id}`} style={style.divSt}>{el.initial_cost}</div>
                            <button onClick={(event) => {
                                this.id = el.id
                                document.getElementById("buttonModel").innerText = "bay"
                                document.getElementById("modal").style.display = "block"
                                document.getElementById("modal").style.left = (event.pageX + 70) + "px"
                                document.getElementById("modal").style.top = (event.pageY - 70) + "px"
                            }} style={style.divButton}>Купить
                            </button>
                        </li>)

                    })}
                </ul>

            </div>
        )
    }

}

export default User;
