<?php
function replaceSpace($str)
{
    $str = explode(" ", $str);
    $merge = implode("%20", $str);
    return $merge;
}