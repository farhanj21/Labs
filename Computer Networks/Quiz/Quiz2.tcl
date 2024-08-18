#the code is not executed due to NS version error idk why i was 
#trying to make it run with differernt versions but there is some error i cannot fix
#no output is shown

set ns [new Simulator]
set tracefile [open output.nam w]
$ns namtrace-all $tracefile

# part 1
set s1 [$ns node]
set s2 [$ns node]
set s3 [$ns node]
set s4 [$ns node]
set r1 [$ns node]
set r2 [$ns node]

# part 2 to 6
$ns duplex-link $s1 $r1 10Mbps 2ms DropTail
$ns duplex-link $s2 $r1 10Mbps 3ms DropTail
$ns duplex-link $r1 $r2 1.5Mbps 20ms DropTail
$ns duplex-link $r2 $s3 10Mbps 4ms DropTail
$ns queue-limit $s1 $r1 15
$ns queue-limit $s2 $r1 15
$ns queue-limit $r1 $r2 25

# part 8 to part 9
set tcp1 [new Agent/TCP]
$ns attach-agent $s1 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $s3 $sink1
$ns connect $tcp1 $sink1
set tcp2 [new Agent/TCP]
$ns attach-agent $s2 $tcp2
set sink2 [new Agent/TCPSink]
$ns attach-agent $s3 $sink2
$ns connect $tcp2 $sink2

$tcp1 set class_ 1
$tcp2 set class_ 2

# part 11 to part 13
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set color "red"
$ftp1 set packetSize_ 1000
$ftp1 set rate_ 1Mb

#part 15
$ns at 0.0 "$ftp1 start"
$ns at 10.0 "$ftp1 stop"
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2
$ftp2 set color "blue"
$ftp2 set packetSize_ 1000
$ftp2 set rate_ 1Mb

#part 14
$ns at 3.0 "$ftp2 start"
$ns at 10.0 "$ftp2 stop"
$ns at 10.01 "finish"

proc finish {} {
    global ns tracefile
    $ns flush-trace
    close $tracefile
    exec nam out.nam &
    exit 0
}

$ns run

