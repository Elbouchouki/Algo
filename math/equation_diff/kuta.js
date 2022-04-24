const k =(x,y,prim)=>{
  return prim(x,y);
}
const yt = (y,k1,k2,k3,k4) => {
  return y+((1/6)*(k1+2*(k2+k3)+k4));
} 
const ytt = (y,h,k1,k2) => {
  return y+((h/2)*(k1+k2));
} 

const kuta_2=(x0,y0,h,primt)=>{
  var x = x0;
  var y = y0;
  for(var i=0;i<3;i++){
    var k1 = k(x,y,primt);
    var k2 = k(x+h,y+h*k1,primt)
    y = ytt(y,h,k1,k2)
    console.log(y);
    x+=h;
  }
}

const kuta_4=(x0,y0,h,primt)=>{
  var x = x0;
  var y = y0;
  for(var i=0;i<3;i++){
    var k1 = k(x,y,primt);
    var k2 = k(x+(h/2),y+(k1/2),primt)
    var k3 = k(x+(h/2),y+(k2/2),primt)
    var k4 = k(x+(h/2),y+(k3/2),primt)
    y = yt(y,k1,k2,k3,k4)
    console.log(y);
    x+=h;
  }
}


const primt=(t,y)=>{
  return t*Math.sin(y);
}
const primt_2=(t,y)=>{
  return t*t+y*y+1;
}

kuta_2(0,1,0.1,primt);
console.log("")
kuta_4(0,1,0.1,primt);