#!/usr/bin/env ruby 
# fish_market.rb
# 
# Use touch go_home.txt from command line  
# to stop business

require_relative 'client'

GO_HOME = "go_home.txt"

# Fishmongers and market access may 
# lead us to unstable states in the 
# fm_queue array
mutex       = Mutex.new
fm_queue    = []
fishmongers = []

# Number of employees working at the same time
staff = ARGV[0].to_i || 1
opening_at = File.ctime(GO_HOME)

# Its possible for clients to come in.
closing = false

# The door throwing clients
   Thread.new do 
     while (!closing) do
       sleep(rand(3));
       mutex.synchronize { 
          fm_queue.push Client.new 
       }
     end
   end

# fishmongers serving clients
staff.times do |employee|
   fishmongers << Thread.new do 
      while(!(closing && fm_queue.empty?)) do
          unless fm_queue.empty?
          mutex.synchronize { 
      	 puts "E:#{employee+1} - Number #{fm_queue.shift.ticket_number?}?"
          }
            sleep(rand(27))
          end
      end
   end
end

# go_home.txt modification detection
while(!closing) do
  if File.ctime(GO_HOME) != opening_at
     closing = true 
     puts "BUSINESS CLOSED"
  end
end

# Doors closed but customers still in
fishmongers.each { |thread| thread.join }

# Everybody out
puts "Every single client has been served. Employees can go home."
