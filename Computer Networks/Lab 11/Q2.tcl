set ns [new Simulator]

set nf [open out.nam w]
$ns namtrace-all $nf

proc finish {} {
  global ns nf

  $ns flush-trace
  close $nf
  exec nam out.nam &
  exit 0
}

#part 1
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

#part 2 + part 3
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mb 20ms DropTail

#part 4
$n0 set queue-limit 10
$n1 set queue-limit 10
$n2 set queue-limit 10
$n3 set queue-limit 10
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right

#part 5 + part 6
set tcp [new Agent/TCP]
set sink [new Agent/TCPSink]
$ns attach-agent $n1 $tcp
$ns attach-agent $n3 $sink
$ns connect $tcp $sink

#part 7
set udp [new Agent/UDP]
set null [new Agent/Null]
$ns attach-agent $n0 $udp
$ns attach-agent $n3 $null
$ns connect $udp $null

#part 8 + part 9
set ftp [new Application/FTP]
set cbr [new Application/Traffic/CBR]
$ftp attach-agent $tcp
$cbr attach-agent $udp
$ns at 0.5 "$ftp start"
$ns at 4.0 "$ftp stop"

#part 10
$ns color $tcp red
$ns color $udp blue

#part 11 + part 12
$cbr set packetSize_ 1000
$cbr set interval 0.01 
$ns at 0.1 "$cbr start"
$ns at 4.5 "$cbr stop"
$ns at 5.0 "finish"

$ns run
