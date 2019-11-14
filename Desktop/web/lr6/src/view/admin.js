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
        outline: 'none',
        background: '#eee',
        transition: '0.3s all',
        cursor: 'pointer'
    }
}

class Admin extends React.Component {

    constructor(prep) {
        super(prep)
        this.state = {
            setting: []
        }
    }
    f=()=>{
    console.log( document.getElementById("select1").value   )
    }
    componentDidMount() {
        axios.get('http://localhost:3456/broker')
            .then(res => {
                this.setState({setting: res.data});
            })
            .catch(function (error) {
                console.log(error);
            })
    }


    render() {
        return (
            <div>
                <ul>
                    {this.state.setting.map(el => {
                        return (<div style={style.divSt}>
                            <div>{el.name}</div>
                            <div>{el.balance}</div>
                            <button style={style.divButton} onClick={this.f}>Начало торгов</button>
                            <select id={`select${el.id}`}>
                                <option>1</option>
                                <option>2</option>
                            </select>
                        </div>)

                    })}
                </ul>

            </div>
        )
    }

}

export default Admin;
