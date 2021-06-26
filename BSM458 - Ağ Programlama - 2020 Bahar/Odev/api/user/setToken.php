<?php

function setToken($uid,$token,$online){
include dirname(__DIR__) ."../../config/db.php";
$q = $db->prepare("CALL setToken(:uid,:token,:online)");
$q->execute(array("uid" => $uid, "token" => $token, "online"=>$online));
}