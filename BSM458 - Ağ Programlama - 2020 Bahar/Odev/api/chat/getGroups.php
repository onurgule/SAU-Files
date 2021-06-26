<?php
session_name("sauchat");
session_start();
function getGroups(){
include dirname(__DIR__) ."../../config/db.php";
$uid = $_SESSION["uid"];
$q = $db->prepare("CALL getGroups(:uid)");
$q->execute(array("uid" => $uid));
$f = $q->fetchAll(PDO::FETCH_ASSOC);
return $f;
}