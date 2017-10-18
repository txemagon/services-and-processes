var pila = []
var mutex = []
var log = null


function Obrero(name, especialidad){
    this.name = name
    this.especialidad = especialidad
}

Obrero.prototype.log = null

Obrero.prototype.cargar = function () {
     this.log.innerHTML += "[" + this.name + "]: El cargar es un placer ...<br/>\n"
}

Obrero.prototype.descargar = function () {
    this.log.innerHTML += "[" + this.name + "]: Scargando me paso el dia scargando ...<br/>\n"
}

function main() {
    Obrero.prototype.log =  document.getElementById("log")
    var macario = new Obrero("Macario", Obrero.prototype.cargar)
    var manuelo = new Obrero("Manuelo", Obrero.prototype.descargar)

    macario.especialidad()
    macario.especialidad.call(manuelo)

    var a = macario.especialidad
    a.call(macario)
    manuelo.especialidad.call(macario) /* Friend */

/*
    mutex.push(cargar)
    mutex.push(cargar)
    mutex.push(descargar)
    mutex.push(cargar)
    mutex.push(descargar)

    for(var i=0; i<mutex.length; i++)
        mutex[i]()
        */
}
