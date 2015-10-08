#!/usr/bin/env ruby
# inyecta.rb

class Array

	def inyecta(acumulador)
		for i in (0...self.size)
			acumulador = yield(acumulador, self[i])
		end
		acumulador
	end

end

puts [1,4,2,5,3,7,6].inyecta(0) { |acu, x| acu + x}
