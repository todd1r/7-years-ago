// var http=require('http');

// // var server=http.createServer(function(req,res){
// //     console.log('request was made:'+req.url);
// //     res.writeHead(200,{'Content-Type':'text/plain'});
// //     res.end('Hey ninjas');
// // });

// // server.listen(7000,'127.0.0.1');
// // console.log('listening to port 7000');


// //14
// var fs=require('fs');
// var myReadStream=fs.createReadStream(__dirname+'/readMe.txt');
// //var myReadStream=fs.createReadStream(__dirname+'/readMe.txt','utf8');


// var myWriteStream=fs.createWriteStream(__dirname+'/writeMe.txt');
// // myReadStream.on('data',function(chunk)
// // {
// //     console.log('new chunk received:');
// //     //console.log(chunk);
// //     myWriteStream.write(chunk);
// // });


// myReadStream.pipe(myWriteStream);




//16
// var http=require('http');
// var fs=require('fs');
// var server=http.createServer(function(req,res)
// {
//     console.log('request was made:'+req.url);
//     res.writeHead(200,{'Content-Type':+'text/plain'});
//     var myReadStream=fs.createReadStream(__dirname+'/readMe.txt','utf8');
//     myReadStream.pipe(res);
// });
// server.listen(7000,'127.0.0.1');



//17
// var http=require('http');
// var fs=require('fs');
// var server=http.createServer(function(req,res)
// {
//     console.log('request was made:'+req.url);
//     res.writeHead(200,{'Content-Type':+'text/html'});
//     var myReadStream=fs.createReadStream(__dirname+'/index.html','utf8');
//     myReadStream.pipe(res);
// });
// server.listen(7000,'127.0.0.1');


// var http=require('http');
// var fs=require('fs');
// var server=http.createServer(function(req,res)
// {
//     console.log('request was made:'+req.url);
//     res.writeHead(200,{'Content-Type':+'application/json'});
//     var myObj={
//         name:'ryu',
//         job:'ninja',
//         age:29
//     };
//     res.end(JSON.stringify(myObj));
// });
// server.listen(7000,'127.0.0.1');



//19
// var http=require('http');
// var fs=require('fs');
// var server=http.createServer(function(req,res)
// {
//     console.log('request was made:'+req.url);
//     if(req.url==='/home'||req.url==='/'){
//     res.writeHead(200,{'Content-Type':+'text/html'});
//     fs.createReadStream(__dirname+'/index.html').pipe(res);
//     }
//     else if(req.url==='/contact'){
//         res.writeHead(200,{'Content-Type':+'text/html'});
//         fs.createReadStream(__dirname+'/contact.html').pipe(res);
//         }
//         else if(req.url==='/api/ninjas'){
//             var ninjas=[{name:'ryu',age:29},{name:'yoshi',age:32}];
//             res.writeHead(200,{'Content-Type':+'application/json'});
//             res.end(JSON.stringify(ninjas));
//             }
//             else {
//                 res.writeHead(200,{'Content-Type':+'text/html'});
//                 fs.createReadStream(__dirname+'/404.html').pipe(res);
//                 }
// });
// server.listen(7000,'127.0.0.1');


//20 
//npm install expresss
//npm uninstall express


//21
//npm init -y
//npm install nodemon -g || npm install -g nodemon
//enter RS in terminal to restart


//23
var express=require('express');
var app=express();
app.get('/',function(req,res)
{
    res.send('this is the homepage');
});
app.get('/contact',function(req,res)
{
    res.send('this is the contact page');
});
app.get('/profile/:name',function(req,res)
{
    res.send('you requested to see a profile with the name of '+req.params.name0);
});
app.listen(3000);