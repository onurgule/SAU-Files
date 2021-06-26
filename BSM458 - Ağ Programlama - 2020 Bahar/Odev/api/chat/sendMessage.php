<?php

function sendMessage($uid,$type,$receiver,$msg){
include dirname(__DIR__) ."../../config/db.php";
$q = $db->prepare("CALL sendMessage(:uid,:type,:receiver,:msg)");
$q->execute(array("uid" => $uid, "type" => $type, "receiver"=>$receiver, "msg" => $msg));
}