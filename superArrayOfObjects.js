// Example data
const aob = 
[
    { framework: 'React.JS', website: 'Paypal' },
    { framework: 'React.JS', website: 'Tesla' },
    { framework: 'Angular', website: 'Google' },
    { framework: 'Vue.JS', website: 'Vue' },
    { framework: 'JavaScript', website: 'inblack67' },
]
const superAob = (data, victim) => {

    const obj = {};
  
    data.forEach((data) => {
        if(data.hasOwnProperty(victim)){
            if(obj[data[victim]]){
                obj[data[victim]]++;
            }
            else{
                obj[data[victim]] = 1;
            }
        }
    })
  
    let superArrayOfObjects = [];
  
    for (const key in obj) {
        superArrayOfObjects = [...superArrayOfObjects, { victim: key, count: obj[key]}];
    }
  
    return superArrayOfObjects;
}

const superAobMethodSecond = (data, victim) => {

    const totalKeys = []
    data.forEach(a =>  {
    if(!totalKeys.includes(a[victim]))
    { 
      totalKeys.push(a[victim]);
    }
    });
    
    let superArrayOfObjects = [];  
    totalKeys.forEach((types) => {

        const length = data.filter((aobject)=> aobject[victim] === types).length;
        superArrayOfObjects = [...superArrayOfObjects, { victim: types, count: length}];
    })
  
    return superArrayOfObjects;
}

console.log(superAob(aob, 'framework'));

console.log(superAobMethodSecond(aob, 'framework'));

// output:-
// [
//     { victim: 'React.JS', count: 2 },
//     { victim: 'Angular', count: 1 },
//     { victim: 'Vue.JS', count: 1 },
//     { victim: 'JavaScript', count: 1 }
// ]
