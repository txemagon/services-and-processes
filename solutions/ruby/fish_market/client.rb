class Client 

  @@ticket = 0 

  def initialize
     @@ticket += 1
     @ticket   = @@ticket
     puts "Hi. I'm client number #{@ticket}."
  end

  def ticket_number?
    @ticket
  end

end


