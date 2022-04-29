#!/usr/bin/perl

$PATH = `pwd`;
chomp($PATH);
print("Source: ".$PATH. "\n\n");

$N = 36;
@benchs = ("MMPosix", "MM1cOMP","MM1fOMP");
@cargas = ("400","1000","1800","2600","3200");
@hilos = ("1", "2", "4", "6", "8");

foreach $b (@benchs){
    foreach $m (@cargas){
        foreach $h (@hilos){
            $file = "$PATH/"."registros/"."$b"."-$m"."-$h".".txt";
            for ($i = 0; $i < $N; $i++){
                system "$PATH/$b $m $h >> $file";
            }
            close $file; 
        }
    }
}
exit(0);