// setTimeout(function()
// {
//  console.log('hello world');
// },3000);

// var time=0;
// var timer=setInterval(function()
// {
//     time+=2;
//     console.log(time +" seconds have passed");
//     if(time>5)
//         {
//             clearInterval(timer);
//         }
// },2000);


// console.log(__dirname);
// console.log(__filename);

// function sayHi()
// {
//     console.log('hi');
// }
// sayHi();

// var sayBye = function()
// {
//     console.log('bye');
// };
// sayBye();


// function callFunction(fun)
// {
//     fun();
// }
// var sayBye = function()
// {
//     console.log('bye');
// };
// callFunction(sayBye);

// var stuff=require('./stuff');
// console.log(stuff.counter(['shaun','crystal']));
// console.log(stuff.adder(5,6));
// console.log(stuff.adder(stuff.pi,6));


//var events=require('events');
// element.on('click',function(){})

// var myEmitter=new events.EventEmitter();

// myEmitter.on('someEvent',function(mssg){
//     console.log(mssg);
// });

// myEmitter.emit('someEvent','the event was emitted');


// var util=require('util');

// var Person=function(name)
// {
//     this.name=name;
// };

// util.inherits(Person,events.EventEmitter);

// var james=new Person('james');
// var mary=new Person('mary');
// var ryu=new Person('ryu');
// var people=[james,mary,ryu];

// people.forEach(function(person)
// {
//     person.on('speak',function(mssg)
// {
//     console.log(person.name+'said:'+mssg);
// });
// });

// james.emit('speak','hey dudes');
// ryu.emit('speak','I want a curry');



//9
// var fs=require('fs');


//this was synchronous version now async. version
// var readMe=fs.readFileSync('readMe.txt','utf8');
// //console.log(readMe);
// fs.writeFileSync('writeMe.txt',readMe);


// var fs=require('fs');
// fs.readFile('readMe.txt','utf8',function(err,data){
//     if (err) {
//         console.error('Error reading file:', err);
//         return;
//     }
//     //console.log(data);
//     fs.writeFile('writeMe.txt',data,function(err)
// {
//     if(err){
//         console.error('error writing file',err);
//     }
// });
// });

// console.log('test');



//10
//sync.
//fs.unlinkSync('writeMe.txt');

//asyn.
// fs.unlink('writeMe.txt', function(err) {
//     if (err) {
//         console.error('Error deleting file:', err);
//     } else {
//         console.log('File deleted successfully');
//     }
// }
// );


//this is synchronous version
//fs.rmdirSync('stuff');

//asynch
// var fs=require('fs');
// fs.rmdir('stuff',  (err) => {
//     if (err) {
//         console.error('Error removing directory:', err);
//     } else {
//         console.log('Directory removed successfully');
//     }
// });



//async.
// var fs=require('fs');
// fs.mkdir('stuff',function(err)
// {
//     if (err) {
//         console.error('Error creating directory:', err);
//         return;
//     }

//     fs.readFile('readMe.txt','utf8',function(err,data)
// { 
//     if (err) {
//         console.error('Error reading file:', err);
//         return;
//     }
//     fs.writeFile('./stuff/writeMe.txt',data,function(err)
//     {
//         if(err){
//             console.error('error writing file',err);
//         }
//         else {
//             console.log('File written successfully');
//         }
//     });
// });
// });


//chatgpt
// fs.rm('stuff', { recursive: true, force: true }, (err) => {
//     if (err) {
//         console.error('Error removing directory:', err);
//     } else {
//         console.log('Directory removed successfully');
//     }
// });




// fs.unlink('./stuff/writeMe.txt',function()
// {
//     fs.rmdir('stuff');
// })


const fs = require('fs');

// Delete the file './stuff/writeMe.txt' first
fs.unlink('./stuff/writeMe.txt', function(err) {
    if (err) {
        console.error('Error deleting file:', err);
        return;
    }

    // File deletion successful, now remove the 'stuff' directory
    fs.rmdir('stuff', function(err) {
        if (err) {
            console.error('Error removing directory:', err);
            return;
        }
        console.log('Directory removed successfully');
    });
});
