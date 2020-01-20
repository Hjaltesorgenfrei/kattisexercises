<?php

function print_diff($t1, $t2, $max)
{
    $i1 = intval($t1);
    $i2 = intval($t2);
    [$d1, $d2] = str_split($t1);
    [$d3, $d4] = str_split($t2);
    

}

[$h1, $m1] = explode(":", trim(fgets(STDIN)));
[$h2, $m2] = explode(":", trim(fgets(STDIN)));

print_diff($h1, $h2, 60);
print_diff($m1, $m2, 24);