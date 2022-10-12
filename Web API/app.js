let button = document.getElementById("button");
let input = document.getElementById("username");
let name1 = document.getElementById("name");
let id = document.getElementById("id1");
let link = document.getElementById("link");
let img = document.getElementById("img");
let followers = document.getElementById("followers");
let following = document.getElementById("following");
let repos1 = document.getElementById("repos");
let allrep = document.getElementById("allrepos");
let final = document.getElementById('res');

button.addEventListener("click", function () {
    allrep.innerHTML = "";
    let name = new XMLHttpRequest();
    let rep = new XMLHttpRequest();
    if (input.value.trim() == "") {
        alert("Empty Value:(")
        return;
    }
    else

        name.open("GET", `https://api.github.com/users/${input.value}`, true);
    rep.open("GET", `https://api.github.com/users/${input.value}/repos`, true);
    name.send();
    rep.send();
    name.addEventListener("load", function (event) {
        let obj = JSON.parse(name.responseText);

        console.log(obj);

        createData(obj);
    });

    rep.addEventListener("load", function () {
        let obj1 = JSON.parse(rep.responseText);
        console.log(obj1);
        //obj1.forEach(createRepos());
        createRepos(obj1);
    })


    function createData(obj) {
        name1.innerHTML = "Name : " + obj.name;
        id.innerHTML = input.value;
        link.href = obj.html_url;
        img.src = obj.avatar_url;
        followers.innerHTML = "Followers : " + obj.followers;
        following.innerHTML = "Following : " + obj.following;
        repos1.innerHTML = "Repos : " + obj.public_repos;
    }
});




function createRepos(obj1) {
    for (let i = 0; i < obj1.length; i++) {
        let div = document.createElement('div');
        let h = document.createElement('a');
        h.innerHTML = obj1[i].name;
        h.href = obj1[i].clone_url;
        h.style.textDecoration = 'none';
        h.style.color = 'white';
        div.style.border = '1px solid black';
        div.appendChild(h);
        allrep.appendChild(div);
        final.style.display = 'block';
    }
}
