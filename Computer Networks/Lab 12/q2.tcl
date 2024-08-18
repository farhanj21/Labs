set ns [new Simulator]

set bw 512Kb
set delay 10ms

set sw1 [$ns node]
set h1 [$ns node]
set h2 [$ns node]
set h3 [$ns node]
set h4 [$ns node]
set h5 [$ns node]

$ns duplex-link $sw1 $h1 $bw $delay DropTail
$ns duplex-link $sw1 $h2 $bw $delay DropTail
$ns duplex-link $sw1 $h3 $bw $delay DropTail
$ns duplex-link $sw1 $h4 $bw $delay DropTail
$ns duplex-link $sw1 $h5 $bw $delay DropTail

$ns color $sw1 blue
$ns color $h1 red
$ns color $h2 blue
$ns color $h3 blue
$ns color $h4 red
$ns color $h5 blue

$ns rtproto DV

set tcp [new Agent/TCP]
$ns attach-agent $h1 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $h4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
$tcp set type_ "full-tcp"
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ns at 0.1 "$ftp start"
$ns at 1.5 "$ftp stop"

set udp [new Agent/UDP]
$ns attach-agent $h2 $udp
set null [new Agent/Null]
$ns attach-agent $h5 $null
$ns connect $udp $null
$udp set packetSize_ 1000 ;# 1 Kilo Byte
$udp set rate_ 256Kb ;# 256 Kbps
set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 1000
$cbr set rate_ 256Kb
$cbr attach-agent $udp
$ns at 0.2 "$cbr start"
$ns at 1.3 "$cbr stop"

# Bring the link between SW1 and H5 down at 0.5 and bring it back up at 0.9
$ns at 0.5 "$ns duplex-link-op $sw1 $h5 orient down"
$ns at 0.9 "$ns duplex-link-op $sw1 $h5 orient up"

# Bring the link between SW1 and H4 down at 0.7 and bring it back up at 1.2
$ns at 0.7 "$ns duplex-link-op $sw1 $h4 orient down"
$ns at 1.2 "$ns duplex-link-op $sw1 $h4 orient up"

# Stop the simulation at 2.0
$ns at 2.0 "finish"

proc finish {} {
    global ns
    $ns halt
    $ns flush-trace
    exit 0
}

$ns duplex-link-op $sw1 $h1 orient right-down
$ns duplex-link-op $sw1 $h2 orient right
$ns duplex-link-op $sw1 $h3 orient right-up
$ns duplex-link-op $sw1 $h4 orient left-up
$ns duplex-link-op $sw1 $h5 orient left

$ns run

