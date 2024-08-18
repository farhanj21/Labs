set ns [new Simulator]

# part 2 = link parameters
set bw 512Kbps
set delay 5ms

# part 1 = 7 nodes
for {set i 0} {$i < 7} {incr i} {
    set node($i) [$ns node]
}

# part 1 = ring topology
for {set i 0} {$i < 6} {incr i} {
    $ns duplex-link $node($i) $node([expr {($i+1) % 7}]) $bw $delay DropTail
}

$ns duplex-link $node(6) $node(0) $bw $delay DropTail ;# Link between last and first node

# part 3 = routing protocol to Distance Vector
$ns rtproto DV

# part 4 = UDP agent at node 0 sending packets to node 3
set udp [new Agent/UDP]
$ns attach-agent $node(0) $udp
set null [new Agent/Null]
$ns attach-agent $node(3) $null
$ns connect $udp $null
set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 1000 ;# 1 Kilo Byte
$cbr set rate_ 100 ;# 100 packets/sec
$cbr attach-agent $udp

# part 5 = Start transmission at 0.02
$ns at 0.02 "$cbr start"

# part 6 = Bring down the link between node 2 and node 3 at 0.4
$ns at 0.4 "$ns duplex-link-op $node(2) $node(3) orient down"

# part 7 = Bring the dropped link back up at 1.0
$ns at 1.0 "$ns duplex-link-op $node(2) $node(3) orient up"

# part 8 = Finish the transmission at 1.5
$ns at 1.5 "$cbr stop"

# part 8 = End the simulation at 2.0
$ns at 2.0 "finish"

proc finish {} {
    global ns
    $ns halt
    $ns flush-trace
    exit 0
}

# part 9 =  procedure to monitor queue size between two nodes
proc monitorQueue {ns node1 node2 interval} {
    global ns
    set now [$ns now]
    set qmon [open "queue_${node1}_${node2}.txt" w]
    puts $qmon "Time QueueSize"
    $ns at $now "queueSize $node1 $node2 $qmon"
    $ns at [expr $now+$interval] "monitorQueue $ns $node1 $node2 $interval"
}

# part 9 = a procedure to get the queue size
proc queueSize {node1 node2 qmon} {
    global ns
    set queue [$ns link-queue $node1 $node2]
    set size [$queue size]
    set now [$ns now]
    puts $qmon "$now $size"
}

# part 9 = monitoring queue sizes
monitorQueue $ns $node(0) $node(1) 0.001
monitorQueue $ns $node(0) $node(6) 0.001

$ns run
