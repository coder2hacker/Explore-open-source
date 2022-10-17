require("dotenv").config()
const express = require("express")
const path = require("path")

const app = express()

app.use(express.json())
app.use(express.urlencoded({extended : true}))


//* middleware to make the folder public
app.use(express.static(path.resolve(__dirname, process.env.PUBLIC_DIR)))

///* router to give response error 404
app.use((err,req,res, next)=>{
    console.log(err.stack)
    res.status(500).send({
        message: err.message
    })
})

app.listen((process.env.PORT), () => {
    console.log("server is running in  " + process.env.PORT)
})
