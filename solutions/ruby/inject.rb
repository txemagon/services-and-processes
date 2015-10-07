#!/usr/bin/env ruby
# inject.rb

def inject(lista, acumulador)
	for i in (0...lista.size)
		acumulador = yield(acumulador, lista[i])
	end
	acumulador
end

p inject( [1,4,2,5,3,7,6], 0) { |acu, x| acu + x}
