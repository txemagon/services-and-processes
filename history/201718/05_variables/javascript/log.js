function Log(div) {
    this.mssgs = []
    this.output = document.getElementById(div)
}

Log.prototype.dump = function (){
    this.output.innerHTML = this.mssgs.toString()
}

Log.prototype.log = function (mssg) {
    this.mssgs.push(new Date() + ": " + mssg + "<br/>\n")
    this.dump()
}
