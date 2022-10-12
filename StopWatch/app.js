document.getElementById("button").addEventListener("click", myFunction);

let id;
let ctr = 0;
let min = 0;
let hrs = 0;
let H = document.getElementById("hrs");
let M = document.getElementById("min");
let addData = document.getElementById("addData")
let h1 = document.getElementById('h1');
let b = document.getElementById("button");

let b1 = document.getElementById("button1");
let count = 0;


b1.addEventListener("click", myFunction2);

function myFunction2() {

    if (ctr % 2 == 0) {
        clearInterval(id);
        id = setInterval(increment, 1000);
        b.style.display = 'none';
        ctr++;
        b1.style.display = 'block';
    }
    else {
        b.style.display = 'block';
        b1.style.display = 'none';
        ctr++;
        clearInterval(id);
    }

}
function myFunction() {

    if (ctr % 2 == 0) {
        clearInterval(id);
        id = setInterval(increment, 1000);
        b.style.display = 'none';
        ctr++;
        b1.style.display = 'block';
    }
    else {
        b.style.display = 'block';
        b1.style.display = 'none';
        ctr++;
        clearInterval(id);
    }



}
function increment() {
    if (count == 59) {
        count = -1;
        min++;
        M.innerHTML = min
    }
    if (min == 59) {
        min = -1;
        hrs++;
        H.innerHTML = hrs;
    }

    count++;
    h1.innerHTML = count;
}

document.getElementById("lap").addEventListener("click", myFunction1);

function myFunction1() {
    if (count > 0) {
        let br = document.createElement('br');
        let hr = document.createElement('hr');
        let div = document.createElement('div');
        let h = document.createElement("h1");
        let m = document.createElement('h1');
        let s = document.createElement('h1');
        let x = document.createElement('p');
        let y = document.createElement('p');
        let z = document.createElement('p');

        x.innerHTML = 'hours';
        y.innerHTML = 'minutes';
        z.innerHTML = 'seconds';

        x.style.fontSize = 50;
        x.style.color = "white"
        m.style.color = "white";
        s.style.color = "white";
        h.style.color = "white";
        y.style.color = "white";
        z.style.color = "white";

        h.innerHTML = hrs;

        m.innerHTML = min;
        s.innerHTML = count;

        div.appendChild(h);
        div.appendChild(x)
        div.appendChild(m);
        div.appendChild(y)
        div.appendChild(s);
        div.appendChild(z);
        h.style.textAlign = 'center';
        div.style.display = 'flex';
        addData.appendChild(div);
        addData.appendChild(hr);
        addData.appendChild(br);
    }
}