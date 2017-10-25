require './machine_gun.rb'

class Steward

    @@count = 0

    def initialize(name, mg)
        @name = name
        @@count += 1
        @dni = @@count
        @where_is_rock_n_roll = mg
    end

    def greet(name)
        puts "Helloooou, Mr. #{name}. I'm #{@dni} - #{@name}, your personal stewart."
    end

    def defend
        @where_is_rock_n_roll.shoot
    end

    def self.count
        @@count
    end

end
