proc printEven {num} {
    set i 4
    while {$i <= $num} {
        puts $i
        incr i 2
    }
}

proc printOdd {num} {
    set i 3
    while {$i <= $num} {
        puts $i
        incr i 2
    }
}

puts "Enter number greater than 4"
flush stdout
set num [gets stdin]

if {![string is integer $num]} {
    puts "Please enter a valid number"
    exit
}

set num [expr {$num + 0}]

if {$num <= 4} {
    puts "Number should be greater than 4"
} else {
    if {$num % 2 == 0} {
        puts "Even numbers from 4 to $num:"
        printEven $num
    } else {
        puts "Odd numbers from 3 to $num:"
        printOdd $num
    }
}
