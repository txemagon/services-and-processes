
Array.prototype.each = function (fn) {

    for (var i=0; i<this.length; i++)
        fn(this[i])
}

Array.prototype.inject = function (acum, fn){

    for (var i=0; i<this.length; i++)
        acum = fn(acum, this[i])

    return acum
}

Array.prototype.select_if = function (fn){
    var r = []

    for (var i=0; i<this.length; i++)
        if (fn(this[i]))
          r.push(this[i])
    return r

}

function main() {

    var a = [1,2,3,4,5,6]
    var p = []

    alert(a.inject(1, function(acum, el){
        return acum * el
    }))

    alert( a.select_if(function(el){
        return el % 2
    }).toSource() )

    a.each(function(el){
        if (el > 2 && el % 2 == 1)
            p.push(el)
    })

    p.each(function (el){
        alert(el)
    })

}
