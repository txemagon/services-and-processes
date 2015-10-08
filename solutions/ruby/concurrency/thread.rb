#!/usr/bin/env ruby
# thread.rb

$mongers = []

def do_monger(word)
    $mongers << Thread.new do

       15000.times do |i|
         puts "#{word.capitalize} #{i}."
       end

    end
end

%w/hola adios/.each { |word| do_monger word }

$mongers.each { |thread| thread.join }
