<?php
$now=strtotime (date("y-m-d h:i:s"));
$noip=strtotime ("2018-11-10 00:00:00");
$guonian=ceil(($zero2-$zero1)/86400);
$im=imagecreatetruecolor(400,400);
$red=imagecolorallocate($im,255,0,0);
for($i=0;$i<$guonian;$i++){
    $x=$i/10;
    $y=$i%10;
    imagerectangle($im,$x*40,$y*40,40,40,$red);
}

header("content-type:image/png");
imagepng($im);

imagedestory($im);
?>