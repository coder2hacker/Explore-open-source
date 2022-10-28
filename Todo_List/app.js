let input = document.querySelector('#input')
let button = document.querySelector('button')
let p = document.querySelector('#todo')

try {
    let arr = JSON.parse(localStorage.getItem('text'))
    arr.forEach(text => {
        let todoText = document.createElement('p')
        todoText.innerText = text
        todoText.className = 'a'
        todoText.id = "text"

        let X = document.createElement('p')
        X.innerText = "X"
        X.className = 'a'
        X.id = "delete"

        let up = document.createElement('p')
        up.innerText = "↑"
        up.className = 'a'
        up.id = "up"

        let down = document.createElement('p')
        down.innerText = "↓"
        down.className = 'a'
        down.id = "down"

        let ele = document.createElement('div')
        ele.className = 'ele'
        ele.appendChild(X)
        ele.appendChild(up)
        ele.appendChild(down)
        ele.appendChild(todoText)
        p.appendChild(ele)

        X.addEventListener('click', function (event) {
            let arr = JSON.parse(localStorage.getItem('text'))
            arr = arr.filter(e => e !== text)

            localStorage.setItem('text', JSON.stringify(arr))
            p.removeChild(ele)
        })

        up.addEventListener('click', function (event) {
            let prevSib = ele.previousElementSibling
            //console.log(prevSib)
            if (prevSib) {
                let arr = JSON.parse(localStorage.getItem('text'))
                let ind1 = arr.indexOf(ele.children[3].innerText)
                let ind2 = arr.indexOf(prevSib.children[3].innerText)
                let temp = arr[ind1]
                arr[ind1] = arr[ind2]
                arr[ind2] = temp
                localStorage.setItem('text', JSON.stringify(arr))

                temp = todoText.innerText
                ele.children[3].innerText = prevSib.children[3].innerText
                prevSib.children[3].innerText = temp
            }
            }
        )

        down.addEventListener('click', function (event) {

            let nextSib = ele.nextElementSibling
            //console.log(prevSib)
            if (nextSib) {
                let arr = JSON.parse(localStorage.getItem('text'))
                let ind1 = arr.indexOf(ele.children[3].innerText)
                let ind2 = arr.indexOf(nextSib.children[3].innerText)
                let temp = arr[ind1]
                arr[ind1] = arr[ind2]
                arr[ind2] = temp
                localStorage.setItem('text', JSON.stringify(arr))

                temp = todoText.innerText
                ele.children[3].innerText = nextSib.children[3].innerText
                nextSib.children[3].innerText = temp
            }
        })
    })
    
} catch (error) {
    
}

input.addEventListener('keypress', function (event) {
    if(event.key !== 'Enter') return
    if (input.value === "") return;

    let text = input.value;

    let todoText = document.createElement('p')
    todoText.innerText = text
    todoText.className = 'a'
    todoText.id = "text"

    let X = document.createElement('p')
    X.innerText = "X"
    X.className = 'a'
    X.id = "delete"

    let up = document.createElement('p')
    up.innerText = "↑"
    up.className = 'a'
    up.id = "up"

    let down = document.createElement('p')
    down.innerText = "↓"
    down.className = 'a'
    down.id = "down"

    let ele = document.createElement('div')
    ele.className = 'ele'
    ele.appendChild(X)
    ele.appendChild(up)
    ele.appendChild(down)
    ele.appendChild(todoText)
    p.appendChild(ele)
    
    input.value = ""
    let arr = JSON.parse(localStorage.getItem('text'))
    //console.log(arr)
    if (arr) {
        arr.push(text)
        localStorage.setItem('text', JSON.stringify(arr))
    }
    else{
        localStorage.setItem('text', JSON.stringify([text]))
    }

    X.addEventListener('click', function (event){
        let arr = JSON.parse(localStorage.getItem('text'))
        arr = arr.filter(e => e !== text)

        localStorage.setItem('text', JSON.stringify(arr))
        p.removeChild(ele)
    })

    up.addEventListener('click', function(event){
        let prevSib = ele.previousElementSibling
        //console.log(prevSib)
        if(prevSib){
            let arr = JSON.parse(localStorage.getItem('text'))
            let ind1 = arr.indexOf(ele.children[3].innerText)
            let ind2 = arr.indexOf(prevSib.children[3].innerText)
            let temp = arr[ind1]
            arr[ind1] = arr[ind2]
            arr[ind2] = temp
            localStorage.setItem('text', JSON.stringify(arr))

            temp = todoText.innerText
            ele.children[3].innerText = prevSib.children[3].innerText
            prevSib.children[3].innerText = temp
        }
    })

    down.addEventListener('click', function (event) {
        let nextSib = ele.nextElementSibling
        //console.log(prevSib)
        if (nextSib) {
            let arr = JSON.parse(localStorage.getItem('text'))
            let ind1 = arr.indexOf(ele.children[3].innerText)
            let ind2 = arr.indexOf(nextSib.children[3].innerText)
            let temp = arr[ind1]
            arr[ind1] = arr[ind2]
            arr[ind2] = temp
            localStorage.setItem('text', JSON.stringify(arr))

            temp = todoText.innerText
            ele.children[3].innerText = nextSib.children[3].innerText
            nextSib.children[3].innerText = temp
        }
    })

})


button.addEventListener('click', function (event) {
    if (input.value === "") return;

    let text = input.value;

    let todoText = document.createElement('p')
    todoText.innerText = text
    todoText.className = 'a'
    todoText.id = "text"

    let X = document.createElement('p')
    X.innerText = "X"
    X.className = 'a'
    X.id = "delete"

    let up = document.createElement('p')
    up.innerText = "↑"
    up.className = 'a'
    up.id = "up"

    let down = document.createElement('p')
    down.innerText = "↓"
    down.className = 'a'
    down.id = "down"

    let ele = document.createElement('div')
    ele.className = 'ele'
    ele.appendChild(X)
    ele.appendChild(up)
    ele.appendChild(down)
    ele.appendChild(todoText)
    p.appendChild(ele)

    input.value = ""
    let arr = JSON.parse(localStorage.getItem('text'))
    //console.log(arr)
    if (arr) {
        arr.push(text)
        localStorage.setItem('text', JSON.stringify(arr))
    }
    else {
        localStorage.setItem('text', JSON.stringify([text]))
    }

    X.addEventListener('click', function (event) {
        let arr = JSON.parse(localStorage.getItem('text'))
        arr = arr.filter(e => e !== text)

        localStorage.setItem('text', JSON.stringify(arr))
        p.removeChild(ele)
    })

    up.addEventListener('click', function (event) {
        let prevSib = ele.previousElementSibling
        //console.log(prevSib)
        if (prevSib) {
            let arr = JSON.parse(localStorage.getItem('text'))
            let ind1 = arr.indexOf(ele.children[3].innerText)
            let ind2 = arr.indexOf(prevSib.children[3].innerText)
            let temp = arr[ind1]
            arr[ind1] = arr[ind2]
            arr[ind2] = temp
            localStorage.setItem('text', JSON.stringify(arr))

            temp = todoText.innerText
            ele.children[3].innerText = prevSib.children[3].innerText
            prevSib.children[3].innerText = temp
        }
    })

    down.addEventListener('click', function (event) {
        let nextSib = ele.nextElementSibling
        //console.log(prevSib)
        if (nextSib) {
            let arr = JSON.parse(localStorage.getItem('text'))
            let ind1 = arr.indexOf(ele.children[3].innerText)
            let ind2 = arr.indexOf(nextSib.children[3].innerText)
            let temp = arr[ind1]
            arr[ind1] = arr[ind2]
            arr[ind2] = temp
            localStorage.setItem('text', JSON.stringify(arr))

            temp = todoText.innerText
            ele.children[3].innerText = nextSib.children[3].innerText
            nextSib.children[3].innerText = temp
        }
    })

})