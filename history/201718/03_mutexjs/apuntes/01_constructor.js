/* new changes this */

function Worker(name) {
    this.q = 0
    this.name = name
}

Worker.prototype.load = function(var q) {
    this.q += q
}

var txema = new Worker("Txema")
txema.load(5)


