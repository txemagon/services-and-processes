
Array.prototype.each = function (fn) {

    for (var i=0; i<this.length; i++)
        fn(this[i])
}

Array.prototype.inject = function (acum, fn){

    for (var i=0; i<this.length; i++)
        acum = fn(acum, this[i])

    return acum
}

function main() {

    var a = [1,2,3,4,5,6]
    var p = []

    a.each(function(el){
        if (el > 2 && el % 2 == 1)
            p.push(el)
    })

    p.each(function (el){
        alert(el)
    })

    alert(a.inject(0, function(acum, el){
        return acum + el * el
    }))
}
