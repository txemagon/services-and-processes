class MachineGun

    @@count = 0

    def initialize
        @@count +=1
        raise "I've only purchased one" if @@count > 1
    end

    def shoot
        puts "ratatata"
    end
end
