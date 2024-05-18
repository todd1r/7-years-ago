var counter=function(arr)
{
    return 'there are '+arr.length+' eles in the arr';
};

var adder=function(a,b)
{
    return `The sum of the 2 nos. is ${a+b}`;
};

var pi=3.142;

// module.exports.counter=counter;
// module.exports.adder=adder;
// module.exports.pi=pi;


module.exports={
    counter:counter,
    adder:adder,
    pi:pi
};



// module.exports.counter=function(arr)
// {
//     return 'there are '+arr.length+' eles in the arr';
// };

// module.exports.adder=function(a,b)
// {
//     return `The sum of the 2 nos. is ${a+b}`;
// };

// module.exports.pi=3.142;