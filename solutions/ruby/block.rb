#!/usr/bin/env ruby
# block.rb
# Demonstrates de use of blocks

require 'prime'

primo    = []
perfecto = []

(1..100).each { |x| primo << x if Prime.prime? x }

(1..100000).each do |x|
    divisores = []
    (x/2).downto(1) { |n| divisores << n if x % n == 0  }

	perfecto << x if divisores.inject(0) { |mem, var| mem + var } == x
end

p primo
p perfecto