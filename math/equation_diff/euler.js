// const euler=(x0,y0,h,stop)=>{
//   y = y0;
//   for(var x=x0;x<=stop;x+=h){
//     console.log(y);
//     y = y+(h*prim(x,y));
//   }
//   console.log(y);
// }
// const prim = (x,y) =>{
//   return (x/y);
// }

// euler(0,1,0.2,1);


const euler=(x0,y0,h,stop,prim)=>{
  y = y0;
  for(var x=x0;x<stop;x+=h){
    console.log(y);
    y = y + (h*prim(x,y));
  }
  console.log(y);
}

const prim_1 = (t,y) =>{
  return t*Math.sin(y);
}

const prim_2 = (t,y) =>{
  return (t*t)+(y*y)+1;
}

const prim_3 = (t,y) =>{
  return y*Math.pow(Math.E,t);
}


// console.log("\n1\n")
// euler(0,2,0.1,0.3,prim_1);
// console.log("\n2\n")
// euler(1,0,0.1,1.3,prim_2);
// console.log("\n3\n")
// euler(0,2,0.1,0.3,prim_3);


// const array = Array(1.0000,
//                     1.0000,
//                     1.0200,
//                     1.0604,
//                     1.1222)

// const trapeze=()=>{
//   var x = (array[0]+array[array.length -1])/2;
//   for (let index = 1; index < array.length -1; index++) {
//     x += array[index];
//   }
//   x = x*0.1;
//   return x;
// }

const x =()=>{
  let nom =1;
  let prenom =2;

  return {nom,prenom};
}

let {nom,prenom}=x();
console.log(nom,prenom)

// const simpson=()=>{
//   var x = (array[0]+array[array.length -1]);
//   for (let index = 1; index < array.length -1; index++) {
//     x += ( index%2==0 ? 2*array[index]:4*array[index]);
//   }
//   x = x*(0.1/3);
//   return x;
// }

// console.log(trapeze());
// console.log(simpson());
