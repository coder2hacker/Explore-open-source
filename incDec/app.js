let counter = document.querySelector('#counter')
let plus = document.querySelector('#plus')
let minus = document.querySelector('#minus')
let reset = document.querySelector('#reset')

let red = document.querySelector('#red')
let blue = document.querySelector('#blue')
let green = document.querySelector('#green')


plus.addEventListener('click', function() {
    console.log(123)
    counter.innerText = parseInt(counter.innerText) + 1
})

minus.addEventListener('click', function () {
    console.log(123)
    if(counter.innerText == 0){
        return
    }
    counter.innerText = parseInt(counter.innerText) - 1
})

reset.addEventListener('click', function () {
    counter.innerText = 0
    counter.style.backgroundColor = 'white'
})

red.addEventListener('click', function(){
    counter.style.backgroundColor = 'red'
})

blue.addEventListener('click', function () {
    counter.style.backgroundColor = 'blue'
})

green.addEventListener('click', function () {
    counter.style.backgroundColor = 'green'
})